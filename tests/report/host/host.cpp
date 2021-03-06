// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include <openenclave/host.h>
#include <openenclave/internal/aesm.h>
#include <openenclave/internal/error.h>
#include <openenclave/internal/hexdump.h>
#include <openenclave/internal/tests.h>
#include <openenclave/internal/utils.h>
#include <ctime>
#include <vector>
#include "../../../common/tcbinfo.h"
#include "../../../host/quote.h"
#include "../common/tests.cpp"
#include "tests_u.h"

#define SKIP_RETURN_CODE 2

extern void TestVerifyTCBInfo(oe_enclave_t* enclave);
extern std::vector<uint8_t> FileToBytes(const char* path);

void generate_and_save_report(oe_enclave_t* enclave)
{
#ifdef OE_USE_LIBSGX
    static uint8_t report[OE_MAX_REPORT_SIZE];
    size_t report_size = sizeof(report);
    OE_TEST(
        oe_get_report(
            enclave,
            OE_REPORT_FLAGS_REMOTE_ATTESTATION,
            NULL,
            0,
            report,
            &report_size) == OE_OK);

    FILE* file = fopen("./data/generated_report.bytes", "wb");
    fwrite(report, 1, report_size, file);
    fclose(file);
#endif
}

void load_and_verify_report()
{
#ifdef OE_USE_LIBSGX
    std::vector<uint8_t> report = FileToBytes("./data/generated_report.bytes");
    OE_TEST(
        oe_verify_report(NULL, &report[0], report.size() - 1, NULL) == OE_OK);
#endif
}

int main(int argc, const char* argv[])
{
    sgx_target_info_t target_info;
    oe_result_t result;
    oe_enclave_t* enclave = NULL;

    const uint32_t flags = oe_get_create_flags();
    if ((flags & OE_ENCLAVE_FLAG_SIMULATE) != 0)
    {
        printf(
            "=== Skipped unsupported test in simulation mode "
            "(report)\n");
        return SKIP_RETURN_CODE;
    }

    // Load and attest report without creating any enclaves.
    if (argc == 3 && strcmp(argv[2], "--attest-generated-report") == 0)
    {
        load_and_verify_report();
        return 0;
    }

    /* Check arguments */
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s ENCLAVE\n", argv[0]);
        exit(1);
    }

    /* Create the enclave */
    if ((result = oe_create_tests_enclave(
             argv[1], OE_ENCLAVE_TYPE_SGX, flags, NULL, 0, &enclave)) != OE_OK)
    {
        oe_put_err("oe_create_enclave(): result=%u", result);
    }

    /* Initialize the target info */
    {
        if ((result = sgx_get_qetarget_info(&target_info)) != OE_OK)
        {
            oe_put_err("sgx_get_qetarget_info(): result=%u", result);
        }
    }

    /*
     * Host API tests.
     */
    g_enclave = enclave;
    TestLocalReport(&target_info);
    TestRemoteReport(NULL);
    TestParseReportNegative(NULL);
    TestLocalVerifyReport(NULL);

#ifdef OE_USE_LIBSGX
    TestRemoteVerifyReport(NULL);

    OE_TEST(test_iso8601_time(enclave) == OE_OK);
    OE_TEST(test_iso8601_time_negative(enclave) == OE_OK);
#endif

    /*
     * Enclave API tests.
     */

    OE_TEST(oe_call_enclave(enclave, "TestLocalReport", &target_info) == OE_OK);

    OE_TEST(
        oe_call_enclave(enclave, "TestRemoteReport", &target_info) == OE_OK);

    OE_TEST(
        oe_call_enclave(enclave, "TestParseReportNegative", &target_info) ==
        OE_OK);

    OE_TEST(
        oe_call_enclave(enclave, "TestLocalVerifyReport", &target_info) ==
        OE_OK);

#ifdef OE_USE_LIBSGX
    OE_TEST(
        oe_call_enclave(enclave, "TestRemoteVerifyReport", &target_info) ==
        OE_OK);

    TestVerifyTCBInfo(enclave);

    // Get current time and pass it to enclave.
    std::time_t t = std::time(0);
    std::tm* tm = std::gmtime(&t);

    // convert std::tm to oe_datetime_t
    oe_datetime_t now = {(uint32_t)tm->tm_year + 1900,
                         (uint32_t)tm->tm_mon + 1,
                         (uint32_t)tm->tm_mday,
                         (uint32_t)tm->tm_hour,
                         (uint32_t)tm->tm_min,
                         (uint32_t)tm->tm_sec};
    test_minimum_issue_date(enclave, now);

    generate_and_save_report(enclave);
#endif

    /* Terminate the enclave */
    if ((result = oe_terminate_enclave(enclave)) != OE_OK)
    {
        oe_put_err("oe_terminate_enclave(): result=%u", result);
    }
    return 0;
}

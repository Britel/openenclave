// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

/**
 * \file raise.h
 *
 * This file defines macros to simplify functions that return oe_result_t.
 * For example, consider the following function definition.
 *
 *     oe_result_t Func1(const char* param)
 *     {
 *         oe_result_t result = OE_UNEXPECTED;
 *         oe_result_t r;
 *
 *         if (!param)
 *         {
 *             result = OE_INVALID_PARAMETER;
 *             goto done;
 *         }
 *
 *         r = Func2(param);
 *         if (r != OE_OK)
 *         {
 *             result = r;
 *             goto done;
 *         }
 *
 *         r = Func3(param);
 *         if (r != OE_OK)
 *         {
 *             result = r;
 *             goto done;
 *         }
 *
 *         result = OE_OK;
 *
 *     done:
 *         return result;
 *     }
 *
 * These macros can be used to simplify the function as follows.
 *
 *     oe_result_t Func1(const char* param)
 *     {
 *         oe_result_t result = OE_UNEXPECTED;
 *
 *         if (!param)
 *             OE_RAISE(OE_INVALID_PARAMETER);
 *
 *         OE_CHECK(Func2(param));
 *         OE_CHECK(Func3(param));
 *
 *         result = OE_OK;
 *
 *     done:
 *         return result;
 *     }
 *
 */

#ifndef _OE_RAISE_H
#define _OE_RAISE_H

#include <openenclave/bits/defs.h>
#include <openenclave/bits/result.h>
#include <openenclave/internal/trace.h>

OE_EXTERNC_BEGIN

#define OE_LOG_FLAGS_ATTESTATION   0x00000001
#define OE_LOG_FLAGS_GET_REPORT    0x00000002
#define OE_LOG_FLAGS_VERIFY_REPORT 0x00000004
#define OE_LOG_FLAGS_COMMON        0x00000008
#define OE_LOG_FLAGS_CERT          0x00000010
#define OE_LOG_FLAGS_TOOLS         0x00000020
#define OE_LOG_FLAGS_CRYPTO        0x00000040
#define OE_LOG_FLAGS_CRYPTO2       0x00000080
#define OE_LOG_FLAGS_SGX_SPECIFIC  0x00000100
#define OE_LOG_FLAGS_IMAGE_LOADING 0x00000200
#define OE_LOG_FLAGS_11            0x00000400
#define OE_LOG_FLAGS_12            0x00000800
#define OE_LOG_FLAGS_13            0x00001000
#define OE_LOG_FLAGS_14            0x00002000
#define OE_LOG_FLAGS_15            0x00004000
#define OE_LOG_FLAGS_16            0x00008000
#define OE_LOG_FLAGS_OTHERS        0x00010000
#define OE_LOG_FLAGS_ENC_HOST      0x40000000
#define OE_LOG_FLAGS_ENCLAVE       0x80000000
#define OE_LOG_FLAGS_ALL           0xffffffff

typedef enum _oe_log_level
{
    OE_LOG_LEVEL_NONE = 0,
    OE_LOG_LEVEL_ERROR = 1,
    OE_LOG_LEVEL_INFO = 2,
    OE_LOG_LEVEL_VERBOSE = 3
} _oe_log_level_t;

#define gLoggingLevel OE_LOG_LEVEL_INFO
#define gLoggingFlags OE_LOG_FLAGS_ALL

#define OE_TRACE(level, ...)   \
    if ((level <= gLoggingLevel) && (trace_flag & gLoggingFlags))\
        OE_PRINTF(__VA_ARGS__);

// This macro sets the 'result' and jumps to the 'done' label before print out a brief message
#define OE_RAISE(RESULT)        \
    do                          \
    {                           \
        result = (RESULT);      \
        if (result != OE_OK)            \
        {                               \
            OE_TRACE(OE_LOG_LEVEL_ERROR,\
            "Failed:%s:%s:%s:%d (%s)\n",        \
            ((trace_flag & OE_LOG_FLAGS_ENCLAVE) ? "e" : \
             (trace_flag & OE_LOG_FLAGS_ENC_HOST) ? "h" : "*"),\
            __FILE__, __FUNCTION__, __LINE__, oe_result_str(result));\
        }\
        goto done;                                               \
    } while (0)

// This macro checks whether the expression argument evaluates to OE_OK. If not, call OE_RAISE
#define OE_CHECK(EXPRESSION)                 \
    do                                       \
    {                                        \
        oe_result_t _result_ = (EXPRESSION); \
        if (_result_ != OE_OK)               \
            OE_RAISE(_result_);              \
    } while (0)

OE_EXTERNC_END

#endif /* _OE_RAISE_H */

# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

if (UNIX)
add_executable(hostcrypto
    main.c
    ../asn1_tests.c
    ../crl_tests.c
    ../ec_tests.c
    ../hash.c
    ../hmac_tests.c
    ../kdf_tests.c
    ../random_tests.c
    ../rsa_tests.c
    ../sha_tests.c
    ../tests.c
    ../utils.c)
else()
add_executable(hostcrypto
    main.c
    ../hash.c
    ../hmac_tests.c
    ../kdf_tests.c
    ../sha_tests.c
    ../tests.c
    ../utils.c)
endif()

target_link_libraries(hostcrypto oehost)

add_test(tests/crypto/host hostcrypto)

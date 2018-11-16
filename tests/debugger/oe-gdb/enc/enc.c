// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include <openenclave/enclave.h>
#include <stdio.h>
#include "oe_gdb_test_t.h"

int enc_add(int a, int b)
{
    int c = a + b;
    printf("hello: c = %d\n", c);
    printf("hello: c = %d\n", c);
    printf("hello: c = %d\n", c);
    return c;
}

int square(int x)
{
    printf("square called with %d\n", x);
    printf(
        "x lies %s\n",
        oe_is_within_enclave(&x, sizeof(x)) ? "within enclave"
                                            : "outside enclave");
    return x * x;
}

OE_SET_ENCLAVE_SGX(
    1,    /* ProductID */
    1,    /* SecurityVersion */
    true, /* AllowDebug */
    1024, /* HeapPageCount */
    1024, /* StackPageCount */
    2);   /* TCSCount */

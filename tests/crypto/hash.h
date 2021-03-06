// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef _TESTS_CRYPTO_HASH_H
#define _TESTS_CRYPTO_HASH_H

#include <openenclave/internal/sha.h>

/* Upper case alphabet */
extern const char* ALPHABET;

/* Hash of ALPHABET string above */
extern OE_SHA256 ALPHABET_HASH;

#endif /* _TESTS_CRYPTO_HASH_H */

#include <mbedtls/sha256.h>
#include "sha.h"

int fs_sha256(fs_sha256_t* hash, const void* data, size_t size)
{
    int ret = -1;
    mbedtls_sha256_context ctx;

    if (hash)
        memset(hash, 0, sizeof(fs_sha256_t));

    if (!hash || !data)
        goto done;

    mbedtls_sha256_init(&ctx);

    if (mbedtls_sha256_starts_ret(&ctx, 0) != 0)
        goto done;

    if (mbedtls_sha256_update_ret(&ctx, data, size) != 0)
        goto done;

    if (mbedtls_sha256_finish_ret(&ctx, hash->data) != 0)
        goto done;

    ret = 0;

done:
    return ret;
}
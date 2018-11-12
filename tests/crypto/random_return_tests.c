#define MAX_LOOP_SIZE 100000000
#include <openenclave/internal/tests.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../common/common.h"
void TestRandreturn()
{
    uint64_t rand_num;
    for (uint64_t i = 0; i < MAX_LOOP_SIZE; i++)
    {
        rand_num = _rdrand();

        OE_TEST(rand_num != 0);
    }
}

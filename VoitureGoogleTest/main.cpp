#include "tst_a.h"
#include "test_testvoitureroule.h"
#include "tst_testvoitureconstructor.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

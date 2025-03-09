// clang-format off
#include <gtest/gtest.h>
#include "Multithreaded_Memcpy.h"

int random_number() { return rand() % 10000; }

TEST(Memcpy, sanity_check)
{
    const int size = 50;
    const int size_bytes = sizeof(int) * size;

    int tab_src[size];
    memset(tab_src, random_number(), size_bytes);

    int tab_dest[size];
    memset(tab_dest, 0, size_bytes);

    memcpy(tab_dest, tab_src, size_bytes);


    EXPECT_EQ(memcmp(tab_src, tab_dest, size_bytes), 0);
}

TEST(Memcpy, my_memcpy_1)
{
    const int size = 5000;
    const int size_bytes = sizeof(int) * size;

    int tab_src[size];
    memset(tab_src, random_number(), size_bytes);

    int tab_dest[size];
    memset(tab_dest, 0, size_bytes);

    Multithreaded_Memcpy::cpy(tab_dest, tab_src, size_bytes, 1);

    EXPECT_EQ(memcmp(tab_src, tab_dest, size_bytes), 0);
}

TEST(Memcpy, my_memcpy_2)
{
    const int size = 5000;
    const int size_bytes = sizeof(int) * size;

    int tab_src[size];
    memset(tab_src, random_number(), size_bytes);

    int tab_dest[size];
    memset(tab_dest, 0, size_bytes);

    Multithreaded_Memcpy::cpy(tab_dest, tab_src, size_bytes, 2);

    EXPECT_EQ(memcmp(tab_src, tab_dest, size_bytes), 0);
}

TEST(Memcpy, my_memcpy_2_5001)
{
    const int size = 5001;
    const int size_bytes = sizeof(int) * size;

    int tab_src[size];
    memset(tab_src, random_number(), size_bytes);

    int tab_dest[size];
    memset(tab_dest, 0, size_bytes);

    Multithreaded_Memcpy::cpy(tab_dest, tab_src, size_bytes, 2);

    EXPECT_EQ(memcmp(tab_src, tab_dest, size_bytes), 0);
}

TEST(Memcpy, my_memcpy_3)
{
    const int size = 5000;
    const int size_bytes = sizeof(int) * size;

    int tab_src[size];
    memset(tab_src, random_number(), size_bytes);

    int tab_dest[size];
    memset(tab_dest, 0, size_bytes);

    Multithreaded_Memcpy::cpy(tab_dest, tab_src, size_bytes, 3);

    EXPECT_EQ(memcmp(tab_src, tab_dest, size_bytes), 0);
}

TEST(Memcpy, my_memcpy_7)
{
    const int size = 5001;
    const int size_bytes = sizeof(int) * size;

    int tab_src[size];
    memset(tab_src, random_number(), size_bytes);

    int tab_dest[size];
    memset(tab_dest, 0, size_bytes);

    Multithreaded_Memcpy::cpy(tab_dest, tab_src, size_bytes, 7);

    EXPECT_EQ(memcmp(tab_src, tab_dest, size_bytes), 0);
}

TEST(Memcpy, my_memcpy_7_1)
{
    const int size = 5000;
    const int size_bytes = sizeof(int) * size;

    int tab_src[size];
    memset(tab_src, random_number(), size_bytes);

    int tab_dest[size];
    memset(tab_dest, 0, size_bytes);

    Multithreaded_Memcpy::cpy(tab_dest, tab_src, size_bytes, 7);

    EXPECT_EQ(memcmp(tab_src, tab_dest, size_bytes), 0);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

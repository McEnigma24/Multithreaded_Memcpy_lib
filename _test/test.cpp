#include "Multithreaded_Memcpy.h"
#include "__preprocessor__.h"
#include <gtest/gtest.h>

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

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(tab_src[i], tab_dest[i]);
    }
}

TEST(Memcpy, my_memcpy_1)
{
    const int size = 5000;
    const int size_bytes = sizeof(int) * size;

    int tab_src[size];
    memset(tab_src, random_number(), size_bytes);

    int tab_dest[size];
    memset(tab_dest, 0, size_bytes);

    Multithreaded_Memcpy::cpy(tab_dest, tab_src, size, size_bytes, 1);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(tab_src[i], tab_dest[i]);
    }
}

TEST(Memcpy, my_memcpy_2)
{
    const int size = 5000;
    const int size_bytes = sizeof(int) * size;

    int tab_src[size];
    memset(tab_src, random_number(), size_bytes);

    int tab_dest[size];
    memset(tab_dest, 0, size_bytes);

    Multithreaded_Memcpy::cpy(tab_dest, tab_src, size, size_bytes, 2);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(tab_src[i], tab_dest[i]);
    }
}

TEST(Memcpy, my_memcpy_2_5001)
{
    const int size = 5001;
    const int size_bytes = sizeof(int) * size;

    int tab_src[size];
    memset(tab_src, random_number(), size_bytes);

    int tab_dest[size];
    memset(tab_dest, 0, size_bytes);

    Multithreaded_Memcpy::cpy(tab_dest, tab_src, size, size_bytes, 2);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(tab_src[i], tab_dest[i]);
    }
}

TEST(Memcpy, my_memcpy_3)
{
    const int size = 5000;
    const int size_bytes = sizeof(int) * size;

    int tab_src[size];
    memset(tab_src, random_number(), size_bytes);

    int tab_dest[size];
    memset(tab_dest, 0, size_bytes);

    Multithreaded_Memcpy::cpy(tab_dest, tab_src, size, size_bytes, 3);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(tab_src[i], tab_dest[i]);
    }
}

TEST(Memcpy, my_memcpy_7)
{
    const int size = 5001;
    const int size_bytes = sizeof(int) * size;

    int tab_src[size];
    memset(tab_src, random_number(), size_bytes);

    int tab_dest[size];
    memset(tab_dest, 0, size_bytes);

    Multithreaded_Memcpy::cpy(tab_dest, tab_src, size, size_bytes, 7);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(tab_src[i], tab_dest[i]);
    }
}

TEST(Memcpy, my_memcpy_7_1)
{
    const int size = 5000;
    const int size_bytes = sizeof(int) * size;

    int tab_src[size];
    memset(tab_src, random_number(), size_bytes);

    int tab_dest[size];
    memset(tab_dest, 0, size_bytes);

    Multithreaded_Memcpy::cpy(tab_dest, tab_src, size, size_bytes, 7);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(tab_src[i], tab_dest[i]);
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

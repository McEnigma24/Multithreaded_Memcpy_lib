#pragma once
#include "Nano_Timer.h"
#include "__preprocessor__.h"
#include <omp.h>

namespace Multithreaded_Memcpy
{
    void cpy_checks(char* dest, char* src, const size_t byte_size, const int thread_count)
    {
        if (nullptr == dest)
        {
            var(dest);
            FATAL_ERROR("nullptr in dest");
        }
        if (nullptr == src)
        {
            var(src);
            FATAL_ERROR("nullptr in src");
        }
        if (byte_size <= 0)
        {
            var(byte_size);
            FATAL_ERROR("INVALID byte_size");
        }
        if (thread_count <= 0)
        {
            var(thread_count);
            FATAL_ERROR("INVALID thread count");
        }
        if (omp_get_active_level() != 0) // called from parallel section
        {
            if (omp_get_nested() == false)
            {
                FATAL_ERROR("OMP_NESTED == false, this limits threads and only one will be active, which will lead to incorrect memcpy operation    "
                            "SET omp_set_nested(true), before first parallel section");
            }
        }
    }

    void cpy(char* dest, char* src, const size_t byte_size, const int thread_count)
    {
        cpy_checks(dest, src, byte_size, thread_count);

        const int chunk_byte_size = byte_size / thread_count;
        const int chunk_byte_size_additional = byte_size % thread_count;

        char* dest_tab[thread_count];
        char* src_tab[thread_count];

        for (int i = 0; i < thread_count; i++)
        {
            dest_tab[i] = dest;
            src_tab[i] = src;

            src += chunk_byte_size;
            dest += chunk_byte_size;

            if (i == 0)
            {
                src += chunk_byte_size_additional;
                dest += chunk_byte_size_additional;
            }
        }

        // clang-format off
        omp_set_num_threads(thread_count);
        #pragma omp parallel
        {
            int i = omp_get_thread_num();
            int local_chunk_byte_size = chunk_byte_size;

            if (i == 0) local_chunk_byte_size += chunk_byte_size_additional;

            memcpy(dest_tab[i], src_tab[i], local_chunk_byte_size);
        }
        // clang-format on
    }

    u64 check_how_many_threads_get_fastest_time(const size_t byte_size)
    {
        Nano_Timer::Timer t;
        u64 smallest_time = -1;
        u64 smallest_thread_num = 0;

        char* src = (char*)malloc(byte_size);
        char* dest = (char*)malloc(byte_size);

        for (int i = 1; i <= 18; i++)
        {
            const int all_reps = 30000;
            for (int reps = 0; reps < all_reps; reps++)
            {
                t.start();
                {
                    cpy(dest, src, byte_size, i);
                }
                t.stop();
            }

            u64 time = t.get_all_in_nano();
            // cout << setw(2) << i << ": " << setw(18) << time << "\n";

            if (time < smallest_time)
            {
                smallest_time = time;
                smallest_thread_num = i;
            }

            t.reset();
        }

        // cout << "The winner for byte_size " << byte_size << " is " << smallest_thread_num << "\n";

        return smallest_thread_num;
    }
}; // namespace Multithreaded_Memcpy

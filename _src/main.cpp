#include "Multithreaded_Memcpy.h"
#include "__preprocessor__.h"
#include "__time_stamp__.h"

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    srand(time(NULL));
    // CORE::clear_terminal(); // tests might not be visible
    time_stamp("It just works");

    const int size_bytes = sizeof(int) * 230000;
    int smallest_thread_num = Multithreaded_Memcpy::check_how_many_threads_get_fastest_time_std_memcpy(size_bytes);

    cout << "STD         -> The winner for byte_size " << CORE::format_number(size_bytes) << " is " << smallest_thread_num << "\n";

    int smallest_thread_num_simd_stream = Multithreaded_Memcpy::check_how_many_threads_get_fastest_time_simd_stream_memcpy(size_bytes);
    cout << "SIMD Stream -> The winner for byte_size " << CORE::format_number(size_bytes) << " is " << smallest_thread_num_simd_stream << "\n";

    return 0;
}
#endif
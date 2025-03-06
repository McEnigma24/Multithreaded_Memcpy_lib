#include "Multithreaded_Memcpy.h"
#include "__preprocessor__.h"
#include "__time_stamp__.h"

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    srand(time(NULL));
    // CORE::clear_terminal(); // test might no be visible
    time_stamp("It just works");

    const int size_bytes = sizeof(int) * 230000;
    Multithreaded_Memcpy::check_how_many_thread_get_fastest_time(size_bytes);

    return 0;
}
#endif
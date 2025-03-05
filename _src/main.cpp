#include "__preprocessor__.h"
#include "__time_stamp__.h"

class test
{
    int tab[100];
};

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    srand(time(NULL));
    CORE::clear_terminal();
    time_stamp("It just works");

    CORE::str::split_string("Hello, World!", ' ');
    var(CORE::str::to_lower_case("Hello, World!"));

    show_sizeof(test);
    show_sizeof_many(test, 100);

    return 0;
}
#endif
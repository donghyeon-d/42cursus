#include <climits>
#include <iostream>
#include <sstream>
#include "Convert.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        Convert a(argv[1]);
        a.display();
    }
}
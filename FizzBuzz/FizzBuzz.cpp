#include <sstream> // Drew: Added to support output streams.
#include <iostream>
#include <algorithm>
#include <numeric> // Drew: std::iota is found in the numeric standard library header on Microsoft compilers, not algorithm.
#include <vector>
#include "FizzBuzz.h"

// FizzBuzz C++ implementation taken from https://rosettacode.org/wiki/FizzBuzz#with_modulo
using namespace std;

//int main()
// Modified the main function to take an output stream, cout replaced with os which defaults to cout if not specified.
int main_FizzBuzz_with_modulo(std::ostream& os)
{
    for (int i = 1; i <= 100; i++)
    {
        if ((i % 15) == 0)
            os << "FizzBuzz\n";
        else if ((i % 3) == 0)
            os << "Fizz\n";
        else if ((i % 5) == 0)
            os << "Buzz\n";
        else
            os << i << "\n";
    }
    return 0;
}


// FizzBuzz C++ implementation taken from https://rosettacode.org/wiki/FizzBuzz#without_modulo_15
using namespace std;

//int main()
// Modified the main function to take an output stream, cout replaced with os which defaults to cout if not specified.
int main_FizzBuzz_without_modulo_15(std::ostream& os)
{
    for (int i = 0; i <= 100; ++i)
    {
        bool fizz = (i % 3) == 0;
        bool buzz = (i % 5) == 0;
        if (fizz)
            os << "Fizz";
        if (buzz)
            os << "Buzz";
        if (!fizz && !buzz)
            os << i;
        os << "\n";
    }
    return 0;
}

// FizzBuzz C++ implementation taken from https://rosettacode.org/wiki/FizzBuzz#without_modulo

//int main()
// Modified the main function to take an output stream, cout replaced with os which defaults to cout if not specified.
int main_FizzBuzz_without_modulo(std::ostream& os)
{
    int i, f = 2, b = 4;

    for (i = 1; i <= 100; ++i, --f, --b)
    {
        if (f && b) { os << i; }
        if (!f) { os << "Fizz"; f = 3; }
        if (!b) { os << "Buzz"; b = 5; }
        os << std::endl;
    }

    return 0;
}

// FizzBuzz C++ implementation taken from https://rosettacode.org/wiki/FizzBuzz#using_std::transform

//int main()
// Modified the main function to take an output stream, cout replaced with os which defaults to cout if not specified.
int main_FizzBuzz_using_std_transform(std::ostream& os)
{
    std::vector<int> range(100);
    std::iota(range.begin(), range.end(), 1);

    std::vector<std::string> values;
    values.resize(range.size());

    auto fizzbuzz = [](int i) -> std::string {
        if ((i % 15) == 0) return "FizzBuzz";
        if ((i % 5) == 0)  return "Buzz";
        if ((i % 3) == 0)  return "Fizz";
        return std::to_string(i);
    };

    std::transform(range.begin(), range.end(), values.begin(), fizzbuzz);

    for (auto& str : values) os << str << std::endl;

    return 0;
}

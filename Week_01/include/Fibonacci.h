//
// Created by aldin on 19/02/2025.
//

#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <string>

// type alias, to avoid copy-pasting unsigned long long int every time :)
using longest = unsigned long long int;

namespace Fibonacci {
    longest recursive(longest n);
    longest iterative(longest n);
    void evaluate(const std::string& algorithm);
}

#endif //FIBONACCI_H

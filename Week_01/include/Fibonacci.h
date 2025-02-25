//
// Created by aldin on 19/02/2025.
//

#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iostream>
#include <chrono>
#include <string>

using longest = unsigned long long int;

namespace Fibonacci {
    longest recursive(longest n);
    longest iterative(longest n);
    void evaluate(const std::string& algorithm);
    static void calculate_times(const std::string& algorithm, longest n);
};

#endif //FIBONACCI_H
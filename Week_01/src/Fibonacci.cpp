//
// Created by aldin on 19/02/2025.
//
#include "../include/Fibonacci.h"

#include <chrono>
#include <iostream>
#include <vector>

// F(93) is the largest Fibonacci number that fits in an unsigned long long
static constexpr longest ITERATIVE_LIMIT = 90;
static constexpr longest RECURSIVE_LIMIT = 40;

static void calculate_times(const std::string& algorithm, longest n);

longest Fibonacci::recursive(const longest n) {
    if (n <= 1) {
        return n;
    }
    return recursive(n - 1) + recursive(n - 2);
}

longest Fibonacci::iterative(const longest n) {
    std::vector<longest> fib(n + 1);

    fib[0] = 0;
    if (n > 0) {
        fib[1] = 1;
        for (longest i = 2; i <= n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }
    return fib[n];
}

void Fibonacci::evaluate(const std::string& algorithm) {
    const longest limit = algorithm == "recursive" ? RECURSIVE_LIMIT : ITERATIVE_LIMIT;
    for (longest i = 10; i <= limit; i += 10) {
        calculate_times(algorithm, i);
    }
}

static void calculate_times(const std::string& algorithm, const longest n) {
    const auto start = std::chrono::high_resolution_clock::now();

    longest result{};
    if (algorithm == "recursive") {
        result = Fibonacci::recursive(n);
    } else if (algorithm == "iterative") {
        result = Fibonacci::iterative(n);
    } else {
        std::cout << algorithm << " is not recognized" << std::endl;
        return;
    }

    const auto stop = std::chrono::high_resolution_clock::now();
    const auto nanoDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    const auto microDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    const auto milliDuration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    const auto secDuration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

    std::cout << "Algorithm: " << algorithm << " | n = " << n << std::endl;
    std::cout << "Result: " << result << std::endl;
    std::cout << "Elapsed time: "
        << nanoDuration.count() << " ns \t "
        << microDuration.count() << " μs \t "
        << milliDuration.count() << " ms \t "
        << secDuration.count() << " s"
        << std::endl;
    std::cout << std::endl;
}

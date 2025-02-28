//
// Created by aldin on 19/02/2025.
//
#include "../include/Fibonacci.h"

#include "../include/MemoryPerf.h"
#include <chrono>

longest Fibonacci::recursive(const longest n) {
    if (n <= 1) {
        return n;
    }
    return recursive(n - 1) + recursive(n - 2);
}

longest Fibonacci::iterative(const longest n) {
    longest fib[n + 1]{};

    fib[0] = 0;
    if (n > 0) {
        fib[1] = 1;
        for (int i = 2; i <= n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }
    return fib[n];
}

void Fibonacci::evaluate(const std::string& algorithm) {
    for (int i = 10; i <= 200; i += 10) {
        calculate_times(algorithm, i);
    }
}

void Fibonacci::calculate_times(const std::string& algorithm, const longest n) {
    const auto start = std::chrono::high_resolution_clock::now();

    longest result{};
    if (algorithm == "recursive") {
        result = recursive(n);
    } else if (algorithm == "iterative") {
        result =  iterative(n);
    } else {
        std::cout << algorithm << " is not recognized" << std::endl;
        return;
    }

    const auto stop = std::chrono::high_resolution_clock::now();
    const auto nanoDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    const auto microDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    const auto milliDuration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    const auto secDuration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

    std::cout << "Algorithm: " << algorithm << " | " << n << " elements" << std::endl;
    std::cout << "Result: " << result << std::endl;
    std::cout << "Elapsed time: "
        << nanoDuration.count() << " ns \t "
        << microDuration.count() << " μs \t "
        << milliDuration.count() << " ms \t "
        << secDuration.count() << " s"
        << std::endl;
    std::cout << std::endl;
}

//
// Created by aldin on 19/02/2025.
//

#include <iostream>

#include "../include/Fibonacci.h"

int main() {
    std::cout << "Fibonacci (recursive): " << Fibonacci::recursive(10) << std::endl;
    std::cout << "Fibonacci (iterative): " << Fibonacci::iterative(10) << std::endl;
    std::cout << std::endl;
    Fibonacci::evaluate("iterative");
}




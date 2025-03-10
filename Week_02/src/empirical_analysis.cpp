//
// Created by aldin on 10/03/2025.
//

#include <cstdlib>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "../../Week_01/include/MemoryPerf.h"
#include "../../Week_02/include/LinkedList.h"

#define ARR_SIZE 100000
#define SAMPLE_SIZE 10

int* generate_array(int len);
LinkedList<int> generate_linked_list(int len);
void evaluate_structure(std::string&& name);
void sleep(int ms);

int main() {
    evaluate_structure("array");
    std::cout << std::endl;
    evaluate_structure("linked_list");
}

void evaluate_structure(std::string&& name) {
    // Force garbage collection and memory stabilization
    sleep(100);

    // Take multiple samples before
    std::vector<size_t> before_samples;
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        before_samples.push_back(MemoryPerf::get_memory_usage());
        sleep(10);
    }

    // Calculate average before
    size_t start_memory = 0;
    for (const auto sample : before_samples) {
        start_memory += sample;
    }
    start_memory /= before_samples.size();

    // Fill in the data structure
    int* arr = nullptr;
    LinkedList<int>* list = nullptr;

    if (name == "array") {
        arr = generate_array(ARR_SIZE);
    } else if (name == "linked_list") {
        list = new LinkedList<int>(generate_linked_list(ARR_SIZE));
    } else {
        std::cout << "Unsupported data structure" << std::endl;
        exit(1);
    }

    // Force memory allocation to complete
    sleep(100);

    // Take multiple samples after
    std::vector<size_t> after_samples;
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        after_samples.push_back(MemoryPerf::get_memory_usage());
        sleep(10);
    }

    // Calculate average after
    size_t end_memory = 0;
    for (const auto sample : after_samples) {
        end_memory += sample;
    }
    end_memory /= after_samples.size();

    const auto total_memory = end_memory - start_memory;

    std::cout << "Data structure: " << name << std::endl;
    std::cout << "Start memory: " << MemoryPerf::format_memory_usage(start_memory) << std::endl;
    std::cout << "End memory: " << MemoryPerf::format_memory_usage(end_memory) << std::endl;
    std::cout << "Total memory used: " << MemoryPerf::format_memory_usage(total_memory) << std::endl;

    delete[] arr;
    delete list;
}

int* generate_array(const int len) {
    int* arr = new int[len];
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % (len * 10);
    }
    return arr;
}

LinkedList<int> generate_linked_list(const int len) {
    LinkedList<int> list;
    for (int i = 0; i < len; i++) {
        list.add_to_front( rand() % (len * 10));
    }
    return list;
}

void sleep(const int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
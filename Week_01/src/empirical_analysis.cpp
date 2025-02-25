#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <random>
#include <thread>

#include "../include/MemoryPerf.h"

#define ARR_SIZE 100000
#define SAMPLE_SIZE 10

std::vector<int> generate_array(int len);
std::vector<int> find_unique_elements_array(const std::vector<int>& arr);
std::vector<int> find_unique_elements_hashmap(const std::vector<int>& arr);
void evaluate_structure(std::string&& name);
void sleep(int ms);

int main() {
    evaluate_structure("array");
    std::cout << std::endl;
    evaluate_structure("hashmap");
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
    std::vector<int> arr = generate_array(ARR_SIZE);
    std::vector<int> result;

    const auto start = std::chrono::high_resolution_clock::now();
    if (name == "array") {
        result = find_unique_elements_array(arr);
    } else if (name == "hashmap") {
        result = find_unique_elements_hashmap(arr);
    } else {
        std::cout << "Unsupported data structure" << std::endl;
        exit(1);
    }
    const auto stop = std::chrono::high_resolution_clock::now();

    const auto nanoDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    const auto microDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    const auto milliDuration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    const auto secDuration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

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
    std::cout << "- Elapsed time: "
        << nanoDuration.count() << " ns \t "
        << microDuration.count() << " μs \t "
        << milliDuration.count() << " ms \t "
        << secDuration.count() << " s"
        << std::endl;
    std::cout << "- Total memory used: " << MemoryPerf::format_memory_usage(total_memory) << std::endl;
    std::cout << std::endl;
}

std::vector<int> generate_array(const int len) {
    std::vector<int> arr;
    arr.reserve(len);
    for (int i = 0; i < len; i++) {
        arr.emplace_back(rand() % (len * 10));
    }
    return arr;
}

void sleep(const int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

std::vector<int> find_unique_elements_array(const std::vector<int>& arr) {
    std::vector<int> result;

    for (size_t i = 0; i < arr.size(); i++) {
        bool isDuplicate = false;

        for (size_t j = 0; j < arr.size(); j++) {
            if (i != j && arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            result.push_back(arr[i]);
        }
    }

    return result;
}

std::vector<int> find_unique_elements_hashmap(const std::vector<int>& arr) {
    std::unordered_map<int, int> frequency;
    std::vector<int> result;

    for (const int& value : arr) {
        frequency[value]++;
    }

    for (const int& value : arr) {
        if (frequency[value] == 1) {
            result.push_back(value);
        }
    }

    return result;
}

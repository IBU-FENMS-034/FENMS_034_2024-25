//
// Created by aldin on 25/03/2025.
//

#include "../include/FileUtils.h"
#include <fstream>
#include <iostream>
#include <sstream>

FileUtils::FileUtils(const std::string &fileName) {
    ips = new IPAddress[NUM_IPS];

    std::ifstream file(fileName);
    std::string line;
    int i = 0;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file at " << fileName << std::endl;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        std::string* tokens = new std::string[6];

        int t = 0;
        while (std::getline(ss, token, ';')) {
            tokens[t++] = token;
        }

        if (t >= 6) {
            long start = std::stol(tokens[0]);
            long end = std::stol(tokens[1]);
            ips[i++] = IPAddress(start, end, tokens[2], tokens[3], tokens[4], tokens[5]);
        }

        delete [] tokens;
    }
}

FileUtils::~FileUtils() {
    delete[] ips;
}


IPAddress *FileUtils::get_all_ips() const {
    return ips;
}
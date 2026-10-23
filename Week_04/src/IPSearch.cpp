//
// Created by aldin on 25/03/2025.
//

#include "../include/IPSearch.h"
#include <iostream>
#include <sstream>

#include "../include/FileUtils.h"

long IPSearch::convert_to_ip_number(const std::string& ip) {
    std::stringstream ss(ip);
    std::string octet;
    long ip_number = 0;
    int count = 0;

    while (std::getline(ss, octet, '.')) {
        long value = std::stol(octet);
        if (value < 0 || value > 255) {
            return -1;
        }
        ip_number = ip_number * 256 + value;
        ++count;
    }

    if (count != 4) {
        return -1;
    }
    return ip_number;
}

IPAddress* IPSearch::search(IPAddress* ips, const std::string& ip) {
    long ip_number = convert_to_ip_number(ip);
    if (ip_number < 0) {
        return nullptr;
    }

    int low = 0;
    int high = NUM_IPS - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (ip_number < ips[mid].start_ip) {
            high = mid - 1;
        } else if (ip_number > ips[mid].end_ip) {
            low = mid + 1;
        } else {
            return &ips[mid];
        }
    }
    return nullptr;
}
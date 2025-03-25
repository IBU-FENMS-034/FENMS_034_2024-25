//
// Created by aldin on 25/03/2025.
//

#ifndef IPADDRESS_H
#define IPADDRESS_H
#include <string>
#include <utility>

struct IPAddress {
    long start_ip{};
    long end_ip{};
    std::string country_code{"-"};
    std::string country_name{"-"};
    std::string region{"-"};
    std::string city{"-"};

    IPAddress() = default;

    IPAddress(const long start, const long end, std::string cc, std::string cn, std::string reg, std::string cty) :
        start_ip(start), end_ip(end),
        country_code(std::move(cc)), country_name(std::move(cn)),
        region(std::move(reg)), city(std::move(cty)) {}
};

#endif //IPADDRESS_H

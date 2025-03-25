//
// Created by aldin on 25/03/2025.
//

#ifndef IPSEARCH_H
#define IPSEARCH_H
#include "IPAddress.h"

class IPSearch {
public:
    static IPAddress* search(IPAddress* ips, const std::string& ip);
    static long convert_to_ip_number(const std::string& ip);
};

#endif //IPSEARCH_H

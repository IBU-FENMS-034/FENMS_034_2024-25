//
// Created by aldin on 14/02/2025.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/Search.h"
#include "../include/Sort.h"
#include <doctest/doctest.h>

#include "../include/IPAddress.h"
#include "../include/FileUtils.h"
#include "../include/IPSearch.h"

// IMPORTANT: DO NOT commit the entire CSV file; add it to .gitignore or keep it outside the repository.
#define FILE_PATH "../resources/IP2LOCATION.csv" // <-- Change path

TEST_CASE("Valid IP address lookups") {
    FileUtils file(FILE_PATH);

    struct TestCase {
        std::string queryIP;
        long start, end;
        std::string cc, country, region, city;
    };

    std::vector<TestCase> cases = {
        { "199.103.106.121", 3345443328L, 3345443583L, "CH", "SWITZERLAND", "BERN", "BERN" },
        { "201.116.231.242", 3379879936L, 3379884543L, "MX", "MEXICO", "DISTRITO FEDERAL", "MEXICO CITY" },
        { "189.2.141.102",   3171061088L, 3171061103L, "BR", "BRAZIL", "RIO DE JANEIRO", "RIO DE JANEIRO" },
        { "221.107.165.82",  3714534912L, 3714839295L, "JP", "JAPAN", "TOKYO", "TOKYO" },
        { "213.33.83.106",   3575730432L, 3575731455L, "AT", "AUSTRIA", "WIEN", "VIENNA" },
        { "85.239.1.253",    1441726464L, 1441729023L, "KW", "KUWAIT", "AL ASIMAH", "KUWAIT" },
        { "112.72.24.183",   1883770880L, 1883783167L, "KR", "KOREA, REPUBLIC OF", "KYONGGI-DO", "SUWON" },
        { "28.144.226.114",  469762048L,  520093695L,  "US", "UNITED STATES", "OHIO", "COLUMBUS" },
        { "9.117.114.203",   156626432L,  159386111L,  "US", "UNITED STATES", "NEW YORK", "ARMONK" },
        { "127.0.0.1",       2130706432L, 2147483647L, "-", "-", "-", "-" }
    };

    for (const auto& c : cases) {
        IPAddress* ip = IPSearch::search(file.get_all_ips(), c.queryIP);
        REQUIRE(ip != nullptr);
        CHECK(ip->start_ip == c.start);
        CHECK(ip->end_ip == c.end);
        CHECK(ip->country_code == c.cc);
        CHECK(ip->country_name == c.country);
        CHECK(ip->region == c.region);
        CHECK(ip->city == c.city);
    }
}

TEST_CASE("Invalid IP address lookups") {
    FileUtils file(FILE_PATH);

    std::vector<std::string> invalidIPs = {
        "255.255.255.260",
        "435.352.234.566"
    };

    for (const auto& ip : invalidIPs) {
        IPAddress* result = IPSearch::search(file.get_all_ips(), ip);
        CHECK(result == nullptr);
    }
}

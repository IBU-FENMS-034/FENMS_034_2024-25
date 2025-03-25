//
// Created by aldin on 25/03/2025.
//

#ifndef FILEUTILS_H
#define FILEUTILS_H
#include "IPAddress.h"

#define NUM_IPS 4637053

class FileUtils {
private:
    IPAddress* ips{};
public:
    explicit FileUtils(const std::string& fileName);
    ~FileUtils();
    [[nodiscard]] IPAddress* get_all_ips() const;
};

#endif //FILEUTILS_H

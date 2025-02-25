//
// Created by aldin on 21/02/2025.
//

#ifndef MEMORYPERF_H
#define MEMORYPERF_H

#include <iostream>
#include <string>

#if defined(_WIN32)
    #include <windows.h>
    #include <psapi.h>
#elif defined(__unix__) || defined(__APPLE__)
    #include <sys/resource.h>
    #include <unistd.h>
#endif

namespace MemoryPerf {
    inline size_t get_memory_usage() {
#if defined(_WIN32)
        PROCESS_MEMORY_COUNTERS_EX pmc;
        if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
            // Use PrivateUsage instead of WorkingSetSize for more accurate measurements
            return pmc.PrivateUsage;
        }
#elif defined(__unix__)
        // On Linux, read from /proc/self/statm for more accurate measurements
        FILE* fp = fopen("/proc/self/statm", "r");
        if (fp) {
            long rss = 0;
            if (fscanf(fp, "%*s%ld", &rss) == 1) {
                fclose(fp);
                return rss * sysconf(_SC_PAGESIZE);
            }
            fclose(fp);
        }
        // Fallback to rusage if /proc/self/statm fails
        struct rusage usage;
        if (getrusage(RUSAGE_SELF, &usage) == 0) {
            return usage.ru_maxrss * 1024;
        }
#elif defined(__APPLE__)
        struct rusage usage;
        if (getrusage(RUSAGE_SELF, &usage) == 0) {
            return usage.ru_maxrss * 1024;
        }
#endif
        return 0;
    }

    inline std::string format_memory_usage(size_t bytes) {
        const char* units[] = {"B", "KB", "MB", "GB"};
        int i = 0;
        double size = bytes;

        while (size >= 1024 && i < 3) {
            size /= 1024;
            i++;
        }

        char buffer[32];
        snprintf(buffer, sizeof(buffer), "%.2f %s", size, units[i]);
        return std::string(buffer);
    }
};

#endif //MEMORYPERF_H
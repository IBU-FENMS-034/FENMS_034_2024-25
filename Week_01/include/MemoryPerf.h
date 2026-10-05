//
// Created by aldin on 21/02/2025.
//

#ifndef MEMORYPERF_H
#define MEMORYPERF_H

#include <cstddef>
#include <cstdio>
#include <string>

#if defined(_WIN32)
    #include <windows.h>
    #include <psapi.h>
#elif defined(__APPLE__)
    #include <mach/mach.h>
#elif defined(__unix__)
    #include <sys/resource.h>
    #include <unistd.h>
#endif

namespace MemoryPerf {
    inline std::size_t get_memory_usage() {
#if defined(_WIN32)
        PROCESS_MEMORY_COUNTERS_EX pmc;
        if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
            // Use PrivateUsage instead of WorkingSetSize for more accurate measurements
            return pmc.PrivateUsage;
        }
#elif defined(__unix__)
        // On Linux, read from /proc/self/statm for more accurate measurements
        std::FILE* fp = std::fopen("/proc/self/statm", "r");
        if (fp) {
            long rss = 0;
            if (std::fscanf(fp, "%*s%ld", &rss) == 1) {
                std::fclose(fp);
                return rss * sysconf(_SC_PAGESIZE);
            }
            std::fclose(fp);
        }
        // Fallback to rusage if /proc/self/statm fails
        struct rusage usage;
        if (getrusage(RUSAGE_SELF, &usage) == 0) {
            return usage.ru_maxrss * 1024;
        }
#elif defined(__APPLE__)
        mach_task_basic_info_data_t info;
        mach_msg_type_number_t count = MACH_TASK_BASIC_INFO_COUNT;
        if (task_info(mach_task_self(), MACH_TASK_BASIC_INFO,
                      reinterpret_cast<task_info_t>(&info), &count) == KERN_SUCCESS) {
            return info.resident_size;
        }
#endif
        return 0;
    }

    inline std::string format_memory_usage(std::size_t bytes) {
        const char* units[] = {"B", "KB", "MB", "GB"};
        int i = 0;
        double size = static_cast<double>(bytes);

        while (size >= 1024 && i < 3) {
            size /= 1024;
            i++;
        }

        char buffer[32];
        std::snprintf(buffer, sizeof(buffer), "%.2f %s", size, units[i]);
        return std::string(buffer);
    }
}

#endif //MEMORYPERF_H
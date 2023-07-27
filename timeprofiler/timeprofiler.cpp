#include <memory>
#include "include/timeprofiler/timeprofiler.hpp"

#if defined(PROFILE_ENABLED)
std::atomic_uint32_t function_hash_counter = 0;
std::vector<funcInfo> FunctionData(100000);
TimeProfilerLogger time_profiler_logger;

bool TimeProfiler_ENABLED_ = true;

TimeProfiler::TimeProfiler(uint32_t& functionName)
    : functionNameHash_(functionName) {
    if (TimeProfiler_ENABLED_) {
        start_ = std::chrono::high_resolution_clock::now();
    }
}

TimeProfiler::~TimeProfiler() {
    if (TimeProfiler_ENABLED_) {
        const auto end = std::chrono::high_resolution_clock::now();
        const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start_);
        FunctionData[functionNameHash_].increment_counters(duration.count(),duration.count()*duration.count(),1);
    }
}

TimeProfilerLogger::~TimeProfilerLogger() {
    std::ofstream out("TimeProfiler.txt");
    out.precision(15);
    for (int i = 0; i < function_hash_counter; ++i) {
        out << FunctionData[i].funcName << ":" << std::endl;
        out << "    Call count: " << FunctionData[i].callCnt << std::endl;
        out << "    AVG time: " << ((double) FunctionData[i].runTime) / FunctionData[i].callCnt << " μs" << std::endl;
        out << "    STD DEV time: " << sqrt((((double) FunctionData[i].SqRunTime) / FunctionData[i].callCnt)
                                                - (((double) FunctionData[i].runTime) / FunctionData[i].callCnt)
                                                    * (((double) FunctionData[i].runTime) / FunctionData[i].callCnt))
            << " μs"
            << std::endl;
        out << "----------------------------------------" << std::endl;
    }
    out.close();
};
#endif

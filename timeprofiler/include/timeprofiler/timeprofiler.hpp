#ifndef TIMEPROFILER_TIMEPROFILER_HPP
#define TIMEPROFILER_TIMEPROFILER_HPP

#include <chrono>
#include <fstream>
#include <mutex>
#include <iostream>
#include <string>
#include <unordered_map>
#include <atomic>
#include <cmath>
#include<vector>

#if defined(PROFILE_ENABLED)

struct funcInfo {
    std::atomic<const char *> funcName;
    std::atomic_long runTime{0};
    std::atomic_long SqRunTime{0};
    std::atomic_int callCnt{0};

    void increment_counters(long rt, long st, int cc) {
        runTime.fetch_add(rt, std::memory_order_relaxed);
        SqRunTime.fetch_add(st, std::memory_order_relaxed);
        callCnt.fetch_add(cc, std::memory_order_relaxed);
    }


    bool set_name(const char *new_name) {
        funcName.store(new_name, std::memory_order_relaxed);
        return true;
    }

};

class TimeProfilerLogger {
public:
    TimeProfilerLogger() = default;

    ~TimeProfilerLogger();
};

class TimeProfiler {
public:
    TimeProfiler(uint32_t &);

    ~TimeProfiler();

private:
    uint32_t functionNameHash_;
    std::chrono::high_resolution_clock::time_point start_;

};

extern std::atomic_uint32_t function_hash_counter;
extern std::vector<funcInfo> FunctionData;
extern bool TimeProfiler_ENABLED_;
extern TimeProfilerLogger time_profiler_logger;

#define PROFILE_SCOPE() \
    static uint32_t function_hash##__func__ = TimeProfiler_ENABLED_ ?  function_hash_counter.fetch_add(1, std::memory_order_acq_rel) : -1; \
    if(TimeProfiler_ENABLED_)   {                 \
        static bool set_name##__func__  = FunctionData[function_hash##__func__].set_name(__func__);                  \
    }                    \
    TimeProfiler profiler##__func__(function_hash##__func__);
#define PROFILE_ON()  TimeProfiler_ENABLED_ = true;
#define PROFILE_OFF() TimeProfiler_ENABLED_ = false;
#else
#define PROFILE_SCOPE()
#define PROFILE_ON()
#define PROFILE_OFF()
#endif

#endif //TIMEPROFILER_TIMEPROFILER_HPP


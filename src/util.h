#pragma once

#ifndef SILENCE_TEXT

#include <iostream>
#include <chrono>

#define PI 3.1415926535897932384626433832795028841

#define LOG(a) std::cout << "Log: " << a << "\n";

#define ERR(message) \
    std::cerr << "[Error]" << message \
    << "\n  File: " << __FILE__ \
    <<  "\n  Function: " << __FUNCTION__ \
    << "\n  Line: " << __LINE__ << "\n"

#define WARN(message) \
    std::cerr << "[Warning]" << message \
    << "\n  File: " << __FILE__ \
    << "\n  Function: " << __FUNCTION__ \
    << "\n  Line: " << __LINE__ << "\n"

#define INFO(message) \
    std::cout << "[Info]" << message \
    << "\n  File: " << __FILE__ \
    << "\n  Function: " << __FUNCTION__ \
    << "\n  Line: " << __LINE__ << "\n"

#define ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            ERR("[Assertion failed]" << message); \
            std::terminate(); \
        } \
    } while (0)

#define TRACK_PERFORMANCE(message, code) \
    do { \
        auto start = std::chrono::high_resolution_clock::now(); \
        code; \
        auto end = std::chrono::high_resolution_clock::now(); \
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); \
        INFO(message << " - Duration: " << duration << " microseconds"); \
    } while (0)

#else

#define LOG(a) 
#define ERR(message)
#define WARN(message)
#define INFO(message)
#define ASSERT(condition, message)
#define TRACK_PERFORMANCE(message, code)

#endif
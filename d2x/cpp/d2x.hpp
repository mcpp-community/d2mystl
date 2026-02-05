#ifndef D2X_HPP__D2X
#define D2X_HPP__D2X

#include <iostream>
#include <string>
#include <source_location>
#include <format>

namespace d2x {
    inline void wait(const std::source_location& loc = std::source_location::current()) {
        std::cout << std::format("\033[33m{}:{} - 🥳 D2X_WAIT: Delete the 'd2x::wait()' or '//d2x::wait()' to continue...\033[0m\n", loc.file_name(), loc.line());
    }

    template <typename T1, typename T2>
    inline bool assert_eq(const T1& a, const T2& b, const std::string& msg = "",
                          const std::source_location& loc = std::source_location::current()) {
        if (a != b) {
            std::cout << std::format("\033[31m{}:{} - ❌(error) | Assertion failed: {} != {}. {}\033[0m\n", 
                        loc.file_name(), loc.line(), a, b, msg);
            return false;
        }
        std::cout << std::format("\033[32m{}:{} - ✅ Assertion passed: {} == {}\033[0m\n", 
                    loc.file_name(), loc.line(), a, b);
        return true;
    }

    inline bool assert_true(bool condition, const std::string& msg = "",
                            const std::source_location& loc = std::source_location::current()) {
        if (!(condition)) {
            std::cout << std::format("\033[31m{}:{} - ❌(error) | Assertion failed: condition is false. {}\033[0m\n", 
                        loc.file_name(), loc.line(), msg);
            return false;
        }
        std::cout << std::format("\033[32m{}:{} - ✅ Assertion passed: condition is true\033[0m\n", 
                    loc.file_name(), loc.line());
        return true;
    }
}

#endif
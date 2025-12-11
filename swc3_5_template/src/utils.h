#pragma once

#include <source_location>
#include <cassert>
#include "templates.h"

// NOTE: anonymous namespace for private implementation details
namespace {
    template<typename T>
    concept Printable = requires(std::ostream &os, const T &value) {
        { os << value } -> std::same_as<std::ostream &>;
    };

    void print(const Printable auto &... args) {
        std::cout << std::boolalpha;
        ((std::cout << args << ' '), ...) << '\n';
    }
}

// NOTE: explain source_location (C++20)
template<typename T>
void show_fail_impl(const char* exprText, T value,
                    const std::source_location& loc = std::source_location::current())
{
    print("===> FAILED:", exprText, "<====");
    print("    Value: ", value);
    print("    Location:", loc.file_name(), ":", loc.line(), " in ", loc.function_name());
    print("========");
}

#define CHECK(exp) \
    do { \
        auto value = (exp); \
        print(#exp, " ==> ", value); \
        if (!static_cast<bool>(value)) { \
            show_fail_impl(#exp, value); \
        } \
    } while(0)

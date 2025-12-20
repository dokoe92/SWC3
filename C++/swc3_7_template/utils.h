#pragma once

#include <iostream>
#include <format>

template <typename... Args>
constexpr void print(std::format_string<Args...> fmt, Args&&... args) {
    std::cout << std::format(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
constexpr void print(std::ostream& os, std::format_string<Args...> fmt, Args&&... args) {
    os << std::format(os, fmt, std::forward<Args>(args)...);
}

template <typename... Args>
constexpr void println(std::format_string<Args...> fmt, Args&&... args) {
    std::cout << std::format(fmt, std::forward<Args>(args)...) << std::endl;
}

template <typename... Args>
constexpr void println(std::ostream& os, std::format_string<Args...> fmt, Args&&... args) {
    os << std::format(fmt, std::forward<Args>(args)...) << std::endl;
}

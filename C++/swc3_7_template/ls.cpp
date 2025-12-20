#include <algorithm>

#include "fs.h"

#include <filesystem>
#include <format>
#include <ranges>
#include <vector>

#include "utils.h"

[[nodiscard]] std::string directory_separator() {
#ifdef _WIN32
    return "\\";
#else
    return "/";
#endif
}

[[nodiscard]] static std::string tolower(std::string str) {
    auto r = std::ranges::views::transform(
        str,
        [](char ch) {
            return tolower(ch);
        });
    return std::string{std::begin(r), std::end(r)};
}

[[nodiscard]] static std::string file_suffix(std::filesystem::directory_entry entry) {
    std::string suffix = "";

    if (entry.is_directory()) {
        suffix += "/";
    }

    if (entry.is_symlink()) {
        suffix += "@";
    }

    return suffix;
}

void ls(std::filesystem::path path) {
    if (std::filesystem::exists(path)) {
        auto absolutePath = std::filesystem::absolute(path);

        println("{}: ", absolutePath.string());

        std::vector<std::filesystem::directory_entry> entries{
            std::filesystem::directory_entry(path), {}};

        std::sort(std::begin(entries), std::end(entries),
            [](const std::filesystem::directory_entry& e1,
                    const std::filesystem::directory_entry& e2) {

                    if (e1.is_directory() && !e2.is_directory()) {
                        return true;
                    }
                    if (!e1.is_directory() && e2.is_directory()) {
                        return false;
                    }

                    std::string e2Lowercase;

                    return tolower(e1.path().filename().string()) <
                        tolower(e2.path().filename().string());
            });

        for (const std::filesystem::directory_entry& entry : entries) {

            // println("{}", entry.path().filename().string(),
            // file_suffix(entry));
        }
    } else {
        std::cout << "Path does not exist" << std::endl;
    }
}

std::optional<std::filesystem::path>
    find(std::string name, std::filesystem::path path) {
        if (!std::filesystem::exists(path)) {
            throw std::runtime_error("Path does not exists");
        }

        for (const auto& entry : std::filesystem::recursive_directory_iterator{path}) {
            if (entry.path().filename().string() == name) {
                return entry.path();
            }
        }
}

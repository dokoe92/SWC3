#pragma once
#include <filesystem>

void ls(std::filesystem::path path = {}); // NOTE: {} -> fs::path::current_path()

[[nodiscard]] std::optional<std::filesystem::path>
    find(std::string name, std::filesystem::path path);

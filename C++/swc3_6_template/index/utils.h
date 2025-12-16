#pragma once

#include <string>
#include <fstream>

bool is_alpha(char ch);
bool is_digit(char ch);
bool is_punct(char ch);

char to_lower(char ch);

std::string normalize(std::string word);
std::string normalize2(std::string_view word);
std::ifstream open_stream(int argc, char *argv[]);

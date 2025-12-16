#include "utils.h"

#include <iostream>
#include <format>
#include <algorithm>
#include <ranges>

using namespace std;

// isalpha does not work for Umlauts etc.
// translate interfaces because C++/STL is strict about interfaces
bool is_alpha(const char ch) {
    return std::isalpha(static_cast<unsigned char>(ch));
}

bool is_digit(const char ch) {
    return std::isdigit(static_cast<unsigned char>(ch));
}

bool is_punct(const char ch) {
    return std::ispunct(static_cast<unsigned char>(ch));
}

char to_lower(const char ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

string normalize(string word) { // e.g. "H3ell?o"

    // copy non-punct characters to beginning
    auto new_end = remove_if(begin(word), end(word), is_punct); // -> "H3elloo"
    //                                                             ^-- new_end

    // move non-digits to beginning
    new_end = remove_if(begin(word), new_end, is_digit); // -> "Hellooo"
    //                                                               ^-- new_end

    // actually remove elements
    word.erase(new_end, end(word)); // -> "Hello"

    ranges::transform(word, begin(word), to_lower); // -> "hello"
    return word;
}

string normalize2(string_view word) {
    auto rng = word
        | views::filter([](const char c) { return !is_punct(c) && !is_digit(c); })
        | views::transform(to_lower);
    return std::string(ranges::begin(rng), ranges::end(rng));
}

ifstream open_stream(const int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "ERROR: missing input file name\n";
        cerr << format("usage: {} <filename>\n", argv[0]);
        exit(1);
    }
    ifstream f{argv[1]};
    if (f.fail()) {
        cerr << format("ERROR: file {} not found\n", argv[1]);
        exit(2);
    }
    return f;
}

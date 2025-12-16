#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <random>
#include <format>
#include <functional>
#include <ranges>

using namespace std;
using namespace std::literals;

#define DEBUG(X) cout << (#X) << " -> " << (X) << endl
#define LOG(X) (X); cout << (#X) << endl

void test_vector() {
    cout << "\n==== vector tests ====\n";

    vector v{1, 2}; // NOTE: <int> inferred

    v.push_back(3);
    for (const auto e : v) {
        DEBUG(e);
    }
    // NOTE: expands to the following
    for (auto it = begin(v); it != end(v); ++it) {
        DEBUG(*it);
    }

    //DEBUG(v);
    DEBUG(v[0]);
    LOG(v[1] = 99);
    DEBUG(v.at(1));
    LOG(v.resize(1));
    DEBUG(v.size());
    LOG(v.clear());
    DEBUG(v.empty());
    DEBUG(v.size());
}

void test_set() {
    cout << "\n==== set tests ====\n";
    set<int> numbers;

    random_device rd;
    mt19937 gen { rd() };
    uniform_int_distribution dist { 0, 3 }; // [0..3] inclusive

    for (int i = 0; i < 100; i++) {
        numbers.insert(dist(gen));
    }

    for (int i = 0; i < 5; i++) {
        DEBUG(numbers.contains(i));
        const auto it = numbers.find(i);
        if (it != end(numbers)) {
            DEBUG(*numbers.find(i));
        } else {
            DEBUG(it == end(numbers));
        }
    }
}

void test_map() {
    cout << "\n==== map tests ====\n";

    map<string, size_t> hashes {};
    constexpr hash<string> h {};
    // LOG(hashes.insert(make_pair<string, int>("Hello", h("Hello"))));
    LOG(hashes.insert({"Hello", h("Hello")}));
    LOG(hashes["World"] = h("World"));
    const auto it = hashes.find("Hello");
    DEBUG(it->first);
    DEBUG(it->second);
    auto& [key, value] = *hashes.find("Hello");
    DEBUG(key);
    DEBUG(value);
}

void test_algorithms() {
    cout << "\n==== algorithm tests ====\n";
    vector<int> primes;
    ranges::copy(views::iota(2, 20), back_inserter(primes));

    auto first = begin(primes);
    auto rest = end(primes);
    for (;first != rest; ++first) {
        rest = remove_if(first+1, rest, [&](auto p) {
            return p % *first == 0;
        });
    }
    primes.erase(rest, end(primes));

    ranges::copy(primes, ostream_iterator<int>{cout, ", "});
}

int main() {
    cout << boolalpha;
    test_vector();
    test_set();
    test_map();
    test_algorithms();
}

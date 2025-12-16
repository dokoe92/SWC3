#pragma once

#include <set>
#include <ostream>
#include <iomanip>
#include <iterator>
#include <ranges>
#include <format>
#include <compare>

template<std::three_way_comparable K, typename V>
class Entry {
    K m_key;
    mutable std::set<V> m_values; // changes to this field are allowed
                                  //   even on const obj

public:
    Entry(K key) : m_key{key} {}

    void add_value(V value) const {
        m_values.insert(value); // mutable values can be changed on const object
    }

    constexpr std::strong_ordering operator <=> (const Entry &other) const {
        return m_key <=> other.m_key;
    }

    constexpr bool operator == (const Entry &other) const = default;

    friend std::ostream& operator << (std::ostream &os, const Entry &e) {
        os << std::format("{:15} ({}):", e.m_key, e.m_values.size());
        std::ranges::copy(e.m_values, std::ostream_iterator<V>(os, ","));
        return os;
    }
};

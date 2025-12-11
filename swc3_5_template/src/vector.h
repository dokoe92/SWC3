#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <initializer_list>
#include <type_traits>
#include <cassert>

namespace swc3::vector {

    template<typename T>
    class vector {
    public:
        using value_type = T;
        using size_type = std::size_t;
        using pointer = value_type *;

    private:
        size_type m_size;
        value_type *m_data{nullptr};

        void check_range(size_type index) const {
            assert(index < m_size && "index out of range");
        }

    public:
        vector() noexcept : m_size(0), m_data(nullptr) {}
        vector(const vector&) = delete;
        vector& operator=(const vector&) = delete;
        vector(vector&& other) {
            using std::swap;
            swap(m_size, other.m_size);
            swap(m_data, other.m_data);
        }
        vector& operator=(vector&& rhs) {
            using std::swap;
            swap(m_size, rhs.m_size);
            swap(m_data, rhs.m_data);

            return *this;
        }

        explicit vector(std::in_place_t, size_type size)
            : m_size(size), m_data(size == 0 ? nullptr : new value_type[size]()) {}

        vector(std::initializer_list<value_type> l) : vector(std::in_place_t, l.size()) {
            size_type i = 0;
            for (auto e: l) {
                m_data[i++] = e;
            }
        }

        value_type operator[](int index) const {
            return m_data[index];
        }

        value_type& operator[](int index) {
            return m_data[index];
        }

        friend std::ostream &operator<<(std::ostream &os, const vector &v) {
            os << '[';
            for (vector::size_type i = 0; i < v.m_size; i++) {
                if (i > 0) {
                    os << ", ";
                }
                os << v.m_data[i];
            }
            return os << ']';
        }
    };
}

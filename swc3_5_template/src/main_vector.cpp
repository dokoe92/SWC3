#include <iostream>
#include "utils.h"
#include "vector.h"

using swc3::vector::vector;

using vector_t = vector<int>;
using double_vector_t = vector<double>;

vector_t make_vector(int capacity) {
    vector_t v{capacity};
    return v;
}

void test_vector() {
    std::cout << "==== test_vector ====" << std::endl;
    vector_t a{1, 2, 3};

    vector_t b{5, 6, 7};
    std::cout << "a: " << a << std::endl;
    std::cout << "a[0]: " << a[0] << std::endl;


    b[0] = 42;
    std::cout <<"b: " << b << std::endl;
    std::cout << "b[0]: " << b[0] << std::endl;

}

void test_vector_move() {
    std::cout << "==== test_vector_move ====" << std::endl;

    auto v = make_vector(10);

    std::cout << "v: " << v << std::endl;

    v = make_vector(4);
    std::cout << "v after move: " << v << std::endl;
}

int main() {
    test_vector();
    test_vector_move();
    return 0;
}


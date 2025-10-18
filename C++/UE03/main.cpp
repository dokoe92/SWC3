#include <iostream>
#include <string>

namespace swc3 {
    int count = 0;

    namespace inner {
        int count = 1;
    }
}

namespace swc3::inner::mostInner {
    int count = 2;
}

namespace std {
    int count = 42;
}

int count = 42;


using namespace std;

void print() {
    std::cout << __PRETTY_FUNCTION__ << std::endl; // vom Compiler...gibt methodenname aus
}

void print(int x) {
    std::cout << __PRETTY_FUNCTION__ << ": " << x << std::endl;
}

void print(void *x) {
    std::cout << __PRETTY_FUNCTION__ << ": " << x << std::endl;
}

// achtung compiler weiß nicht ob er die ohne parameter oder die mit default aufrufen soll
// void print(const char* x = "default") {
//     std::cout << __PRETTY_FUNCTION__ << ": " << x << std::endl;
// }

// man kann nur letzten argumenten default werte geben - man kann nicht dem ersten default geben und zweiten keinen default
void print(int v, const char *x = "default") {
    std::cout << __PRETTY_FUNCTION__ << ": " << x << std::endl;
}

int divide(int a, int b, bool &ok) {
    // bool* durch bool& ersetzt so darf nicht null sein
    if (b == 0) {
        ok = false;
        return 0;
    }

    ok = true;
    return a / b;
}

class Array {
    int size{0};
    int *data{nullptr};

public:
    Array();

    Array(int size);

    Array(const Array &other) // wird aufgerufen wenn Kopie gebraucht wird
        : size{other.size},
          data{new int[other.size]}
    {
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~Array() {
        delete[] data;
    }

    Array& operator=(const Array& rhs) { // rhs = right hand standing - Das ist ein Muster
        if (this == &rhs) {
            return * this;
        }
        if (data) {
            delete[] data;
        }

        size = rhs.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = rhs.data[i];
        }

        return *this;
    }

    [[nodiscard]] int getSize() const {
        // Zustand von Objekt wird nicht verändert -- Alles was Zustand nicht ändert immer mit const markieren.
        return size;
    }

    [[nodiscard]] int at(int i) const {
        return data[i];
    }

    [[nodiscard]] int &at(int i) {
        return data[i];
    }

    // If called with negative, looks from the end of array - python style
    [[nodiscard]] int &operator[](int index) {
        if (index < 0) {
            return data[size + index];
        }
        return data[index];
    }



    [[nodiscard]] int operator[](int index) const {
        if (index < 0) {
            return data[size + index];
        }
        return data[index];
    }

    Array& operator<<(int item) {
        // könnte man so implementieren dass a2 << 4 möglich ist
    }
};

Array::Array() {
};

Array::Array(int size)
    : size{size}, data{new int[size]} //  ACHTUNG INITIALISIERUNGSREIHENFOLGE BEACHTEN!
{
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

void print(const Array& arr) { // brauchen wir nicht immer kopieren --> von Array zu Array&
    // wenn mit const übergeben dürfen nur Methodne aufgerufen werden die mit const markiert sind
    std::cout << "Array[size=" << arr.getSize() << ", data=[";

    for (int i = 0; i < arr.getSize(); i++) {
        std::cout << arr.at(i) << ", ";
    }
    std::cout << "]" << std::endl;
}

void doSomething(Array& arr) {
    arr[0] = arr.getSize();
}

std::ostream& operator<<(std::ostream& os, const Array& rhs) { // output stream operator overload
    for (int i = 0; i < rhs.getSize(); i++) {
        std::cout << rhs.at(i) << ", ";
    }
    return os;
}


int main() {
    {
        using namespace swc3; // so kann lokal verwendet werden. achtung bei gleichen variablen etc full qualified name!
    }
    printf("\nHello C printf!\n");

    // man kann auch ohne std also cout << ...wegen namespace std
    std::cout << "Hello, World!\n";

    std::cout << "swc3::count = " << ::swc3::count << std::endl;
    std::cout << "::count = " << ::count << std::endl;
    std::cout << "swc3::inner::mostInner::count = " <<
            swc3::inner::mostInner::count << std::endl;

    std::cout << "######" << std::endl;

    print();
    // print(3);
    print(nullptr);

    // POINTER
    std::cout << "######" << std::endl;

    int value = 42;
    int *pValue = &value;

    std::cout << "value = " << value << std::endl;

    int &rValue = value;
    // int& rValue = nullptr; geht nicht
    rValue = 100;

    std::cout << "rValue = " << rValue <<
            ", value = " << value << std::endl;

    // bool ok = false;
    // int r = divide(10,0, ok); // lässt sich nicht erkennen ob Variable geändert wird oder nicht - Lesbarkeit nicht optimal
    // std::cout << "r = " << r << std::endl;

    bool ok1 = false;
    bool ok2 = false;

    // Zeiger umnähgen geht nicht
    bool &rOk = ok1;
    rOk = ok2;
    // rOk = &ok2; Adresse auf rOk --> wäre true da Adresse nicht null

    // so würde man zeiger umhängen
    // bool* pOk = &ok1;
    // pOk = &ok2;

    std::cout << ok1 << std::endl;
    std::cout << ok2 << std::endl;

    // STRING
    std::string s1 = "Hello";
    std::string s2 = "World";

    std::cout << "s1.length() = " << s1.length() << std::endl;
    std::cout << (s1 + s2) << std::endl;

    std::cout << "s1 == 'Hello': " << (s1 == "Hello") << std::endl;

    for (char ch: s2) {
        std::cout << "'" << ch << "' ";
    }

    // ARRAY
    Array a;

    std::cout << a.getSize() << std::endl;

    // a.getSize(); // noDiscard braucht man weill Beisüiel QDate dt{QDate::now()} dt.addAys(3);  --> fügt nicht 3 Tage hinzu sondern gibt MEthode zurück. Compilerwarnung sehr sinnvoll

    Array a1;
    print(a1);

    Array a2{10};
    print(a2);

    a2.at(3) = 42;
    print(a2);

    a2[4] = 43;
    print(a2);

    a2[-1] = 10;
    print(a2);

    doSomething(a2);
    print(a2);

    a1 = a2;
    print(a1);

    // OPERATOR = überschreibung auch wichtig weil
    // Array a3 = a2; wäre sonst Konstruktor
    //
    // Kopieren auch wichtig weil
    // Array a2[a1}; damit Referenzen richtig kopiert werden

    std::cout << a2;

    return 0;
}

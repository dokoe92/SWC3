Zuweisungsoperator: Achtung Selbstzuweisung prüfen!



Warum muss man Kopierkonstruktor, Destruktor und Zuweisungsoperator implementieren?
Dekonstruktor: der allokierte Speicher muss freigegeben werden wenn das Objekt nicht mehr verwendet wird
Kopierkonstruktor: Wenn das Objekt kopiert wird werden die internen Werte des Arrays nicht weitergegeben (flache Kopie) aber es muss ein eigenes Array mit allen Werten kopiert werden.
Zuweisungsoperator: ähnlich Kopierkonstruktor aber es werden vom this* Objekt die Werte gelöscht / überschrieben und mit den Werten vom anderen Objekt befüllt


Matrix(int nrows = 1, int ncols = 1)
    :nrow(nrows), ncols(ncols) {
        values = new double[nrows * ncols];
    }

 ~Matrix()= {
    delete []values;
 }

 Matrix(const Matrix &m) {
    int rows = n.nrows;
    int cols = n.cols;
    values = new double[rows * cols];
    for (int i = 0; i < rows * cols; ++i) {
        values[i] = m.values[i];
    }
 }

 Matrix& operator=(const Matrix& m) {
    if (this != m) {
        delete[] values;
        nrows = m.nrows;
        ncols = m.ncols;
        values = new double[nrows * ncols];
        for (int i = 0; i < nrows * ncols; ++i) {
            values[i] = m.values[i];
        }
    }
    return *this;
 }

 ## MOVE OHNE SWAP ###
     Matrix(Matrix&& m) noexcept
        : nrows(m.nrows), ncols(m.ncols), values(m.values) {

        // Ursprungsobjekt in gültigen Zustand setzen
        m.nrows = 0;
        m.ncols = 0;
        m.values = nullptr;
    }


### MOVE ASSIGNMENT OHNE SWAP
Matrix& operator=(Matrix&& m) noexcept {
    if (this == &m)
        return *this;

    delete[] values;

    nrows = m.nrows;
    ncols = m.ncols;
    values = m.values;

    m.nrows = 0;
    m.ncols = 0;
    m.values = nullptr;

    return *this;
}

### MOVE CSTR MIT SWAP ##
Matrix swap(Matrix&& m) noexcept {
    std::swap(nrows, m.nrows);   // primitive int
    std::swap(ncols, m.ncols);   // primitive int
    std::swap(values, m.values); // primitiver Zeiger
}

### MOVE ASSIGNMENT MIT SWAP ###
Matrix& swap(Matrix&& m) {
    if (this != m) {
        std::swap(nrows, m.rows);
        std::swap(ncols, m.cols);
        std::swap(values, m.values);
    }
    return *this;
}


 int main() {
    Matrix a(1,1);
    Matrix b(2,2);

    Matrix c = a;
    b = a;
 }

 bei free / maloc wird nur Speicher allokiert freigegeben.
 bei new / delete wird Speicher reserviert UND Konstruktor / Dekonstruktor wird aufgerufen.


 --------------------------------------------------------------------


template<typename T, typename Pred>
swo3::vector<T> filter(const swo3::vector<T>& v, Pred p) {
    swo3::vector<T> result;             // leeren Vektor erstellen

    for (auto it = v.begin(); it != v.end(); ++it) { // über alle Elemente iterieren
        if (p(*it)) {                    // Predicate prüfen
            result.add(*it);             // Element zum Ergebnis hinzufügen
        }
    }

    return result;                       // gefilterten Vektor zurückgeben
}

### Polymorphie #########
#include <iostream>

class Base {
public:
    virtual ~Base() { std::cout << "Base dtor\n"; }
    virtual void foo() { std::cout << "Base::foo\n"; }
};

class Derived : public Base {
public:
    ~Derived() override { std::cout << "Derived dtor\n"; }
    void foo() override { std::cout << "Derived::foo\n"; }
};

int main() {
    Base* b = new Derived();
    b->foo();    // -> Derived::foo
    delete b;    // -> Derived dtor, Base dtor
}

### Dynamic Cast ##########
class Base { public: virtual ~Base() = default; };
class Derived : public Base {};

void test(Base* b) {
    if (Derived* d = dynamic_cast<Derived*>(b)) {
        // Erfolgreicher Downcast
    } else {
        // Cast fehlgeschlagen → d == nullptr
    }
}

### SWAP ###
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

### Operator überladen #######
class Vec2 {
public:
    float x, y;

    Vec2(float x, float y) : x(x), y(y) {}

    // += (member)
    Vec2& operator+=(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    // + (non-member)
    friend Vec2 operator+(Vec2 a, const Vec2& b) {
        a += b;
        return a;
    }
};



Vererbung & Polymorphie
Virtuelle Destruktoren

In Basisklassen immer den Destruktor virtual machen, wenn polymorph gearbeitet wird.

Sonst: undefiniertes Verhalten, wenn über einen Base-Pointer auf ein Derived-Objekt gelöscht wird.

Virtuelle Funktionen

Bedeutung von virtuellem Binden verstehen.

Beim Überschreiben:

virtual in der Basisklasse.

override in der abgeleiteten Klasse verwenden (Fehlerprävention).

Casting

Cast von Derived → Base immer erlaubt (Upcast), keine Prüfung nötig.

Cast von Base → Derived nur sicher via dynamic_cast.

dynamic_cast<Derived*>(ptr) kann nullptr liefern → immer prüfen.

Objektlebensdauer
Stack vs. Heap

Stack-Objekte: automatische Lebensdauer, werden selbständig zerstört.

Heap-Objekte (new): manuelle Verwaltung → Verantwortung für korrektes delete.

Speicherlecks vermeiden (oder besser: Smart Pointer verwenden).

Kopieren, Zuweisen, Verschieben
Rule of 3

Implementieren, wenn die Klasse Ressourcen verwaltet:

Destruktor

Kopierkonstruktor

Copy-Zuweisungsoperator

Rule of 5

Erweitert um Move-Semantik:
4. Move-Konstruktor
5. Move-Zuweisungsoperator

Zuweisungsoperatoren

Selbstzuweisung prüfen (if (this == &other) return *this;)

Am Ende return *this; zurückgeben

Copy-and-Swap

Robuste Implementierung des Copy-Zuweisungsoperators

Ausfallsicher (starke Ausnahmegarantie)

Minimiert Code-Duplizierung

Move-Semantik

Ressourcen transferieren statt kopieren

Quellobjekt in gültigen, aber Ressourcen-leeren Zustand versetzen

Operatorüberladung

Sinnvolle und konsistente Semantik verwenden

Besonders wichtig:

Copy-Zuweisungsoperator

Move-Zuweisungsoperator

Keine überraschenden oder unnatürlichen Seiteneffekte erzeugen
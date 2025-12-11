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
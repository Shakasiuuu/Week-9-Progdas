#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.1416;

// Deklarasi fungsi
double distance(double, double, double, double);
double radius(double, double, double, double);
double circumference(double);
double area(double);

int main() {
    double x1, y1, x2, y2; // Titik pusat dan titik pada lingkaran
    double r, c, a;  // Radius, keliling, dan luas

    // Input koordinat pusat lingkaran
    cout << "---- Program Menghitung Lingkaran ----\n";

    cout << "Masukkan nilai koordinat x pada pusat lingkaran: ";
    cin >> x1;

    // Input koordinat titik pada lingkaran
    cout << "Masukkan nilai koordinat y pada pusat lingkaran: ";
    cin >> y1;

    cout << "Masukkan nilai koordinat x pada titik di lingkaran: ";
    cin >> x2;

    cout << "Masukkan nilai koordinat y pada titik di lingkaran: ";
    cin >> y2;

    // Menghitung jari-jari lingkaran menggunakan fungsi radius()
    r = radius(x1, y1, x2, y2);
     // Menghitung keliling lingkaran menggunakan fungsi circumference()
    c = circumference(r);
     // Menghitung luas lingkaran menggunakan fungsi area()
    a = area(r);

    cout << "\nJari-jari (radius): " << r;
    cout << "\nDiameter: " << 2 * r;
    cout << "\nKeliling: " << c;
    cout << "\nLuas: " << a << endl;

    return 0;
}

// ===== Definisi Fungsi =====
// Fungsi distance()
// Menghitung jarak antara dua titik (x1, y1) dan (x2, y2)
// Rumus: √((x2 - x1)² + (y2 - y1)²)
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Fungsi radius()
double radius(double x1, double y1, double x2, double y2) {
    return distance(x1, y1, x2, y2);
}

// Fungsi circumference()
// Menghitung keliling lingkaran
// Rumus: 2 * π * r
double circumference(double r) {
    return 2 * pi * r;
}

// Fungsi area()
// Menghitung luas lingkaran
// Rumus: π * r²
double area(double r) {
    return pi * pow(r, 2);
}

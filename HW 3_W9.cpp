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
    double x1, y1, x2, y2;
    double r, c, a; // Hindari bentrok nama variabel dan fungsi

    cout << "---- Program Menghitung Lingkaran ----\n";

    cout << "Masukkan nilai koordinat x pada pusat lingkaran: ";
    cin >> x1;

    cout << "Masukkan nilai koordinat y pada pusat lingkaran: ";
    cin >> y1;

    cout << "Masukkan nilai koordinat x pada titik di lingkaran: ";
    cin >> x2;

    cout << "Masukkan nilai koordinat y pada titik di lingkaran: ";
    cin >> y2;

    r = radius(x1, y1, x2, y2);
    c = circumference(r);
    a = area(r);

    cout << "\nJari-jari (radius): " << r;
    cout << "\nDiameter: " << 2 * r;
    cout << "\nKeliling: " << c;
    cout << "\nLuas: " << a << endl;

    return 0;
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double radius(double x1, double y1, double x2, double y2) {
    return distance(x1, y1, x2, y2);
}

double circumference(double r) {
    return 2 * pi * r;
}

double area(double r) {
    return pi * pow(r, 2);
}

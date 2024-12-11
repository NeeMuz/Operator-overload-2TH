#include <iostream>

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            std::wcerr << L"Error: Denominator cannot be zero." << std::endl;
            exit(1);
        }
    }

    Fraction operator+(const Fraction& other) const {
        return { numerator * other.denominator + other.numerator * denominator, denominator * other.denominator };
    }

    Fraction operator-(const Fraction& other) const {
        return { numerator * other.denominator - other.numerator * denominator, denominator * other.denominator };
    }

    Fraction operator*(const Fraction& other) const {
        return { numerator * other.numerator, denominator * other.denominator };
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            std::wcerr << L"Error: Division by zero." << std::endl;
            exit(1);
        }
        return { numerator * other.denominator, denominator * other.numerator };
    }

    void print() const {
        std::wcout << numerator << L"/" << denominator;
    }
};

int main() {
    setlocale(LC_ALL, "English");

    Fraction f1(1, 2);
    Fraction f2(3, 4);

    std::wcout << L"Sum: ";
    (f1 + f2).print();
    std::wcout << std::endl;

    std::wcout << L"Difference: ";
    (f1 - f2).print();
    std::wcout << std::endl;

    std::wcout << L"Product: ";
    (f1 * f2).print();
    std::wcout << std::endl;

    std::wcout << L"Quotient: ";
    (f1 / f2).print();
    std::wcout << std::endl;

    return 0;
}
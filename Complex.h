#pragma once
#include <iostream>

class Complex
{
private:
	double r; // Модуль
	double phi; // Аргумент

public:
	Complex();

	Complex(const double r, const double phi);

	Complex(const double digit);

	Complex operator+ (const Complex& rhs);

	Complex operator- (const Complex& rhs);

	Complex operator* (const Complex& rhs);

	Complex operator/ (const Complex& rhs);

	double Re() const;

	double Im() const;

	double R() const;

	double Phi() const;

	friend std::istream& operator>> (std::istream& is, Complex& obj);
	friend std::ostream& operator<< (std::ostream& os, const Complex& obj);
};

double Arg(double x, double y); // Вспомогательная функция для создания комплексного числа по известным x и y

Complex y(const Complex& z);

Complex sin(const Complex& z);

Complex tg(const Complex& z);

Complex th(const Complex& z);

Complex sh(const Complex& z);
#pragma once

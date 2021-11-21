#include "Complex.h"

Complex::Complex() {
	r = 0;
	phi = 0;
}

Complex::Complex(const double r, const double phi) : r(r), phi(phi) { }

Complex::Complex(const double digit)
{
	double x = digit, y = 0;

	r = sqrt(x * x + y * y);
	phi = Arg(x, y);
}

Complex Complex::operator+ (const Complex& rhs) {
	double x = this->Re() + rhs.Re(),
		y = this->Im() + rhs.Im();

	Complex result;
	result.r = sqrt(x * x + y * y);
	result.phi = Arg(x, y);

	return result;
}

Complex Complex::operator- (const Complex& rhs) {
	double x = this->Re() - rhs.Re(),
		y = this->Im() - rhs.Im();

	Complex result;
	result.r = sqrt(x * x + y * y);
	result.phi = Arg(x, y);

	return result;
}

Complex Complex::operator* (const Complex& rhs) {
	Complex result;

	result.r = this->r * rhs.r;
	result.phi = this->phi + rhs.phi;

	return result;
}

Complex Complex::operator/ (const Complex& rhs) {
	Complex result;

	result.r = this->r / rhs.r;
	result.phi = this->phi - rhs.phi;

	return result;
}

double Complex::Re() const { return r * cos(phi); }

double Complex::Im() const { return r * sin(phi); }

double Complex::R() const { return r; }

double Complex::Phi() const { return phi; }

std::istream& operator>>(std::istream& is, Complex& obj)
{
	is >> obj.r >> obj.phi;

	return is;
}

std::ostream& operator<<(std::ostream& os, const Complex& obj)
{
	os << "r= " << obj.R() << " phi= " << obj.Phi();

	return os;
}

double Arg(double x, double y)
{
	double PI = 3.1415926535;

	if (x > 0 && y >= 0)
		return atan(y / x);
	else if (x < 0 && y >= 0)
		return PI - atan(abs(y / x));
	else if (x < 0 && y < 0)
		return PI + atan(abs(y / x));
	else if (x > 0 && y < 0)
		return 2 * PI - atan(abs(y / x));
	else if (x == 0 && y > 0)
		return PI / 2;
	else if (x == 0 && y < 0)
		return (3 * PI) / 2;
}

Complex y(const Complex& z) {
	Complex res(2 * z.R(), z.Phi());
	res = res + Complex(exp(5) * 1) + Complex(exp(5) * z.R(), z.Phi());
	return res;
}

Complex sin(const Complex& z) {
	double x = sin(z.Re()) * cosh(z.Im()),
		y = cos(z.Re()) * sinh(z.Im());

	Complex result(sqrt(x * x + y * y), Arg(x, y));
	return result;
}

Complex tg(const Complex& z) {
	double x = sin(2 * z.Re()) / (cos(2 * z.Re()) + cosh(2 * z.Im())),
		y = sinh(2 * z.Im()) / (cos(2 * z.Re()) + cosh(2 * z.Im()));

	Complex result(sqrt(x * x + y * y), Arg(x, y));
	return result;
}

Complex th(const Complex& z) {

	double x = (cosh(z.Re()) * sinh(z.Re()) * pow(cos(z.Im()), 2) + cosh(z.Re()) * sinh(z.Re()) * pow(sin(z.Im()), 2))
		/
		(pow(cosh(z.Re()), 2) * pow(cos(z.Im()), 2) + pow(sinh(z.Re()), 2) * pow(sin(z.Im()), 2)),

		y = (pow(cosh(z.Re()), 2) * cos(z.Im()) * sin(z.Im()) - pow(sinh(z.Re()), 2) * cos(z.Im()) * sin(z.Im()))
		/
		(pow(cosh(z.Re()), 2) * pow(cos(z.Im()), 2) + pow(sinh(z.Re()), 2) * pow(sin(z.Im()), 2));

	Complex result(sqrt(x * x + y * y), Arg(x, y));
	return result;
}

Complex sh(const Complex& z) {
	double x = sinh(z.Re()) * cos(z.Im()),
		y = cosh(z.Re()) * sin(z.Im());

	Complex result(sqrt(x * x + y * y), Arg(x, y));
	return result;
}

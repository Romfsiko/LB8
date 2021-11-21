#include "Complex.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");

	Complex a1;
	cout << "Демонстация объекта а1 => " << a1 << endl;

	Complex a2(1, 2);
	cout << "Демонстация объекта а2 => " << a2 << endl;

	Complex a3(4);
	cout << "Демонстация объекта а3 => " << a3 << endl;

	cout << endl;

	cout << "Операция сложение (а3 + а2) => " << a3 + a2 << endl;
	cout << "Операция разность (а3 - а2) => " << a3 - a2 << endl;
	cout << "Операция умножение (а3 * а2) => " << a3 * a2 << endl;
	cout << "Операция деление (а3 / а2) => " << a3 / a2 << endl;

	cout << endl;

	cout << "Вручную введите данные (т.е. r, а затем phi) для объекта a1 " << endl;
	cin >> a1;

	cout << "Данные объекта a1 => "
		<< "Re = " << a1.Re()
		<< " Im = " << a1.Im()
		<< " R = " << a1.R()
		<< " Phi = " << a1.Phi()
		<< endl;

	cout << endl;

	cout << "Результат индивидуальной функции y(a2) => " << y(a2) << endl;
	cout << "Результат функции sin(a2) => " << sin(a2) << endl;
	cout << "Результат функции tg(a2) => " << tg(a2) << endl;
	cout << "Результат функции th(a2) => " << th(a2) << endl;
	cout << "Результат функции sh(a2) => " << sh(a2) << endl;

	return 0;
}

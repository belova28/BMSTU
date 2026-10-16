#include <iostream>
#include <iomanip>
#include <cstdlib>
#define _USE_MATH_DEFINES   
#include <math.h>
using namespace std;
int main(int argc, char* argv[])
{
	double e; // Точность
	cout << "E="; cin >> e;  

	double sum_w = 0, sl_w; // Сумма и слагаемое
	int k_w = 1, znak_w = 1; // Параметр ряда и знак слагаемого
	int n_w = 0; // Счетчик числа повторений цикла

	double sum_dw = 0, sl_dw;
	int k_dw = 1, znak_dw = 1;
	int n_dw = 0;

	double sum_f = 0, sl_f;
	int k_f = 1, znak_f = 1;
	int n_f = 0;

	sl_w = 1. / ((2. * k_w) * (2. * k_w + 1.) * (2. * k_w + 2.)); 
	while (sl_w >= e)
	{
		sum_w += sl_w * znak_w; 
		k_w++; 
		znak_w *= -1; 
		n_w++; 
		sl_w = 1. / ((2. * k_w) * (2. * k_w + 1.) * (2. * k_w + 2.));
	}
	sum_w = 3. + 4. * sum_w;

	do
	{
		sl_dw = 1. / ((2. * k_dw) * (2. * k_dw + 1.) * (2. * k_dw + 2.));
		sum_dw += sl_dw * znak_dw; 
		k_dw++; 
		znak_dw *= -1;
		n_dw++; 
	} while (sl_dw >= e);
	sum_dw = 3. + 4. * sum_dw; 

	for (k_f = 1; ; k_f++)
	{
		sl_f = 1. / ((2. * k_f) * (2. * k_f + 1.) * (2. * k_f + 2.)); 
		if (sl_f < e) break; 
		sum_f += sl_f * znak_f;
		znak_f *= -1; 
		n_f++; 
	}
	sum_f = 3. + 4. * sum_f; 

	cout << fixed << setprecision(10);
	cout << "while:    Sum = " << sum_w << "  n = " << n_w << " PI = " << M_PI << endl;
	cout << "do-while: Sum = " << sum_dw << "  n = " << n_dw << " PI = " << M_PI << endl;
	cout << "for:      Sum = " << sum_f << "  n = " << n_f << " PI = " << M_PI << endl;

	system("pause");  // Останавливаем программу до нажатия любой клавиши
	return 0;
}

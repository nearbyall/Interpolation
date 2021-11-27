#pragma once

#include <cmath>

class Interpolation
{

public:

	double ntGrid[101][2], lgGrid[101][2];
	double fpxGrid[101], fpyGrid[101];

	//Метод Лагранжа
	void lagrangeMethod(double X[101], double Y[101], int n);

	//Метод Ньютона
	void newtonMethod(double X[101], double Y[101], int n);

	//Выбранная функция
	double xsinx(double x);

	//Построение сетки с выбранной функцией
	void grid(double x0, double h, int N);
	
	//Исследование поведения ошибки
	double error(double x0, double h, double N);

};


#include "Interpolation.h"

void Interpolation::lagrangeMethod(double X[101], double Y[101], int n)
{

	for (int i = 0; i <= 100; i++) {

		lgGrid[i][0] = X[0] + i * ((X[n - 1] - X[0]) / 100);

		double result = 0;

		for (int k = 0; k < n; k++)
		{
			double p = 1;
			for (int j = 0; j < n; j++)
			{
				if (j != k)
				{
					p *= (lgGrid[i][0] - X[j]) / (X[k] - X[j]);
				};
			};
			result += p * Y[k];
		};

		lgGrid[i][1] = result;
	}

}

void Interpolation::newtonMethod(double X[101], double Y[101], int n)
{

	for (int i = 0; i <= 100; i++) {

		ntGrid[i][0] = X[0] + i * ((X[n - 1] - X[0]) / 100);

		double G[101][101];
		for (int k = 0; k < n; k++)
		{
			G[k][0] = Y[k];
		};
		for (int k = 1; k < n; k++)
		{
			for (int j = 1; j <= k; j++)
			{
				G[k][j] = (G[k][j - 1] - G[j - 1][j - 1]) / (X[k] - X[j - 1]);
			};
		};
		double result = G[n - 1][n - 1];
		for (int k = 1; k < n; k++)
		{
			result *= (ntGrid[i][0] - X[n - k]) + G[n - 1 - k][n - 1 - k];
		};
		ntGrid[i][1] = result;
	}

}

double Interpolation::xsinx(double x)
{
	return x * sin(x);
}

void Interpolation::grid(double x0, double h, int N)
{
	for (int i = 0; i < N; i++) {

		fpxGrid[i] = x0 + h * i;
		fpyGrid[i] = xsinx(x0 + h * i);
	}
}

double Interpolation::error(double x0, double h, double N)
{

	grid(x0, h, N);

	lagrangeMethod(fpxGrid, fpyGrid, N);

	double max = 0;

	for (int i = 0; i <= 100; i++) {
		double tp = abs(lgGrid[i][1] - xsinx(lgGrid[i][0]));
		if (tp > max) max = tp;
	}

	return max;

}

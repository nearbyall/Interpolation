#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>

#include "Interpolation.h"

int main()
{
	std::ifstream fin("interpolation_polynomial_41.lb3");

	double X[101], Y[101];
	int n = 0;

	if (!fin.is_open()) std::cout << "Error open file 'interpolation_polynomial_41.lb3'" << std::endl;

	while (!fin.eof()) {
		std::string t;
		fin >> t;
		n++;
	}
	fin.seekg(std::ios_base::beg);

	n /= 2;

	double tmp[101][2];

	Interpolation interpolation;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			fin >> tmp[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		X[i] = tmp[i][0];
		Y[i] = tmp[i][1];
	}

	interpolation.newtonMethod(X, Y, n);
	interpolation.lagrangeMethod(X, Y, n);


	std::ofstream fout("lab3_ip_Melnikov_41.cmp");

	if (!fout.is_open()) std::cout << "lab3_ip_Melnikov_41.cmp'" << std::endl;
	fout << "________" << "Newton" << "______________________________" << "Lagrange" << "________" << std::endl;
	for (int i = 0; i <= 100; i++) {
		fout << interpolation.ntGrid[i][0] << std::setw(15) << interpolation.ntGrid[i][1] 
			<< std::setw(20) << interpolation.lgGrid[i][0] << std::setw(15) << interpolation.lgGrid[i][1] << std::endl;
	}

	std::ofstream fiout("lab3_inv_Melnikov_21.txt");
	if (!fiout.is_open()) std::cout << "Error open file 'lab3_inv_Melnikov_21.txt'" << std::endl;

	double x0, xl, h;
	int N;

	x0 = -6.5; xl = 6.5;

	for (N = 2; N <= 100; N++) {

		h = (xl - x0) / (double)N;

		fiout << N << std::setw(20) << interpolation.error(x0, h, N) << std::endl;

	}

	return 0;

}
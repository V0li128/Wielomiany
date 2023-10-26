#pragma once
#include <vector>
using namespace std;
class Polynomial
{
public:
	vector<float> wspolczynniki;
	Polynomial();

	int stopien();

	void addPolynomials(Polynomial drugi);

	void substractPolynomials(Polynomial drugi);

	void multiplyPolynomials(Polynomial drugi);
};


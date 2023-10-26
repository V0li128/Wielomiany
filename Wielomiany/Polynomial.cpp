#include "Polynomial.h"

#include <string>
#include <sstream>
#include <iostream>

using namespace std;


Polynomial::Polynomial()
{
	int i = 0;
	float liczba;
	while (true)
	{
		string wejscie;
		cout << "podaj a" << i << " ";
		cin >> wejscie;
		if (wejscie == "stop")
		{
			break;
		}
		else if (stringstream(wejscie) >> liczba)
		{
			wspolczynniki.push_back(liczba);
		}
		i++;
	}
}

int Polynomial::stopien()
{
	return wspolczynniki.size() -1;
}

void Polynomial::addPolynomials(Polynomial drugi)
{
	int stopien_diff;
	vector <float> addedPolynomials;
	stopien_diff = wspolczynniki.size() - drugi.wspolczynniki.size();
	if (stopien_diff > 0)
	{
		for(int i=0; i<drugi.wspolczynniki.size(); i++)
		{
			addedPolynomials.push_back(wspolczynniki.at(i) + drugi.wspolczynniki.at(i));
		}
		for (int i = drugi.wspolczynniki.size(); i < wspolczynniki.size(); i++)
		{
			addedPolynomials.push_back(wspolczynniki.at(i));
		}
	}
	if (stopien_diff == 0)
	{
		for (int i = 0; i < drugi.wspolczynniki.size(); i++)
		{
			addedPolynomials.push_back(wspolczynniki.at(i) + drugi.wspolczynniki.at(i));
		}
	}
	if (stopien_diff < 0)
	{
		for (int i = 0; i < wspolczynniki.size(); i++)
		{
			addedPolynomials.push_back(wspolczynniki.at(i) + drugi.wspolczynniki.at(i));
		}
		for (int i = wspolczynniki.size(); i < drugi.wspolczynniki.size(); i++)
		{
			addedPolynomials.push_back(drugi.wspolczynniki.at(i));
		}
	}
	for (int i = addedPolynomials.size() - 1; i >= 0; i--)
	{

		if (addedPolynomials.at(i) < 0)
			cout << addedPolynomials.at(i) << "*x^" << i << " ";
		else if (addedPolynomials.at(i) == 0)
			continue;
		else if (i < addedPolynomials.size() - 1)
			cout << "+" << addedPolynomials.at(i) << "*x^" << i << " ";
		else
			cout << addedPolynomials.at(i) << "*x^" << i << " ";
	}
}

void Polynomial::substractPolynomials(Polynomial drugi)
{
	int stopien_diff;
	int zerowanie = 0;
	vector <float> subPolynomials;
	stopien_diff = wspolczynniki.size() - drugi.wspolczynniki.size();
	if (stopien_diff > 0)
	{
		for (int i = 0; i < drugi.wspolczynniki.size(); i++)
		{
			subPolynomials.push_back(wspolczynniki.at(i) - drugi.wspolczynniki.at(i));
		}
		for (int i = drugi.wspolczynniki.size(); i < wspolczynniki.size(); i++)
		{
			subPolynomials.push_back(wspolczynniki.at(i));
		}
	}
	if (stopien_diff == 0)
	{
		for (int i = 0; i < drugi.wspolczynniki.size(); i++)
		{
			subPolynomials.push_back(wspolczynniki.at(i) - drugi.wspolczynniki.at(i));
		}
	}
	if (stopien_diff < 0)
	{
		for (int i = 0; i < wspolczynniki.size(); i++)
		{
			subPolynomials.push_back(wspolczynniki.at(i) - drugi.wspolczynniki.at(i));
		}
		for (int i = wspolczynniki.size(); i < drugi.wspolczynniki.size(); i++)
		{
			subPolynomials.push_back(-drugi.wspolczynniki.at(i));
		}
	}
	for (int i = subPolynomials.size() - 1; i >= 0; i--)
	{

		if (subPolynomials.at(i) < 0)
			cout << subPolynomials.at(i) << "*x^" << i << " ";
		else if (subPolynomials.at(i) == 0)
			continue;
		else if(i<subPolynomials.size()-1)
			cout << "+" << subPolynomials.at(i) << "*x^" << i << " ";
		else 
			cout << subPolynomials.at(i) << "*x^" << i << " ";
	}
	for (int i = 0; i < subPolynomials.size(); i++)
	{
		if(subPolynomials.at(i) == 0)
		{
			zerowanie++;
		}
	}
	if (zerowanie == wspolczynniki.size())
		cout << "0" << endl;
}

void Polynomial::multiplyPolynomials(Polynomial drugi)
{
	
	vector <float> multiPolynomials;
	int multiStopien = wspolczynniki.size() + drugi.wspolczynniki.size() - 2;
//	for (int i = 0; i <= multiStopien; i++)
//		multiPolynomials.push_back(0);
	multiPolynomials.resize(multiStopien+1);
	for (int i = 0; i < wspolczynniki.size();i++)
	{
		for (int j = 0; j < drugi.wspolczynniki.size(); j++)
		{
			multiPolynomials.at(i+j) += (wspolczynniki.at(i) * wspolczynniki.at(j));
		}
	}
	for (int i = multiPolynomials.size() - 1; i >= 0; i--)
	{

		if (multiPolynomials.at(i) < 0)
			cout << multiPolynomials.at(i) << "*x^" << i << " ";
		else if (multiPolynomials.at(i) == 0)
			continue;
		else if (i < multiPolynomials.size() - 1)
			cout << "+" << multiPolynomials.at(i) << "*x^" << i << " ";
		else
			cout << multiPolynomials.at(i) << "*x^" << i << " ";
	}
	
}



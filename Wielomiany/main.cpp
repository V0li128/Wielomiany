#include "Polynomial.h"
#include <iostream>

using namespace std;

int main()
{
	
	int liczba;
	//wpisywanie wspolczynnikow od uzytkownika dla dwoch wielomianow
	//wspolczyniki zaczynaja sie od prawej strony rownania - od x^0, zeby pasowalo do vectorow, ktore tez sie zaczynaja od 0
	cout << "Podawaj wspolczynniki pierwszego wielomianu, zaczynajac od a0 konczac na an, oddzielajac je ENTEREM. Aby zakonczyc wpisywanie wyslij napis stop\n";
	Polynomial pierwszy;
	cout << "Podawaj wspolczynniki drugiego wielomianu, zaczynajac od a0 konczac na an, oddzielajac je ENTEREM. Aby zakonczyc wpisywanie wyslij napis stop\n";
	Polynomial drugi;

	//stopnie pierwszego i drugiego wielomianu
	cout << "stopien wielomianu pierwszego wynosi: " << pierwszy.stopien() << endl;
	cout << "stopien wielomianu drugiego wynosi: " << drugi.stopien() << endl;

	//dodawanie wielomianow
	cout << "dodawanie tych dwoch wielomianow wyglada tak: ";
	pierwszy.addPolynomials(drugi);
	cout << endl;
	
	//odejmowanie pierwszy - drugi
	cout << "odejmowanie drugiego wielomianu od pierwszego wyglada tak: ";
	pierwszy.substractPolynomials(drugi);
	cout << endl;

	//mno¿enie jednego z drugim
	cout << "mnozenie jednego wielomianu z drugim wyglada tak: ";
	pierwszy.multiplyPolynomials(drugi);
	cout << endl;


	return 0;
}
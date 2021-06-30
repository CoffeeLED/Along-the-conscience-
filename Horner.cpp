#include <iostream>
#include <string>
using namespace std;

void Title();
void Transmission();
int CheckAllProblems(int* n);
int CheckForEmpty(double* n);
//===========================title==========================
void Title() {
	system("cls");
	cout << "_______________________________________________________________________________\n";
	cout << "|                               ALGORYTM HORNERA                              |\n";
	cout << "|                      zrobil program: Aliaksei Yunevich                      |\n";
	cout << "_______________________________________________________________________________\n";
	cout << endl;
}
//===========================transmission to the next step==========================
void Transmission() {
	cout << endl;
	system("PAUSE");
	Title();
}
//=======================function of checking the number================================
int CheckAllProblems(double* n) {
	while (*n < 0 || cin.fail() || (*n - (int)*n) != 0) {
		cin.clear();
		if (*n < 0) {
			cout << endl;
			cout << " - (Uwaga!) Wprowadzony poteg jest mniejszy od zera";
			cout << endl;
			cout << " - Prosze napisac inny poteg 'x': ";
		}
		else if ((*n - (int)*n) != 0) {
			cout << endl;
			cout << " - (Uwaga!) Prosze napisac calkowity poteg 'x': ";
			cout << endl;
			cout << " - Prosze napisac liczbe najwyzszy poteg 'x': ";
		}
		else {
			cout << endl;
			cout << " - (Uwaga!) Prosze pisac tylko i wylacznie liczby";
			cout << endl;
			cout << " - Prosze napisac liczbe najwyzszy poteg 'x': ";
		
		}
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> *n;
	}

	return *n;
}
//=======================function of check the number================================
int CheckForEmpty(double* n) {
	while (cin.fail() || (*n - (int)*n) != 0) {
		cin.clear();	
		if ((*n - (int)*n) != 0) {
			cout << endl;
			cout << " - (Uwaga!) Liczby ulamkowe nie pasuja";
			cout << endl;
			cout << " - Prosze napisac liczbe calkowita: ";
		}
		else {
			cout << endl;
			cout << " - (Uwaga!) Prosze pisac tylko i wylacznie liczby";
			cout << endl;
			cout << " - Prosze napisac liczbe: ";
		}
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> *n;
	}

	return *n;
}

int main() {
	//=======================variables=========================
	double n;
	double x;
	double f;
	//=========================================================

	Title();
	cout << " - Prosze napisac najwyzszy poteg 'x': ";	
	cin >> n;
	CheckAllProblems(&n);
	double* a = new double[n];
	cout << endl;
	cout << " - Prosze napisac wszystkie a: " << endl;
	cout << endl;
	for (int i = 0; i <= n; i++) {
		cout << " a (#" << i+1 << ") = ";
		cin >> a[i];
		CheckForEmpty(&a[i]);
		cout << endl;
	}
	Transmission();
	cout << endl;
	cout << " - Zbudowana formula: " << endl;
	cout << endl;
	int t = n; //build the formula
	for (int i = 0; i <= n; i++) {
		if (i == 0) cout << "   f(x) = ";
		if (i != n) {
			if (a[i] != 0) {			
				if (t == 1) {
					if (a[i] == 1) cout << "x" << " + ";
					else if (a[i] < 0) cout << "(" << a[i] << ")" << "x" << " + ";
					else cout << a[i] << "x" << " + ";
				}
				else if (t > 1) {
					if (i != 0 && a[i] < 0) cout << "(" << a[i] << ")" << "x^" << t << " + ";
					else if (a[i] == 1)	cout << "x^" << t << " + ";
					else cout << a[i] << "x^" << t << " + ";
				}
				else {
					cout << a[i] << "x^" << t << " + ";		
				}

				t--;
			}

			else t--;
		}
		else if (a[i] < 0) cout << "(" << a[i] << ")" ;
		else	cout << a[i];

	}
	cout << endl;
	cout << endl;
	cout << " - W jakim punkcie powinien byc x? Prosze napisac: ";
	cin >> x;
	CheckForEmpty(&x);
	cout << endl;
	cout << endl;
	cout << " - Rozwiazanie: " << endl;
	cout << endl;
	t = n; //sulution of the formula
	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			f = a[0];
			cout << "f" << t << " = " << f << endl;
			t--;
		}
		else{	
			cout << "f" << t << " = " << "(" << f << " * " << x << ")" << " + ";
			if (a[i] < 0) cout << "(" << a[i] << ")";
			else cout << a[i];
			f = (f * x) + a[i];
			cout << " = " << f << endl;
			t--;
		}
	}
	cout << endl;
	cout << " - Odpowiedz: " << f << endl;
	cout << endl;
	system("PAUSE");
}
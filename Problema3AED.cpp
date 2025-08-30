#include "iostream"
using namespace std;
//cuantas veces esta escrita la palabra ahi
		
int contarpalabras(char pupiletras[10][10], char palabra[10]) {
	int cont = 0;

	for (char (*p)[10] = pupiletras; p < pupiletras + 10; p++)
	{
		for (char* q = *p; q < *p + 10; q++)
		{

			char* i = palabra;
			char* z = q;
			while (*z == *i) {
				z = z + 10;
				i++;
			}
			if (*i == '\0') { cont++; }

			char* j = palabra;
			char* y = q;
			while (*y == *j) {

				y = y - 1;
				j++;
			}
			if (*j == '\0') { cont++; }

			char* k = palabra;
			char* x = q;
			while (*x == *k) {

				x = x + 1;
				k++;
			}
			if (*k == '\0') { cont++; }

			char* m = palabra;
			char* n = q;
			while (*n == *m) {

				n = n - 10;
				m++;
			}
			if (*m == '\0') { cont++; }
		}
	}

	return cont;
}



int main() {
	char pupiletras[10][10] = {
	{'T','P','P','A','P','T','P','R','P','T'},
	{'O','P','A','T','A','P','O','Z','O','J'},
	{'S','A','T','A','T','O','T','A','Z','I'},
	{'A','T','A','P','A','P','A','T','O','S'},
	{'P','A','T','A','N','O','D','O','T','N'},
	{'T','A','A','P','A','T','I','P','A','P'},
	{'R','R','N','A','D','O','T','A','P','O'},
	{'E','D','N','T','A','P','O','T','A','T'},
	{'N','I','I','A','T','I','T','A','P','A'},
	{'P','S','S','N','T','T','T','P','A','P'},
	};

	char palabra[100];
	cout << "Ingrese la palabra a buscar: ";
	cin >> palabra;
	for (char *i = palabra; *i != '\0'; i++)
	{
		if (*i>='a' && *i <= 'z')
		{
			*i = *i - 32;
			cout << *i ;
		}
	}

	int cont = contarpalabras(pupiletras, palabra);

	cout << cont  << endl;
}

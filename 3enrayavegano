#include "iostream"
using namespace std;

void matriz1(char  (*A)[3]) {
	for (char (*p)[3] = A; p <= A + 2; p++)
	{
		for (char* q = *p; q < *(p + 1); q++)
		{
			cout << " " << *q << " " << '|';

		}
		cout << endl;
	}
}

bool ganador(char matriz[3][3], char simbolo) {
	for (int i = 0; i < 3; i++) {
		if (matriz[i][0] == simbolo && matriz[i][1] == simbolo && matriz[i][2] == simbolo)
			return true;
		if (matriz[0][i] == simbolo && matriz[1][i] == simbolo && matriz[2][i] == simbolo)
			return true;
	}
	if (matriz[0][0] == simbolo && matriz[1][1] == simbolo && matriz[2][2] == simbolo)
		return true;
	if (matriz[0][2] == simbolo && matriz[1][1] == simbolo && matriz[2][0] == simbolo)
		return true;
	return false;
}

void jugar() {
	char matriz[3][3] = { '1','2','3','4','5','6','7','8','9' };


	int turnos = 0;
	char caracter = 'X';

	while (turnos < 9) {
		if (caracter=='X')
		{
			matriz1(matriz);
			int posicion;
			cout << "turno del jugador1" << endl;
			cout << "elija que posicion poner 'X': " << endl;
			cin >> posicion;

			int f = (posicion - 1) / 3;
			int c = (posicion - 1) % 3;

			matriz[f][c] = caracter;
		}
		else {

			matriz1(matriz);
			int posicion;
			cout << "turno del jugador2" << endl;
			cout << "elija que posicion poner 'O': " << endl;
			cin >> posicion;

			int f = (posicion - 1) / 3;
			int c = (posicion - 1) % 3;

			matriz[f][c] = caracter;
		}
		

		if (ganador(matriz, caracter)) {
			matriz1(matriz);
			cout << "El jugador " << (caracter == 'X' ? "1" : "2") << " ha ganado!\n";
			break;
		}

		caracter = (caracter == 'X') ? 'O' : 'X';

		turnos++;


	}

}

int main() {

	char matriz[3][3] = { '1','2','3','4','5','6','7','8','9' };


	while (true) {
		int x;
		cout << "quiere jugar? " << endl;
		cin >> x;
		if (x == 1)
		{
			jugar();


		}
		else {
			break;
		}


	}




	return 0;
}

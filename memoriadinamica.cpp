#include "iostream"
using namespace std;
void fun1(int fil , int col , int*** p, int ***q) {
	*p = new int* [fil];
	for (int **q = *p; q < *p+fil; q++)
	{
		*q = new int[col];
	}

	*q = new int* [fil];
	for (int **z = *q; z < *q + fil; z++)
	{
		*z = new int[col];
	}

}

int** fun2(int fil, int col) {
	int** t = new int*[fil];
	for (int **p = t; p < t+fil; p++)
	{
		*p = new int[col];
	}
	return t;

}






int main() {
	int fil = 3;
	int col = 3;

	int fil2 = 3;
	int col2 = 3;
	int** p;
	int** q;
	fun1(fil, col, &p , &q);
	
	int** y;
	y = fun2(fil2, col2);
	

	for (int i = 0; i < fil; i++)
	{
		delete[] y[i];
	}
	delete[] y;



	for (int i = 0; i < fil; i++)
	{
		delete[] p[i];
		delete[] q[i];
	}
	delete[] p;
	delete[] q;

}



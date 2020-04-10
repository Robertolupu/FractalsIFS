#include <ctime>
#include <stdio.h>

// Incloem les capçaleres que necessitem de la biblioteca
#include "../IFS/headers/ifs.h"
#include <iostream>

int main(int argc, char **argv)
{
	IFS A;
	tPoint b;
	int iter, nPoints;
	A.read();
	b.read();
	srand(time(NULL));
	cin >> nPoints;
	cin >> iter;
	for (int i=0;i<nPoints;i++){
		A.calculateRandomOrbit(b,iter).write();
	}
}
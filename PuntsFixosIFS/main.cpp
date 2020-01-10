#include <stdio.h>

// Incloem les capçaleres que necessitem de la biblioteca
#include "../IFS/headers/ifs.h"
#include <iostream>

int main(int argc, char **argv)
{
	IFS a;
	a.read();
	int period;
	cin >> period;
	for(int i=1;i<=period;i++) 
		a.GetPeriodicOrbits(period);
}
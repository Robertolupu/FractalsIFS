#include <stdio.h>

// Incloem les capçaleres que necessitem de la biblioteca
#include "../IFS/headers/transformation.h"
#include <iostream>

int main(int argc, char **argv)
{
	IFS a;
	a.read();	
	int period;
	cin >> period;

	a.GetPeriodicOrbits(period);
}
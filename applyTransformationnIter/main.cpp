#include <stdio.h>//niteracions

// Incloem les capçaleres que necessitem de la biblioteca
#include "../IFS/headers/transformation.h"
#include <iostream>

int main(int argc, char **argv)
{
	
	tAffTransformation t;
	tPoint p;
	t.read();
	p.read();
	uint n;
	cin >> n;
	for(int i=0; i<n; i++){
	p=t.applyToPoint(p);
	p.write();
	}
	
}
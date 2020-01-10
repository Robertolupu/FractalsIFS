#include <stdio.h>

// Incloem les capçaleres que necessitem de la biblioteca
#include "../IFS/headers/ifs.h"
#include <iostream>

int main(int argc, char **argv)
{
	
	IFS a;
	a.read();
	a.write();
}
/**
 * Inici:
 * Finals novembre: Cal treballar la definició de transformació afí...
 * 					3) Comprovar que una aplicació és contractiva -> pendent//creo que ya esta
 * 
 * 15 desembre
 * 					7) Comprovar que l'IFS està format per aplicacions contractives -> pendent//creo que ya esta
 * 					10) Representar la imatge del fractal obtingut en el punt anterior -> info gnuplot per diferents opcions de represemtació
 * 
 * 22 desembre
 * 					12) Calcular les òrbites periòdiques de període 2, 3, 5, 7...
 * 
 * 31 desembre
 * 					13) Calcular les òrbites periòdiques de períodes amb un nombre no primer
 * 					14) Representar totes les òrbites periòdiques fins a període 10 i comparar-ho amb el fractal
 * 					    obtingut a partir d'òrbites aleatòries
 **/
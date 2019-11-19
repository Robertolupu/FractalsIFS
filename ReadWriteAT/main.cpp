#include <stdio.h>

// Incloem les capçaleres que necessitem de la biblioteca
#include "../IFS/headers/transformation.h"
#include <iostream>

int main(int argc, char **argv)
{

	
	tAffTransformation t;
	tPoint p,p1;
	t.read();
	t.calculateFixedPoint().write();
	p.read();
	int maxIter;
	float tol,dP;
	cout << "Nombre màxim d'iteracions:";
	cin >> maxIter;
	p1=t.applyToPoint(p);
	dP=p.distanceWith(p1);
	cout << ":/n la distancia entre el punt i la primera iteració és:";
	cout << dP;
	cout << ":/n Tolerància:";
	cin >> tol;
	p=p1;
	if(tol < dP ){
		int i=0;
		for(i<maxIter;dP>tol;){
			p1=t.applyToPoint(p);
			dP=p.distanceWith(p1);
			p=p1;
			i++;
		}
	}
	if(tol>dP){
		cout << "Aconseguit/n";
	} else {
		cout << "No aconseguit/n";
	}
	p.write();
  //exemple(); // aquesta funció està a la biblioteca
  
  //solveSystem();
  
  //tAffTransformation t1, t2;
  //tPoint p1,p2;
  //tPoint fixedPoint;
  //t1.read();
  //p1.read();
  //p2 = t1.applyToPoint(p1);
  //t2.read();
  //t1.write();
  //p1.write();
  //p2.write();
  //fixedPoint = t1.calculateFixedPoint();
  //fixedPoint.write();
  //tAffTransformation composicio = tAffTransformation::composeAffTransformation(t1, t2);
  //composicio.write();
}
  


/**
 * Inici:
 * Finals novembre: Cal treballar la definició de transformació afí...
 * 					3) Comprovar que una aplicació és contractiva
 * 					4) Aplicar una transformació moltes vegades a un punt fins que convergeixi (això permet obtenir el punt fix)
 * 					**5) Calcular el punt fix d'una aplicació contractiva resolent el sistema
 * 					**5b) Compondre dues transformacions lineals
 * 
 * 15 desembre
 * 					6) Llegir i escriure la definició d'un IFS
 * 					7) Comprovar que l'IFS està format per aplicacions contractives
 * 					8) Calcular l'òrbita aleatòria d'un punt sota un IFS
 * 					9) Generar 5000 punts d'un fractal IFS generant òrbites aleatòries de punts inicials aleatoris
 * 					10) Representar la imatge del fractal obtingut en el punt anterior
 * 					10b) Donat un llistat de transformacions afins i un llistat de nombres qualssevol [1,5,8,3], obtenir
 *                       la tranformació  T(3)·T(8)·T(5)·T(1)       
 * 
 * 22 desembre
 * 					11) Calcular els punts fixos d'un IFS
 * 					12) Calcular les òrbites periòdiques de període 2, 3, 5, 7...
 * 
 * 31 desembre
 * 					13) Calcular les òrbites periòdiques de períodes amb un nombre no primer
 * 					14) Representar totes les òrbites periòdiques fins a període 10 i comparar-ho amb el fractal
 * 					    obtingut a partir d'òrbites aleatòries
 **/
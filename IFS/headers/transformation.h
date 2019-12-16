#ifndef __TRANSFORMATION_H__
#define __TRANSFORMATION_H__

#include <stdio.h>
#include "../Eigen/Dense"
#include <vector>
#include <stdlib.h>
using namespace std;
using namespace Eigen;

typedef double tElement;
typedef Matrix<tElement, Dynamic, Dynamic> tMatrixDynamic;
	//Abrebriem tot el procés de crear una matriu dynamica sota el nom de tMatrixDynamic
typedef Matrix<tElement, Dynamic, 1> tVectorDynamic;
	//Abrebriem tot el procés de crear un vector dynamic sota el nom de tVectorDynamic
class tPoint {	//Aquí definirem què és un punt i les funcions que es poden fer a partir d'aquest
	public:
	int dim;	// la dimensió del punt
	tVectorDynamic point;	// el vector que representa el punt
					//Aquestes són les funcions que es poden fer amb un punt
					//Estan definides al fitxer transformation.cpp
	void read();
	//void read(int dim);
	void write();
	tVectorDynamic getTranslationVector();
	float distanceWith(tPoint p1);
};	

class tAffTransformation {	//Aquí definirem què és una transformació afí
	int dim;	// la dimensió de la transformació
	tMatrixDynamic matrix;	// la matriu de la transformació

	public: // aquí posarem aquelles funcions que es poden fer amb una transformació afí
			//Estan definides al fitxer transformation.cpp
	void read();
	//void read(int dim);
	void write();
	tMatrixDynamic getLinealMatrix();
	tVectorDynamic getTranslationVector();
	bool isContractiveTransformation();
	tPoint applyToPoint(tPoint point);
	tPoint calculateFixedPoint();
	static tAffTransformation composeAffTransformation(tAffTransformation t1, tAffTransformation t2);
};

class IFS {		//Aquí definirem què és un fractal IFS
	int dim;	//la dimensió euclidiana en què es treballa
	int numT;	//el número de transformacions què té
	public:		
	vector<tAffTransformation> IFSvector;	//Aquest és el vector en què cada element és una transformació afí
					//Aquestes són les funcions que es poden fer amb un fractal IFS
					//Estan definides al fitxer transformation.cpp
	void read();
	void write();
	bool hasContractiveTransformations();
	tPoint calculateAleatoriOrbit(tPoint p1);
	tAffTransformation TransformationOfNTransformations();
	//vector PeriodicOrbitP1();
	//vector PeriodicOrbitP2();
	//vector PeriodicOrbitPn();
	//vector PeriodicOrbitP1toN();
	
};




#endif

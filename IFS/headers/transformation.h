#ifndef __TRANSFORMATION_H__
#define __TRANSFORMATION_H__

#include <stdio.h>
#include "../Eigen/Dense"

using namespace std;
using namespace Eigen;

void solveSystem();

typedef double tElement;
typedef Matrix<tElement, Dynamic, Dynamic> tMatrixDynamic;
typedef Matrix<tElement, Dynamic, 1> tVectorDynamic;

class tPoint {
	public:
	int dim; // la dimensió
	tVectorDynamic point; // la seva matriu
	
	void read();
	//void read(int dim);
	void write();
	tVectorDynamic getTranslationVector();
	float distanceWith(tPoint p1);
};	

class tAffTransformation {
	int dim; // la dimensió
	tMatrixDynamic matrix; // la seva matriu

	public: // aquí posarem aquelles "accions" que es poden fer amb una transformació afí
	void read();
	//void read(int dim);
	void write();
	tMatrixDynamic getLinealMatrix();
	tVectorDynamic getTranslationVector();
	bool isContractiveTransformation() { return true; };
	tPoint applyToPoint(tPoint point);
	tPoint calculateFixedPoint();
	static tAffTransformation composeAffTransformation(tAffTransformation t1, tAffTransformation t2);
};

class IFS {
	int dim;
	int numT;
};




#endif

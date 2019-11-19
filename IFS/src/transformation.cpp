#include <stdio.h>
#include <iostream>
#include "../headers/transformation.h"



void solveSystem()
{
	// Solve Ax=b
   Matrix3f A;
   Vector3f b;
   A << 1,2,3,  4,5,6,  7,8,10;
   b << 3, 3, 4;
   cout << "Here is the matrix A:\n" << A << endl;
   cout << "Here is the vector b:\n" << b << endl;
   Vector3f x = A.colPivHouseholderQr().solve(b);
   cout << "The solution is:\n" << x << endl;
}



void tAffTransformation::read(){
	cout << "Llegint una transformació...\n";
	cout << "Escriu la dimensió:\n";
	cin >> this->dim;
	this->matrix.resize(this->dim + 1,this->dim + 1);
	for(int nRow = 0; nRow < this->dim; nRow++) {
		for(int nCol=0 ; nCol< this->dim + 1; nCol++) {
			cin >> this->matrix(nRow, nCol) ;
		}
	}
	this->matrix(this->dim, this->dim) =1;
	
}

void tAffTransformation::write(){
	cout << "Escrivint una transformació...\n";
	cout << "La dimensió de la trans. és " << this->dim << ".\n";
	cout << this->matrix << "\n";
}

tMatrixDynamic tAffTransformation::getLinealMatrix() {
	tMatrixDynamic MatrixDynamic;
	MatrixDynamic = this->matrix.block(0,0,this->dim,this->dim);
	return MatrixDynamic;
}

tVectorDynamic tAffTransformation::getTranslationVector() {
	tVectorDynamic VectorDynamic;
	VectorDynamic = this->matrix.block(0,this->dim,this->dim,1);
	return VectorDynamic;
}

void tPoint::read(){
	cout << "Llegint un punt...\n";
	cout << "Escriu la dimensió:\n";
	cin >> this->dim;
	this->point.resize(this->dim + 1,1);
	for(int nRow=0;nRow < this->dim; nRow++){
		cin >> this->point(nRow,0);
	}

	this->point(this->dim,0)=1;
}

void tPoint::write(){
	cout << "Escrivint un punt...\n";
	cout << "La dimensió del punt és " << this->dim << ".\n";
	for(int nRow=0; nRow < this->dim ; nRow++){
		cout << this->point(nRow,0) << "\n";
	}
	
}	

tVectorDynamic tPoint::getTranslationVector() {
	tVectorDynamic VectorDynamic;
	VectorDynamic = this->point.block(0,0,this->dim,1);
	return VectorDynamic;
	
}


float tPoint::distanceWith(tPoint p1){
	tVectorDynamic distanceVector;
	distanceVector = p1.getTranslationVector()-this->point.block(0,0,this->dim,1);
	return distanceVector.norm();
	
}

tPoint tAffTransformation::applyToPoint(tPoint point){
	tPoint res;
	res.dim = point.dim;
	res.point = this->matrix*point.point;
	return res;
}

tPoint tAffTransformation::calculateFixedPoint(){
	tMatrixDynamic A = this->getLinealMatrix();
	tMatrixDynamic Id;
	Id.setIdentity(this->dim, this->dim);
	A = A - Id;
	tVectorDynamic b = -this->getTranslationVector();
	tPoint fixedPoint;
	fixedPoint.dim = this->dim;
	fixedPoint.point = A.colPivHouseholderQr().solve(b);
	
	return fixedPoint;
}

/* static */ tAffTransformation tAffTransformation::composeAffTransformation(tAffTransformation t1, tAffTransformation t2) {
	assert(t1.dim == t2.dim);
	tAffTransformation ComposedTransformation;
	ComposedTransformation.dim = t1.dim;
	ComposedTransformation.matrix = t1.matrix*t2.matrix;
	return ComposedTransformation;
}

//tMatrixDynamic A = this->getLinealMatrix();//restar Id
	//tVectorDynamic b = this->getTranslationVector();
	//tPoint fixedPoint;
	//fixedPoint.dim = this->dim;
	//fixedPoint.point = A.colPivHouseholderQr().solve(-b);
	//
	//return fixedPoint;
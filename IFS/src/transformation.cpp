#include <stdio.h>
#include <iostream>
#include "../headers/transformation.h"




void tPoint::read(){	//funció per a llegir un punt.
	cout << "Llegint un punt...\n";
	cout << "Escriu la dimensió:\n";
	cin >> this->dim;		//S'intodueix la dimensió del punt
	this->point.resize(this->dim + 1,1);		//El punt passa a tenir la seva dimensió més 1 files i 1 columna
	for(int nRow=0;nRow < this->dim; nRow++){	//S'utilitza la funció for per a entrar cada element del punt per ordre des de l'element 0 fins a l'element coincident amb el número de la dimensió menys 1 ja que la posició en programació comença amb un 0
		cin >> this->point(nRow,0);		
	}

	this->point(this->dim,0)=1;		//L'últim element (per tant el que coincideix en nombre de posició amb la dimensió) és un 1
}

void tPoint::write(){		//funció per a escriure un punt
	cout << "Escrivint un punt...\n";
	cout << "La dimensió del punt és " << this->dim << ".\n";		//primer s'escriu la seva dimensió
	for(int nRow=0; nRow < this->dim ; nRow++){		//mitjançant la funció for s'escriu cada element per ordre en una linia diferent
		cout << this->point(nRow,0) << "\n";
	}
	
}	

tVectorDynamic tPoint::getTranslationVector() {		//funció per obtenir el vector sense l'últim element que és sempre un 1
	tVectorDynamic VectorDynamic;
	VectorDynamic = this->point.block(0,0,this->dim,1);
	return VectorDynamic;
	
}


float tPoint::distanceWith(tPoint p1){		//funcio per determinar la distancia entre dos punts
	tVectorDynamic distanceVector = p1.getTranslationVector()-this->point.block(0,0,this->dim,1);
			//es crea un vector que representa la distancia entre els dos punts, és a dir, es resta el segon punt al primer
	return distanceVector.norm();		//es calcula el mòdul del vector, és a dir la distància entre els dos punts
	
}

void tAffTransformation::read(){		//funció de llegir una transformació afí
	cout << "Llegint una transformació...\n";
	cout << "Escriu la dimensió:\n";
	cin >> this->dim;		//primer s'introdueix la dimensió
	this->matrix.resize(this->dim + 1,this->dim + 1);		//la matriu de la transformació passa a ser de dimensió més una files i mateix nombre de columnes
	for(int nRow = 0; nRow < this->dim; nRow++) {
		for(int nCol=0 ; nCol< this->dim + 1; nCol++) {
			cin >> this->matrix(nRow, nCol) ;
		}
	}		//mitjançant dues funcions for s'introdueixen tots els elements menys els de l'última fila
	this->matrix(this->dim, this->dim) =1;		//l'últim element de tots passa a ser un 1, els altres no definits són zeros
}

void tAffTransformation::write(){		//funció per a llegir una transformació afí
	cout << "Escrivint una transformació...\n";
	cout << "La dimensió de la trans. és " << this->dim << ".\n";
	for(int nRow = 0; nRow < this->dim; nRow++) {
		for(int nCol=0 ; nCol< this->dim + 1; nCol++) {
			cout << this->matrix(nRow, nCol) ;
		}
	}	
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

bool tAffTransformation::isContractiveTransformation() { 
	tMatrixDynamic p= this->matrix * this->matrix.transpose();
	p(this->dim,this->dim)= 0;
	return (p.maxCoeff() <1);
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

tAffTransformation tAffTransformation::composeAffTransformation(tAffTransformation t1, tAffTransformation t2) {
	assert(t1.dim == t2.dim);
	tAffTransformation ComposedTransformation;
	ComposedTransformation.dim = t1.dim;
	ComposedTransformation.matrix = t1.matrix*t2.matrix;
	return ComposedTransformation;
}
 
void IFS::read(){
	cin >> this->dim;
	cin >> this->numT;
	this->IFSvector.resize(numT);
	for (int i=0;i<numT; i++){
		this->IFSvector[i].read();
	}

}
	
void IFS::write(){
	cout << "La dimensió de les transfromacions del fractal IFS és: " << this->dim << "\n";
	for(int i=0;i<numT;i++){
		this->IFSvector[i].write();
		cout << "\n";
	}
}
	// @todo completar amb escriptura transformacions
	
bool IFS::hasContractiveTransformations(){
	int n=1;
	for(int i=0; i>numT;i++){
		if (this->IFSvector[i].isContractiveTransformation()){
			n=n*1;
		}else{
			n=n*0;
		}
	}
	return (n==1);
}

tPoint IFS::calculateAleatoriOrbit(tPoint p1){
	tPoint p=IFSvector[rand()%(numT-1)].applyToPoint(p1);
	for (int i=0;i<998;i++){
		p=IFSvector[rand()%(numT-1)].applyToPoint(p);
	}
	return p;
}

tAffTransformation IFS::TransformationOfNTransformations(){
	int n,a;
	cin >> n;
	cin >> a;
	int b;
	tAffTransformation t= this.IFSvector[a];
	for(int i =0;i<n;i++){
		cin >> b;
		t.composeAffTransformation(t, this.IFSvector[b]);
	}
	return t;
}
	
vector IFS::PeriodicOrbitP1(){
	vector<tPoint> v;
	v.resize(this->numT);
	for(int i=0; i<numT;i++){
		v[i]=this->IFSvector[i].calculateFixedPoint();
	}
	return v;
}
vector IFS::PeriodicOrbitP2(){
	vector<tPoint> v;
	v.resize(this->numT);
	for(int i=0; i<numT;i++){
		int n=1;
		v[i]=this->IFSvector[n].applyToPoint(this->IFSvector[i].calculateFixedPoint());
		n++;
		if (n==this->numT){
			n=0;
		}
	}
}
vector IFS::PeriodicOrbitPn(){
	
}
vector IFS::PeriodicOrbitP1toN(){
	
}
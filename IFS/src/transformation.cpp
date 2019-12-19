#include <stdio.h>
#include <iostream>
#include <ctime>
#include "../headers/transformation.h"

bool _help_text = true;

void tPoint::read(){	//funció per a llegir un punt.
	if (_help_text) {
		cout << "Llegint un punt...\n";
		cout << "Escriu la dimensió:\n";
	}
	cin >> this->dim;		//S'intodueix la dimensió del punt
	this->point.resize(this->dim + 1,1);		//El punt passa a tenir la seva dimensió més 1 files i 1 columna
	for(int nRow=0;nRow < this->dim; nRow++){	//S'utilitza la funció for per a entrar cada element del punt per ordre des de l'element 0 fins a l'element coincident amb el número de la dimensió menys 1 ja que la posició en programació comença amb un 0
		cin >> this->point(nRow,0);		
	}

	this->point(this->dim,0)=1;		//L'últim element (per tant el que coincideix en nombre de posició amb la dimensió) és un 1
}

void tPoint::write(){		//funció per a escriure un punt
	if (_help_text) {
		cout << "Escrivint un punt...\n";
		cout << "La dimensió del punt és " << this->dim << ".\n";		//primer s'escriu la seva dimensió
	}

	for(int nRow=0; nRow < this->dim ; nRow++){		//mitjançant la funció for s'escriu cada element per ordre en una linia diferent
		cout << this->point(nRow,0) << " ";
	}
	cout << "\n";
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

void tAffTransformation::read(int dimension){		//funció de llegir una transformació afí
	if (_help_text) {
		cout << "Llegint una transformació...\n";
		cout << "Escriu la dimensió:\n";
	}
	this->dim = dimension;
	this->fillMatrix();
}

void tAffTransformation::read(){		//funció de llegir una transformació afí
	if (_help_text) {
		cout << "Llegint una transformació...\n";
		cout << "Escriu la dimensió:\n";
	}
	cin >> this->dim;		//primer s'introdueix la dimensió
	this->fillMatrix();
}

void tAffTransformation::fillMatrix() {
	this->matrix.resize(this->dim + 1,this->dim + 1);		//la matriu de la transformació passa a ser de dimensió més una files i mateix nombre de columnes
	for(int nRow = 0; nRow < this->dim; nRow++) {
		for(int nCol=0 ; nCol< this->dim + 1; nCol++) {
			cin >> this->matrix(nRow, nCol) ;
		}
	}		//mitjançant dues funcions for s'introdueixen tots els elements menys els de l'última fila
	this->matrix(this->dim, this->dim) =1;		//l'últim element de tots passa a ser un 1, els altres no definits són zeros
}

void tAffTransformation::write(){		//funció per a llegir una transformació afí
	if (_help_text) {
		cout << "Escrivint una transformació...\n";
		cout << "La dimensió de la trans. és " << this->dim << ".\n";
	}
	cout << this->matrix;
		cout << "\n";
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
	// s'ha d'agafar la part lineal
	return (p.maxCoeff() < 1); // revise
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
	if (_help_text) {
		cout << "Llegint IFS. Dimensió i numT.\n";
	}

	cin >> this->dim;
	cin >> this->numT;
	this->IFSvector.resize(numT);
	for (int i=0;i<numT; i++){
		this->IFSvector[i].read(this->dim);
	}

}
	
void IFS::write(){
	if (_help_text){
		cout << "La dimensió de les transfromacions del fractal IFS és: " << this->dim << "\n";
	}
	for(int i=0;i<numT;i++){
		this->IFSvector[i].write();
		cout << "\n";
	}
}
	// @todo completar amb escriptura transformacions
	
bool IFS::hasContractiveTransformations(){
	int n=1;
	for(int i=0; i>numT;i++){
		if (!this->IFSvector[i].isContractiveTransformation())
			return false;
	}
	return true;
}

tPoint IFS::calculateRandomOrbit(tPoint p1){
	tPoint p=p1;
	for (int i=0;i<1000;i++){
		p=IFSvector[rand()%numT].applyToPoint(p);
	}
	return p;
}

tAffTransformation IFS::TransformationOfNTransformations(){
	int n;
	cin >> n;
	vector<int> transfNums;

	for(int i =0;i<n;i++){
		cin >> transfNums[i];
	}

	return this->TransformationOfVTransformations(transfNums);
}

tAffTransformation IFS::TransformationOfVTransformations(vector<int> v){
	tAffTransformation t= this->IFSvector[0];
	for(int i=1;i<v.size();i++){
		t= tAffTransformation::composeAffTransformation(t,this->IFSvector[i]);
	}
	return t;
}

	
void IFS::PeriodicOrbitP1(){

	for(int i=0; i<numT;i++){
		this->IFSvector[i].calculateFixedPoint().write();
	}
}

void IFS::GetPeriodicOrbits(int period){
	int p=2;
	bool igualtat=false;
	vector<int> transNums,last;
	transNums.resize(period,0);
	last.resize(period,numT-1);
	do{
		for(int i=0;i<this->numT;i++){
			for (vector<int>::const_iterator i = transNums.begin(); i != transNums.end(); ++i)
				std::cout << *i << ' ';
			cout << "\n";
			//comprovar si el periode es correcte i que no es repeteixi
			
			//calcular orbita periodica sencera asociada a transNums i escrigui els punts
			//this->funcioAmb Nom Nou(transNums);
			if(transNums==last) return;
			transNums[period-1]++;
		}
		if(transNums==last) return;
		transNums[period-1]=0;
		if(transNums[period-p]==this->numT-1){
			do{
				transNums[period-p]=0;
				p++;
			}while(transNums[period-p]==this->numT-1);
			transNums[period-p]++;
			p=2;
		}else{
			transNums[period-p]++;
		}
	}while(true);
}

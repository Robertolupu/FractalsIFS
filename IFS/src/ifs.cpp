#include <stdio.h>
#include <iostream>
#include <ctime>
#include "../headers/ifs.h"

bool _help_text = false;
	// _help_text is always false except we change it

void tPoint::read(){
	if (_help_text) {
		cout << "Reading a point...\n";
		cout << "Write the dimension:\n";
	}
	cin >> this->dim;		
		// It reads the dimension
	this->point.resize(this->dim + 1,1);		
		// The point vector has dimension rows and one col
	for(int nRow=0;nRow < this->dim; nRow++){	
			cin >> this->point(nRow,0);		
	}
		// It reads every element except the las one
	this->point(this->dim,0)=1;
		// The last element is a 1
}

void tPoint::read(int dimension){
	if (_help_text) {
		cout << "Reading an affine transformation...\n";
		cout << "Write the dimension:\n";
	}
	this->dim = dimension;
		// The affine transformation's dimension is the given number "dimension"
	this->fillMatrix();
		// It fills the vector
}

void tPoint::read(tPoint point){
	this->dim= point.point.rows();
	this->point.resize(this->dim + 1,1);
	for(int i=0;i<this->dim-1;i++){
		this->point(i,0)=point.point(i,0);
	}
	this->point(this->dim,0)=1;
}

void tPoint::fillMatrix() {
	this->point.resize(this->dim + 1,1);
		// The vector of the point has dimension rows and one col
	for(int nRow=0;nRow < this->dim; nRow++){	
		cin >> this->point(nRow,0);		
	}
		// It reads every element of the vector except the last one
	this->point(this->dim,0)=1;
		// The last element is a 1
}

void tPoint::write(){
	if (_help_text) {
		cout << "Writting a point...\n";
		cout << "Its dimension is " << this->dim << ".\n";
		// It writes its dimension
	}
	for(int nRow=0; nRow < this->dim ; nRow++){	
		cout << this->point(nRow,0) << " ";
	}
		// It writes every element of the point 
	cout << "\n";
}	

tVectorDynamic tPoint::getTranslationVector() {	
	 return this->point.block(0,0,this->dim,1);
}


float tPoint::distanceWith(tPoint p1){	
	tVectorDynamic distanceVector = p1.getTranslationVector()-this->point.block(0,0,this->dim,1);
		// It makes a vector which is the first point minus the second one
	return distanceVector.norm();
		// The norm of this vector is the distance between the two points so it returnes this norm
}

void tAffTransformation::read(int dimension){
	if (_help_text) {
		cout << "Reading an affine transformation...\n";
		cout << "Write the dimension:\n";
	}
	this->dim = dimension;
		// The dimension of the affine transformation is the same as the given number "dimension"
	this->fillMatrix();
		// It fills the matrix
}

void tAffTransformation::read(){
	if (_help_text) {
		cout << "Reading an affine transformation ...\n";
		cout << "Write the dimension:\n";
	}
	cin >> this->dim;
		// Firstly it reads the dimension
	this->fillMatrix();
		// It fills the matrix
}

void tAffTransformation::fillMatrix() {
	this->matrix.resize(this->dim + 1,this->dim + 1);
		// The matrix has dimension rows and cols
	for(int nRow = 0; nRow < this->dim; nRow++) {
		for(int nCol=0 ; nCol< this->dim + 1; nCol++) {
			cin >> this->matrix(nRow, nCol) ;
		}
	}
		// It reads all the elements except the last row
	this->matrix(this->dim, this->dim) =1;
		// The last element is a 1
		// The other elements of the last row are 0 because they haven't been read
}

void tAffTransformation::write(){
	if (_help_text) {
		cout << "Writing an affine transformation...\n";
		cout << "Its dimension is " << this->dim << ".\n";
	}
	cout << this->matrix;
		// It writes the matrix of the affine transformation
		cout << "\n";
}	
	

tMatrixDynamic tAffTransformation::getLinealMatrix() {
	return this->matrix.block(0,0,this->dim,this->dim);
}

tVectorDynamic tAffTransformation::getTranslationVector() {
	return this->matrix.block(0,this->dim,this->dim,1);
}

bool tAffTransformation::isContractiveTransformation() { 
	tMatrixDynamic p= this->getLinealMatrix()*this->getLinealMatrix().transpose();
		// It makes a matrix which is the product between the lineal matrix of the affine transformation and its transposed 
	return (p.operatorNorm()<1);
		// It returns true only if the operator norm of the previous matrix is less than one
}
	
tPoint tAffTransformation::applyToPoint(tPoint point){
	tPoint res;
		// It makes a point
	res.dim = point.dim;
		// The dimension of this point is the same as the dimension of the given point
	res.point = this->matrix*point.point;
		// The vector of the point is the product between the affine transformation and the vector of the given point
	return res;
		// It returns this point
}

tPoint tAffTransformation::calculateFixedPoint(){
	tMatrixDynamic A = this->getLinealMatrix();
	tMatrixDynamic Id;
	Id.setIdentity(this->dim, this->dim);
	A=A-Id;
		// It makes a matrix A which is the lineal matrix of the affine transformation minus the Identity matrix
	tVectorDynamic b = -this->getTranslationVector();
		// It makes a matrix b which is minus the translation vector of the affine transformation
	tPoint fixedPoint;
		// It makes a point
	fixedPoint.dim = this->dim;
		// The dimension of the point is the same as the dimension of the affine matrix
	fixedPoint.point = A.colPivHouseholderQr().solve(b);
		// It solves the system: A*fixedPoint=b
	fixedPoint.dim=this->dim;
	return fixedPoint;
		// It returns the fixed point
}

tAffTransformation tAffTransformation::composeAffTransformation(tAffTransformation t1, tAffTransformation t2) {
	assert(t1.dim == t2.dim);
	tAffTransformation ComposedTransformation;
		// It makes an affine transfromation
	ComposedTransformation.dim = t1.dim;
		// The dimension of the affine transformation is the same as the dimension of the first given affine transformation
	ComposedTransformation.matrix = t1.matrix*t2.matrix;
		// The matrix affine transformation is the product between the matrixes of the first and the secon given transformations
	return ComposedTransformation;
		// It returns the composed affine transformation
}

void IFS::read(){
	if (_help_text) {
		cout << "Reading IFS fractal.\n";
		cout << "Write its dimension and its number of affine transformations: ";
	}
	cin >> this->dim;
		// It reads the euclidean dimension of the IFS fractal
	cin >> this->numT;
		// It reads the number of transformations of the IFS fractal
	this->IFSvector.resize(numT);
		// The vector that contains the affine transformations has number of transformations elements
	for (int i=0;i<numT; i++){
		this->IFSvector[i].read(this->dim);
	}
		// It reads every affine transformation 

}
	
void IFS::write(){
	if (_help_text){
		cout << "The dimension of the IFS fractal is: " << this->dim << "\n";
	}
	for(int i=0;i<numT;i++){
		this->IFSvector[i].write();
		cout << "\n";
	}
		// It writes every affine transformation in order 
}
	
bool IFS::hasContractiveTransformations(){
	for(int i=0; i>this->numT;i++){
		if (this->IFSvector[i].isContractiveTransformation()==false)
			return false;
	}
	return true;
		// It looks at every affine transformation, if one of them is not, it returns false
}

tPoint IFS::calculateRandomOrbit(tPoint p1,int iter){
	for (int i=0;i<iter;i++){
		p1=IFSvector[rand()%numT].applyToPoint(p1);
	}
		// It applies a randomly an affine transformation of the IFS fractal to a given point for a given number of times 
	return p1;
		// It returns the resulting point
}

tAffTransformation IFS::resultingTransformation(vector<int> v){
	tAffTransformation t=this->IFSvector[v[0]];
		// It makes an affine transformation which is the same as the number of transformation that the first element of the given vector 
	for(int i=1;i<v.size();i++){
		t= tAffTransformation::composeAffTransformation(t,this->IFSvector[v[i]]);
	}
		// It composes an affine transformation of all the vector elements
	return t;
		// It returns the resulting affine transformation
}
void IFS::GetPeriodicOrbit(vector<int> v){
	tPoint point=this->resultingTransformation(v).calculateFixedPoint();
	point.write();
	for(int i=1;i<v.size();i++){
		point.point=this->IFSvector[v[v.size()-i]].getLinealMatrix()*point.point+this->IFSvector[v[v.size()-i]].getTranslationVector();
		point.write();
	}
}
	
void IFS::GetPeriodicOrbits(int period){
	int p=2;
	vector<int> transNums,last;
	bool repeatedVector = false;
	transNums.resize(period,0);
	last.resize(period,this->numT-1);
	do{
		for(int i=0;i<this->numT;i++){
			//for (vector<int>::const_iterator i = transNums.begin(); i != transNums.end(); ++i)
				//std::cout << *i << ' ';
			//cout << "\n";
			//Filtrar ex:123<->312
			repeatedVector=false;
			for(int i=1;i<transNums.size();i++){
				int a=0;
				for(int j=0;j<transNums.size();j++)
					a+=transNums[j]*pow(10,j)-transNums[(j+i)%transNums.size()]*pow(10,j);
				if(a<=0)
					repeatedVector=true;
			}
			//calcular orbita periodica sencera asociada a transNums i escrigui els punts
			if(!repeatedVector)
				this->GetPeriodicOrbit(transNums);
			if(transNums==last) return;
			transNums[period-1]++;
		}
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
	} while(true);
} 


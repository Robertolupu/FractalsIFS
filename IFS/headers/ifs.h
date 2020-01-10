#ifndef __TRANSFORMATION_H__
#define __TRANSFORMATION_H__

#include <stdio.h>
#include "../Eigen/Dense"
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;
using namespace Eigen;

extern bool _help_text;		
	// Bool for help text
	// When this bool is true, the program writes information like "introduce the dimension"
typedef double tElement;
typedef Matrix<tElement, Dynamic, Dynamic> tMatrixDynamic;
	// tMatrixDynamic is a matrix of tElements with dynamic rows and cols
typedef Matrix<tElement, Dynamic, 1> tVectorDynamic;
	// tMatrixDynamic is a vector of tElements with dynamic rows and one col
	
class tPoint {
		// Definition of point and its functions
	public:
	int dim;	
		// The dimension of the point
	tVectorDynamic point;
		// The vector which represents the point
// These are the functions of a point
// They are defined in the document transformation.cpp
	void read();
		// Function that reads the dimension and the elements of a point putting at the last position a 1
	void read(int dim);
		// Function that reads the elements of a point putting at the last position a 1 after it recived the dimension 
	void read(tPoint point);
		// Function that puts a one at the end of the given point
	void fillMatrix();
		// Necessary function for the previous one
	void write();
		// Function that writes the a point
	tVectorDynamic getTranslationVector();
		// Function that returns the point without the last 1
	float distanceWith(tPoint p1);
		// Function that calculates the distance between two points
};	

class tAffTransformation {	
		// Definition of an affine transformation
	public:
	int dim;	
		// The dimension of the affine transformation
	tMatrixDynamic matrix;	
		// The matrix of the affine transformation
		
// These are the functions of an affine transformation
// They are defined in the document transformation.cpp
	void read();
		// Function that reads the dimension and the elements of an affine transformation putting 0 at the last row positions and a 1 at the last position
	void read(int dim);
		// Function that reads the elements of an affine transformation putting 0 at the last row positions and a 1 at the last position after it recived the dimension 
	void fillMatrix();
		// Necessary function for the previous one
	void write();
		// Function that writes the a point
	tMatrixDynamic getLinealMatrix();
		// Function that returns the matrix of tha affine transformation without the last row and col
	tVectorDynamic getTranslationVector();
		// Function that returns a vector, the las col of the matrix of the affine transformation without the last 1
	bool isContractiveTransformation();
		// Function that checks if an affine is contractive 
	tPoint applyToPoint(tPoint point);
		// Function that applies an affine transformation to a point
	tPoint calculateFixedPoint();
		// Function that returns the fixed point of an affine transformation (if it has a fixed point)
	static tAffTransformation composeAffTransformation(tAffTransformation t1, tAffTransformation t2);
		// Functions that returns an affine transformation composed by other two affine transformations
};

class IFS {	
		// Definition of an IFS fractal
	public:
	int dim;
		// The euclidean dimension of the IFS fractal
	int numT;
		// The number of affine transformations of the IFS fractal
	vector<tAffTransformation> IFSvector;	
		// The vector that contains the affine transformations of the IFS fractal
// These are the functions of an IFS fractal
// They are defined in the document transformation.cpp
	void read();
		// Function that reads an IFS fractal
	void write();
		// Function that writes an IFS fractal
	bool hasContractiveTransformations();
		// Function that checks if an IFS fractal is composed by contractive affine transformations
	tPoint calculateRandomOrbit(tPoint p1, int iter);
		// Function that applies randomly an affine transformation of the IFS fractal int times and it returns the resulting point
	tAffTransformation resultingTransformation(vector<int> v);
		// Function that returns the resulting affine transformation using a vector
	void GetPeriodicOrbit(vector<int> v);
		// Function that returns every point of the periodic given orbit
	void GetPeriodicOrbits(int period);
		// Function that writes every fixed point of a given period
};
#endif
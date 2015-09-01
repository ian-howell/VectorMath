#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using std::ostream;

class Vector
{
public:
	// Constructors
	Vector(double i, double j, double k=0);
	Vector();

	double getMagnitude() const;


	// Friend functions and operation overloaders
	friend ostream& operator <<(ostream& outStream, const Vector& a);
	friend const Vector operator+(const Vector& a, const Vector& b);
	friend const Vector operator-(const Vector& a, const Vector& b);
	friend const Vector operator*(double x, const Vector& a);
	friend const Vector operator*(const Vector& a, double x);
	friend double dot(const Vector& a, const Vector& b);
	friend const Vector cross(const Vector& a, const Vector& b);
	friend double angle(const Vector& a, const Vector& b);

	friend bool operator==(const Vector& a, const Vector&b);
	friend const Vector operator -(const Vector& a);




private:
	double i, j, k, magnitude;
	
	// calculates the size of the vector
	double calcMagnitude() const;


};

#endif

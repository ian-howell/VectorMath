#include "Vector.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::ostream;

Vector::Vector(double i, double j, double k)
{
	this->i = i;
	this->j = j;
	this->k = k;

	magnitude = calcMagnitude();
}

Vector::Vector() : i(0), j(0), k(0), magnitude(0)
{ // Body left intentionally empty
}

double Vector::getMagnitude() const
{
	return magnitude;
}

double Vector::calcMagnitude() const
{
	if (i == 0 && j == 0 && k == 0)
		return 0;

	return sqrt(pow(i, 2) + pow(j, 2) + pow(k, 2));

}

ostream& operator <<(ostream& outStream, const Vector& a)
{
	outStream << a.i << "i + " << a.j << "j + " << a.k << "k";

	return outStream;

}

const Vector operator+(const Vector& a, const Vector& b)
{
	double newI = a.i + b.i;
	double newJ = a.j + b.j;
	double newK = a.k + b.k;

	return Vector(newI, newJ, newK);
}

const Vector operator-(const Vector& a, const Vector& b)
{
	double newI = a.i - b.i;
	double newJ = a.j - b.j;
	double newK = a.k - b.k;

	return Vector(newI, newJ, newK);
}

const Vector operator*(double x, const Vector& a)
{
	double newI = a.i * x;
	double newJ = a.j * x;
	double newK = a.k * x;

	return Vector(newI, newJ, newK);
}

const Vector operator*(const Vector& a, double x)
{
	return x * a;
}

double dot(const Vector& a, const Vector& b)
{
	return ((a.i * b.i) + (a.j * b.j) + (a.k * b.k)); 
}

const Vector cross(const Vector& a, const Vector& b)
{
	double newI = ((a.j * b.k) - (a.k * b.j));
	double newJ = ((a.k * b.i) - (a.i * b.k));
	double newK = ((a.i * b.j) - (a.j * b.i));

	return Vector(newI, newJ, newK);
}

double angle(const Vector& a, const Vector& b)
{
	return acos(dot(a, b) / (a.magnitude * b.magnitude));
}

bool operator==(const Vector& a, const Vector&b)
{
}

const Vector operator -(const Vector& a)
{
	return Vector(-(a.i), -(a.j), -(a.k));
}

#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector(int dimension){
	allocSize =0;
	fDimension = dimension;
	double array[dimension];
	fElements = array;
	for(int i=0;i<dimension;i++){
		array[i]=0;
	}
}
Vector::Vector(int size,const double element[]){
	allocSize = size;
	fDimension = size;
	double array[size];
	fElements = array;
	for(int i=0;i<size;i++){
		array[i]=element[i];
	}
}
Vector::Vector(const Vector &source){
	fDimension = source.fDimension;
	allocSize = source.allocSize;
	double array[fDimension];
	fElements = array;
	for(int i=0;i<fDimension;i++){
		array[i]=source.array[i];
	}
}
Vector::~Vector(){
	
}
int Vector::getDimension() const{
	return fDimension;
}
void Vector::setDimension(int Dimension){
	fDimension = Dimension;
}
Vector& Vector::operator=(const Vector &v2){
	if(fDimension != v2.fDimension){
		cout << "error";
	}
	else{
		allocSize = v2.allocSize;
		for(int i=0;i<v2.fDimension;i++){
			array[i]=v2.array[i];
		}
		return *this;
	}

}
double& Vector::operator[](int index){
	fElements = &array[index];
	return *fElements;
	fElements = array;
	
}
double Vector::operator[](int index)const{
	return array[index];
}
Vector Vector::operator+(const Vector &v2)const{
	if(fDimension != v2.fDimension){
		cout<<"error";
	}
	else {
		Vector temp(*this);
		for(int i=0;i<fDimension;i++){
			temp.array[i]+=v2.array[i];
		}
		return temp;
	}

}
Vector Vector::operator-(const Vector &v2)const{
	if(fDimension != v2.fDimension){
		cout<<"error";
	}	
	else{
		Vector temp(*this);
		for(int i=0;i<v2.fDimension;i++){
			temp.array[i]-=v2.array[i];
		}
		return temp;
	}
}
Vector & Vector::operator+=(const Vector &v2){
	if(fDimension != v2.fDimension){
		cout << "error";
	}
	else{
		for(int i=0;i<fDimension;i++){
			this->array[i]+=v2.array[i];
		}
	}
	return *this;
}

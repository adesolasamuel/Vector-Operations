/*
 * VectorOperation.cpp
 *
 *  Created on: 5 May 2022
 *      Author: Samuel Adesola
 */

#include <math.h>
#include <sstream>
#include <string>
#include "VectorOperation.h"
#include "OperationExceptions.h"


namespace vec {

// THREE COMPONENT VECTOR

VectorOperation::VectorOperation(double i, double j, double k): m_i(i), m_j(j), m_k(k) {
	// TODO Auto-generated constructor stub
	if (m_k == 0){
//		std::cout << "Two Vector Component" << std::endl;
		istwoCompoVector = true;
	}
	else {
//		std::cout << "Three Component Vector" << std::endl;
		isthreeCompoVector = true;
	}

}

// Vector Dimension Checker

std::string VectorOperation::checkDimension(){
	if (VectorOperation::isthreeCompoVector == true){
		return "Three Component Vector";
	}
	else if (VectorOperation::istwoCompoVector == true){
		return "Two Component Vector";
	}
	else{
		return "Vector type not known";
	}
}


//overloading the stream insertion operation to output vectors

std::ostream &operator<<(std::ostream &out, const VectorOperation &oprt){
	if(oprt.getK() != 0){
	out << "(" << oprt.getI() << "," << oprt.getJ() << "," << oprt.getK() << ")";
	}
	else{
		out << "(" << oprt.getI() << "," << oprt.getJ() << ")";
	}
	return out;
}

//Overloading the == operator to check for vector equality

bool VectorOperation::operator==(const VectorOperation &oprt){
	return this->m_i == oprt.m_i && this->m_j == oprt.m_j && this->m_k == oprt.m_k;
}

//Overloading the * to perform scalar multiplication of vector

VectorOperation operator*(const VectorOperation &oprt, double s){
	return VectorOperation(s*oprt.getI(), s*oprt.getJ(), s*oprt.getK());
}

//Overloading the * to perform scalar multiplication of vector

VectorOperation operator*(double s, const VectorOperation &oprt){
	return VectorOperation(s*oprt.getI(), s*oprt.getJ(), s*oprt.getK());
}

//Vector dot product calculation

double dotPro(const VectorOperation &vec1, const VectorOperation &vec2){
	try{
		if ((vec1.threeCompoVectorStatus() == true) && (vec2.threeCompoVectorStatus() == true)){
	return (vec1.getI()*vec2.getI()) + (vec1.getJ()*vec2.getJ()) + (vec1.getK()*vec2.getK());
		}
		else if((vec1.twoCompoVectorStatus() == true) && (vec2.twoCompoVectorStatus() == true)){
			return ((vec1.getI()*vec2.getI()) + (vec1.getJ()*vec2.getJ()));
		}
		else{
			throw VectorOperationErrors("Invalid Vector Operation", 4);
		}
}
catch(VectorOperationErrors &err){
	std::cout << "ERROR: " << err.getMessage() << std::endl;
	return 0;
}
}


//Vector Cross product

VectorOperation crossPro(const VectorOperation &vec1, const VectorOperation &vec2){
	try{
		if ((vec1.threeCompoVectorStatus() == true) && (vec2.threeCompoVectorStatus() == true)){
	return VectorOperation(((vec1.getJ()*vec2.getK()) - (vec1.getK()*vec2.getJ())), -((vec1.getI()*vec2.getK()) - (vec1.getK()*vec2.getI())), ((vec1.getI()*vec2.getJ()) - (vec1.getJ()*vec2.getI())));
}
		else{
			throw VectorOperationErrors("Invalid Vector Operation", 3);	//This calls errThree
		}
	}
	catch(VectorOperationErrors &err){
		std::cout << "ERROR: " << err.getMessage() << std::endl;
		return VectorOperation(0, 0, 0);
	}
}

// Overloading the + operator

VectorOperation operator+(const VectorOperation &vec1, const VectorOperation &vec2) throw(VectorOperationErrors){
	try{
	if ((vec1.threeCompoVectorStatus() == true) && (vec2.threeCompoVectorStatus() == true)){

		return VectorOperation(vec1.getI() + vec2.getI(), vec1.getJ() + vec2.getJ(), vec1.getK() + vec2.getK());

	}
	else if ((vec1.twoCompoVectorStatus() == true) && (vec2.twoCompoVectorStatus() == true)){

		return VectorOperation(vec1.getI() + vec2.getI(), vec1.getJ() + vec2.getJ());

	}
	else{

		throw VectorOperationErrors("Invalid Vector Operation", 1);

	}
	}
	catch (VectorOperationErrors &err) {
		std::cout << "Error: " << err.getMessage() << std::endl;
		return VectorOperation(0, 0, 0);
	}
}


//Overloading the - operator

VectorOperation operator-(const VectorOperation &vec1, const VectorOperation &vec2){
	try{
		if ((vec1.threeCompoVectorStatus() == true) && (vec2.threeCompoVectorStatus() == true)){
	return VectorOperation(vec1.getI() - vec2.getI(), vec1.getJ() - vec2.getJ(), vec1.getK() - vec2.getK());
	}
		else if ((vec1.twoCompoVectorStatus() == true) && (vec2.twoCompoVectorStatus() == true)){

			return VectorOperation(vec1.getI() - vec2.getI(), vec1.getJ() - vec2.getJ());

		}
		else{

			throw VectorOperationErrors("Invalid Vector Operation", 2);

		}
	}
	catch(VectorOperationErrors &err){
		std::cout << "ERROR: " << err.getMessage() << std::endl;
		return VectorOperation(0, 0, 0);
	}
}

// Modulus operation using VectorOperation object.mod()

double VectorOperation::mod(){
	return sqrt((this->m_i*this->m_i) + (this->m_j*this->m_j) + (this->m_k*this->m_k));
}

// Modulus operation using VectorOperation mod(object)

double mod(const VectorOperation &vec){
	return sqrt((vec.getI()*vec.getI()) + (vec.getJ()*vec.getJ()) + (vec.getK()*vec.getK()));
}

//Unit Vector of a Vector. Unit vector of a vector A is given by A/det(A)

std::string unitVector(const VectorOperation &vec){
	std::stringstream unitV;
	unitV << vec;
	unitV << "/";
	unitV << mod(vec);
	return unitV.str();
}

//Direction Cosines

std::string directionCosine(const VectorOperation &vec){
	std::stringstream dirCos;
	dirCos << "cos alpha = ";
	dirCos << vec.getI()/mod(vec);
	dirCos << "  cos beta = ";
	dirCos << vec.getJ()/mod(vec);

	if(vec.threeCompoVectorStatus() == true){
	dirCos << "  cos gama = ";
	dirCos << vec.getK()/mod(vec);
	}

	return dirCos.str();
}

double VectorOperation::cosalpha(){
	return (this->m_i/this->mod());
}

double VectorOperation::cosbeta(){
	return (this->m_j/this->mod());
}

double VectorOperation::cosgama(){
	return (this->m_k/this->mod());
}

VectorOperation::~VectorOperation() {
	// TODO Auto-generated destructor stub
}

} /* namespace vec */

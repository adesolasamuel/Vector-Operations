/*
 * VectorOperation.h
 *
 *  Created on: 5 May 2022
 *      Author: Samuel Adesola
 */


#include <iostream>
#include "OperationExceptions.h"
#ifndef VECTOROPERATION_H_
#define VECTOROPERATION_H_

namespace vec {

class VectorOperation {
private:
	double m_i;
	double m_j;
	double m_k;
	bool isthreeCompoVector{false};
	bool istwoCompoVector{false};

public:
	VectorOperation(double i, double j, double k = 0);
	double mod();
	double cosalpha();
	double cosbeta();
	double cosgama();
	std::string checkDimension();
	bool operator==(const VectorOperation &oprt);



//Getters
	double getI() const {
		return m_i;
	}

	double getJ() const {
		return m_j;
	}

	double getK() const {
		return m_k;
	}

	bool threeCompoVectorStatus() const {
		return isthreeCompoVector;
	}

	bool twoCompoVectorStatus() const {
		return istwoCompoVector;
	}

	virtual ~VectorOperation();
};


// Overloading operators, check the VectorOpeartion.cpp file to learn more

std::ostream &operator<<(std::ostream &out, const VectorOperation &oprt);
VectorOperation operator*(const VectorOperation &oprt, double s);
VectorOperation operator*(double s, const VectorOperation &oprt);
double dotPro(const VectorOperation &vec1, const VectorOperation &vec2);
VectorOperation crossPro(const VectorOperation &vec1, const VectorOperation &vec2);
VectorOperation operator+(const VectorOperation &vec1, const VectorOperation &vec2) throw(VectorOperationErrors);
VectorOperation operator-(const VectorOperation &vec1, const VectorOperation &vec2);
double mod(const VectorOperation &vec);
std::string unitVector(const VectorOperation &vec);
std::string directionCosine(const VectorOperation &vec);

} /* namespace sam */

#endif /* VECTOROPERATION_H_ */

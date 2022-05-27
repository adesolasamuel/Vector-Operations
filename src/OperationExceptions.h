/*
 * OperationExceptions.h
 *
 *  Created on: 18 May 2022
 *      Author: Samuel Adesola
 */
#include <string.h>

#ifndef OPERATIONEXCEPTIONS_H_
#define OPERATIONEXCEPTIONS_H_

class VectorOperationErrors : public std::exception{

private:
	std::string message;
	int m_code;

	const std::string errOne {"You cannot add vectors of different dimensions"};
	const std::string errTwo {"You cannot Subtract vectors of different dimensions"};
	const std::string errThree {"Vector/Cross product of non 3D vector not supported"};
	const std::string errFour {"Dot product of non uniform vectors not supported"};

public:
	VectorOperationErrors(const std::string &m, int code) : message(m), m_code(code) { }

	const std::string &getMessage() const {
		switch(m_code){
		case 1:
			 return errOne;
			 break;
		case 2:
			return errTwo;
			break;
		case 3:
			return errThree;
		case 4:
			return errFour;
		default:
			return message;
		}

	}



};





#endif /* OPERATIONEXCEPTIONS_H_ */

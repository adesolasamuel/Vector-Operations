//============================================================================
// Name        : Vector.cpp
// Author      : ADESOLA SAMUEL
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Vector Operations in Mathematics, Ansi-style
//============================================================================

#include <iostream>
#include "VectorOperation.h"

int main() {

// Example 1: Creating a 3D vector object
// The constructor has was overloaded to determine vector dimention automatically based on the number of parameter passed during initialization
//
	
	vec::VectorOperation a(2, 3, 2);
	vec::VectorOperation b(3, -2, 1);
	vec::VectorOperation c(9, 10);
	vec::VectorOperation d(15, 23);


// Example 2: Vector equality and Scalar multiplication of vectors
// The example before tests whether vector a is equal to b and then perform a sample scalar multiplication of vactor based on the result
// The == operator has been overloaded to test for equality of vectors. This works for both 2D and 3D vectors
	
	if(a == b){	// Returns false
		std::cout << 2 * a << std::endl;
	}
	else{
		std::cout << d * 1 << std::endl;
	}

// Example 3: Vector Addition
// The + operator has been overloaded to add two vectors of the same dimention together. If vectors of different dimention was passed,
// it will through an exception which has been properly handled from the exemption header file.
	
	std::cout << a + b << std::endl;
	std::cout << a + c << std::endl;		//Exception thrown

// Example 4: Vector Subtraction
// The - operator has been overloaded to subtract vectors of the same dimention together. If vectors of different dimention was passed,
// it will through an exception which has been properly handled from the exemption header file.
	
	std::cout << a - b << std::endl;
	std::cout << a - c << std::endl;		//Exception thrown

//Example 5: Modulus or Magnitude of a vector Vector.
// Two different methods of getting the modulus of a vector was implemented. The two both works fine for both 2D and 3D vectors.
	
	std::cout << a.mod() << std::endl;
	std::cout << mod(a) << std::endl;

//Example 6: Dot Product
// Dot product can be performed on both 2D and 3D vector. An exception will be thrown if vectors of different dimention was called in mathematics.

	std::cout << dotPro(b, a) << std::endl;
	std::cout << dotPro(c, d) << std::endl;

// Example 7: Cross Product.
// In mathematics, cross product is design for 3D vectors, the program throws an exception if crossPro is called for 2D Vectors
	
	std::cout << crossPro(a, b) << std::endl;

// Example 8: Unit Vectors
// Unit vector is defines as a vecor divided by its determinant. It can be called only on one vector whether 2D or 3D
	
	std::cout << unitVector(b) << std::endl;
	std::cout << unitVector(d) << std::endl;
	
// Example 9: Direction Cosines
// Direction cosines of vectors produce 2 answers cos alpha and cos beta for 2D vector and 3 answers cos alpha, cos beta and cos gama for 3D vectors
// Two different methods was implemented to achieve this. A general method the push the whole answers on the screen once and a mrthod for calling each component
	
	std::cout << directionCosine(a) << std::endl;
	std::cout << a.cosalpha() << std::endl;
	std::cout << a.cosbeta() << std::endl;
	std::cout << a.cosgama() << std::endl;

return 0;
}

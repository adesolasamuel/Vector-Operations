//============================================================================
// Name        : Vector.cpp
// Author      : ADESOLA SAMUEL
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Vector Operations in Mathematics, Ansi-style
//============================================================================

#include <iostream>
#include "VectorOperation.h"

using namespace std;

int main() {

/*
	vec::VectorOperation a(2, 3, 2);
	vec::VectorOperation b(3, -2, 1);
	vec::VectorOperation c(9, 10, 16);
	vec::VectorOperation d(15, 14, 23);
*/

/*
	if(a == b){
		std::cout << 2 * a << std::endl;
	}
	else{
		std::cout << d * 1 << std::endl;
	}

	std::cout << a + b << std::endl;
	std::cout << a.mod() << std::endl;
	std::cout << mod(a) << std::endl;
	std::cout << dotPro(b, a) << std::endl;
	std::cout << crossPro(a, b) << std::endl;

*/

	vec::VectorOperation a(2, -5, 1);
	vec::VectorOperation b(2, 5);

//	std::cout << dotPro(a, b) << std::endl;
	std::cout << unitVector(b) << std::endl;
	std::cout << directionCosine(a) << std::endl;
	std::cout << b.cosalpha() << std::endl;
	std::cout << b.cosbeta() << std::endl;
	std::cout << b.cosgama() << std::endl;

//	std::cout << a + b << std::endl;
//	std::cout << mod(b) << std::endl;



return 0;
}

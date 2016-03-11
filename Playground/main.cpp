//
//  main.cpp
//  Playground
//
//  Created by Fu Lam Diep on 11.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include <iostream>

class A {
public:
	int x = 1;
	
	A () {
		x = 2;
	}
	
	A (int x) : x(x) {
		
	}
};


class B : public A
{
public:
	B () : A(4) {
		
	}
};


int main(int argc, const char * argv[]) {
	B* b = new B();
	fprintf(stderr, "%i", b->x);
    return 0;
}

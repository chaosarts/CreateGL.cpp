//
//  main.cpp
//  Playground
//
//  Created by Fu Lam Diep on 11.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include <iostream>
#include <stdarg.h>
#include <list>
#include <initializer_list>
#include <glm/glm.hpp>

using namespace std;

void log (const char* format, ...)
{
	va_list aptr;
	va_start(aptr, format);
	vfprintf(stderr, format, aptr);
	va_end(aptr);
}

int main(int argc, const char * argv[]) {
	void* data = malloc(sizeof(float) + sizeof(double) + sizeof(int));
	void* ptr = data;
	
	*((float*) ptr) = (float) 1.0;
	
	ptr = (void*)(((float*) ptr) + 1);
	*((double*) ptr) = (double) 2.0;
	
	ptr = (void*)(((double*) ptr) + 1);
	*((int*) ptr) = (int) 3;
	
	ptr = data;
	log("%f\n", *((float*) ptr));
	
	ptr = (void*)(((float*) ptr) + 1);
	log("%f\n", *((double*) ptr));
	
	ptr = (void*)(((double*) ptr) + 1);
	log("%i\n", *((int*) ptr));

    return 0;
}

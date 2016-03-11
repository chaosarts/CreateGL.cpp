//
//  Translation.cpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "Translation.hpp"


namespace creategl {
	
	Translation::Translation (vec3 position) : position(position) {}
	
	Translation::Translation (float x, float y, float z) : Translation(vec3(x, y, z)) {}
	
	Translation::~Translation() {}
	
	mat4 Translation::apply (mat4 matrix)
	{
		return translate(matrix, position);
	}
	
	
	mat4 Translation::revert(mat4 matrix)
	{
		return translate(matrix, -position);
	}
}
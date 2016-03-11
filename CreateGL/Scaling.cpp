//
//  Scaling.cpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "Scaling.hpp"

namespace creategl {
	
	Scaling::Scaling (vec3 scaling) : scaling(scaling) {}
	
	Scaling::Scaling (float x, float y, float z) : Scaling(vec3(x, y, z)) {}
	
	Scaling::~Scaling() {}
	
	mat4 Scaling::apply (mat4 matrix)
	{
		return glm::scale(matrix, scaling);
	}
	
	mat4 Scaling::revert (mat4 matrix)
	{
		return glm::scale(matrix, -scaling);
	}
}
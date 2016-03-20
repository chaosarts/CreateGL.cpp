//
//  Scaling.cpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "scaling.hpp"

namespace creategl {
	
	Scaling::Scaling (glm::vec3 scaling) : scaling(scaling) {}
	
	Scaling::Scaling (float x, float y, float z) : Scaling(glm::vec3(x, y, z)) {}
	
	Scaling::~Scaling() {}
	
	glm::mat4 Scaling::apply (glm::mat4 matrix)
	{
		return glm::scale(matrix, scaling);
	}
	
	glm::mat4 Scaling::revert (glm::mat4 matrix)
	{
		return glm::scale(matrix, -scaling);
	}
}
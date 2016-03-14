//
//  Translation.cpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "Translation.hpp"


namespace creategl {
	
	Translation::Translation (glm::vec3 position) : position(position) {}
	
	Translation::Translation (float x, float y, float z) : Translation(glm::vec3(x, y, z)) {}
	
	Translation::~Translation() {}
	
	glm::mat4 Translation::apply (glm::mat4 matrix)
	{
		return translate(matrix, position);
	}
	
	
	glm::mat4 Translation::revert(glm::mat4 matrix)
	{
		return translate(matrix, -position);
	}
}
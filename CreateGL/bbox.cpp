//
//  bbox.cpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include <algorithm>
#include "bbox.hpp"

using namespace std;

namespace creategl {
	
	bbox::bbox(float left, float right, float bottom, float top, float near, float far) :
		left(min(left, right)), right(max(left, right)),
		bottom(min(bottom, top)), top(max(bottom, top)),
		near(min(near, far)), far(max(near, far))
	{
		
	}
	
	
	bbox::bbox(glm::vec3 center, float width, float height, float depth)
	{
		const float halfWidth = width / 2;
		const float halfHeight = height / 2;
		const float halfDepth = depth / 2;
		
		left = center.x - halfWidth;
		right = center.x + halfWidth;
		bottom = center.y - halfHeight;
		top = center.y + halfHeight;
		near = center.z - halfDepth;
		far = center.z + halfDepth;
	}
	
	
	bbox::bbox(float width, float height, float depth) : bbox(glm::vec3(0.0), width, height, depth)
	{
		
	}
	
	
	bbox::bbox() : bbox(0, 0, 0, 0, 0, 0) {}
	
	
	bbox::~bbox () {}
	
	
	float bbox::getWidth()
	{
		return abs(right - left);
	}
	
	
	float bbox::getHeight()
	{
		return abs(top - bottom);
	}
	
	
	float bbox::getDepth()
	{
		return abs(far - near);
	}
	
	
	glm::vec3 bbox::getCenter()
	{
		return glm::vec3((right - left) / 2, (top - bottom) / 2, (far - near) / 2);
	}
}
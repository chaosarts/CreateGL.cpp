//
//  BoundingBox.cpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "BoundingBox.hpp"

namespace creategl {
	
	BoundingBox::BoundingBox(float left, float right, float bottom, float top, float near, float far) :
		left(min(left, right)), right(max(left, right)),
		bottom(min(bottom, top)), top(max(bottom, top)),
		near(min(near, far)), far(max(near, far))
	{
		
	}
	
	
	BoundingBox::BoundingBox(vec3 center, float width, float height, float depth) :
		BoundingBox(-width, width, )
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
	
	
	BoundingBox::BoundingBox(float width, float height, float depth) : BoundingBox(vec3(0.0), width, height, depth)
	{
		
	}
	
	
	BoundingBox::BoundingBox() : BoundingBox(0, 0, 0, 0, 0, 0) {}
	
	
	BoundingBox::~BoundingBox () {}
	
	
	float BoundingBox::getWidth()
	{
		return abs(right - left);
	}
	
	
	float BoundingBox::getHeight()
	{
		return abs(top - bottom);
	}
	
	
	float BoundingBox::getDepth()
	{
		return abs(far - near);
	}
	
	
	vec3 BoundingBox::getCenter()
	{
		return vec3((right - left) / 2, (top - bottom) / 2, (far - near) / 2);
	}
}
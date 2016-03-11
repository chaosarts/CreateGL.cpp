//
//  Rotation.cpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "Rotation.hpp"

namespace creategl {	
	
	Rotation::Rotation (float rad, float x, float y, float z) : Rotation (rad, vec3(x, y, z))
	{
		
	}
	
	
	Rotation::Rotation (float rad, vec3 axis) : rad(rad), axis(axis)
	{
		
	}
	
	
	Rotation::~Rotation() {
		
	}
	
	
	mat4 Rotation::apply (mat4 matrix)
	{
		const float alpha = rad / 2;
		const float sinAlpha = sin(alpha);
		const quat quaternion = quat(axis.x * sinAlpha, axis.y * sinAlpha, axis.z * sinAlpha, cos(alpha));
		return mat4_cast(quaternion) * matrix;
	}
	
	
	mat4 Rotation::revert (mat4 matrix)
	{
		const float alpha = - (rad / 2);
		const float sinAlpha = sin(alpha);
		const quat quaternion = quat(axis.x * sinAlpha, axis.y * sinAlpha, axis.z * sinAlpha, cos(alpha));
		return mat4_cast(quaternion) * matrix;
	}
}
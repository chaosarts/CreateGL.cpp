//
//  Rotation.hpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef Rotation_hpp
#define Rotation_hpp

#include <stdio.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include "Transformation.hpp"

using namespace glm;

namespace creategl {
	struct Rotation : public Transformation
	{
	public:
		
		/** Provides the angle to rotate with */
		float rad;
		
		/** Provides the rotation axis */
		vec3 axis;
		
		/** Creates a rotation transformation */
		Rotation (float rad, float x, float y, float z);
		
		/** Creates a rotation transformation */
		Rotation (float rad, vec3 axis);
		
		/** Destroys the transformation */
		virtual ~Rotation ();
		
		/** Applies the transformation to the matrix */
		virtual mat4 apply (mat4 matrix);
		
		/** Discards the transformation */
		virtual mat4 revert (mat4 matrix);
	};
}
#endif /* Rotation_hpp */

//
//  Scaling.hpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef Scaling_hpp
#define Scaling_hpp

#include <stdio.h>
#include <glm/gtc/matrix_transform.hpp>
#include "Transformation.hpp"

using namespace glm;

namespace creategl {
	struct Scaling : public Transformation
	{
	public:
		/** Provides the scaling value of the transformation */
		vec3 scaling;
		
		/** Creates a new scaling transformtaion */
		Scaling(vec3 scaling);
		
		/** Creates a new scaling transformtaion */
		Scaling(float x, float y, float z);
		
		/** Destroys the transformation */
		virtual ~Scaling ();
		
		/** Applies the transformation */
		mat4 apply (mat4 matrix);
		
		/** Discards the transformation */
		virtual mat4 revert (mat4 matrix);
	};
}
#endif /* Scaling_hpp */

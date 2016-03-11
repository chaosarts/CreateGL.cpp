//
//  Translation.hpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef Translation_hpp
#define Translation_hpp

#include <stdio.h>
#include <glm/gtc/matrix_transform.hpp>
#include "Transformation.hpp"

using namespace glm;

namespace creategl {
	struct Translation : public Transformation
	{
	public:
		
		/** Provides the vector, that indicates in which direection to translate */
		vec3 position;
		
		/** Creates a new translate transformation */
		Translation(vec3 position);
		
		/** Creates a new translate transformation */
		Translation(float x, float y, float z);
		
		/** Destroys the transofrmation */
		virtual ~Translation ();
		
		/** Applies the transformation to according matrix */
		mat4 apply (mat4 matrix);
		
		/** Discards the transformation */
		virtual mat4 revert (mat4 matrix);
	};
}
#endif /* Translation_hpp */

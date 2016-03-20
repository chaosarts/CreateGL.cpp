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

namespace creategl {
	struct Translation : public Transformation
	{
	public:
		
		/** Provides the vector, that indicates in which direection to translate */
		glm::vec3 position;
		
		/** Creates a new translate transformation */
		Translation(glm::vec3 position);
		
		/** Creates a new translate transformation */
		Translation(float x, float y, float z);
		
		/** Destroys the transofrmation */
		virtual ~Translation ();
		
		/** Applies the transformation to according matrix */
		glm::mat4 apply (glm::mat4 matrix);
		
		/** Discards the transformation */
		virtual glm::mat4 revert (glm::mat4 matrix);
	};
}
#endif /* Translation_hpp */

//
//  Transformation.hpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef Transformation_hpp
#define Transformation_hpp

#include <stdio.h>
#include <glm/glm.hpp>

namespace creategl {
	struct Transformation
	{
	public:
		virtual ~Transformation () {};
		virtual glm::mat4 apply (glm::mat4 matrix) = 0;
		virtual glm::mat4 revert (glm::mat4 matrix) = 0;
	};
}

#endif /* Transformation_hpp */

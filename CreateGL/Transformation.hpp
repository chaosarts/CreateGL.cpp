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

using namespace glm;

namespace creategl {
	struct Transformation
	{
	public:
		virtual ~Transformation () {};
		virtual mat4 apply (mat4 matrix) = 0;
		virtual mat4 revert (mat4 matrix) = 0;
	};
}

#endif /* Transformation_hpp */

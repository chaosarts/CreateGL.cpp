//
//  geom.hpp
//  CreateGL
//
//  Created by Fu Lam Diep on 14.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef CreateGL_geom_h
#define CreateGL_geom_h

#include <glm/glm.hpp>
#include <ChaosGL/attrib.h>

namespace creategl
{
	template<typename T, glm::precision P = glm::highp>
	struct tgeom : public virtual tattrib_countable<glm::tvec3<T, P>>
	{
		
	};
}

#endif /* geom_h */

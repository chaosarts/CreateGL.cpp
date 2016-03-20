//
//  bbox.hpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef bbox_hpp
#define bbox_hpp

#include <stdio.h>
#include <glm/glm.hpp>

namespace creategl {
	struct bbox
	{

	public:
		
		/** Provides the lower x of the box */
		float left;
		
		/** Provides the upper x of the box */
		float right;
		
		/** Provides the lower y of the box */
		float bottom;
		
		/** Provides the upper y of the box */
		float top;
		
		/** Provides the lower z of the box */
		float near;
		
		/** Provides the upper z of the box */
		float far;
		
		/**
		 * Creates a new symetric bounding box around the center
		 * @param left
		 * @param right
		 * @param bottom
		 * @param top
		 * @param near
		 * @param far
		 */
		bbox(float left, float right, float bottom, float top, float near, float far);
		
		/**
		 * Creates a new symetric bounding box around the center
		 * @param center
		 * @param width
		 * @param height
		 * @param depth
		 */
		bbox(glm::vec3 center, float width, float height, float depth);
		
		/**
		 * Creates a new symetric bounding box around the center being zero
		 * @param width
		 * @param height
		 * @param depth
		 */
		bbox (float width, float height, float depth);
		
		
		/**
		 * Creates a new bounding box with no width, height and depth
		 */
		bbox ();
		
		
		/**
		 * Destroyes the bounding box
		 */
		virtual ~bbox ();
		
		
		float getWidth ();
		
		
		float getHeight ();
		
		
		float getDepth ();
		
		
		glm::vec3 getCenter ();
	};
}
#endif /* bbox_hpp */

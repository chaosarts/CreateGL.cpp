//
//  Shape.hpp
//  CreateGL
//
//  Created by Fu Lam Diep on 19.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef CreateGL_Shape_hpp
#define CreateGL_Shape_hpp

#include "DisplayObject.hpp"
#include <ChaosGL/Drawable.hpp>
#include <ChaosGL/geom.hpp>


namespace creategl
{
	class Shape : public virtual DisplayObject, public virtual chaosgl::Drawable
	{
	public:
		
		/**
		 * Creates a new shape with given geometry
		 * @param geometry: The geometry for the shape
		 */
		Shape (chaosgl::geom* geometry);
		
		
		/**
		 * Creates a new shape with empty geometry
		 */
		Shape ();
		
		
		/**
		 * Sets the geometry of this shape
		 * @param geometry
		 */
		chaosgl::geom* setGeometry (chaosgl::geom* geometry);
		
		
		/**
		 * Returns the
		 */
		chaosgl::geom* getGeometry ();
		
		
		/**
		 * Destroys the shape
		 */
		virtual ~Shape ();
		
	private:
		
		/** Provides the geometry of the shape */
		chaosgl::geom* _geometry;
	};
}

#endif /* Shape_hpp */

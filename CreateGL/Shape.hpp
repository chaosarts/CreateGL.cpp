//
//  Shape.hpp
//  CreateGL
//
//  Created by Fu Lam Diep on 11.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <ChaosGL/geom.hpp>
#include "DisplayObject.hpp"

namespace creategl {
	class Shape : public DisplayObject
	{
	private:
		
	public:
		
		/// Creates a new Shape object with an no geometry
		Shape ();
		
		
		/// Creates a new Shape object with given geometry
//		Shape (chaosgl::geom geometry);
		
		
		/// Destroys the Shape object
		virtual ~Shape ();
		
		
		/// Sets the geometry of the shape
//		void setGeometry (chaosgl::geom geometry);
		
		
		/// Returns the geometry of the shape
//		chaosgl::geom getGeometry ();
	};
}
#endif /* Shape_hpp */

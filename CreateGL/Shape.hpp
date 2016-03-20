//
//  Shape.hpp
//  CreateGL
//
//  Created by Fu Lam Diep on 11.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <glm/glm.hpp>
#include <ChaosGL/geom.hpp>
#include "DisplayObject.hpp"
#include "bbox.hpp"

namespace creategl {
	template<typename T = float, glm::precision P = glm::defaultp>
	class Shape : public DisplayObject
	{
	public:
		/** Describes its own type */
		typedef Shape<T, P> Self;
		
		/** Describes the type of the geomtry */
		typedef chaosgl::tgeom<T, P> GeometryType;
		
		/** Describes the vector type, which the geometry holds */
		typedef glm::tvec3<T, P> VectorType;
		
		/** Describes the value type, which the vector type holds */
		typedef T ValueType;
	private:
		
		/** Provides the geometry of this shape */
		GeometryType* _geometry;
		
	public:
		
		/** 
		 * Creates a new Shape object with an empty geometry
		 */
		Shape () : Shape (chaosgl::tgeom_list<T, P>()) {}
		
		
		/** 
		 * Creates a new Shape object with given geometry
		 * @param geometry
		 */
		Shape (GeometryType geometry)
		{
			setGeometry(geometry);
		}
		
		
		/**
		 * Destroys the Shape object
		 */
		virtual ~Shape ()
		{
			delete _geometry;
		};
		
		
		/**
		 * Sets the geometry of the shape
		 * @param geometry
		 */
		void setGeometry (GeometryType geometry)
		{
			_geometry = &geometry;
		}
		
		
		/**
		 * Returns the geometry of the shape
		 */
		const GeometryType getGeometry () const
		{
			return *_geometry;
		}
		
		
		/**
		 * Returns the bounding box of this shape
		 */
		virtual bbox getBounds () 
		{
			glm::tvec3<float> min = _geometry->getMinValues();
			glm::tvec3<float> max = _geometry->getMaxValues();
			return bbox(min.x, max.x, min.y, max.y, min.z, max.z);
		}
	};
}
#endif /* Shape_hpp */

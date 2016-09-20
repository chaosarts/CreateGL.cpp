//
//  Shape.cpp
//  CreateGL
//
//  Created by Fu Lam Diep on 19.04.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "Shape.hpp"

namespace creategl
{
	Shape::Shape (chaosgl::geom* geometry)
	{
		setGeometry(geometry);
	}
	
	
	Shape::Shape () : Shape(new chaosgl::geom_list())
	{
		
	}
	
	
	chaosgl::geom* Shape::setGeometry(chaosgl::geom *geometry)
	{
		chaosgl::geom* old = _geometry;
		_geometry = geometry;
		return old;
	}
	
	
	chaosgl::geom* Shape::getGeometry()
	{
		return _geometry;
	}
}
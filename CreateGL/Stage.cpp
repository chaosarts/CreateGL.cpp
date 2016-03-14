//
//  Stage.cpp
//  CreateGL
//
//  Created by Fu Lam Diep on 11.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "Stage.hpp"

namespace creategl {
	
	long Stage::addChild(creategl::DisplayObject *displayObject)
	{
		displayObject->_stage = this;
		return Container::addChild(displayObject);
	}
	
	
	DisplayObject* Stage::removeChild(long index)
	{
		DisplayObject* child = Container::removeChild(index);
		child->_stage = nullptr;
		return child;
	}
	
	
	long Stage::removeChild (DisplayObject* displayObject)
	{
		displayObject->_stage = nullptr;
		return Container::removeChild(displayObject);
	}
}
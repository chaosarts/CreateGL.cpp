//
//  CreateGL.cpp
//  CreateGL
//
//  Created by Fu Lam Diep on 21.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "CreateGL.hpp"

namespace creategl
{
	bool _initialized = false;
	
	bool init (int argc, const char** argv)
	{
		if (!_initialized)
		{
			chaosgl::init(argc, argv);
			_initialized = true;
		}
		
		return _initialized;
	}
}
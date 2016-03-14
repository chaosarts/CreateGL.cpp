//
//  Stage.hpp
//  CreateGL
//
//  Created by Fu Lam Diep on 11.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef Stage_hpp
#define Stage_hpp

#include <stdio.h>
#include "Container.hpp"
namespace creategl {
	class Stage : public Container
	{
	public:
		virtual long addChild (DisplayObject* displayObject);
		
		virtual DisplayObject* removeChild (long index);
		
		virtual long removeChild (DisplayObject* displayObject);
	};
}
#endif /* Stage_hpp */

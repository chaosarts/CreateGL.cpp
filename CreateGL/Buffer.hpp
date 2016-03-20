//
//  Buffer.hpp
//  CreateGL
//
//  Created by Fu Lam Diep on 18.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef CreateGL_Buffer_hpp
#define CreateGL_Buffer_hpp

#include <ChaosGL/Buffer.hpp>

namespace creategl {
	class Buffer : public chaosgl::Buffer
	{
	public:
		class Block;
		
	public:
		void buffer ();
		
		class Block {
			
		};
	};
}

#endif /* Buffer_hpp */

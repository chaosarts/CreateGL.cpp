//
//  TransformSequence.hpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef TransformSequence_hpp
#define TransformSequence_hpp

#include <stdio.h>
#include <list>
#include <stack>
#include <glm/glm.hpp>
#include "Transformation.hpp"

using namespace std;
using namespace glm;

namespace creategl {
	
	struct TransformSequence
	{
	private:
		
		/**
		 * Contains a queue of pending transformations
		 */
		list<Transformation*> _new;
		
		/**
		 * Contains a stack of processed transformations
		 */
		stack<Transformation*> _done;
		
		/**
		 * Contains a steack of undone transformations
		 */
		stack<Transformation*> _undone;
		
		
		/** Provides the transformation matrix */
		mat4 _cache = mat4(1.0);
		
	public:
		/**
		 * Returns the transformation matrix
		 */
		mat4 getMatrix ();
		
		/**
		 *
		 */
		void reset ();
		
		/**
		 * Adds a new transformation to the sequence
		 */
		void add (Transformation* transformation);
		
		/**
		 * Applies the last undone transformation
		 */
		void redo ();
		
		/**
		 * Discards the last transformation
		 */
		void undo ();
	};
}

#endif /* TransformSequence_hpp */

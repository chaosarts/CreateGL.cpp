//
//  Container.hpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef Container_hpp
#define Container_hpp

#include <stdio.h>
#include <vector>

#include "DisplayObject.hpp"

using namespace std;

namespace creategl {
	class Container : public virtual DisplayObject
	{
	private:
		
		/** Provides a list of display objects */
		vector<DisplayObject*> _children;
		
	public:
		/**
		 * Creates a new container object
		 */
		Container ();
		
		
		/**
		 * Destroys the container
		 */
		virtual ~Container ();
		
		
		/**
		 * Returns the bounding box of the container
		 */
		virtual BoundingBox getBounds ();
		
		
		/**
		 * Returns the count of children contained in this container
		 */
		long count ();
		
		
		/**
		 * Returns the list of children
		 */
		vector<DisplayObject*> getChildren ();
		
		
		/**
		 * @see DisplayObject::childAt
		 */
		DisplayObject* operator[](long index);
		
		
		/**
		 * Adds a new child to the container and returns the count of children
		 * @param displayObject
		 */
		long addChild (DisplayObject* displayObject);
		
		
		/**
		 * Returns the index of the child object if contained in this container, otherwise -1
		 * @param displayObject
		 */
		long indexOf (DisplayObject* displayObject);
		
		
		/**
		 * Returns the display object at given index or null, if index is out of bounce
		 * @param index
		 */
		DisplayObject* childAt (long index);
		
		
		/**
		 * Returns true if the child has been added to this container
		 * @param displayObject
		 */
		bool hasChild (DisplayObject* displayObject);
		
		
		/**
		 * Returns true if this container is the ancestor of the display object
		 * @param displayObject
		 */
		bool isAncestorOf (DisplayObject* displayObject);
		
		
		/**
		 * Removes the child at given index and returns it
		 * @param index
		 */
		DisplayObject* removeChild (long index);
		
		
		/**
		 * Removes the child from container and returns its index
		 * @param displayObject
		 */
		long removeChild (DisplayObject* displayObject);
	};
}
#endif /* Container_hpp */

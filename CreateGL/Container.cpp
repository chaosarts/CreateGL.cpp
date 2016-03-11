//
//  Container.cpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "Container.hpp"


namespace creategl {
	Container::Container () {}
	
	
	Container::~Container () {}
	
	
	long Container::count () {return _children.size();}
	
	
	vector<DisplayObject*> Container::getChildren ()
	{
		return _children;
	}
	
	
	BoundingBox Container::getBounds()
	{
		if (_boundingBoxIsDirty)
		{			
			vector<DisplayObject*>::iterator it = _children.begin();

			while (it != _children.end())
			{
				
			}
		}
		
		return _boundingBox;
	}
	
	
	DisplayObject* Container::operator[] (long index)
	{
		return childAt(index);
	}
	
	
	long Container::addChild (creategl::DisplayObject *displayObject)
	{
		if (Container* c = dynamic_cast<Container*>(displayObject))
			if (c == this || c->isAncestorOf(this)) return _children.size() - 1;
		
		_children.push_back(displayObject);
		return _children.size() - 1;
	}
	
	
	long Container::indexOf (creategl::DisplayObject *displayObject)
	{
		vector<DisplayObject*>::iterator it = _children.begin();
		long i = 0;
		while (it != _children.end())
		{
			if (*it == displayObject) return i;
			i++; it++;
		}
		return -1;
	}
	
	
	DisplayObject* Container::childAt (long index)
	{
		if (index < 0 || index > _children.size()) return nullptr;
		return _children.at(index);
	}
	
	
	bool Container::hasChild (creategl::DisplayObject *displayObject)
	{
		return indexOf(displayObject) >= 0;
	}
	
	
	bool Container::isAncestorOf (creategl::DisplayObject *displayObject)
	{
		DisplayObject* child = displayObject;
		while (child->_parent != nullptr || child->_parent != this) child = child->_parent;
		return child != nullptr;
	}
	
	
	long Container::removeChild(creategl::DisplayObject *displayObject)
	{
		long index = indexOf(displayObject);
		if (index < 0) return index;
		
		vector<DisplayObject*>::iterator it = (_children.begin() + index);
		_children.erase(it);
		
		return index;
	}
	
	
	DisplayObject* Container::removeChild(long index)
	{
		if (index < 0 || index > count()) return nullptr;
		
		DisplayObject* child = _children[index];
		vector<DisplayObject*>::iterator it = (_children.begin() + index);
		_children.erase(it);
		
		return child;
	}
}
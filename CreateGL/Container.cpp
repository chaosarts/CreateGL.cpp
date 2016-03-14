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
				BoundingBox box = (*it++)->getBounds();
				_boundingBox.left = std::min(_boundingBox.left, box.left);
				_boundingBox.right = std::max(_boundingBox.right, box.right);
				_boundingBox.bottom = std::min(_boundingBox.bottom, box.bottom);
				_boundingBox.top = std::max(_boundingBox.top, box.top);
				_boundingBox.near = std::min(_boundingBox.near, box.near);
				_boundingBox.far = std::max(_boundingBox.far, box.far);
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
		
		if (displayObject->_parent != nullptr)
			displayObject->_parent->removeChild(displayObject);
		
		displayObject->_parent = this;
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
		if (index < 0 || index >= _children.size()) return nullptr;
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
	
	
	DisplayObject* Container::removeChild(long index)
	{
		if (index < 0 || index >= count()) return nullptr;
		
		DisplayObject* child = _children[index];
		vector<DisplayObject*>::iterator it = (_children.begin() + index);
		_children.erase(it);
		
		return child;
	}
	
	
	long Container::removeChild(creategl::DisplayObject *displayObject)
	{
		long index = indexOf(displayObject);
		if (index < 0) return index;
		
		vector<DisplayObject*>::iterator it = (_children.begin() + index);
		_children.erase(it);
		
		return index;
	}
}
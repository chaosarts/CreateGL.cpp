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
	
	
	long Container::count () const {
		return _children.size();
	}
	
	
	vector<DisplayObject*> Container::getChildren () const
	{
		return _children;
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
	
	
	bbox Container::getBounds()
	{
		if (_bboxIsDirty)
		{
			vector<DisplayObject*>::iterator it = _children.begin();
			while (it != _children.end())
			{
				bbox box = (*it++)->getBounds();
				_bbox.left = std::min(_bbox.left, box.left);
				_bbox.right = std::max(_bbox.right, box.right);
				_bbox.bottom = std::min(_bbox.bottom, box.bottom);
				_bbox.top = std::max(_bbox.top, box.top);
				_bbox.near = std::min(_bbox.near, box.near);
				_bbox.far = std::max(_bbox.far, box.far);
			}
		}
		
		return _bbox;
	}
}
//
//  TransformSequence.cpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "TransformSequence.hpp"


namespace creategl {
	
	mat4 TransformSequence::getMatrix()
	{
		// Handle all new tranformations
		while (_new.size() > 0) {
			
			// Move transformation from new to done
			Transformation* transformation = _new.front();
			_new.pop_front();
			_done.push(transformation);
			
			// Apply transformation to cache matrix
			_cache = transformation->apply(_cache);
		}
		
		return _cache;
	}
	
	
	void TransformSequence::reset ()
	{
		_cache = mat4(1.0);
		_new.clear();
		
		while (!_undone.empty())
		{
			Transformation* t = _undone.top();
			_undone.pop();
			delete t;
		}
		
		while (!_done.empty())
		{
			Transformation* t = _done.top();
			_done.pop();
			delete t;
		}
	}
	
	
	void TransformSequence::add (creategl::Transformation *transformation)
	{
		// The undone stack must be cleared if a new transformation is added
		while (_undone.size() > 0)
		{
			Transformation* t = _undone.top();
			_undone.pop();
			delete t;
		}
		
		_new.push_back(transformation);
	}
	
	
	void TransformSequence::redo ()
	{
		if (_undone.size() == 0) return;
		
		Transformation* transformation = _undone.top();
		_undone.pop();
		
		if (_new.size() > 0)
		{
			_new.push_back(transformation);
		}
		else
		{
			_done.push(transformation);
			_cache = transformation->apply(_cache);
		}
	}
	
	
	void TransformSequence::undo ()
	{
		// Determine if undo from pending (_new) list
		// or from processed (_done) stack
		
		if (_new.size() > 0)
		{
			Transformation* transformation = _new.back();
			_new.pop_back();
			_undone.push(transformation);
		}
		
		else if (_done.size())
		{
			Transformation* transformation = _done.top();
			_done.pop();
			_undone.push(transformation);
			
			// Nedds to reverted from cache since it has been applied
			_cache = transformation->revert(_cache);
		}
	}
}
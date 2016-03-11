//
//  DisplayObject.cpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "DisplayObject.hpp"

namespace creategl {
	DisplayObject::~DisplayObject ()
	{
		
	}
	
	
	mat4 DisplayObject::getTranslationMatrix ()
	{
		if (_translationIsDirty)
		{
			_translationMatrixCache = translate(mat4(1.0), _position);
			_translationIsDirty = false;
		}
		
		return _translationMatrixCache;
	}
	
	
	mat4 DisplayObject::getRotationMatrix ()
	{
		if (_rotationIsDirty)
		{
			_rotationMatrixCache = mat4_cast(_rotation);
			_rotationIsDirty = false;
		}
		
		return _rotationMatrixCache;
	}
	
	
	mat4 DisplayObject::getScalingMatrix()
	{
		if (_scalingIsDirty)
		{
			_scalingMatrixCache = scale(mat4(1.0), _scaling);
			_scalingIsDirty = false;
		}
		
		return _scalingMatrixCache;
	}
	
	
	mat4 DisplayObject::getTransformationMatrix ()
	{
		if (_translationIsDirty || _rotationIsDirty || _scalingIsDirty)
		{
			_transformMatrixCache = getTranslationMatrix() * getRotationMatrix() * getScalingMatrix();
		}
		
		return _transformMatrixCache;
	}
	
	
	vec3 DisplayObject::getPosition()
	{
		return _position;
	}
	
	
	vec3 DisplayObject::moveTo (vec3 position)
	{
		// Prevent to set cache dirty
		if (_position == position) return vec3(0);
		vec3 rel = position - _position;
		_position = position;
		_translationIsDirty = true;
		return rel;
	}
	
	
	vec3 DisplayObject::moveTo (float x, float y, float z)
	{
		return moveTo(vec3(x, y, z));
	}
	
	
	vec3 DisplayObject::moveBy(vec3 movement)
	{
		_position += movement;
		_translationIsDirty = true;
		return _position;
	}
	
	
	vec3 DisplayObject::moveBy (float x, float y, float z)
	{
		return moveBy(vec3(x, y, z));
	}
	
	
	quat DisplayObject::getRotationQuaternion ()
	{
		return _rotation;
	}
	
	
	void DisplayObject::setRotationQuaternion (quat rotation)
	{
		// Prevent to set cache dirty
		if (_rotation == rotation) return;
		_rotation = normalize(rotation);
		_rotationIsDirty = true;
	}
	
	
	vec3 DisplayObject::getRotationAxis ()
	{
		const float sinAlpha = sin(getRotation());
		return vec3(_rotation.x / sinAlpha, _rotation.y / sinAlpha, _rotation.z / sinAlpha);
	}
	
	
	float DisplayObject::getRotation()
	{
		return acos(_rotation.w) * 2.0;
	}
	
	
	void DisplayObject::setRotation(float angle, vec3 axis)
	{
		vec3 normalized = normalize(axis);
		float alpha = angle / 2.0;
		float sinAlpha = sin(alpha);
		setRotationQuaternion(quat(normalized.x * sinAlpha, normalized.y * sinAlpha, normalized.z * sinAlpha, cos(alpha)));
	}
	
	
	quat DisplayObject::rotate (float angle, vec3 axis)
	{
		const vec3 normalized = normalize(axis);
		const float alpha = angle / 2.0;
		const float sinAlpha = sin(alpha);
		const quat rotation = quat(normalized.x * sinAlpha, normalized.y * sinAlpha, normalized.z * sinAlpha, cos(alpha));
		setRotationQuaternion(normalize(_rotation * rotation));
		return _rotation;
	}
	
	
	quat DisplayObject::rotate (float angle, float x, float y, float z)
	{
		return rotate(angle, vec3(x, y, z));
	}
	
	
	quat DisplayObject::rotateX (float angle)
	{
		return rotate(angle, vec3(1, 0, 0));
	}
	
	
	quat DisplayObject::rotateY (float angle)
	{
		return rotate(angle, vec3(0, 1, 0));
	}
	
	
	quat DisplayObject::rotateZ (float angle)
	{
		return rotate(angle, vec3(0, 0, 1));
	}
}
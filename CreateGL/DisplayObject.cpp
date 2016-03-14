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
	
	
	glm::mat4 DisplayObject::getTranslationMatrix ()
	{
		if (_translationIsDirty)
		{
			_translationMatrixCache = translate(glm::mat4(1.0), _position);
			_translationIsDirty = false;
		}
		
		return _translationMatrixCache;
	}
	
	
	glm::mat4 DisplayObject::getRotationMatrix ()
	{
		if (_rotationIsDirty)
		{
			_rotationMatrixCache = mat4_cast(_rotation);
			_rotationIsDirty = false;
		}
		
		return _rotationMatrixCache;
	}
	
	
	glm::mat4 DisplayObject::getScalingMatrix()
	{
		if (_scalingIsDirty)
		{
			_scalingMatrixCache = scale(glm::mat4(1.0), _scaling);
			_scalingIsDirty = false;
		}
		
		return _scalingMatrixCache;
	}
	
	
	glm::mat4 DisplayObject::getTransformationMatrix ()
	{
		if (_translationIsDirty || _rotationIsDirty || _scalingIsDirty)
		{
			_transformMatrixCache = getTranslationMatrix() * getRotationMatrix() * getScalingMatrix();
		}
		
		return _transformMatrixCache;
	}
	
	
	glm::vec3 DisplayObject::getPosition()
	{
		return _position;
	}
	
	
	glm::vec3 DisplayObject::moveTo (glm::vec3 position)
	{
		// Prevent to set cache dirty
		if (_position == position) return glm::vec3(0);
		glm::vec3 rel = position - _position;
		_position = position;
		_translationIsDirty = true;
		return rel;
	}
	
	
	glm::vec3 DisplayObject::moveTo (float x, float y, float z)
	{
		return moveTo(glm::vec3(x, y, z));
	}
	
	
	glm::vec3 DisplayObject::moveBy(glm::vec3 movement)
	{
		_position += movement;
		_translationIsDirty = true;
		return _position;
	}
	
	
	glm::vec3 DisplayObject::moveBy (float x, float y, float z)
	{
		return moveBy(glm::vec3(x, y, z));
	}
	
	
	glm::quat DisplayObject::getRotationQuaternion ()
	{
		return _rotation;
	}
	
	
	void DisplayObject::setRotationQuaternion (glm::quat rotation)
	{
		// Prevent to set cache dirty
		if (_rotation == rotation) return;
		_rotation = normalize(rotation);
		_rotationIsDirty = true;
	}
	
	
	glm::vec3 DisplayObject::getRotationAxis ()
	{
		const float sinAlpha = sin(getRotation());
		return glm::vec3(_rotation.x / sinAlpha, _rotation.y / sinAlpha, _rotation.z / sinAlpha);
	}
	
	
	float DisplayObject::getRotation()
	{
		return acos(_rotation.w) * 2.0;
	}
	
	
	void DisplayObject::setRotation(float angle, glm::vec3 axis)
	{
		glm::vec3 normalized = normalize(axis);
		float alpha = angle / 2.0;
		float sinAlpha = sin(alpha);
		setRotationQuaternion(glm::quat(normalized.x * sinAlpha, normalized.y * sinAlpha, normalized.z * sinAlpha, cos(alpha)));
	}
	
	
	glm::quat DisplayObject::rotate (float angle, glm::vec3 axis)
	{
		const glm::vec3 normalized = normalize(axis);
		const float alpha = angle / 2.0;
		const float sinAlpha = sin(alpha);
		const glm::quat rotation = glm::quat(normalized.x * sinAlpha, normalized.y * sinAlpha, normalized.z * sinAlpha, cos(alpha));
		setRotationQuaternion(normalize(_rotation * rotation));
		return _rotation;
	}
	
	
	glm::quat DisplayObject::rotate (float angle, float x, float y, float z)
	{
		return rotate(angle, glm::vec3(x, y, z));
	}
	
	
	glm::quat DisplayObject::rotateX (float angle)
	{
		return rotate(angle, glm::vec3(1, 0, 0));
	}
	
	
	glm::quat DisplayObject::rotateY (float angle)
	{
		return rotate(angle, glm::vec3(0, 1, 0));
	}
	
	
	glm::quat DisplayObject::rotateZ (float angle)
	{
		return rotate(angle, glm::vec3(0, 0, 1));
	}
}
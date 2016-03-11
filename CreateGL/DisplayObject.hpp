//
//  DisplayObject.hpp
//  CreateGL
//
//  Created by Fu Lam Diep on 10.03.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef DisplayObject_hpp
#define DisplayObject_hpp

#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

#include "BoundingBox.hpp"

using namespace glm;
using namespace glm;

namespace creategl {
	class Container;
	
	class DisplayObject
	{
		friend class Container;
	private:
		
		/** Indicates if the transformation needs an update */
		bool _translationIsDirty = false;
		
		/** Indicates if the rotation needs an update */
		bool _rotationIsDirty = false;
		
		/** Indicates if the scaling needs an update */
		bool _scalingIsDirty = false;
		
		/** Provides the parent container */
		Container* _parent = nullptr;
		
		/** Provides the position of the object */
		vec3 _position = vec3(0);
		
		/** Provides the rotation of the object */
		quat _rotation = quat(1.0, 0.0, 0.0, 0.0);
		
		/** Provides the scaling for each dimension */
		vec3 _scaling = vec3(1.0, 1.0, 1.0);
		
		/** Provids the reference point to relate to for transformation */
		vec3 _reference = vec3(0);
		
		/** Caches the translation matrix */
		mat4 _translationMatrixCache = mat4(1.0);
		
		/** Caches the rotation matrix */
		mat4 _rotationMatrixCache = mat4(1.0);
		
		/** Caches the scaling matrix */
		mat4 _scalingMatrixCache = mat4(1.0);
		
		/** Caches the complete transformation matrix */
		mat4 _transformMatrixCache = mat4(1.0);
		
	protected:
		
		/** Provides the bounding box */
		BoundingBox _boundingBox = BoundingBox();
		
		/** Indicates, whether the box is obsolete or not */
		bool _boundingBoxIsDirty = false;
		
	public:
		
		/**
		 * Destructor
		 */
		virtual ~DisplayObject ();
		
		
		/**
		 * Returns the bounding box
		 * @return The bounding box of the object
		 */
		virtual BoundingBox getBounds () = 0;
		
		
		/**
		 * Returns the translation matrix according to performed rotation
		 * on this display object
		 */
		mat4 getTranslationMatrix ();
		
		
		/**
		 * Returns the rotation matrix according to performed rotation
		 * on this display object
		 */
		mat4 getRotationMatrix ();
		
		
		/**
		 * Returns the scaling matrix according to performed rotation
		 * on this display object
		 */
		mat4 getScalingMatrix ();
		
		
		/**
		 * Returns the transformation matrix
		 */
		mat4 getTransformationMatrix ();
		
		
		/**
		 * Returns the position of the object
		 */
		vec3 getPosition ();
		
		
		/**
		 * Moves the object relative to parent object and returns the relative position
		 * to its previous position.
		 * @param position
		 * @return The movement relative to prev pos
		 */
		vec3 moveTo (vec3 position);
		
		
		/**
		 * Moves the object relative to parent object and returns the relative position
		 * to its previous position within the parent scope.
		 * @param x The x coordinate
		 * @param y The y coordinate
		 * @param z The z coordinate
		 * @return The realtive movement to the previous position
		 */
		vec3 moveTo (float x, float y, float z);
		
		
		/**
		 * Moves the object relative to its current position and returns the resulting
		 * absolute position.
		 * @param movement The relative movement to the current position
		 * @return The new absolute pos
		 */
		vec3 moveBy (vec3 movement);
		
		
		/**
		 * Moves the object relative to its current position and returns the resulting
		 * absolute position within the parent scope.
		 * @param x The x coordinate
		 * @param y The y coordinate
		 * @param z The z coordinate
		 * @return The realtive movement to the previous position
		 */
		vec3 moveBy (float x, float y, float z);
		
		
		/**
		 * Returns the rotation quaterion
		 */
		quat getRotationQuaternion ();
		
		
		/**
		 * Sets the rotation directly by a quaternion
		 */
		void setRotationQuaternion (quat rotation);
		
		
		/**
		 * Returns the current rotation axis
		 */
		vec3 getRotationAxis ();
		
		
		/**
		 * Returns the current rotation
		 */
		float getRotation ();
		
		
		/**
		 * Sets the rotation of the object absolute
		 */
		void setRotation (float rad, vec3 axis);
		
		
		/**
		 * Rotates the object around the given axis by given angle in rad
		 */
		quat rotate (float rad, vec3 axis);
		
		
		/**
		 * Rotates the object around the given axis by given angle in rad
		 */
		quat rotate (float rad, float x, float y, float z);
		
		
		/**
		 * Rotates the object around the x axis by given angle in rad
		 */
		quat rotateX (float rad);
		
		
		/**
		 * Rotates the object around the x axis by given angle in rad
		 */
		quat rotateY (float rad);
		
		
		/**
		 * Rotates the object around the x axis by given angle in rad
		 */
		quat rotateZ (float rad);
	};
}

#endif /* DisplayObject_hpp */

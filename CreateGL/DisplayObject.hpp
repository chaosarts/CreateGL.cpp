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

namespace creategl {
	class Container;
	class Stage;
	
	class DisplayObject
	{
		friend class Container;
		friend class Stage;
	private:
		
		/** Indicates if the transformation needs an update */
		bool _translationIsDirty = false;
		
		/** Indicates if the rotation needs an update */
		bool _rotationIsDirty = false;
		
		/** Indicates if the scaling needs an update */
		bool _scalingIsDirty = false;
		
		/** Provides the parent container */
		Container* _parent = nullptr;
		
		/** Provides the stage in which the */
		Stage* _stage = nullptr;
		
		/** Provides the position of the object */
		glm::vec3 _position = glm::vec3(0);
		
		/** Provides the rotation of the object */
		glm::quat _rotation = glm::quat(1.0, 0.0, 0.0, 0.0);
		
		/** Provides the scaling for each dimension */
		glm::vec3 _scaling = glm::vec3(1.0, 1.0, 1.0);
		
		/** Provids the reference point to relate to for transformation */
		glm::vec3 _reference = glm::vec3(0);
		
		/** Caches the translation matrix */
		glm::mat4 _translationMatrixCache = glm::mat4(1.0);
		
		/** Caches the rotation matrix */
		glm::mat4 _rotationMatrixCache = glm::mat4(1.0);
		
		/** Caches the scaling matrix */
		glm::mat4 _scalingMatrixCache = glm::mat4(1.0);
		
		/** Caches the complete transformation matrix */
		glm::mat4 _transformMatrixCache = glm::mat4(1.0);
		
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
		glm::mat4 getTranslationMatrix ();
		
		
		/**
		 * Returns the rotation matrix according to performed rotation
		 * on this display object
		 */
		glm::mat4 getRotationMatrix ();
		
		
		/**
		 * Returns the scaling matrix according to performed rotation
		 * on this display object
		 */
		glm::mat4 getScalingMatrix ();
		
		
		/**
		 * Returns the transformation matrix
		 */
		glm::mat4 getTransformationMatrix ();
		
		
		/**
		 * Returns the position of the object
		 */
		glm::vec3 getPosition ();
		
		
		/**
		 * Moves the object relative to parent object and returns the relative position
		 * to its previous position.
		 * @param position
		 * @return The movement relative to prev pos
		 */
		glm::vec3 moveTo (glm::vec3 position);
		
		
		/**
		 * Moves the object relative to parent object and returns the relative position
		 * to its previous position within the parent scope.
		 * @param x The x coordinate
		 * @param y The y coordinate
		 * @param z The z coordinate
		 * @return The realtive movement to the previous position
		 */
		glm::vec3 moveTo (float x, float y, float z);
		
		
		/**
		 * Moves the object relative to its current position and returns the resulting
		 * absolute position.
		 * @param movement The relative movement to the current position
		 * @return The new absolute pos
		 */
		glm::vec3 moveBy (glm::vec3 movement);
		
		
		/**
		 * Moves the object relative to its current position and returns the resulting
		 * absolute position within the parent scope.
		 * @param x The x coordinate
		 * @param y The y coordinate
		 * @param z The z coordinate
		 * @return The realtive movement to the previous position
		 */
		glm::vec3 moveBy (float x, float y, float z);
		
		
		/**
		 * Returns the rotation glm::quaterion
		 */
		glm::quat getRotationQuaternion ();
		
		
		/**
		 * Sets the rotation directly by a glm::quaternion
		 */
		void setRotationQuaternion (glm::quat rotation);
		
		
		/**
		 * Returns the current rotation axis
		 */
		glm::vec3 getRotationAxis ();
		
		
		/**
		 * Returns the current rotation
		 */
		float getRotation ();
		
		
		/**
		 * Sets the rotation of the object absolute
		 */
		void setRotation (float rad, glm::vec3 axis);
		
		
		/**
		 * Rotates the object around the given axis by given angle in rad
		 */
		glm::quat rotate (float rad, glm::vec3 axis);
		
		
		/**
		 * Rotates the object around the given axis by given angle in rad
		 */
		glm::quat rotate (float rad, float x, float y, float z);
		
		
		/**
		 * Rotates the object around the x axis by given angle in rad
		 */
		glm::quat rotateX (float rad);
		
		
		/**
		 * Rotates the object around the x axis by given angle in rad
		 */
		glm::quat rotateY (float rad);
		
		
		/**
		 * Rotates the object around the x axis by given angle in rad
		 */
		glm::quat rotateZ (float rad);
	};
}

#endif /* DisplayObject_hpp */

#ifndef FAGL_ROTATION_H
#define FAGL_ROTATION_H

#include "CommonInclude.h"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include "BasicTypes.h"

namespace fagl {
	glm::quat Turn(const glm::vec3 axis, const float angle);
	glm::quat Turn(const glm::vec3 baseAxis, const float angle, const glm::quat currentRotation);

	glm::vec3 TurnPoint(const glm::vec3 point, const glm::vec3 axis, const float angle);
	glm::vec3 TurnPoint(const glm::vec3 point, const glm::vec3 baseAxis, const float angle, const glm::quat currentRotation);
	
	class Rotation_Manager {
		protected:
			glm::vec3 BaseUpVec;
			glm::vec3 BaseGazeVec;
			glm::vec3 BaseRightVec;
			glm::quat currentRotation;

		public:

			void TurnBase(const glm::vec3 baseAxis, const float angle);
			void TurnBase(const CAMERA_VECTOR baseAxis, const float angle);

			void Turn(const glm::vec3 axis, const float angle);
			void Turn(const CAMERA_VECTOR axis, const float angle);

			void RollBase(const float angle);
			void PitchBase(const float angle);
			void YawBase(const float angle);

			void Roll(const float angle);
			void Pitch(const float angle);
			void Yaw(const float angle);

			glm::quat GetCurrentRotation() const;

			glm::vec3 GetUpAxis() const;
			glm::vec3 GetGazeAxis() const;
			glm::vec3 GetRightAxis() const;

			glm::vec3 GetBaseUpAxis() const;
			glm::vec3 GetBaseGazeAxis() const;
			glm::vec3 GetBaseRightAxis() const;

			glm::vec3 GetAxis(const CAMERA_VECTOR axis) const;
			glm::vec3 GetBaseAxis(const CAMERA_VECTOR axis) const;

			glm::vec3 Rotate(const glm::vec3 point) const;
			glm::mat4 GetRotationMatrix() const;

			Rotation_Manager(const glm::vec3 up, const glm::vec3 gaze);
			Rotation_Manager(const glm::vec3 up, const glm::vec3 gaze, const glm::vec3 right);

			Rotation_Manager(const glm::vec3 up, const glm::vec3 gaze, const glm::quat rotation);
			Rotation_Manager(const glm::vec3 up, const glm::vec3 gaze, const glm::vec3 right, const glm::quat rotation);

			Rotation_Manager(const glm::vec3 up, const glm::vec3 gaze, const float xRot, const float yRot, const float zRot);
			Rotation_Manager(const glm::vec3 up, const glm::vec3 gaze, const glm::vec3 right, const float xRot, const float yRot, const float zRot);
	};
}

#include "Rotation.inl"

#endif
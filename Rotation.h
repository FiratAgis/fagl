#ifndef FAGL_ROTATION_H
#define FAGL_ROTATION_H

#include "FAGL.h"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include "BasicTypes.h"

namespace fagl {
	/// <summary>
	/// Create a rotation quaternion around an axis.
	/// </summary>
	/// <param name="axis"> Axis.</param>
	/// <param name="angle"> Turn angle in degrees.</param>
	/// <returns> Rotation quaternion.</returns>
	glm::quat Turn(const glm::vec3 axis, const float angle);

	/// <summary>
	/// Modify an axis using a rotation quaternion and create a rotation quaternion around that axis.
	/// </summary>
	/// <param name="baseAxis"> Original axis.</param>
	/// <param name="angle"> Turn angle in degrees.</param>
	/// <param name="currentRotation"> Starting rotation quaternion.</param>
	/// <returns> Rotation quaternion.</returns>
	glm::quat Turn(const glm::vec3 baseAxis, const float angle, const glm::quat currentRotation);

	/// <summary>
	/// Rotate a point around an axis.
	/// </summary>
	/// <param name="point"> Original point.</param>
	/// <param name="axis"> Axis.</param>
	/// <param name="angle"> Turn angle in degrees.</param>
	/// <returns> The rotated point.</returns>
	glm::vec3 TurnPoint(const glm::vec3 point, const glm::vec3 axis, const float angle);

	/// <summary>
	/// Modify an axis using a rotation quaternion and rotate a point around that axis.
	/// </summary>
	/// <param name="point"> Original point.</param>
	/// <param name="baseAxis"> Original axis.</param>
	/// <param name="angle"> Turn angle in degrees.</param>
	/// <param name="currentRotation"> Starting rotation quaternion.</param>
	/// <returns> The rotated point.</returns>
	glm::vec3 TurnPoint(const glm::vec3 point, const glm::vec3 baseAxis, const float angle, const glm::quat currentRotation);
	
	class Rotation_Manager {
		protected:
			glm::vec3 BaseUpVec;
			glm::vec3 BaseGazeVec;
			glm::vec3 BaseRightVec;
			glm::quat currentRotation;

		public:
			/// <summary>
			/// Turn around the unmodified axis.
			/// </summary>
			/// <param name="baseAxis"> Axis</param>
			/// <param name="angle"> Turn angle in degrees.</param>
			void TurnBase(const glm::vec3 baseAxis, const float angle);

			/// <summary>
			/// Turn around the unmodified axis.
			/// </summary>
			/// <param name="baseAxis"> Axis</param>
			/// <param name="angle"> Turn angle in degrees.</param>
			void TurnBase(const CAMERA_VECTOR baseAxis, const float angle);

			/// <summary>
			/// Turn around the axis after it modified according to current rotation.
			/// </summary>
			/// <param name="axis"> Axis</param>
			/// <param name="angle"> Turn angle in degrees.</param>
			void Turn(const glm::vec3 axis, const float angle);

			/// <summary>
			/// Turn around the axis after it modified according to current rotation.
			/// </summary>
			/// <param name="axis"> Axis</param>
			/// <param name="angle"> Turn angle in degrees.</param>
			void Turn(const CAMERA_VECTOR axis, const float angle);

			/// <summary>
			/// Roll around the original gaze vector.
			/// </summary>
			/// <param name="angle"> Turn angle in degrees.</param>
			void RollBase(const float angle);

			/// <summary>
			/// Roll around the original right vector.
			/// </summary>
			/// <param name="angle"> Turn angle in degrees.</param>
			void PitchBase(const float angle);

			/// <summary>
			/// Roll around the original up vector.
			/// </summary>
			/// <param name="angle"> Turn angle in degrees.</param>
			void YawBase(const float angle);

			/// <summary>
			/// Roll around the current gaze vector.
			/// </summary>
			/// <param name="angle"> Turn angle in degrees.</param>
			void Roll(const float angle);

			/// <summary>
			/// Roll around the current right vector.
			/// </summary>
			/// <param name="angle"> Turn angle in degrees.</param>
			void Pitch(const float angle);

			/// <summary>
			/// Roll around the current up vector.
			/// </summary>
			/// <param name="angle"> Turn angle in degrees.</param>
			void Yaw(const float angle);

			/// <summary>
			/// Get current rotation quaternion.
			/// </summary>
			/// <returns> Current rotation quaternion.</returns>
			glm::quat GetCurrentRotation() const;

			/// <summary>
			/// Get current up vector.
			/// </summary>
			/// <returns> Current up vector.</returns>
			glm::vec3 GetUpAxis() const;

			/// <summary>
			/// Get current gaze vector.
			/// </summary>
			/// <returns> Current gaze vector.</returns>
			glm::vec3 GetGazeAxis() const;

			/// <summary>
			/// Get current right vector.
			/// </summary>
			/// <returns> Current right vector.</returns>
			glm::vec3 GetRightAxis() const;

			/// <summary>
			/// Get original up vector.
			/// </summary>
			/// <returns> Original up vector.</returns>
			glm::vec3 GetBaseUpAxis() const;

			/// <summary>
			/// Get original gaze vector.
			/// </summary>
			/// <returns> Original gaze vector.</returns>
			glm::vec3 GetBaseGazeAxis() const;

			/// <summary>
			/// Get original right vector.
			/// </summary>
			/// <returns> Original right vector.</returns>
			glm::vec3 GetBaseRightAxis() const;

			/// <summary>
			/// Get the current value of the axis.
			/// </summary>
			/// <param name="axis"> Axis.</param>
			/// <returns> Its current value.</returns>
			glm::vec3 GetAxis(const CAMERA_VECTOR axis) const;

			/// <summary>
			/// Get the original value of the axis.
			/// </summary>
			/// <param name="axis"> Axis.</param>
			/// <returns> Its original value.</returns>
			glm::vec3 GetBaseAxis(const CAMERA_VECTOR axis) const;

			/// <summary>
			/// Rotate a point according to current rotation.
			/// </summary>
			/// <param name="point"> The original point.</param>
			/// <returns> Its new value.</returns>
			glm::vec3 Rotate(const glm::vec3 point) const;

			/// <summary>
			/// Returns the rotation matrix that is equivalent to current rotation.
			/// </summary>
			/// <returns> Rotation matrix.</returns>
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
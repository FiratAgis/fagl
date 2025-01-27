namespace fagl {
	using glm::quat;
	using glm::vec3;

	inline quat Turn(const vec3 axis, const float angle)
	{
		return glm::angleAxis(angle, axis);
	}
	inline quat Turn(const vec3 baseAxis, const float angle, const quat currentRotation)
	{
		vec3 axis = currentRotation * baseAxis;
		return glm::angleAxis(angle, axis) * currentRotation;
	}

	inline vec3 TurnPoint(const vec3 point, const vec3 axis, const float angle)
	{
		return Turn(axis, angle) * point;
	}

	inline vec3 TurnPoint(const vec3 point, const vec3 baseAxis, const float angle, const quat currentRotation)
	{
		return Turn(baseAxis, angle, currentRotation) * point;
	}

	inline void Rotation_Manager::TurnBase(const vec3 baseAxis, const float angle) { currentRotation = glm::angleAxis(angle, baseAxis) * GetCurrentRotation(); }
	inline void Rotation_Manager::TurnBase(const CAMERA_VECTOR baseAxis, const float angle) { currentRotation = glm::angleAxis(angle, GetBaseAxis(baseAxis)) * GetCurrentRotation(); }

	inline void Rotation_Manager::Turn(const vec3 axis, const float angle) { currentRotation = glm::angleAxis(angle, Rotate(axis)) * GetCurrentRotation(); }
	inline void Rotation_Manager::Turn(const CAMERA_VECTOR axis, const float angle) { currentRotation = glm::angleAxis(angle, GetAxis(axis)) * GetCurrentRotation(); }

	inline void Rotation_Manager::RollBase(const float angle) { TurnBase(CAMERA_VECTOR::GAZE_VECTOR, angle); }
	inline void Rotation_Manager::PitchBase(const float angle) { TurnBase(CAMERA_VECTOR::RIGHT_VECTOR, angle); }
	inline void Rotation_Manager::YawBase(const float angle) { TurnBase(CAMERA_VECTOR::UP_VECTOR, angle); }

	inline void Rotation_Manager::Roll(const float angle) { Turn(CAMERA_VECTOR::GAZE_VECTOR, angle); }
	inline void Rotation_Manager::Pitch(const float angle) { Turn(CAMERA_VECTOR::RIGHT_VECTOR, angle); }
	inline void Rotation_Manager::Yaw(const float angle) { Turn(CAMERA_VECTOR::UP_VECTOR, angle); }

	inline quat Rotation_Manager::GetCurrentRotation() const { return currentRotation; }

	inline vec3 Rotation_Manager::GetUpAxis() const { return currentRotation * GetBaseUpAxis(); }
	inline vec3 Rotation_Manager::GetGazeAxis() const { return currentRotation * GetBaseGazeAxis(); }
	inline vec3 Rotation_Manager::GetRightAxis() const { return currentRotation * GetBaseRightAxis(); }

	inline vec3 Rotation_Manager::GetBaseUpAxis() const { return BaseUpVec; }
	inline vec3 Rotation_Manager::GetBaseGazeAxis() const { return BaseGazeVec; }
	inline vec3 Rotation_Manager::GetBaseRightAxis() const { return BaseRightVec; }

	inline vec3 Rotation_Manager::GetAxis(const CAMERA_VECTOR axis) const
	{
		switch (axis) {
		case CAMERA_VECTOR::GAZE_VECTOR:
			return GetGazeAxis();
		case CAMERA_VECTOR::RIGHT_VECTOR:
			return GetRightAxis();
		case CAMERA_VECTOR::UP_VECTOR:
			return GetUpAxis();
		}
		return vec3();
	}
	inline vec3 Rotation_Manager::GetBaseAxis(const CAMERA_VECTOR axis) const
	{
		switch (axis) {
		case CAMERA_VECTOR::GAZE_VECTOR:
			return GetBaseGazeAxis();
		case CAMERA_VECTOR::RIGHT_VECTOR:
			return GetBaseRightAxis();
		case CAMERA_VECTOR::UP_VECTOR:
			return GetBaseUpAxis();
		}
		return vec3();
	}

	inline vec3 Rotation_Manager::Rotate(vec3 point) const { return GetCurrentRotation() * point; }
	inline glm::mat4 Rotation_Manager::GetRotationMatrix() const { return glm::toMat4(GetCurrentRotation()); }


	inline Rotation_Manager::Rotation_Manager(const vec3 up, const vec3 gaze) : BaseUpVec(glm::normalize(up)), BaseGazeVec(glm::normalize(gaze)), BaseRightVec(glm::normalize(glm::cross(gaze, up))), currentRotation(glm::vec3(0, 0, 0)) { }
	inline Rotation_Manager::Rotation_Manager(const vec3 up, const vec3 gaze, const vec3 right) : BaseUpVec(glm::normalize(up)), BaseGazeVec(glm::normalize(gaze)), BaseRightVec(glm::normalize(right)), currentRotation(glm::vec3(0, 0, 0)) { }

	inline Rotation_Manager::Rotation_Manager(const vec3 up, const vec3 gaze, const quat rotation) : BaseUpVec(glm::normalize(up)), BaseGazeVec(glm::normalize(gaze)), BaseRightVec(glm::normalize(glm::cross(gaze, up))), currentRotation(rotation) { }
	inline Rotation_Manager::Rotation_Manager(const vec3 up, const vec3 gaze, const vec3 right, const quat rotation) : BaseUpVec(glm::normalize(up)), BaseGazeVec(glm::normalize(gaze)), BaseRightVec(glm::normalize(right)), currentRotation(rotation) { }

	inline Rotation_Manager::Rotation_Manager(const vec3 up, const vec3 gaze, const float xRot, const float yRot, const float zRot) : BaseUpVec(glm::normalize(up)), BaseGazeVec(glm::normalize(gaze)), BaseRightVec(glm::normalize(glm::cross(gaze, up))), currentRotation(glm::vec3(xRot, yRot, zRot)) { }
	inline Rotation_Manager::Rotation_Manager(const vec3 up, const vec3 gaze, const vec3 right, const float xRot, const float yRot, const float zRot) : BaseUpVec(glm::normalize(up)), BaseGazeVec(glm::normalize(gaze)), BaseRightVec(glm::normalize(right)), currentRotation(glm::vec3(xRot, yRot, zRot)) { }
}

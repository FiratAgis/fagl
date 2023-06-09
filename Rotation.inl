namespace fagl {
	using glm::quat;
	using glm::vec3;

	quat Turn(const vec3 axis, const float angle)
	{
		return glm::angleAxis(angle, axis);
	}
	quat Turn(const vec3 baseAxis, const float angle, const quat currentRotation)
	{
		vec3 axis = currentRotation * baseAxis;
		return glm::angleAxis(angle, axis) * currentRotation;
	}

	vec3 TurnPoint(const vec3 point, const vec3 axis, const float angle)
	{
		return Turn(axis, angle) * point;
	}

	vec3 TurnPoint(const vec3 point, const vec3 baseAxis, const float angle, const quat currentRotation)
	{
		return Turn(baseAxis, angle, currentRotation) * point;
	}

	void Rotation_Manager::TurnBase(const vec3 baseAxis, const float angle) { currentRotation = glm::angleAxis(angle, baseAxis) * GetCurrentRotation(); }
	void Rotation_Manager::TurnBase(const CAMERA_VECTOR baseAxis, const float angle) { currentRotation = glm::angleAxis(angle, GetBaseAxis(baseAxis)) * GetCurrentRotation(); }

	void Rotation_Manager::Turn(const vec3 axis, const float angle) { currentRotation = glm::angleAxis(angle, Rotate(axis)) * GetCurrentRotation(); }
	void Rotation_Manager::Turn(const CAMERA_VECTOR axis, const float angle) { currentRotation = glm::angleAxis(angle, GetAxis(axis)) * GetCurrentRotation(); }

	void Rotation_Manager::RollBase(const float angle) { TurnBase(CAMERA_VECTOR::GAZE_VECTOR, angle); }
	void Rotation_Manager::PitchBase(const float angle) { TurnBase(CAMERA_VECTOR::RIGHT_VECTOR, angle); }
	void Rotation_Manager::YawBase(const float angle) { TurnBase(CAMERA_VECTOR::UP_VECTOR, angle); }

	void Rotation_Manager::Roll(const float angle) { Turn(CAMERA_VECTOR::GAZE_VECTOR, angle); }
	void Rotation_Manager::Pitch(const float angle) { Turn(CAMERA_VECTOR::RIGHT_VECTOR, angle); }
	void Rotation_Manager::Yaw(const float angle) { Turn(CAMERA_VECTOR::UP_VECTOR, angle); }

	quat Rotation_Manager::GetCurrentRotation() const { return currentRotation; }

	vec3 Rotation_Manager::GetUpAxis() const { return currentRotation * GetBaseUpAxis(); }
	vec3 Rotation_Manager::GetGazeAxis() const { return currentRotation * GetBaseGazeAxis(); }
	vec3 Rotation_Manager::GetRightAxis() const { return currentRotation * GetBaseRightAxis(); }

	vec3 Rotation_Manager::GetBaseUpAxis() const { return BaseUpVec; }
	vec3 Rotation_Manager::GetBaseGazeAxis() const { return BaseGazeVec; }
	vec3 Rotation_Manager::GetBaseRightAxis() const { return BaseRightVec; }

	vec3 Rotation_Manager::GetAxis(const CAMERA_VECTOR axis) const
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
	vec3 Rotation_Manager::GetBaseAxis(const CAMERA_VECTOR axis) const
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

	vec3 Rotation_Manager::Rotate(vec3 point) const { return GetCurrentRotation() * point; }
	glm::mat4 Rotation_Manager::GetRotationMatrix() const { return glm::toMat4(GetCurrentRotation()); }


	Rotation_Manager::Rotation_Manager(const vec3 up, const vec3 gaze) : BaseUpVec(glm::normalize(up)), BaseGazeVec(glm::normalize(gaze)), BaseRightVec(glm::normalize(glm::cross(gaze, up))), currentRotation(glm::vec3(0, 0, 0)) { }
	Rotation_Manager::Rotation_Manager(const vec3 up, const vec3 gaze, const vec3 right) : BaseUpVec(glm::normalize(up)), BaseGazeVec(glm::normalize(gaze)), BaseRightVec(glm::normalize(right)), currentRotation(glm::vec3(0, 0, 0)) { }

	Rotation_Manager::Rotation_Manager(const vec3 up, const vec3 gaze, const quat rotation) : BaseUpVec(glm::normalize(up)), BaseGazeVec(glm::normalize(gaze)), BaseRightVec(glm::normalize(glm::cross(gaze, up))), currentRotation(rotation) { }
	Rotation_Manager::Rotation_Manager(const vec3 up, const vec3 gaze, const vec3 right, const quat rotation) : BaseUpVec(glm::normalize(up)), BaseGazeVec(glm::normalize(gaze)), BaseRightVec(glm::normalize(right)), currentRotation(rotation) { }

	Rotation_Manager::Rotation_Manager(const vec3 up, const vec3 gaze, const float xRot, const float yRot, const float zRot) : BaseUpVec(glm::normalize(up)), BaseGazeVec(glm::normalize(gaze)), BaseRightVec(glm::normalize(glm::cross(gaze, up))), currentRotation(glm::vec3(xRot, yRot, zRot)) { }
	Rotation_Manager::Rotation_Manager(const vec3 up, const vec3 gaze, const vec3 right, const float xRot, const float yRot, const float zRot) : BaseUpVec(glm::normalize(up)), BaseGazeVec(glm::normalize(gaze)), BaseRightVec(glm::normalize(right)), currentRotation(glm::vec3(xRot, yRot, zRot)) { }
}
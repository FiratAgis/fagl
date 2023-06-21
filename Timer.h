#ifndef FAGL_TIMER_H
#define FAGL_TIMER_H

#include "FAGL.h"
#include <map>

class Time_Manager {

	private:
		std::map<unsigned int, float> timestamps;
		float fpsLimit = 0.0f;
		bool fpsLimitEnabled = true;
		float* deltaTimePointer = NULL;
		unsigned int fpsTimer = 0;
	public:
		
		void UpdateTimeStamp(unsigned int i) {
			timestamps[i] = glfwGetTime();
		}
		float TimeSinceTimeStamp(unsigned int i) {
			return glfwGetTime() - timestamps[i];
		}
		float GetTimeStamp(unsigned int i) {
			return timestamps[i];
		}
		float TimeSinceStart() {
			return TimeSinceTimeStamp(0);
		}
		float TimeSinceFrame() {
			return TimeSinceTimeStamp(1);
		}
		float NewFrame() {
			float deltaTime = TimeSinceFrame();
			UpdateTimeStamp(1);
			return deltaTime;
		}
		float NewTimeStampPeriod(unsigned int i) {
			float deltaTime = TimeSinceTimeStamp(i);
			UpdateTimeStamp(i);
			return deltaTime;
		}
		void EnableFPSlimit(float frameRate, float* dTime, unsigned int timer_no = 2) {
			fpsLimitEnabled = true;
			fpsLimit = 1.0f / frameRate;
			deltaTimePointer = dTime;
			fpsTimer = timer_no;
			UpdateTimeStamp(fpsTimer);

		}
		bool IsNewFrame() {
			if (fpsLimitEnabled) {
				*deltaTimePointer = TimeSinceTimeStamp(fpsTimer);
				UpdateTimeStamp(fpsTimer);
				if (TimeSinceFrame() > fpsLimit) {
					NewFrame();
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		Time_Manager() {
			timestamps[0] = glfwGetTime();
			timestamps[1] = glfwGetTime();
		}
		Time_Manager(float frameRate, float* dTime, unsigned int timer_no = 2) {
			timestamps[0] = glfwGetTime();
			timestamps[1] = glfwGetTime();
			EnableFPSlimit(frameRate, dTime, timer_no);
		}
};

#endif

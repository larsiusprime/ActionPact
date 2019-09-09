#ifndef ACTIONPACT_ACTION_ANALOG
#define ACTIONPACT_ACTION_ANALOG

#include "types.h"

class ActionAnalog {

	public:
		void (*callback)(ActionAnalog * action);
	
		double x; // X-axis value, or the value of a single-axis analog input.
		double y; // Y-axis value. (If action only has single-axis input this is always 0
	
		ActionAnalog(char * name, void (*callback)(ActionAnalog * action));
		~ActionAnalog();
		
		void update();
		
		void add(InputAnalog * i);
		void addGamepad(int deviceID, int gamepadInputID, t_stateA trigger, t_axis axis);
		void addMousePosition(t_stateA trigger, t_axis axis);
		void addMouseClickAndDragMotionInput(
			t_mouseID mID,
			t_stateA trigger,
			t_axis axis,
			int pixelsPerUnit,
			float deadZone,
			bool invertY,
			bool invertX);
		
}

#endif /*ACTIONPACT_ACTION_ANALOG*/
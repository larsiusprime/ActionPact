#ifndef ACTIONPACT_INPUT
#define ACTIONPACT_INPUT

#include "types.h"

class Input {
	
	public:
		/* Digital or Analog */
		t_inputType type;
		
		/* Mouse, Keyboard, Gamepad, SteamInput, etc */
		t_device device;
		
		/* Backend handle */
		int deviceID;
		
		/* Input code (L/R mouse button, key code, etc) */
		int inputID;
		
		/* What state triggers this action (PRESSED, JUST_PRESSED, RELEASED, JUST_RELEASED) */
		t_state trigger;
		
		Input(t_inputType type, int deviceID, int inputID, t_state trigger);
		~Input();
		
		void update();
		bool check(Action * action);
}

class DigitalInput : public Input {
	
	public:
		
		DigitalInput();
		~DigitalInput();
		
		bool checkD(DigitalActoin * action);
}

class AnalogInput : public Input {
	
	public:
	
		AnalogInput();
		~AnalogInput();
		
		bool checkA(AnalogAction * action);
}

#endif /*ACTIONPACT_INPUT*/
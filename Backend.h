#ifndef ACTIONPACT_BACKEND
#define ACTIONPACT_BACKEND

#include "types.h"

class Backend {
	
	public:
		char * name;
		
		/* Call this function every frame for every digital input */
		void (updateDigital*)(t_device d, int deviceID, int inputID, bool pressed);
		
		/* Call this function every frame for every analog input */
		void (updateAnalog*)(t_device d, int deviceID, double inputID, t_axis axis);
		
		Backend(
			char * name,
			void (updateDigital*)(t_device d, int deviceID, int inputID, bool pressed),
			void (updateAnalog*)(t_device d, int deviceID, double inputID, t_axis axis)
		);
		
		~Backend();
}

#endif /*ACTIONPACT_BACKEND*/
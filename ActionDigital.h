#ifndef ACTIONPACT_ACTION_DIGITAL
#define ACTIONPACT_ACTION_DIGITAL

#include "types.h"

class ActionDigital : public Action{
	
	public:
		void (*callback)(ActionDigital * action); // call when this action fires
		
		ActionDigital(char * name, void (*callback)(ActionDigital * action));
		~ActionDigital();
		
		void add(InputDigital * i);
		bool check();
}

#endif /*ACTIONPACT_ACTION_DIGITAL*/
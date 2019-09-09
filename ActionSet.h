#ifndef ACTIONPACT_ACTION_SET
#define ACTIONPACT_ACTION_SET

#include "input.h"

class ActionSet {
	
	public:
		/* Name of the action set (e.g. "Menu", "Driving", "In-Game", etc) */
		char * name;
		
		/* A unique handle for this action set, used as a lookup key for any backend 
		 * specific handles (e.g. SDL, Steam Input).
		 */
		int handle;
		
		/* Digital actions in this set */
		ActionDigital * digitalActions;
		
		/* Analog actions in this set */
		ActionAnalog * analogActions;
		
		/* Whether this action set runs when update() is called */
		bool active;
		
		/* Creates an action set
		 *
		 * @param set       Pointer to the ActionSet you are initializing
		 * @param data      ActionSet definition file
		 * @param callbackD A function to call when digital actions fire
		 * @param callbackA A function to call when analog actions fire
		 *
		 */
		ActionSet(ActionSet * set, void * data, void (*callbackD)(ActionDigital * d), void (*callbackA)(ActionAnalog * a));
		~ActionSet();

		void addDigital(ActionDigital * action);
		void addAnalog(ActionAnalog * action);

		bool removeDigital(ActionDigital * action);
		bool removeAnalog(ActionAnalog * action);

		void update();

}

#endif /*ACTIONPACT_ACTION_SET*/
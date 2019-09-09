#ifndef ACTIONPACT_ACTION_SET_REGISTER
#define ACTIONPACT_ACTION_SET_REGISTER

#include "types.h"
#include <vector>

class ActionSetRegister {
	
	public:
		int mouseSet;
		int keyboardSet;
		int gamepadAllSet;
		int blackBoxAllSet;
		
		vector<int> gamepadSets;
		vector<int> blackBoxSets;
		
		ActionSetRegister();
		~ActionSetRegister();
		
		void activate(int set, t_device d, int deviceID);
		void markActiveSets(ActionSet * sets, int count);
		void update(ActionSet * sets, int count);
		
	private:
		void setActivate(int set, t_device d, int deviceID, bool doActivate);
		void updateBlackBox(vector<ActionSet> sets);
		void updateBlackBoxBindings(vector<ActionSet> sets);
		void updateBlackBoxDigitalActionBindings(DigitalAction * action, int deviceID, int setHandle);
		void updateBlackBoxAnalogActionBindings(AnalogAction * action, int deviceID, int setHandle);
		void updateBlackBoxInputs(vector<ActionSet> sets);
		
		void changeBlackBoxActionSet(int deviceHandle, int newSet, vector<ActionSet> sets);
		
		void syncDevice(t_device d, vector<ActionSet> sets);
		void clearSetFromVector(int set = -1, vector<int> vec);
		
		int cheapChecksum(vector<int> vec, int count);
}

#endif /*ACTIONPACT_ACTION_SET_REGISTER*/
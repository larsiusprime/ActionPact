#ifndef ACTIONPACT_ACTION_MANAGER
#define ACTIONPACT_ACTION_MANAGER

#include "types.h"
#include "Backend.h"

class ActionManager {
	
	public:
		
		//variables
			vector<Backend> backends;
			vector<ActionSet> sets;
			
			ActionSet defaultSet;
			
			//Callbacks:
			void (deviceDisconnected*)(t_device device, int deviceID);
			void (deviceConnected*)(t_device device, int deviceID);
			void (inputsChanged*)(vector<Action> actions);
		
		//methods
			ActionManager();
			~ActionManager();
			
			void update();
			
			void activateSet(int set, t_device device, int deviceID);
			void deactivateSet(int set, int deviceID);
			
			bool addAction(Action * action, int set);
			bool removeAction(Action * action, bool destroy);
			
			int addSet(ActionSet * set);
			bool removeSet(ActionSet * set, bool destroy);
			
			int getSetIndex(const char * name);
			const char * getSetName(int index);
			
			ActionSet * getSet(int index);
			ActionSet * getSetActivatedForDevice(t_device device, int deviceID);
			
	private:
		//variables
			ActionSetRegister reg;
		
		//methods
			void onChange();
			void onStateSwitched();
			void onDeviceConnected(t_device device, int deviceID);
			void onDeviceDisconnected(t_device device, int deviceID);
			
			void onBlackBoxConnected(int handle);
			void onBlackBoxDisconnected(int handle);
			void updateBlackBoxes();
			void updateBlackBoxInputs();
}

#endif /*ACTIONPACT_ACTION_MANAGER*/
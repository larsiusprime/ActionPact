#ifndef ACTIONPACT_ACTION
#define ACTIONPACT_ACTION

#include "input.h"
#include <vector>

class Action {
	
	public:
		t_inputType type;      //digital or analog
		char * name;
		int handle;            //unique identifier
		bool triggered;        //if true, take action in the game somehow
		
		vector<Input> inputs;  //inputs attached to this action
		
		bool blackBoxChanged;  //blackbox bindings have changed since last poll
		
		Action(t_inputType type, char * name);
		~Action();
		void removeAll(destroy:bool=true);
		void remove(Input * i, destroy:bool=false);
		
		bool check();  // See if this action has just been triggered
		void update(); // Check inputs & fire callbacks if anything triggers
		bool match(Action * other); // Check if it is the same name & handle
		
	protected:
		double x;
		double y;
		
		int timestamp;
		bool checked;
		
		void addGeneric(Input * i);
		bool hasInput(Input * i);
}

#endif /*ACTIONPACT_ACTION*/
#ifndef ACTIONPACT_MANAGER
#define ACTIONPACT_MANAGER

#include "types.h"

ActionSetManager data;

int init(t_backend backend);

/**
 * Activate an action set for a particular device
 * @param	set			The integer ID for the Action Set you want to activate
 * @param	deviceId	The integer ID for the device
 * @return  whether it was successfully activated
*/
bool activate_action_set(int set, int deviceId);

/**
 * Add an action to a particular action set
 * @param	action	The Action you want to add
 * @param	set		The index of the ActionSet you want to add
 * @return	whether it was successfully added
 */
bool add_action(Action action, int set);

/**
 * Add an ActionSet to the manager
 * @param	set		The ActionSet you want to add
 * @return	if success, the set's index; -1 otherwise
 */
int add_set(ActionSet set);

/**
 * Deactivate an ActionSet for any devices it is currently active for
 * @param	set			The integer ID for the ActionSet you want to deactivate
 * @param	device_id	The integer ID for the device you want to deactivate
 */
bool deactivate_set(int set, int deviceId);

/***********************************************/



#endif /*ACTIONPACT_MANAGER*/
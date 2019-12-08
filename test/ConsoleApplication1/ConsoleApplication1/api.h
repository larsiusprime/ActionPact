#ifndef ACTIONPACT_API
#define ACTIONPACT_API

#include "types.h"

/**
 * Add an input that will trigger the given action
 * @param	action	the action you're modifying
 * @param	input	the input you're adding
 */
void action_add_input(Action action, Input input);

/**
 * See if this action has just been triggered
 * Side effect: if it has triggered, it will also fire the callback (if it's defined)
 * @return	whether it's just been triggered
 */
bool action_check(Action action);

/**
 * Create a new analog action
 * @param name		the name of your action
 * @param callback	the function to call when this action fires
 * @return an ActionData struct of your action
 */
Action action_create_analog(const char* name, callback_action_analog callback);

/**
 * Create a new digital action
 * @param name		the name of your action
 * @param callback	the function to call when this action fires
 * @return an ActionData struct of your action
 */
Action action_create_digital(const char* name, callback_action_digital callback);

/**
 * Destroy an action
 */
void action_destroy(Action action);

/**
 * Test if two actions are equivalent (checks name and backend id)
 * @return true if yes, false if no
 */
bool action_match(Action a, Action b);

/**
 * Test if the given input is attached to the given action
 * @return true if yes, false if no
 */
bool action_input_exists(Action action, Input input);



#endif /*ACTIONPACT_API*/
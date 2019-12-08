#ifndef ACTIONPACT_TYPES
#define ACTIONPACT_TYPES

#define DEVICE_ALL -1           // every connected device of the given type
#define DEVICE_FIRST_ACTIVE -2  // the first connected device with active input
#define DEVICE_NONE -3          // no device

#include <vector>

typedef enum t_input {
	DIGITAL,
	ANALOG
} t_input;

typedef enum t_state {
	JUST_RELEASED = -1,
	RELEASED = 0,
	PRESSED = 1,
	JUST_PRESSED = 2
} t_stateD;

typedef enum t_stateA {
	JUST_STOPPED = -1,
	STOPPED = 0,
	MOVED = 1,
	JUST_MOVED = 2
} t_stateA;

typedef enum t_backend {
	UNKNOWN,
	SDL,
	STEAM_INPUT,
	OPEN_XR
} t_backend;

typedef enum t_device {
	UNKNOWN_DEVICE,
	MOUSE,
	MOUSE_WHEEL,
	KEYBOARD,
	GAMEPAD,
	BLACK_BOX,
	OTHER,
	ALL,
	NONE,
} t_device;

typedef enum t_mouseID {
	LEFT,
	RIGHT,
	MIDDLE,
} t_mouseID;

typedef enum t_axis {
	HORIZONTAL,
	VERTICAL
} t_analogAxis;

typedef int callback;
typedef int callback_action_digital;
typedef int callback_action_analog;

/**
 * A bucket for referring to a specific device by type & slot number
 */

typedef struct InputDeviceObject {
	t_device device;
	int id;
	const char* model;
} InputDeviceObject;

typedef struct Input {
	t_input type;
	t_device device;
	int device_id;
	int input_id;
	t_state trigger;
};

typedef struct ActionSetManager {
	int num_sets;
	callback device_disconnected;
	callback device_connected;
	callback inputs_changed;
};

typedef struct Action {
	t_inputType type;      //digital or analog
	const char* name;
	int backend_handle;    //unique identifier
	bool triggered;        //if true, take action in the game somehow

	vector<Input> inputs;  //inputs attached to this action

	bool blackBoxChanged;  //blackbox bindings have changed since last poll

	double _x;
	double _y;

	int _timestamp;
	bool _checked;
};

#endif /*ACTIONPACT_TYPES*/
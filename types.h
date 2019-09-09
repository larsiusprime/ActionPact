#ifndef ACTIONPACT_TYPES
#define ACTIONPACT_TYPES

#define DEVICE_ALL -1           // every connected device of the given type
#define DEVICE_FIRST_ACTIVE -2  // the first connected device with active input
#define DEVICE_NONE -3          // no device

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
	UNKNOWN,
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

/**
 * A bucket for referring to a specific device by type & slot number
 */

typedef struct InputDeviceObject {
	t_device device,
	int id;
	char * model;
} InputDeviceObject;

#endif /*ACTIONPACT_TYPES*/
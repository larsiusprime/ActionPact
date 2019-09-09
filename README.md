# ActionPact
Fiddling around with a C API for universal input actions

Initialization:
```cpp
//Initialize a new manager from the given configuration
ActionManager manager = ActionManager.fromConfig("path");
```

Every frame:
```cpp
manager.update(elapsed_time_in_ms);
```

Working with a backend:
```cpp
SDLBackend sdl = new SDLBackend();
manager.addBackend(sdl);

ActionSet basic = manager.getActionSet("basic");
ActionDigital jump = basic.getAction("jump");

SDLDigitalInput leftMouse = new SDLBackend.getMouseInput(LEFT_MB, JUST_PRESSED);
SDLDigitalInput spaceBar = new SDLBackend.getKeyInput(SPACEBAR, JUST_PRESSED);
SDLDigitalInput aButton = new SDLBackend.getGamepad(A_BUTTON, JUST_PRESSED, FIRST_ACTIVE);

jump.addInput(leftMouse);
jump.addInput(spaceBar);
jump.addInput(aButton);
```

/*
DSFML - The Simple and Fast Multimedia Library for D

Copyright (c) <2013> <Jeremy DeHaan>

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications,
and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source distribution


***All code is based on code written by Laurent Gomila***


External Libraries Used:

SFML - The Simple and Fast Multimedia Library
Copyright (C) 2007-2013 Laurent Gomila (laurent.gom@gmail.com)

All Libraries used by SFML - For a full list see http://www.sfml-dev.org/license.php
*/

#ifndef DSFML_JOYSTICK_H
#define DSFML_JOYSTICK_H


// Headers
#include <DSFMLC/Window/Export.h>
#include <stddef.h>


//Global joysticks capabilities
enum
{
    sfJoystickCount       = 8,  /// Maximum number of supported joysticks
    sfJoystickButtonCount = 32, /// Maximum number of supported buttons
    sfJoystickAxisCount   = 8   /// Maximum number of supported axes
};



//Axes supported by SFML joysticks
typedef enum
{
    sfJoystickX,    /// The X axis
    sfJoystickY,    /// The Y axis
    sfJoystickZ,    /// The Z axis
    sfJoystickR,    /// The R axis
    sfJoystickU,    /// The U axis
    sfJoystickV,    /// The V axis
    sfJoystickPovX, /// The X axis of the point-of-view hat
    sfJoystickPovY  /// The Y axis of the point-of-view hat
} sfJoystickAxis;



//Check if a joystick is connected
DSFML_WINDOW_API DBool sfJoystick_isConnected(DUint joystick);


//Return the number of buttons supported by a joystick
DSFML_WINDOW_API DUint sfJoystick_getButtonCount(DUint joystick);


//Check if a joystick supports a given axis
DSFML_WINDOW_API DBool sfJoystick_hasAxis(DUint joystick, DInt axis);


//Check if a joystick button is pressed
DSFML_WINDOW_API DBool sfJoystick_isButtonPressed(DUint joystick, DUint button);


//Get the current position of a joystick axis
DSFML_WINDOW_API float sfJoystick_getAxisPosition(DUint joystick, DInt axis);

//Get the length of a joystick name for buffer generation
DSFML_WINDOW_API size_t sfJoystick_getIdentificationNameLength (DUint joystick);

//Write the name of the joystick name to a D-side buffer
DSFML_WINDOW_API void sfJoystick_getIdentificationName(DUint joystick, DUint * nameBuffer);

//Get the joystick information
DSFML_WINDOW_API void sfJoystick_getIdentification(DUint joystick, DUint * vendorID, DUint* productId);

//Update the states of all joysticks
DSFML_WINDOW_API void sfJoystick_update(void);


#endif // SFML_JOYSTICK_H

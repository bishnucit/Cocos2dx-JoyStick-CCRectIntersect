Cocos2dx-JoyStick-CCRectIntersect
=================================

This module deals with Joystick implementation using CCRect

Here i tried to implement Joystick behavior without using any Premade Joystick library.
The concept of this Module is just taking four images which would act as Top-Right-bot-left which upon detecting touch
will move the object that it is pointing to in this place which is a Red Mouse Pointer.

This Module has some bugs due to Co-ordinate / Resolution problems where some place touch are not detected due to improper
conversion from ccp to Worldspace.

![Zoom keyboard — small keyboard to improve educational experience during Zoom sessions](https://github.com/olgapavlova/zoom_keyboard/assets/5625988/2c973657-f33d-4834-b911-65db6cab1ba1)
# Zoom Keyboard
Small keyboard to improve educational experience during Zoom sessions.

Provides 3 buttons for the hotkeys:
* Raise hand/lower hand
* Mute/unmute audio
* Show/hide in-meeting chat panel

Two main buttons support student's use case: raise hand → unmute audio → answer the question → mute audio, lower hand.
As an extra feature, third button shows/hides in-meeting chat to avoid annoyance which happens because of chat allerts.

Platform: Digispark ATtiny 85.
Arduino Pro Micro is also supported.

Hotkey set: Zoom for Apple computers.
Windows, Linux, etc. could be configured without any problems.
 
 
 
![How Zoom keyboard_works](https://github.com/olgapavlova/zoom_keyboard/assets/5625988/c11ce52a-9fe9-46d7-bc52-84594faacb27)
 
 
 
## Apple Hotkeys Configuration for Multilanguage Environments
If you practice more than one language, it might be tricky to use not only this keyboard, but Zoom hotkeys as a whole. The reason is, most hotkeys work only in English keyboard layout.

The second problem is, Digispark Keyboard library has any clue about Option button. Is can be resolved, hovewer makes code a bit complicated.

Fortunately, Zoom allows to reconfigure hotkeys. Here is my solution to avoid all possible troubles.
* Alt + 1 -- raise hand/lower hand
* Alt + Shift + 0 -- mute/unmute audio
* F7 -- show/hide in-meeting chat panel
Changes should be appied both to Zoom and to Arduino code.

To avoid conflict between chat, hand, and audio, it is better to check hand and audio as global hotkeys. They have to be configured in Zoom, not in Arduino code.

![Zoom keyboard — small keyboard to improve educational experience during Zoom sessions](https://github.com/olgapavlova/zoom_keyboard/assets/5625988/2c973657-f33d-4834-b911-65db6cab1ba1)
# Zoom Keyboard
Small keyboard to improve educational experience during Zoom sessions.

Provides 3 buttons for the hotkeys:
* Raise hand/lower hand
* Mute/unmute audio
* Show/hide in-meeting chat panel

Two main buttons support student's use case:  
raise hand → unmute audio → answer the question → mute audio, lower hand.  
As an extra feature, third button shows/hides in-meeting chat to avoid annoyance which happens because of chat allerts.

Platform: Digispark ATtiny 85.  
Arduino Pro Micro is also supported.

Hotkey set: Zoom for Apple computers.  
Windows, Linux, etc. could be configured without any problems.

&nbsp; 
 
![How Zoom keyboard_works](https://github.com/olgapavlova/zoom_keyboard/assets/5625988/c11ce52a-9fe9-46d7-bc52-84594faacb27)
 
&nbsp; 

## Full Cirquit Diagram
> [!CAUTION]
> **Never** use this code without adapted circuit diagram. It just will not work properly.

The main idea of this cirquit is to avoid contact bounce without, well, coding. Code is fine, but my interest here is to make out-of-code solution for contact bounce, and to practice in cirquits.

&nbsp;

![Full cirquit diagram for Zoom keyboard](https://github.com/olgapavlova/zoom_keyboard/assets/5625988/7656b938-0886-4e6d-8caa-029cd1dc3319)

&nbsp;

![Breadboard prototype of Zoom keyboard](https://github.com/olgapavlova/zoom_keyboard/assets/5625988/3e66ba8a-be09-422c-8dff-8041e19eac43)

&nbsp;

## Apple Hotkeys Configuration for Multilanguage Environments
If you practice more than one language, it might be tricky to use not only this keyboard, but Zoom hotkeys as a whole. The reason is, most hotkeys work only in English keyboard layout.

The second problem is, [DigiKeyboard](https://github.com/digistump/DigistumpArduino/tree/master/digistump-avr/libraries/DigisparkKeyboard) library has not any clue about <kbd>Option</kbd> button. Is can be resolved, hovewer makes code a bit complicated.

Fortunately, Zoom allows to reconfigure hotkeys. Here is my solution to avoid all possible troubles.
* <kbd>ALT</kbd> + <kbd>1</kbd> — raise hand/lower hand
* <kbd>ALT</kbd> + <kbd>SHIFT</kbd> + <kbd>0</kbd> — mute/unmute audio
* <kbd>F7</kbd> — show/hide in-meeting chat panel
Changes should be appied both to Zoom and to Arduino code.

To avoid conflict between chat, hand, and audio, it is better to check hand and audio as global hotkeys. They have to be configured in Zoom, not in Arduino code.

## Useful Links
These sources altogether are enough to rebuild the project from scratch.
Partially in Russian language. I hope, it cannot be tricky to translate it automatically.
* [GTK Keyboard](https://youtu.be/BGkTiVP5ryY?si=Cz4yyMLpRYj-izkc) (video) — Digispark keyboard with two keys; looks pretty
* [Alex Gyver's intro to Digispark](https://alexgyver.ru/lessons/digispark/) — a bit old, but still inspiring
* [Linux Mint Digispark installation](https://startingelectronics.org/tutorials/arduino/digispark/digispark-linux-setup/) — step by step guide; do not forget “Programmer: Micronucleus” option!
* [DigiKeyboad library](https://github.com/digistump/DigistumpArduino/tree/master/digistump-avr/libraries/DigisparkKeyboard) — Github source; useful to read
* [Using multiple modifiers](http://digistump.com/board/index.php?topic=116.0) — in short, use binary operation | (OR) to combine MOD_*
* [Contact bounce demistified](http://codius.ru/articles/Arduino_Дребезг_программное_и_аппаратное_устранение) — how to find out and how to avoid both in code or in cirquit
* [Alex Gyver's introduction to classes on Arduino](https://alexgyver.ru/lessons/class/) — class usage is not necessary but very funny in this tiny project
* [Alex Gyver's introduction to self-made libraries on Arduino](https://alexgyver.ru/lessons/library-writing/) — see the previous line about classes


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

Hotkey preset: Zoom for Apple computers, customized version (see below).  
Windows, Linux, etc. could be configured without any problems, and all have been tested.

&nbsp; 
 
![How Zoom keyboard_works](https://github.com/olgapavlova/zoom_keyboard/assets/5625988/c11ce52a-9fe9-46d7-bc52-84594faacb27)
 
&nbsp; 

## Hardware
> [!CAUTION]
> **Never** use this code without adapted circuit diagram. It just will not work properly.

The main idea of this cirquit is to avoid contact bounce without, well, coding. Code is fine, but my interest here is to make out-of-code solution for contact bounce, and to practice in cirquits.

### Full Cirquit Diagram
![Full cirquit diagram for Zoom keyboard](https://github.com/olgapavlova/zoom_keyboard/assets/5625988/7656b938-0886-4e6d-8caa-029cd1dc3319)

### Breadboard Prototype
It is not necessary to mount all details (as you can see on photo), one button is enough for prototype purposes.

![Breadboard prototype of Zoom keyboard](https://github.com/olgapavlova/zoom_keyboard/assets/5625988/3e66ba8a-be09-422c-8dff-8041e19eac43)

### Cirquit Board
Buttons and Digispark are connected separately with wires.
![Cirquit Board for Zoom Keyboard](https://github.com/olgapavlova/zoom_keyboard/assets/5625988/c7e8e9f4-6e37-4799-b33c-f56cba4b22f8)


## Software and System Configuration
> [!WARNING]
> The code is preconfigured for my system only. To work properly on your side, it has to be changed a bit as it explained below.

### Pin Numbers
Preprocessor variables PIN_* in zoom_keyboard.ino file configures your button pins in usual Arduino way.
```c++
#define PIN_HAND 0
...
#define PIN_MIC 1
...
#define PIN_CHAT 2
```

You can use only 0, 1, and 2 pins.
3 and 4 pins are reserved for USB on Digispark boards, and not available for this project.
You can try to use 5 pin. However, some boards do not support it properly, so be careful.

### Debug Mode
In Button.h file, there is a string with DEBUG preprocessing variable:
```c++
#define DEBUG 0
```
Change to 1 (and save the file), if you wish to switch modificators (<kbd>SHIFT</kbd>, etc.) off.

### Apple Hotkeys Configuration for Multilanguage Environments
If you practice more than one language, it might be tricky to use not only this keyboard, but Zoom hotkeys as a whole. The reason is, most hotkeys work only in English keyboard layout.

The second problem is, [DigiKeyboard](https://github.com/digistump/DigistumpArduino/tree/master/digistump-avr/libraries/DigisparkKeyboard) library has not any clue about <kbd>CMD</kbd> button. Is can be resolved, hovewer makes code a bit complicated.

Fortunately, [Zoom allows to reconfigure hotkeys](https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0067050).  
Here is my solution to avoid all possible troubles.
* <kbd>ALT</kbd> + <kbd>1</kbd> — raise hand/lower hand
* <kbd>ALT</kbd> + <kbd>SHIFT</kbd> + <kbd>0</kbd> — mute/unmute audio
* <kbd>F7</kbd> — show/hide in-meeting chat panel
Changes should be appied both to Zoom and to Arduino code.

To avoid conflict between chat, hand, and audio, it is better to check hand and audio as global hotkeys. They have to be configured in Zoom, not in Arduino code.

To configure Arduino code, change some preprocessing variables:
```
#define KEY_HAND  KEY_1
#define MOD_HAND  MOD_ALT_LEFT
...
#define KEY_MIC   KEY_0
#define MOD_MIC   MOD_ALT_LEFT | MOD_SHIFT_LEFT
...
#define KEY_CHAT  KEY_F7
#define MOD_CHAT  0
```

To combine two mod keys, join them with | (OR) operator.

You can find the full list of available key codes in [DigiKeyboard library source code](https://github.com/digistump/DigistumpArduino/tree/master/digistump-avr/libraries/DigisparkKeyboard).

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


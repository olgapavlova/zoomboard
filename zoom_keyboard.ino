/*

  Zoom Keyboard
  Small keyboard to improve educational experience during Zoom sessions.

  Provides 3 buttons for the hotkeys:
  -- raise hand/lower hand;
  -- mute/unmute audio;
  -- show/hide in-meeting chat panel.
  
*/

#include <DigiKeyboard.h>
#include "Button.h"

// Hotkeys and pins
#define KEY_HAND  KEY_1
#define MOD_HAND  MOD_ALT_LEFT
#define PIN_HAND  0

#define KEY_MIC   KEY_0
#define MOD_MIC   MOD_ALT_LEFT | MOD_SHIFT_LEFT
#define PIN_MIC   1

#define KEY_CHAT  KEY_F7
#define MOD_CHAT  0
#define PIN_CHAT  2

// * * * = = = = = = = = = = = = = = = * * * //

Button handButton(PIN_HAND, KEY_HAND, MOD_HAND);
Button micButton(PIN_MIC, KEY_MIC, MOD_MIC);
Button chatButton(PIN_CHAT, KEY_CHAT, MOD_CHAT);

void setup() {}

void loop() {
  handButton.check_and_react();
  micButton.check_and_react();
  chatButton.check_and_react();
}
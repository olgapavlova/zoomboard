#pragma once
#include <Arduino.h>

// Use DEBUG variable to switch on/off keys like SHIFT, CTRL, etc.
#define DEBUG 0

// Main button class -- pin, hotkey, action logic
class Button {
  public:
    Button(int pin, byte key, byte mod) {
      _pin = pin;
      _key = key;
      _mod = mod;

      pinMode(_pin, INPUT); // define button pin behavior
    }

    void check_and_react() { // main class method
      _check_current_state();
      _react_on_changes();
    }

  private:
    byte _pin;
    byte _key;
    byte _mod;

    bool _pressed_flag = false;  // state flag
    bool _current_state = LOW;  // normal button behavior is off
    
    void _activate_key() { // do what is button created for; in this case -- press and release specific hotkey
      DigiKeyboard.sendKeyStroke(_key, (1 - DEBUG) * _mod);
    }

    void _check_current_state() { // what is going on with button
      _current_state = !digitalRead(_pin); // Schmitt trigger requires inverion
    }

    int _just_happend() { // what has happend just now
      return (int)_current_state - (int)_pressed_flag; // 1 -- button is on, -1 -- button is off, 0 -- no changes in button state
    }

    void _react_on_changes() { // if something happens, it is time to react
     switch (_just_happend()) {
        case 1: // button is on
          _pressed_flag = true;
          _activate_key();
          break;

        case -1: // button is off
          _pressed_flag = false;
          break;
      }
    }

};

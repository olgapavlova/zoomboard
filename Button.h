#pragma once
#include <Arduino.h>

// Класс работы с кнопкой
class Button {
  public:
    Button(int pin, byte key, byte mod) {
      _pin = pin;
      _key = key;
      _mod = mod;

      pinMode(_pin, INPUT); // инициировать пин, к которому подключена кнопка
    }

    void check_and_react() { // проверить состояние кнопки и отреагировать на него (основная функция класса)
      _check_current_state();
      _react_on_changes();
    }

  private:
    byte _pin;
    byte _key;
    byte _mod;

    bool _pressed_flag = false;  // флаг состояния
    bool _current_state = LOW;  // нажатость кнопки (нормально разомкнута)
    
    void _activate_key() { // сделать то, что кнопка должна сделать; сейчас -- нажать горячую клавишу
      DigiKeyboard.sendKeyStroke(_key, _mod);
    }

    void _check_current_state() { // обновить состояние кнопки
      _current_state = !digitalRead(_pin); // инверсия из-за триггера Шмитта
    }

    int _just_happend() { // выяснить, что произошло
      return (int)_current_state - (int)_pressed_flag; // 1 -- кнопка нажата, -1 -- отпущена, 0 -- без изменений
    }

    void _react_on_changes() { // отреагировать на произошедшее
     switch (_just_happend()) {
        case 1: // кнопка нажата
          _pressed_flag = true;
          _activate_key();
          break;

        case -1: // кнопка отпущена
          _pressed_flag = false;
          break;
      }
    }

};

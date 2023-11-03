/*

  Прошивка для трёхкнопочной клавиатуры.

  Кнопки отправляют команды в Zoom:
  -- поднять/опустить руку;
  -- включить/выключить звук;
  -- показать/скрыть чат.

*/

#include <Keyboard.h>

// Класс работы с кнопкой
class ZoomButton {
  public:
    ZoomButton(int pin, void (*function)()) {
      _pin = pin;
      _react_on_press_pointer = *function;
      pinMode(_pin, INPUT);
    }

    void check_and_react() { // TODO разбить на две функции, а то в этой два действия, перегруз
      _update_current_state();

      // TODO Перевести два if на switch (just-функцию тоже можно оставить одну)
      if (_just_pressed()) {
          _pressed_flag = true;  // TODO так неаккуратно, надо как-то иначе сделать
          _react_on_press();
      }

      if (_just_released()) { _pressed_flag = false; }
    }

  private:
    int _pin;  // ?TODO выбрать тип попроще
    bool _pressed_flag = false;  // флаг состояния
    bool _current_state = LOW;  // нажатость кнопки
    
    void (*_react_on_press_pointer)();  // указатель на функцию-обработчик нажатия
    void _react_on_press() { (*_react_on_press_pointer)(); }  // обёртка указателя на функцию-обработчик нажатия

    void _update_current_state() {
      _current_state = !digitalRead(_pin);  // TODO обновить после подключения триггера Шмитта
    }

    bool _just_pressed() {  // проверка, что кнопка только что нажата
      return (_current_state && !_pressed_flag);
    }

    bool _just_released() {  // проверка, что кнопка только что отпущена
      return (!_current_state && _pressed_flag);
    }

};

int pinLED = 9;  // TODO зашить реакцию светодиодом в класс кнопки

// функции-обработчики для разных кнопок
void click_hand_on_off();
void click_sound_on_off();
void click_chat_on_off();

// кнопки с привязкой к Zoom-функциональности
ZoomButton handButton(8, click_hand_on_off);
ZoomButton soundButton(7, click_sound_on_off);
ZoomButton chatButton(A3, click_chat_on_off);

/*
  СТАРТ ПРОГРАММЫ
*/
void setup() {
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, HIGH);
}

/*
  ОСНОВНОЙ ЦИКЛ ПРОГРАММЫ
*/
void loop() {
  handButton.check_and_react();
  soundButton.check_and_react();
  chatButton.check_and_react();
}

/*
  ФУНКЦИИ РЕАКЦИИ НА КНОПКИ
*/

// TODO шаблонизировать функции нажатия горячих клавиш

// поднять-опустить руку
void click_hand_on_off() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write('1');
  Keyboard.releaseAll();
}

// вкл-выкл звук
void click_sound_on_off() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write('0');
  Keyboard.releaseAll();
}

// показать-скрыть чат
void click_chat_on_off() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write('4');
  Keyboard.releaseAll();
}
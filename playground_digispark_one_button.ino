/*

  Прошивка для трёхкнопочной клавиатуры.

  Кнопки отправляют команды в Zoom:
  -- поднять/опустить руку;
  -- включить/выключить звук;
  -- показать/скрыть чат.

  PIN_HEAD  Пин кнопки поднятия/опускания руки.
  PIN_SOUND Пин кнопки вкл/выкл звука.
  PIN_CHAT  Пин кнопки отображения чата.

  DEBUG Если переменная определена, клавиатура переходит в отладочный режим
        -- кнопки отправляют только чистые символы, без клавиш-модификаторов.

*/

#include <Keyboard.h>

#define DEBUG 1

#define PIN_HAND  7
#define PIN_SOUND 8
#define PIN_CHAT  9

#ifdef DEBUG
#define KEYBOARD_PRESS(x)
#else
#define KEYBOARD_PRESS(x) Keyboard.press(x)
#endif

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
      // Serial.println(_pressed_flag);
      // Serial.println(_current_state);

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
      _current_state = !digitalRead(_pin); // инверсия из-за подтяжки к 5 В
    }

    bool _just_pressed() {  // проверка, что кнопка только что нажата
      return (_current_state && !_pressed_flag);
    }

    bool _just_released() {  // проверка, что кнопка только что отпущена
      return (!_current_state && _pressed_flag);
    }

};

// функции-обработчики для разных кнопок
void click_hand_on_off();
void click_sound_on_off();
void click_chat_on_off();

// кнопки с привязкой к Zoom-функциональности
ZoomButton handButton(PIN_HAND, click_hand_on_off);
ZoomButton soundButton(PIN_SOUND, click_sound_on_off);
ZoomButton chatButton(PIN_CHAT, click_chat_on_off);

/*
  СТАРТ ПРОГРАММЫ
*/
void setup() {
  // pinMode(pinLED, OUTPUT);
  // digitalWrite(pinLED, HIGH);
  // Serial.begin(9600);
  //Keyboard.press(' ');
  //Keyboard.releaseAll();
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
  KEYBOARD_PRESS(KEY_LEFT_ALT);
  Keyboard.write('1');
  Keyboard.releaseAll();
}

// вкл-выкл звук
void click_sound_on_off() {
  KEYBOARD_PRESS(KEY_LEFT_ALT);
  KEYBOARD_PRESS(KEY_LEFT_SHIFT);
  Keyboard.write('0');
  Keyboard.releaseAll();
}

// показать-скрыть чат
void click_chat_on_off() {
  KEYBOARD_PRESS(KEY_LEFT_ALT);
  KEYBOARD_PRESS(KEY_LEFT_SHIFT);
  Keyboard.write('4');
  Keyboard.releaseAll();
}
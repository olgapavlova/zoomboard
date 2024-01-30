/*

  Прошивка для трёхкнопочной клавиатуры.

  Кнопки отправляют команды в Zoom:
  -- поднять/опустить руку;
  -- включить/выключить звук;
  -- показать/скрыть чат.

  PIN_HAND  Пин кнопки поднятия/опускания руки.
  PIN_MIC Пин кнопки вкл/выкл микрофона.
  PIN_CHAT  Пин кнопки отображения чата.

  DEBUG Если переменная определена, клавиатура переходит в отладочный режим
        -- кнопки отправляют только чистые символы, без клавиш-модификаторов.

*/

#include <DigiKeyboard.h>
#include "Button.h"

#define DEBUG 1

#define PIN_HAND  0   // пин кнопки руки
#define PIN_MIC   1   // пин кнопки микрофона
#define PIN_CHAT  2   // пин кнопки чата

// Определения горячих клавиш
// KEY -- клавиши основной клавиатуры,
// MOD -- клавиши-модификаторы
#define KEY_HAND
#define MOD_HAND

#define KEY_MIC
#define MOD_MIC

#define KEY_CHAT
#define MOD_CHAT



// функции-обработчики для разных кнопок
void click_hand_on_off();
void click_sound_on_off();
void click_chat_on_off();

// кнопки с привязкой к Zoom-функциональности
Button handButton(PIN_HAND, click_hand_on_off);
Button soundButton(PIN_MIC, click_sound_on_off);
Button chatButton(PIN_CHAT, click_chat_on_off);

/*
  СТАРТ ПРОГРАММЫ
*/
void setup() {

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
  DigiKeyboard.sendKeyStroke(KEY_A);
}

// вкл-выкл звук
void click_sound_on_off() {
  DigiKeyboard.sendKeyStroke(KEY_B);
}

// показать-скрыть чат
void click_chat_on_off() {
  DigiKeyboard.sendKeyStroke(KEY_C);
}
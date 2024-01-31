/*

  Прошивка для трёхкнопочной клавиатуры.

  Кнопки отправляют команды в Zoom:
  -- поднять/опустить руку;
  -- включить/выключить звук;
  -- показать/скрыть чат.

  DEBUG Если переменная определена, клавиатура переходит в отладочный режим
        -- кнопки отправляют только чистые символы, без клавиш-модификаторов. (TODO TODO TODO)

*/

#include <DigiKeyboard.h>
#include "Button.h"

// Определения горячих клавиш
// KEY -- клавиши основной клавиатуры,
// MOD -- клавиши-модификаторы
#define KEY_HAND  KEY_1
#define MOD_HAND  MOD_ALT_LEFT
#define PIN_HAND  0   // пин кнопки руки

#define KEY_MIC   KEY_0
#define MOD_MIC   MOD_ALT_LEFT | MOD_SHIFT_LEFT
#define PIN_MIC   1   // пин кнопки микрофона

#define KEY_CHAT  KEY_F7
#define MOD_CHAT  0
#define PIN_CHAT  2   // пин кнопки чата

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
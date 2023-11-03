#include <Keyboard.h>

int pinButtonRed = 7;
int pinButtonYellow = 8;
int pinButtonBlack = A3;
int pinLED = 9;

bool flagRed = false;
bool flagYellow = false;
bool flagBlack = false;

void click_hand_on_off();
void click_sound_on_off();
void click_chat_on_off();

void setup() {
  pinMode(pinButtonRed, INPUT);
  pinMode(pinButtonYellow, INPUT);
  pinMode(pinButtonBlack, INPUT);
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, HIGH);
}


void loop() {
  // читаем инвертированное значение для удобства
  bool btnStateRed = !digitalRead(pinButtonRed);
  bool btnStateYellow = !digitalRead(pinButtonYellow);
  bool btnStateBlack = !digitalRead(pinButtonBlack);

  if (btnStateRed && !flagRed) {  // обработчик нажатия красной кнопки
    flagRed = true;
    digitalWrite(pinLED, HIGH);
    click_sound_on_off();
  }

  if (btnStateYellow && !flagYellow) {  // обработчик нажатия жёлтой кнопки
    flagYellow = true;
    digitalWrite(pinLED, HIGH);
    click_hand_on_off();    
  }

  if (btnStateBlack && !flagBlack) {  // обработчик нажатия чёрной кнопки
    flagBlack = true;
    digitalWrite(pinLED, HIGH);
    click_chat_on_off();    
  }

  if (!btnStateRed && flagRed) {  // обработчик отпускания
    flagRed = false;  
    digitalWrite(pinLED, LOW);
  }

  if (!btnStateYellow && flagYellow) {  // обработчик отпускания
    flagYellow = false;  
    digitalWrite(pinLED, LOW);

  if (!btnStateBlack && flagBlack) {  // обработчик отпускания
    flagBlack = false;  
    digitalWrite(pinLED, LOW);
  }
}

void click_hand_on_off() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write('1');
  Keyboard.releaseAll();
}

void click_sound_on_off() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write('0');
  Keyboard.releaseAll();
}

void click_chat_on_off() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write('4');
  Keyboard.releaseAll();
}
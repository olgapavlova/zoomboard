#include <Keyboard.h>

int pinButton = 8;
int pinLED = 2;

bool flag = false;

void click_hand_on_off();
void click_sound_on_off();

void setup() {
  pinMode(pinButton, INPUT);
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, HIGH);
}


void loop() {
  // читаем инвертированное значение для удобства
  bool btnState = !digitalRead(pinButton);
  if (btnState && !flag) {  // обработчик нажатия
    flag = true;
    digitalWrite(pinLED, HIGH);
    click_hand_on_off();
    click_sound_on_off();
    
  }
  if (!btnState && flag) {  // обработчик отпускания
    flag = false;  
    digitalWrite(pinLED, LOW);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('b');
    Keyboard.release(KEY_LEFT_SHIFT);
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
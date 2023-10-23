#include <Codekeys.h>
#include <EasyHID.h>
#include <HIDPrivate.h>
#include <usbconfig.h>

#include <Arduino.h>

#include <EncButton.h>
Button btn(7, INPUT_PULLUP, HIGH);

static uint32_t clickedMoment;
bool clicked = false;

void setup() {
    Serial.begin(9600);
    HID.begin();
}

void loop() {
    btn.tick();

    if (btn.click()) {
      Serial.println("Hand");
      Keyboard.click(KEY_LEFT_ALT, KEY_1); // Alt + 1 — поднять/опустить руку (нужно перенастроить Zoom)
      clicked = true;
      clickedMoment = millis();
    }

    if ((clicked) && (millis() - clickedMoment > 3000)) { // Три секунды
      Serial.println("Mic");
      Keyboard.click(KEY_LEFT_SHIFT, KEY_LEFT_ALT, KEY_0); // Shift + Alt + 0 — включить/выключить микрофон (нужно перенастроить Zoom)     
      clicked = false;
    }

}

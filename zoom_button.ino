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
      Keyboard.click(KEY_LEFT_SHIFT, KEY_Y);
      clicked = true;
      clickedMoment = millis();
    }

    if ((clicked) && (millis() - clickedMoment > 3000)) {
      Serial.println("Mic");
      Keyboard.click(KEY_LEFT_SHIFT, KEY_A);      
      clicked = false;
    }

}

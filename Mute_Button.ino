//https://www.thingiverse.com/thing:3551855
//https://github.com/balassy/microsoft-teams-mic-mute-button
//https://www.arduino.cc/en/Reference/KeyboardModifiers

#include <HID.h>
#include <Keyboard.h>

// connected PIN8
const int switch_pin        = 8;

int button_state            = 0;
int previous_button_state   = HIGH;
long last_debounce_time     = 0;
const long debounce_delay   = 50;

void setup() 
{
  // We use internal pullup registor 'cause the switch directly connected.
  pinMode(switch_pin,INPUT_PULLUP); 
  digitalWrite(switch_pin, HIGH);
  
  Keyboard.begin();
}


void loop() 
{
  button_state = digitalRead(switch_pin);
  if ((button_state != previous_button_state) && (button_state == HIGH)) 
  {
    if ((millis() - last_debounce_time) > debounce_delay) 
    {

      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(';');

      delay(300);
      Keyboard.releaseAll(); // This is important after every Keyboard.press it will continue to be pressed
      last_debounce_time = millis();
    }
  }
  previous_button_state = button_state;
}

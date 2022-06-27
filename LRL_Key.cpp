#include "Arduino.h"
#include "LRL_Key.h"

static int DEFAULT_KEY_PIN = A0;

LRL_Key::LRL_Key()
{
  _refreshRate = 10;
  _keyPin = DEFAULT_KEY_PIN;
  _prevKey = KEY_NONE;
  _oldTime = 0;
}

// Used to categorize button presses based on analog read of input pin
static int bmap[6]= {60,200,400,600,800,1024};

int LRL_Key::getKey()
{
  int key = SAMPLE_WAIT;

  if (millis() > _oldTime + _refreshRate) {
     int _analog = analogRead(_keyPin);

     for (int a=0;a<6;a++) {
       if(_analog<bmap[a]) {
         key=a;
         break;
       }
     } // for

     if (_prevKey != key) {
       _prevKey = key;
     } else {
       key = SAMPLE_WAIT; // Indicative of NO CHANGE
     }

     _oldTime = millis();
   } 

   return key;
}

void LRL_Key::setRate(int rate)
{
  _refreshRate = rate;
}


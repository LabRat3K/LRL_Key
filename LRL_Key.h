#ifndef LRL_Key_h
#define LRL_Key_h

/* LabRat's Lights KEYPAD shield */
#include "Arduino.h"

#define SAMPLE_WAIT -1

// Order is important as this must match the incremental
// order of the values in the BMAP array
#define KEY_NONE   (0x05)
#define KEY_SELECT (0x04)
#define KEY_LEFT   (0x03)
#define KEY_DOWN   (0x02)
#define KEY_UP     (0x01)
#define KEY_RIGHT  (0x00)

class LRL_Key
{
  public:
    LRL_Key();
    int getKey();
    void setRate(int);
  private:
    int _refreshRate;
    int _keyPin;
    int _threshold;
    int _prevKey;
    unsigned long _oldTime;
};

#endif


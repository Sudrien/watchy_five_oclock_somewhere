#ifndef WATCHY_FIVE_OCLOCK_SOMEWHERE_H
#define WATCHY_FIVE_OCLOCK_SOMEWHERE_H

#include <Watchy.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <sunset.h>

#define DEG2RAD 0.0174532925

class WatchyFiveOclockSomewhere : public Watchy{
    using Watchy::Watchy;
    public:
        WatchyFiveOclockSomewhere(const watchySettings& s) : Watchy(s) {}
        void drawWatchFace();
  };
#endif

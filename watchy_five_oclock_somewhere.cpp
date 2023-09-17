#include "watchy_five_oclock_somewhere.h"

void WatchyFiveOclockSomewhere::drawWatchFace() {
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_WHITE);


  float m = currentTime.Minute;
  float h = currentTime.Hour + currentTime.Minute / 60.0;
  // keep the hour at 5 pm
  float h_offset = 150 - h * 30.0;

  // keep the minute at noon
  //float h_offset = 360 - m * 6.0;


  display.fillCircle(100, 100, 99, GxEPD_BLACK);
  display.fillCircle(100, 100, 73, GxEPD_WHITE);

  display.setFont(&FreeSansBold9pt7b);

  int16_t  x_point, y_point;
  int16_t  x_center, y_center;
  uint16_t w_center, h_center;

  for(int16_t i = 1; i <= 12; i++) {
    x_point = 100 + 87 * sin((i * 30.0 + h_offset) * DEG2RAD);
    y_point = 112 - 87 * cos((i * 30.0 + h_offset) * DEG2RAD);
    display.getTextBounds(String(i), 100, 100, &x_center, &y_center, &w_center, &h_center); // make sure it's on screen
    display.setCursor(x_point - w_center / 2, y_point - h_center / 2);
    display.println(i);
    }

  float VBAT = getBatteryVoltage();
  if(VBAT > 4.1){
    display.fillCircle(100 + 67 * sin(h_offset * DEG2RAD), 100 - 67 * cos(h_offset * DEG2RAD), 5, GxEPD_BLACK);
    display.fillCircle(100 + 67 * sin(h_offset * DEG2RAD), 100 - 67 * cos(h_offset * DEG2RAD), 3, GxEPD_WHITE);
    }
  if(VBAT > 3.95){
    display.fillCircle(100 + 59 * sin(h_offset * DEG2RAD), 100 - 59 * cos(h_offset * DEG2RAD), 5, GxEPD_BLACK);
    display.fillCircle(100 + 59 * sin(h_offset * DEG2RAD), 100 - 59 * cos(h_offset * DEG2RAD), 3, GxEPD_WHITE);
    }
  if(VBAT > 3.80){
    display.fillCircle(100 + 51 * sin(h_offset * DEG2RAD), 100 - 51 * cos(h_offset * DEG2RAD), 5, GxEPD_BLACK);
    display.fillCircle(100 + 51 * sin(h_offset * DEG2RAD), 100 - 51 * cos(h_offset * DEG2RAD), 3, GxEPD_WHITE);
    }

  // minute hand
  display.fillTriangle(
    100 + 80 * sin((m * 6.0 + h_offset) * DEG2RAD),
    100 - 80 * cos((m * 6.0 + h_offset) * DEG2RAD),
    100 + 4 * sin((m * 6.0 + 90 + h_offset) * DEG2RAD),
    100 - 4 * cos((m * 6.0 + 90 + h_offset) * DEG2RAD),
    100 + 4 * sin((m * 6.0 - 90 + h_offset) * DEG2RAD),
    100 - 4 * cos((m * 6.0 - 90 + h_offset) * DEG2RAD),
    GxEPD_BLACK
    );

  // hour hand
  display.fillTriangle(
    100 + 40 * sin((h * 30.0 + h_offset) * DEG2RAD),
    100 - 40 * cos((h * 30.0 + h_offset) * DEG2RAD),
    100 + 8 * sin((h * 30.0 + 90 + h_offset) * DEG2RAD),
    100 - 8 * cos((h * 30.0 + 90 + h_offset) * DEG2RAD),
    100 + 8 * sin((h * 30.0 - 90 + h_offset) * DEG2RAD),
    100 - 8 * cos((h * 30.0 - 90 + h_offset) * DEG2RAD),
    GxEPD_BLACK
    );
  }




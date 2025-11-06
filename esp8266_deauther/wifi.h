/* This software is licensed under the MIT License: https://github.com/spacehuhntech/esp8266_deauther */

#pragma once

#include <Arduino.h>

namespace wifi {
    void begin();
    void setWifiChannel(uint8_t ch, bool force = false);
}
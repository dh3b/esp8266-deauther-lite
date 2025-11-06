// ...existing code...
#include "wifi.h"
extern "C" {
    #include "user_interface.h"
}
#include <ESP8266WiFi.h>

#include "language.h"
#include "debug.h"
#include "settings.h"
#include "Attack.h"
#include "Scan.h"

// removed: CLI.h, webfiles.h, ESP8266WebServer, DNSServer, MDNS etc.

namespace wifi {

    void begin() {
        // minimal: set station mode to allow promiscuous sniffing
        WiFi.mode(WIFI_STA);
        WiFi.disconnect();
        // ensure channel set to configured
        setWifiChannel(settings::getWifiSettings().channel, true);
    }

    void setWifiChannel(uint8_t ch, bool force) {
        wifi_channel = ch;
        // attempt to set channel in SDK
        wifi_set_channel(ch); // SDK call; keep as in original code
    }
}
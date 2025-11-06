/* This software is licensed under the MIT License: https://github.com/spacehuhntech/esp8266_deauther */

#pragma once

#include <Arduino.h> // Arduino String, Serial
#include "A_config.h"

// ===== VERSION ===== //
typedef struct version_t {
    uint8_t major;
    uint8_t minor;
    uint8_t revision;
} version_t;

// ===== AUTOSAVE ===== //
typedef struct autosave_settings_t {
    bool     enabled;
    uint32_t time;
} autosave_t;

// ===== ATTACK ===== //
typedef enum beacon_interval_t {
    INTERVAL_1S    = 0,
    INTERVAL_100MS = 1
} beacon_interval_t;

typedef struct attack_settings_t {
    // General
    bool     attack_all_ch;
    bool     random_tx;
    uint32_t timeout;

    // Deauth
    uint8_t deauths_per_target;
    uint8_t deauth_reason;

    // Beacon
    beacon_interval_t beacon_interval;

    // Probe
    uint8_t probe_frames_per_ssid;
} attack_settings_t;

// ====== WIFI ====== //
typedef struct wifi_settings_t {
    uint8_t channel;
    uint8_t mac_st[6];
    uint8_t mac_ap[6];
} wifi_settings_t;

// ===== SNIFFER ===== //
typedef struct sniffer_settings_t {
    uint16_t channel_time;
    uint16_t min_deauth_frames;
} sniffer_settings_t;

// ===== LED ===== //
typedef struct led_settings_t {
    bool enabled;
} led_settings_t;

// ===== DISPLAY ===== //
typedef struct display_settings_t {
    bool     enabled;
    uint32_t timeout;
} display_settings_t;

// ===== SETTINGS ===== //
typedef struct settings_t {
    uint32_t                magic_num;
    version_t               version;
    autosave_settings_t     autosave;
    attack_settings_t       attack;
    wifi_settings_t         wifi;
    sniffer_settings_t      sniffer;
    led_settings_t          led;
    display_settings_t      display;
} settings_t;

namespace settings {
    void load();
    void save(bool force = false);

    void reset();
    void print();

    const settings_t& getAllSettings();
    const version_t& getVersion();
    const autosave_settings_t& getAutosaveSettings();
    const attack_settings_t& getAttackSettings();
    const wifi_settings_t& getWifiSettings();
    const sniffer_settings_t& getSnifferSettings();
    const led_settings_t& getLEDSettings();
    const display_settings_t& getDisplaySettings();

    void setAllSettings(settings_t& settings);
    void setAutosaveSettings(const autosave_settings_t& autosave);
    void setAttackSettings(const attack_settings_t& attack);
    void setWifiSettings(const wifi_settings_t& wifi);
    void setSnifferSettings(const sniffer_settings_t& sniffer);
    void setLEDSettings(const led_settings_t& led);
    void setDisplaySettings(const display_settings_t& display);
}
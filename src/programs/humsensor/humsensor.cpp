
#include "Arduino.h"

#include "./services/humsensor/domain.h"

#include "./components/debug/console/console.h"
#include "./components/network/wifi/wifi.h"
#include "./components/storage/eeprom/storeEeprom.h"
#include "./components/board/ESP/espBoard.h"
#include "./components/webserver/webserver/webserver.h"
#include "./components/ota/espOta/espOta.h"
#include "./components/time/ntp/ntp.h"

Domain* HumSensor = new Domain();

void setup() {
  Console* console = new Console();
  HumSensor->setBoardInterface(new ESPBoard()); // FOR EspBoard BOARD
  HumSensor->setDebugInterface(console);
  HumSensor->setNetworkInterface(new EspWifi());
  HumSensor->setStorageInterface(new StoreEeprom()); // USE EEPROM for storage
  HumSensor->setWebServerInterface(new EspWebServer());
  HumSensor->setOtaInterface(new ESPOta());
  HumSensor->setTimeInterface(new Ntp());
  HumSensor->setup();
}

void loop() {
  HumSensor->loop();
}
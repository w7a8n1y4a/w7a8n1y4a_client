#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#include "w7a8n1y4a_client.h"

w7a8n1y4a_client  client("WOWA_GARAGE", "h40s-o7u6-mjib");
// w7a8n1y4a_client  client("WOWA-HP_DACHA", "h40s-o7u6-mjib");
// w7a8n1y4a_client  client("SilberHome", "32G#64a*");
// w7a8n1y4a_client  client("her", "w7a8n1y4a");

int test_int;
float test_float;
void setup() {
  Serial.begin(115200);
}

void loop() {
  client.reset();
  test_int = client.get_http_int("http://silberworks.ru/sensor/sensor_state.php?k=");
  test_float = client.get_http_float("http://silberworks.ru/sensor/sensor_state.php?k=");
  delya(1);
}

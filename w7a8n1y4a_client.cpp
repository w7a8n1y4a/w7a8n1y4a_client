#include "w7a8n1y4a_client.h"

void w7a8n1y4a_client::w7a8n1y4a_client(const char* ssi, const char* passwor){
  ssid = ssi;
  password = passwor;

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  delay(10000);
}
void w7a8n1y4a_client::reset(){
  if(count_reload >= 20){
    if(millis() - mls_timer_reload > 60000){
      WiFi.begin(ssid, password);
      delay(10000);
      mls_timer_reload = millis();
    }
    count_reload = 0;
  }
}
int w7a8n1y4a_client::get_http_int(String Link){
  int info = 0;

  HTTPClient http;
  http.begin(Link);
  http.addHeader("Content-Type", "application/json");

  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK) {
    String response = http.getString();
    info = response.toInt();
  }else{
    count_reload++;
  }
  http.end();
  return info;
}
float w7a8n1y4a_client::get_http_float(String Link){
  float info = 0;

  HTTPClient http;
  http.begin(Link);
  http.addHeader("Content-Type", "application/json");

  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK) {
    String response = http.getString();
    info = response.toFloat();
  }else{
    count_reload++;
  }
  http.end();
  return info;
}


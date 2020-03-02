#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>


class w7a8n1y4a_client{
public:

    w7a8n1y4a_client(const char* ssid, const char* password);

    void reset();

    int get_http_int(String Link);
    float get_http_float(String Link);

private:
    const char* ssid;
    const char* password;
    
    uint32_t mls_timer_reload = 0;
    uint32_t count_reload = 0;
};

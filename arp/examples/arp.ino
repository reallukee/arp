#include "arp.hpp"

#include "arduino_secret.hpp"

char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASSWORD;

int status = WL_IDLE_STATUS;

RestApi api;

Response mario(Request &request)
{
    return Response(200, "OK", "Mario!");
}

Response luigi(Request &request)
{
    return Response(200, "OK", "Luigi!");
}

void setup()
{
    Serial.begin(9600);

    while (!Serial);

    if (WiFi.status() == WL_NO_MODULE)
    {
        while (true);
    }

    while (status != WL_CONNECTED)
    {
        status = WiFi.begin(ssid, pass);

        delay(10000);
    }

    api.listen(DEFAULT_PORT);

    api.endpoint("GET", "/mario", mario);
    api.endpoint("GET", "/luigi", luigi);
}

void loop()
{
    api.read();
}

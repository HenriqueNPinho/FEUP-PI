/* #include <WiFi.h>
#include <PubSubClient.h>

const char *ssid = "THOMSONC15130";
const char *pass = "81C1BBF76C";

const char *broker = "broker.mqttdashboard.com";
const int port = 8000;

WiFiClient espClient;
PubSubClient client(broker, port, espClient);

void setupWifi()
{
    delay(100);
    Serial.print("\nConnecting to");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(100);
        Serial.print("-");
    }
    Serial.print("\nConnected to");
    Serial.println(ssid)
}

void reconnect()
{
    while (!client.connected())
    {
        Serial.print("\nConnecting to ");
        Serial.println(broker);
        if (client.connect())
        {
            Serial.print("\nConnected to ");
            Serial.println(broker);
        }
        else
        {
            Serial.println("\nTrying connect again");
            delay(5000);
        }
    }
}

void setup()
{
    Serial.begin(115200);
    setupWifi();
    client.setServer(broker, port);
}

void loop()
{
    // put your main code here,to run repeatedly:
    if (!client.connected())
    {
        reconnect();
    }
    client.loop();
    client.publish("secretaria", '{ "mesa": "2", "sensor": "Livre" }');
} */
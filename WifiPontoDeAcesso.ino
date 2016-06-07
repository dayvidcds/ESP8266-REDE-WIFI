#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char *ssid = "NomeDaRede";
const char *password = "senh@123456";

ESP8266WebServer server(80);

void handleRoot() {
	server.send(200, "text/html", "<h1>Golira</h1><br><input type = ""text""/>");
}

void setup() {
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configurando ponto de acesso...");
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("Endereço IP: ");
	Serial.println(myIP);
	server.on("/", handleRoot);
	server.begin();
	Serial.println("HTTP Server Iniciado!");
}

void loop() {
	server.handleClient();
}

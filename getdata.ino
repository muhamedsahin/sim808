#include <SoftwareSerial.h>

SoftwareSerial SIM808(7, 8); // RX, TX

void setup() {
  SIM808.begin(9600);
  SIM808.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  delay(1000);
  SIM808.println("AT+SAPBR=3,1,\"APN\",\"<apn>\"");
  delay(1000);
  SIM808.println("AT+SAPBR=1,1");
  delay(3000);
}

void loop() {
  SIM808.println("AT+HTTPPARA=\"URL\",\"http://example.com\"");
  delay(1000);
  SIM808.println("AT+HTTPPARA=\"CID\",1");
  delay(1000);
  SIM808.println("AT+HTTPPARA=\"CONTENT\",\"application/json\"");
  delay(1000);
  SIM808.println("AT+HTTPDATA=20,10000");
  delay(10000);
  SIM808.print("{\"name\":\"John\",\"age\":30}");
  delay(1000);
  SIM808.println("AT+HTTPACTION=1");
  delay(3000);
}

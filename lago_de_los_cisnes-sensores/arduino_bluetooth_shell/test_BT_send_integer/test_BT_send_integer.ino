/**
En un terminal hacer
sudo rfcomm connect 0 00:03:19:0D:0E:66 1
Para que se produzca la conexion via puerto serie.
Luego se puede leer desde Pd 

*/

int led = 13;
int val = -1;

void setup(){
	delay(2000);
	Serial.begin(115200);
	delay(2000);
	Serial.print("AT+JSEC=1,1,1,04,1111\r\n"); // Enable security command
	delay(2000);
	Serial.print("AT+JDIS=3\r\n"); // Discorable command
	delay(2000);
	Serial.print("AT+JRLS=1101,11,Serial Port,01,000000\r\n"); // Register local sevice command
	delay(2000);
	Serial.print("AT+JAAC=1\r\n");// Auto accept connection requests command
	delay(2000);
	pinMode(led, OUTPUT);
	digitalWrite(led,HIGH);
	Serial.flush();
	val = Serial.read();
	while (val != 'R'){
	  val = Serial.read();
	}
	delay(1000);
	Serial.print("AT+JSCR\r\n"); // Stream Connection Request command
}

void loop(){
//	Serial.println("88");
//    Serial.write();
    Serial.write(88);
	delay(100);
}

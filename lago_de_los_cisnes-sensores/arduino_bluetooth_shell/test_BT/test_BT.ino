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
	Serial.println("Hola caracola...");
	delay(2000);
}

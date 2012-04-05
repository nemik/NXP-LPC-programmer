HardwareSerial target = HardwareSerial();

int isp = PIN_D0;
int reset = PIN_D1;

void setup()
{
  Serial.begin(19200);
  target.begin(19200);
  pinMode(reset, OUTPUT);
}

void loop() 
{
  digitalWrite(reset,HIGH);
  
  pinMode(isp, INPUT);           // set pin to input
  digitalWrite(isp, HIGH); 

  // pulse reset low
  pinMode(reset, OUTPUT);
  digitalWrite(reset, LOW);
  delay(100);

  // reset input, with pullup
  pinMode(reset, INPUT);
  digitalWrite(reset, HIGH); 

  while (Serial.available() < 1) 
  {
  }

  // pull ISP and nReset low
  pinMode(reset, OUTPUT);
  pinMode(isp, OUTPUT);
  digitalWrite(reset, LOW);
  digitalWrite(isp, LOW);

  delay(10);

  // Bring target out of reset
  pinMode(reset, INPUT);
  digitalWrite(reset, HIGH); 

  delay(10);

	while (1) 
	{
		if (target.available()) 
		{
			Serial.print((char)target.read());
		}
		if (Serial.available()) 
		{
			target.print((char)Serial.read());
		}
	}
}


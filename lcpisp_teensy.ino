HardwareSerial target = HardwareSerial();

int isp = PIN_D0;
int reset = PIN_D1;

int in1;
int in0;
int i;
int l;
int sa;
int ta;

void setup()
{
  Serial.begin(19200);
  target.begin(19200);
  pinMode(reset, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() 
{
  digitalWrite(reset,HIGH);
  
  //digitalWrite(9, HIGH);
  pinMode(isp, INPUT);           // set pin to input
  digitalWrite(isp, HIGH); 
  // ISP Input with pullup
  //isp.input();
  //isp.mode(PullUp);

  pinMode(reset, OUTPUT);
  digitalWrite(reset, LOW);
  // pulse reset low
  //reset.output();
  //reset = 0;
  delay(100);

  pinMode(reset, INPUT);
  digitalWrite(reset, HIGH); 
  // reset input, with pullup
  //reset.input();
  //reset.mode(PullUp);

  while (Serial.available() < 1) {
  }

  digitalWrite(13,HIGH);

  pinMode(reset, OUTPUT);
  pinMode(isp, OUTPUT);
  digitalWrite(reset, LOW);
  digitalWrite(isp, LOW);
  // pull ISP and nReset low
  //reset.output();
  //isp.output();
  //reset = 0;
  //isp = 0;

  delay(10);

  pinMode(reset, INPUT);
  digitalWrite(reset, HIGH); 
  // Bring target out of reset
  //reset.input();
  //reset.mode(PullUp);

  delay(10);

  while (1) {

   if (target.available()) {
      Serial.print((char)target.read());
  }
  if (Serial.available()) {
      target.print((char)Serial.read());
  }
   
    
  }
}


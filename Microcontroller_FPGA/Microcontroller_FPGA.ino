////////////////////////////////////////
// Filename: Microcontroller_FPGA     //
// Authors: Alex Rhee and Robert King //
// Date Created: 3/20/23              //
// Last Modified: 3/20/23             //
////////////////////////////////////////

int SYN = 2; //SS
int SYN_EN = 3;
int XTAL_EN = 4;
int UPC = 5; //SS
int PA_EN = 6;
int DNC = 7; //SS
int LNA_EN = 8;
int VB_EN = 9;
int SDO = 11; //MOSI
int SDI = 12; //MISO
int SCLK = 13; //SCK

void setup()
{
  Serial.begin(9600);

  pinMode(SYN, OUTPUT);
  pinMode(SYN_EN, OUTPUT);
  pinMode(XTAL_EN, OUTPUT);
  pinMode(UPC, OUTPUT);
  pinMode(PA_EN, OUTPUT);
  pinMode(DNC, OUTPUT);
  pinMode(LNA_EN, OUTPUT);
  pinMode(VB_EN, OUTPUT);
  pinMode(SDO, OUTPUT);
  pinMode(SDI, INPUT);
  pinMode(SCLK, OUTPUT);

  digitalWrite(SYN, LOW); //Disable device
  digitalWrite(SYN_EN, LOW); //Disable device
  digitalWrite(XTAL_EN, LOW); //Disable device
  digitalWrite(UPC, LOW); //Disable device
  digitalWrite(PA_EN, LOW); //Disable device
  digitalWrite(DNC, LOW); //Disable device
  digitalWrite(LNA_EN, LOW); //Disable device
  digitalWrite(VB_EN, LOW); //Disable device

  while (!Serial); //Checks if Serial Monitor is open

  Serial.println("Input 1 for off state and values 2 - 4 to turn on synthesizer, up converter, and down converter subsystems");
}

void loop()
{
  if (Serial.available()) //Checks if data has arrived
  {
    int state = Serial.parseInt(); //Looks for a valid integer

    if (state == 1) //Checks state integer
    {
      digitalWrite(SYN, LOW); //Disable device
      digitalWrite(SYN_EN, LOW); //Disable device
      digitalWrite(XTAL_EN, LOW); //Disable device
      digitalWrite(UPC, LOW); //Disable device
      digitalWrite(PA_EN, LOW); //Disable device
      digitalWrite(DNC, LOW); //Disable device
      digitalWrite(LNA_EN, LOW); //Disable device
      digitalWrite(VB_EN, LOW); //Disable device
    }
    else if (state == 2) //Checks state integer
    {
      digitalWrite(SYN, HIGH); //Enable device
      digitalWrite(SYN_EN, HIGH); //Enable device
      digitalWrite(XTAL_EN, HIGH); //Enable device

      digitalWrite(UPC, LOW); //Disable device
      digitalWrite(PA_EN, LOW); //Disable device
      digitalWrite(DNC, LOW); //Disable device
      digitalWrite(LNA_EN, LOW); //Disable device
      digitalWrite(VB_EN, LOW); //Disable device
    }
    else if (state == 3) //Checks state integer
    {
      digitalWrite(UPC, HIGH); //Enable device
      digitalWrite(PA_EN, HIGH); //Enable device

      digitalWrite(SYN, LOW); //Disable device
      digitalWrite(SYN_EN, LOW); //Disable device
      digitalWrite(XTAL_EN, LOW); //Disable device
      digitalWrite(DNC, LOW); //Disable device
      digitalWrite(LNA_EN, LOW); //Disable device
      digitalWrite(VB_EN, LOW); //Disable device
    }
    else if (state == 4) //Checks state integer
    {
      digitalWrite(DNC, HIGH); //Enable device
      digitalWrite(LNA_EN, HIGH); //Enable device
      digitalWrite(VB_EN, HIGH); //Enable device

      digitalWrite(SYN, LOW); //Disable device
      digitalWrite(SYN_EN, LOW); //Disable device
      digitalWrite(XTAL_EN, LOW); //Disable device
      digitalWrite(UPC, LOW); //Disable device
      digitalWrite(PA_EN, LOW); //Disable device
    }
  }
}

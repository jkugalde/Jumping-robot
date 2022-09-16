const int s1 = A0;
const int s2 = A1;

int aread0 = 0;
int aread1 = 0;

void setup() {
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  Serial.begin(9600);

}

void loop() {

aread0 = analogRead(s1);
aread1 = analogRead(s2);

Serial.print(aread0);
Serial.print("    ");
Serial.println(aread1);

}

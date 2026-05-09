#define echoPin 12
#define trigPin 13
#define    enA 3
#define    in1 5
#define    in2 4
#define    enB 9
#define    in3 7
#define    in4 8

long sure, uzaklik;

void setup(){
       pinMode(enA,OUTPUT);
      pinMode(in1,OUTPUT);
      pinMode(in2,OUTPUT);
       pinMode(enB,OUTPUT);
      pinMode(in3,OUTPUT);
      pinMode(in4,OUTPUT); 
      pinMode(echoPin,INPUT);
      pinMode(trigPin,OUTPUT);
      Serial.begin(9600);
}

void loop(){
  Serial.println(uzaklik);
digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure=pulseIn(echoPin, HIGH);
  uzaklik = 0.01723 * sure;

  if(uzaklik>0 && uzaklik<25){
    geri();
    delay(1000);
    sag();
    delay(500);
    Serial.println("geri + sag");}

  else{
    ileri(); 
    Serial.println("geri + sag");} 
}


void geri(){
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      analogWrite(enA,150);
      analogWrite(enB,150);
}
void ileri(){
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
      analogWrite(enA,150);
      analogWrite(enB,150);
}
void sag(){
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      analogWrite(enA,150);
}

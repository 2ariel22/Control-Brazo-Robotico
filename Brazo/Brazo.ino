#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos_0 = 172; // Calculo de pulsos para 0 grados
unsigned int pos_180 = 565; //Calculo de pulsos para 180 grados

const int servo_ch_1 = 0,servo_ch_2 = 1,servo_ch_3 = 2,servo_ch_4 = 3,servo_ch_5 = 4;// asignar el canal

int PosicionS1 = 0,PosicionS2 = 180,PosicionS3 = 0,PosicionS4 = 0,PosicionS5 = 180;

void movServo(uint8_t n_servo, int angulo) {
  int duty;
  duty = map(angulo, 0, 180, pos_0, pos_180);
  servos.setPWM(n_servo, 0, duty);
}

void MoveMid(bool Direccion){

  if(Direccion){
    PosicionS1+=5;
    PosicionS2-=5;
    movServo(servo_ch_2, PosicionS2); //Mover servo del canal 1
    delay(50);
    movServo(servo_ch_1, PosicionS1); //Mover servo del canal 1
    delay(50);
  }
  else{
    PosicionS1-=5;
    PosicionS2+=5;
    movServo(servo_ch_2, PosicionS2); //Mover servo del canal 1
    delay(50);
    movServo(servo_ch_1, PosicionS1); //Mover servo del canal 1
    delay(50);
  }
  Serial.println(PosicionS1);
  Serial.println(PosicionS2);
}

void MoveBase(bool Direccion){ //HIGH para sumar
  if(Direccion){
    PosicionS3+=5;
    movServo(servo_ch_3, PosicionS3); //Mover servo del canal 1
    delay(50);
  }
  else{
    PosicionS3-=5;
  movServo(servo_ch_3, PosicionS3); //Mover servo del canal 1
  
  delay(50);
  }
  
  Serial.println(PosicionS3);

}

void MoveEfector(bool Direccion){

  if(Direccion){
    PosicionS4+=5;
    movServo(servo_ch_4, PosicionS4); //Mover servo del canal 1
    delay(50);
  }
  else{
    PosicionS4-=5;
  movServo(servo_ch_4, PosicionS4); //Mover servo del canal 1
  
  delay(100);
  }
  
  Serial.println(PosicionS4);

}
void Gripper(bool Direccion){
   if(Direccion){
    PosicionS5+=5;
    movServo(servo_ch_5, PosicionS5); //Mover servo del canal 1
    delay(50);
  }
  else{
    PosicionS5-=5;
  movServo(servo_ch_5, PosicionS5); //Mover servo del canal 1
  
  delay(100);
  }
  
  Serial.println(PosicionS5);
}


void Inicial(){
  PosicionS1 = 0,PosicionS2 = 180,PosicionS3 = 0,PosicionS4 = 0,PosicionS5 = 180;
  movServo(servo_ch_1, PosicionS1); //Mover servo del canal 1
  
  movServo(servo_ch_2, PosicionS2); //Mover servo del canal 1
  
  movServo(servo_ch_3, PosicionS3); //Mover servo del canal 1

  movServo(servo_ch_4, PosicionS4); //Mover servo del canal 1
 
  movServo(servo_ch_5, PosicionS5); //Mover servo del canal 1
  delay(100);


}

void VerificarAngulo(){
  if(PosicionS1 > 175){
    PosicionS1 = 175;
  }
  else if(PosicionS1 < 5){
    PosicionS1 = 5;
  }

  if(PosicionS2 > 175){
    PosicionS2 = 175;
  }
  else if(PosicionS2 < 5){
    PosicionS2 = 5;
  }

  if(PosicionS3 > 175){
    PosicionS3 = 175;
  }
  else if(PosicionS3 < 5){
    PosicionS3 = 5;
  }
  if(PosicionS4 > 175){
    PosicionS4 = 175;
  }
  else if(PosicionS4 < 5){
    PosicionS4 = 5;
  }
  if(PosicionS5 > 175){
    PosicionS5 = 175;
  }
  else if(PosicionS5 < 5){
    PosicionS5 = 5;
  }
}

void setup() {
  Serial.begin(9600);
  servos.begin();
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz
  Inicial();
  

}

void loop() {
  if(Serial.available()){
    char dato = Serial.read();
    VerificarAngulo();
    
    if(dato =='0'){
      Gripper(HIGH);
    }
    else if(dato =='a'){
      Gripper(LOW);
    }
    else if(dato =='1'){
      MoveBase(HIGH);
    }
    else if(dato =='2'){
      MoveBase(LOW);
    }
    else if(dato =='3'){
      MoveMid(HIGH);
    }
    else if(dato =='4'){
      MoveMid(LOW);
    }
     else if(dato =='5'){
      MoveEfector(HIGH);
    }
    else if(dato =='6'){
      MoveEfector(LOW);
    }
    else if(dato =='7'){
      MoveEfector(HIGH);
    }
    else if(dato =='8'){
      MoveEfector(LOW);
    }
 
    else if(dato =='9'){
      Inicial();
    }

    delay(100);
  }
  

}
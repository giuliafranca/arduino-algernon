#define SensorDrt 7
#define SensorEsq 5
#define SensorFrente1 8
#define SensorFrente2 4

#define MotorD_sentido1 11
#define MotorD_sentido2 10
#define MotorE_sentido1 9
#define MotorE_sentido2 6

int pwm, espera;

void setup() {
  Serial.begin(9600);
  pinMode(MotorE_sentido1, OUTPUT);
  pinMode(MotorE_sentido2, OUTPUT);
  pinMode(MotorD_sentido1, OUTPUT);
  pinMode(MotorD_sentido2, OUTPUT);
  
  pinMode(SensorDrt, INPUT);
  pinMode(SensorEsq, INPUT);
  pinMode(SensorFrente1, INPUT);
  pinMode(SensorFrente2, INPUT);

/* boas práticas*/
  analogWrite(MotorE_sentido1, 0);
  analogWrite(MotorE_sentido2, 0);
  analogWrite(MotorD_sentido1, 0);
  analogWrite(MotorD_sentido2, 0);

  pwm = 0;
  espera = 0;
}

void loop() {
//  Correr(128);
//  if(digitalRead(SensorDrt) == 1){ //direita liberada
//    Parar();
//    RodarDir(255, 300);
//  }else if (digitalRead(SensorEsq) == 1 && (digitalRead(SensorFrente1) || digitalRead(SensorFrente2)) == 0 && digitalRead(SensorDrt) == 0){ //apenas esquerda liberada
//    Parar();
//    RodarEsq(255, 300);
//  }else if((digitalRead(SensorFrente1) || digitalRead(SensorFrente2)) == 0 && digitalRead(SensorEsq) == 0 && digitalRead(SensorDrt) == 0){ //todos bloqueados
//    Parar();
//    RodarDir(255, 600);
//  }
    
//    Correr(255);
//    Parar();
//    Re(255);
//    Parar();
//    RodarEsq(255, 300);
//    Parar();
//    RodarDir(255, 300);

      Correr(205);
      if(digitalRead(SensorFrente1) == 0 && digitalRead(SensorFrente2) == 0){
        Re(255);
        Parar();
        Parar();
        RodarDir(255, 550);
        Parar();
      }
}


void Correr(int pwm){
  analogWrite(MotorE_sentido1, pwm);
  analogWrite(MotorE_sentido2, 0);
  analogWrite(MotorD_sentido1, pwm);
  analogWrite(MotorD_sentido2, 0);
  delay(500);
}

void Re(int pwm){
  analogWrite(MotorE_sentido1, 0);
  analogWrite(MotorE_sentido2, pwm);
  analogWrite(MotorD_sentido1, 0);
  analogWrite(MotorD_sentido2, pwm);
  delay(500);
}

void RodarDir(int pwm, int del){
    analogWrite(MotorE_sentido1, pwm);
    analogWrite(MotorE_sentido2, 0);
    analogWrite(MotorD_sentido1, 0);
    analogWrite(MotorD_sentido2, pwm);
    delay(del);
}

void RodarEsq(int pwm, int del){
    analogWrite(MotorE_sentido1, 0);
    analogWrite(MotorE_sentido2, pwm);
    analogWrite(MotorD_sentido1, pwm);
    analogWrite(MotorD_sentido2, 0);
    delay(del);
}

void Parar(){
  digitalWrite(MotorE_sentido1, HIGH);
  digitalWrite(MotorE_sentido2, HIGH);
  digitalWrite(MotorD_sentido1, HIGH);
  digitalWrite(MotorD_sentido2, HIGH); 
  delay(1000);
}

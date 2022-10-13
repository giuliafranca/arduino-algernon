#define SensorDrt 7
#define SensorEsq 5
#define SensorFrente1 8
#define SensorFrente2 4

#define MotorD_sentido1 11
#define MotorD_sentido2 10
#define MotorE_sentido1 9
#define MotorE_sentido2 6

int velesq, veldir, meia, completa;

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

  velesq = 0;
  veldir = 0;
  meia = 0;
  completa = 0;
}

void loop() {
    velesq = 100;
    veldir = 100;
    meia = 380;  //para 100 de velocidade
    completa = 630; //para 100 de velocidade
//  Correr(128);
//  if(digitalRead(SensorDrt) == 1){ //direita liberada
//    Parar();
//    RodarDir(64, 3);
//  }else if (digitalRead(SensorEsq) == 1 && (digitalRead(SensorFrente1) == 0 || digitalRead(SensorFrente2) == 0)){ //apenas esquerda liberada
//    Parar();
//    RodarEsq(64, 6);
//  }else if((digitalRead(SensorEsq) == 0){ //todos bloqueados
//    Parar();
//    RodarDir(64, 12);
//  }
      Correr(velesq, veldir);
//      if(digitalRead(SensorFrente1) == 0 && digitalRead(SensorFrente2) == 0){
//        Parar();
//        Re(velesq, veldir);
//        Parar();
//        RodarDir(velesq, veldir, completa);
//        Parar();
//      }
}


void Correr(int pwm1,int pwm2){
  analogWrite(MotorE_sentido1, pwm1);
  analogWrite(MotorE_sentido2, 0);
  analogWrite(MotorD_sentido1, pwm2);
  analogWrite(MotorD_sentido2, 0);
//  delay(500);
}

void Re(int pwm1,int pwm2){
  analogWrite(MotorE_sentido1, 0);
  analogWrite(MotorE_sentido2, pwm1);
  analogWrite(MotorD_sentido1, 0);
  analogWrite(MotorD_sentido2, pwm2);
  delay(300);
}

void RodarDir(int pwm1, int pwm2, int del){
    analogWrite(MotorE_sentido1, pwm1);
    analogWrite(MotorE_sentido2, 0);
    analogWrite(MotorD_sentido1, 0);
    analogWrite(MotorD_sentido2, pwm2);
    delay(del);
}

void RodarEsq(int pwm1, int pwm2, int del){
    analogWrite(MotorE_sentido1, 0);
    analogWrite(MotorE_sentido2, pwm1);
    analogWrite(MotorD_sentido1, pwm2);
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

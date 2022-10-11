#define SensorDrt 7
#define SensorEsq 5
#define SensorFrente1 8
#define SensorFrente2 4
#define Encoder1 2
#define Encoder2 3

#define MotorD_sentido1 11
#define MotorD_sentido2 10
#define MotorE_sentido1 9
#define MotorE_sentido2 6

unsigned int pulsos_por_volta = 20;
int pwm;
volatile long int pulsos1;

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
  pinMode(Encoder1, INPUT);

  //aciona o contador a cada pulso
  attachInterrupt(digitalPinToInterrupt(Encoder1), Contador1, FALLING); 

/* boas práticas*/
  analogWrite(MotorE_sentido1, 0);
  analogWrite(MotorE_sentido2, 0);
  analogWrite(MotorD_sentido1, 0);
  analogWrite(MotorD_sentido2, 0);

  pwm = 0;
  pulsos1 = 0;
}

void loop() {
//  Correr(128);
//  if(digitalRead(SensorDrt) == 1){ //direita liberada
//    Parar();
//    RodarDir(64, 3);
//  }else if (digitalRead(SensorEsq) == 1 && (digitalRead(SensorFrente1) || digitalRead(SensorFrente2)) == 0 && digitalRead(SensorDrt) == 0){ //apenas esquerda liberada
//    Parar();
//    RodarEsq(64, 6);
//  }else if((digitalRead(SensorFrente1) || digitalRead(SensorFrente2)) == 0 && digitalRead(SensorEsq) == 0 && digitalRead(SensorDrt) == 0){ //todos bloqueados
//    Parar();
//    RodarDir(64, 12);
//  }
 //   RodarEsq(100, 20);
    Parar();    
}


void Correr(int pwm){
  analogWrite(MotorE_sentido1, pwm);
  analogWrite(MotorE_sentido2, 0);
  analogWrite(MotorD_sentido1, pwm);
  analogWrite(MotorD_sentido2, 0);
}

void RodarDir(int pwm, int psl){
  pulsos1 = 0;
  while(pulsos1 <= psl){
    analogWrite(MotorE_sentido1, pwm);
    analogWrite(MotorE_sentido2, 0);
    analogWrite(MotorD_sentido1, 0);
    analogWrite(MotorD_sentido2, pwm);
  }
}

void RodarEsq(int pwm, int psl){
  pulsos1 = 0;
  while(pulsos1 <= psl){
    analogWrite(MotorE_sentido1, 0);
    analogWrite(MotorE_sentido2, pwm);
    analogWrite(MotorD_sentido1, pwm);
    analogWrite(MotorD_sentido2, 0);
//    Serial.println(voltas1);
  }
}

void Parar(){
  digitalWrite(MotorE_sentido1, HIGH);
  digitalWrite(MotorE_sentido2, HIGH);
  digitalWrite(MotorD_sentido1, HIGH);
  digitalWrite(MotorD_sentido2, HIGH); 
  delay(4000);
}

void Contador1(){ 
  pulsos1++;
  delay(100);
  Serial.println(pulsos1);
}

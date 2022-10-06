#define SensorDrt 4 
#define SensorEsq 3
#define SensorFrente1 5
#define SensorFrente2 2
#define Encoder1 1
#define Encoder2 7

#define MotorA_sentido1 11
#define MotorA_sentido2 10
#define MotorB_sentido1 9
#define MotorB_sentido2 6

unsigned int pulsos_por_volta = 20;
int pwm, voltas1, voltas2;
unsigned long int pulsos1, pulsos2;

void setup() {
  Serial.begin(9600);
  pinMode(MotorA_sentido1, OUTPUT);
  pinMode(MotorA_sentido2, OUTPUT);
  pinMode(MotorB_sentido1, OUTPUT);
  pinMode(MotorB_sentido2, OUTPUT);
  
  pinMode(SensorDrt, INPUT);
  pinMode(SensorEsq, INPUT);
  pinMode(SensorFrente1, INPUT);
  pinMode(SensorFrente2, INPUT);
  pinMode(Encoder1, INPUT);
  pinMode(Encoder2, INPUT);

  //aciona o contador a cada pulso
  attachInterrupt(Encoder1, Contador1, RISING); 
  attachInterrupt(Encoder2, Contador2, RISING); 

/* boas práticas*/
  analogWrite(MotorA_sentido1, 0);
  analogWrite(MotorA_sentido2, 0);
  analogWrite(MotorB_sentido1, 0);
  analogWrite(MotorB_sentido2, 0);

  pwm = 0;
  pulsos1 = 0;
  voltas1 = 0;
  pulsos2 = 0;  
  voltas2 = 0;
}

void loop() {
  Correr(64);
  if(digitalRead(SensorDrt) == 1){ //direita liberada
    Parar();
    RodarDir(64, 64, 6);
  }else if (digitalRead(SensorEsq) == 1 && (digitalRead(SensorFrente1) || digitalRead(SensorFrente2)) == 0 && digitalRead(SensorDrt) == 0){ //apenas esquerda liberada
    Parar();
    RodarEsq(64, 64, 6);
  }else if((digitalRead(SensorFrente1) || digitalRead(SensorFrente2)) == 0 && digitalRead(SensorEsq) == 0 && digitalRead(SensorDrt) == 0){ //todos bloqueados
    Parar();
    RodarDir(64, 64, 12);
  }
}


void Correr(int pwm){
  analogWrite(MotorA_sentido1, 0);
  analogWrite(MotorA_sentido2, pwm);
  analogWrite(MotorB_sentido1, 0);
  analogWrite(MotorB_sentido2, pwm);
}

void RodarDir(int pwm1,int pwm2, int vlt){
  pulsos1 = 0;
  voltas1 = 0;
  while(voltas1 < vlt){
    analogWrite(MotorA_sentido1, pwm1);
    analogWrite(MotorA_sentido2, 0);
    analogWrite(MotorB_sentido1, 0);
    analogWrite(MotorB_sentido2, pwm2);
  }
}

void RodarEsq(int pwm1,int pwm2, int vlt){
  pulsos1 = 0;
  voltas1 = 0;
  while(voltas1 < vlt){
    analogWrite(MotorA_sentido1, 0);
    analogWrite(MotorA_sentido2, pwm1);
    analogWrite(MotorB_sentido1, pwm2);
    analogWrite(MotorB_sentido2, 0);
  }
}

void Parar(){
  digitalWrite(MotorA_sentido1, HIGH);
  digitalWrite(MotorA_sentido2, HIGH);
  digitalWrite(MotorB_sentido1, HIGH);
  digitalWrite(MotorB_sentido2, HIGH); 
}

void Contador1(){ 
  pulsos1++;
  voltas1 = pulsos1/20; 
}

void Contador2(){
  pulsos2++;
  voltas2 = pulsos2/20;
}

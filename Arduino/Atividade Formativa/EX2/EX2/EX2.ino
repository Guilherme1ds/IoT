#define TRIG 9
#define ECHO 10
#define BUZZER 5
#define DIST_MIN 20

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duracao = pulseIn(ECHO, HIGH);
  float distancia = duracao * 0.0343 / 2;

  Serial.print("Distância: ");
  Serial.println(distancia);

  digitalWrite(BUZZER, distancia > 0 && distancia < DIST_MIN);
  delay(200);
}

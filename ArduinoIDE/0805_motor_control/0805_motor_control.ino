// 핀 설정
const int stepPin = 3;     // STEP 핀
const int dirPin = 4;      // DIR 핀
const int enPin = 2;       // ENABLE 핀

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);

  // 모터 드라이버 활성화
  digitalWrite(enPin, LOW);

  // 회전 방향 설정 (HIGH = 정방향, LOW = 역방향)
  digitalWrite(dirPin, HIGH);
}

void loop() {
  // 스텝 200개 = 1회전 (기본 1.8도 스텝 모터 기준)
  for (int i = 0; i < 200; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000); // 속도 조절 (값을 줄이면 빠르게 회전)
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }

  delay(1000); // 잠시 멈춤

  // 방향 바꾸기
  digitalWrite(dirPin, LOW);
  delay(1000);

  // 반대 방향으로 200스텝
  for (int i = 0; i < 200; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }

  delay(1000);
  digitalWrite(dirPin, HIGH); // 다시 정방향
}

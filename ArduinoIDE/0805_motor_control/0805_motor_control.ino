// 핀 번호 설정
#define EN_PIN   2   // ENABLE
#define STEP_PIN 3   // STEP
#define DIR_PIN  4   // DIRECTION

void setup() {
  pinMode(EN_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  digitalWrite(EN_PIN, LOW);  // ENABLE 활성화 (LOW가 활성)
  digitalWrite(DIR_PIN, LOW); // 초기 방향
}

void loop() {
  // 정방향 200스텝 (1바퀴: 모터 스펙에 따라 다름)
  for (int i = 0; i < 200; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(800); // 펄스 속도
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(800);
  }
  delay(500); // 잠시 대기

  // 방향 반대로 변경
  digitalWrite(DIR_PIN, !digitalRead(DIR_PIN));
  delay(500);
}

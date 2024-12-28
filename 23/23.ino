#include <Fuzzy.h>
#include <DHT.h>
int Sensor_pin = 8;
DHT sensor(Sensor_pin.DHT11);

//Fuzzy
Fuzzy *fuzzy = new Fuzzy();

// FuzzyInput Temperature
FuzzySet *VeryCold = new FuzzySet(0, 0, 10, 20);
FuzzySet *Cold = new FuzzySet(10, 20, 20, 30);
FuzzySet *Good = new FuzzySet(20, 30, 30, 40);
FuzzySet *Hot = new FuzzySet(30, 40, 50, 50);
// FuzzyInput Humidity
FuzzySet *VeryLow = new FuzzySet(0, 0, 20, 40);
FuzzySet *Low = new FuzzySet(20, 40, 40, 60);
FuzzySet *Normal = new FuzzySet(40, 60, 60, 80);
FuzzySet *High = new FuzzySet(60, 80, 80, 100);
FuzzySet *VeryHigh = new FuzzySet(80, 100, 120, 120);
// FuzzyOutput Execution Time
FuzzySet *VeryShort = new FuzzySet(0, 1, 1, 2);
FuzzySet *Short = new FuzzySet(1, 2, 2, 3);
FuzzySet *General = new FuzzySet(2, 3, 3, 4);
FuzzySet *Long = new FuzzySet(3, 4, 4, 5);
FuzzySet *VeryLong = new FuzzySet(4, 5, 5, 6);

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
  // FuzzyInput for Temperature
  FuzzyInput *temperature = new FuzzyInput(1);
  temperature->addFuzzySet(VeryCold);
  temperature->addFuzzySet(Cold);
  temperature->addFuzzySet(Good);
  temperature->addFuzzySet(Hot);
  fuzzy->addFuzzySet(temperature);
  // FuzzyInput for Humidity
  FuzzyInput *humidity = new FuzzyInput(2);
  humidity->addFuzzySet(VeryLow);
  humidity->addFuzzySet(Low);
  humidity->addFuzzySet(Normal);
  humidity->addFuzzySet(High);
  humidity->addFuzzySet(VeryHigh);
  fuzzy->addFuzzySet(humidity);
  // FuzzyOutput for Execution Time
  FuzzyOutput *execution = new FuzzyOutput(1);
  execution->addFuzzySet(VeryShort);
  execution->addFuzzySet(Short);
  execution->addFuzzySet(General);
  execution->addFuzzySet(Long);
  execution->addFuzzySet(VeryLong);
  fuzzy->addFuzzySet(execution);
}

// Building FuzzyRule1
FuzzyRuleAntecedent *antecedent1 = new FuzzyRuleAntecedent();   // 조건식
antecedent1->joinWithAND(VeryCold, VeryLow);

FuzzyRuleCosequent *consequent1 = new FuzzyRuleConsequent();    // 결론
consequent1->addOutput(VeryShort);

FuzzyRule *fuzzyRule1 = new fuzzyRule(1, antecedent1, consequent1);//규칙
fuzzy->addFuzzyRule(fuzzyRule1);

// Building FuzzyRule2
FuzzyRuleAntecedent *antecedent2 = new FuzzyRuleAntecedent();   // 조건식
antecedent2->joinWithAND(Cold, VeryLow);

FuzzyRuleConsequent *consequent2 = new FuzzyRuleConsequent();   // 결론
consequent2->addOutput(VeryShort);

// Building FuzzyRule3
FuzzyRuleAntecedent *antecedent3 = new FuzzyRuleAntecedent();   // 조건식
antecedent3->joinWithAND(Good, VeryLow);

FuzzyRuleConsequent *consequent3 = new FuzzyRuleConsequent();    // 결론
consequent3->addOutput(Short);

FuzzyRule *fuzzyRule3 = new FuzzyRule(3, antecedent3, conseqeunt3);//규칙
fuzzy->addFuzzyRule(fuzzyRule3);

// Building FuzzyRule4
FuzzyRuleAntecedent *antecedent4 = new FuzzyRuleAntecedent(); // 조건식
antecedent4->joinWithAND(Hot, VeryLow);

FuzzyRuleConsequent *consequent4 = new FuzzyRuleConsequent(); // 결론
consequent4->addOutput(Short);

FuzzyRule *fuzzyRule4 = new FuzzyRule(4, antecedent4, consequent4); // 규칙
fuzzy->addFuzzyRule(fuzzyRule4);

// Building FuzzyRule5
FuzzyRuleAntecedent *antecedent5 = new FuzzyRuleAntecedent(); // 조건식
antecedent5->joinWithAND(VeryCold, Low);

FuzzyRuleConsequent *consequent5 = new FuzzyRuleConsequent(); // 결론
consequent5->addOutput(VeryShort);

FuzzyRule *fuzzyRule5 = new FuzzyRule(5, antecedent5, consequent5); // 규칙
fuzzy->addFuzzyRule(fuzzyRule5);

// Building FuzzyRule6
FuzzyRuleAntecedent *antecedent6 = new FuzzyRuleAntecedent(); // 조건식
antecedent6->joinWithAND(Cold, Low);

FuzzyRuleConsequent *consequent6 = new FuzzyRuleConsequent(); // 결론
consequent6->addOutput(Short);

FuzzyRule *fuzzyRule6 = new FuzzyRule(6, antecedent6, consequent6); // 규칙
fuzzy->addFuzzyRule(fuzzyRule6);

// Building FuzzyRule7
FuzzyRuleAntecedent *antecedent7 = new FuzzyRuleAntecedent(); // 조건식
antecedent7->joinWithAND(Good, Low);

FuzzyRuleConsequent *consequent7 = new FuzzyRuleConsequent(); // 결론
consequent7->addOutput(Short);

FuzzyRule *fuzzyRule7 = new FuzzyRule(7, antecedent7, consequent7); // 규칙
fuzzy->addFuzzyRule(fuzzyRule7);

// Building FuzzyRule8
FuzzyRuleAntecedent *antecedent8 = new FuzzyRuleAntecedent(); // 조건식
antecedent8->joinWithAND(Hot, Low);

FuzzyRuleConsequent *consequent8 = new FuzzyRuleConsequent(); // 결론
consequent8->addOutput(General);

FuzzyRule *fuzzyRule8 = new FuzzyRule(8, antecedent8, consequent8); // 규칙
fuzzy->addFuzzyRule(fuzzyRule8);

// Building FuzzyRule9
FuzzyRuleAntecedent *antecedent9 = new FuzzyRuleAntecedent(); // 조건식
antecedent9->joinWithAND(VeryCold, Normal);

FuzzyRuleConsequent *consequent9 = new FuzzyRuleConsequent(); // 결론
consequent9->addOutput(Short);

FuzzyRule *fuzzyRule9 = new FuzzyRule(9, antecedent9, consequent9); // 규칙
fuzzy->addFuzzyRule(fuzzyRule9);

// Building FuzzyRule10
FuzzyRuleAntecedent *antecedent10 = new FuzzyRuleAntecedent(); // 조건식
antecedent10->joinWithAND(Cold, Normal);

FuzzyRuleConsequent *consequent10 = new FuzzyRuleConsequent(); // 결론
consequent10->addOutput(Short);

FuzzyRule *fuzzyRule10 = new FuzzyRule(10, antecedent10, consequent10); // 규칙
fuzzy->addFuzzyRule(fuzzyRule10);

// Building FuzzyRule11
FuzzyRuleAntecedent *antecedent11 = new FuzzyRuleAntecedent(); // 조건식
antecedent11->joinWithAND(Good, Normal);

FuzzyRuleConsequent *consequent11 = new FuzzyRuleConsequent(); // 결론
consequent11->addOutput(General);

FuzzyRule *fuzzyRule11 = new FuzzyRule(11, antecedent11, consequent11); // 규칙
fuzzy->addFuzzyRule(fuzzyRule11);

// Building FuzzyRule12
FuzzyRuleAntecedent *antecedent12 = new FuzzyRuleAntecedent(); // 조건식
antecedent12->joinWithAND(Hot, Normal);

FuzzyRuleConsequent *consequent12 = new FuzzyRuleConsequent(); // 결론
consequent12->addOutput(General);

FuzzyRule *fuzzyRule12 = new FuzzyRule(12, antecedent12, consequent12); // 규칙
fuzzy->addFuzzyRule(fuzzyRule12);

// Building FuzzyRule13
FuzzyRuleAntecedent *antecedent13 = new FuzzyRuleAntecedent(); // 조건식
antecedent13->joinWithAND(VeryCold, High);

FuzzyRuleConsequent *consequent13 = new FuzzyRuleConsequent(); // 결론
consequent13->addOutput(Short);

FuzzyRule *fuzzyRule13 = new FuzzyRule(13, antecedent13, consequent13); // 규칙
fuzzy->addFuzzyRule(fuzzyRule13);

// Building FuzzyRule14
FuzzyRuleAntecedent *antecedent14 = new FuzzyRuleAntecedent(); // 조건식
antecedent14->joinWithAND(Cold, High);

FuzzyRuleConsequent *consequent14 = new FuzzyRuleConsequent(); // 결론
consequent14->addOutput(General);

FuzzyRule *fuzzyRule14 = new FuzzyRule(14, antecedent14, consequent14); // 규칙
fuzzy->addFuzzyRule(fuzzyRule14);

// Building FuzzyRule15
FuzzyRuleAntecedent *antecedent15 = new FuzzyRuleAntecedent(); // 조건식
antecedent15->joinWithAND(Good, High);

FuzzyRuleConsequent *consequent15 = new FuzzyRuleConsequent(); // 결론
consequent15->addOutput(General);

FuzzyRule *fuzzyRule15 = new FuzzyRule(15, antecedent15, consequent15); // 규칙
fuzzy->addFuzzyRule(fuzzyRule15);

// Building FuzzyRule16
FuzzyRuleAntecedent *antecedent16 = new FuzzyRuleAntecedent(); // 조건식
antecedent16->joinWithAND(Hot, High);

FuzzyRuleConsequent *consequent16 = new FuzzyRuleConsequent(); // 결론
consequent16->addOutput(Long);

FuzzyRule *fuzzyRule16 = new FuzzyRule(16, antecedent16, consequent16); // 규칙
fuzzy->addFuzzyRule(fuzzyRule16);

// Building FuzzyRule17
FuzzyRuleAntecedent *antecedent17 = new FuzzyRuleAntecedent(); // 조건식
antecedent17->joinWithAND(VeryCold, VeryHigh);

FuzzyRuleConsequent *consequent17 = new FuzzyRuleConsequent(); // 결론
consequent17->addOutput(General);

FuzzyRule *fuzzyRule17 = new FuzzyRule(17, antecedent17, consequent17); // 규칙
fuzzy->addFuzzyRule(fuzzyRule17);

// Building FuzzyRule18
FuzzyRuleAntecedent *antecedent18 = new FuzzyRuleAntecedent(); // 조건식
antecedent18->joinWithAND(Cold, VeryHigh);

FuzzyRuleConsequent *consequent18 = new FuzzyRuleConsequent(); // 결론
consequent18->addOutput(General);

FuzzyRule *fuzzyRule18 = new FuzzyRule(18, antecedent18, consequent18); // 규칙
fuzzy->addFuzzyRule(fuzzyRule18);

// Building FuzzyRule19
FuzzyRuleAntecedent *antecedent19 = new FuzzyRuleAntecedent(); // 조건식
antecedent19->joinWithAND(Good, VeryHigh);

FuzzyRuleConsequent *consequent19 = new FuzzyRuleConsequent(); // 결론
consequent19->addOutput(Long);

FuzzyRule *fuzzyRule19 = new FuzzyRule(19, antecedent19, consequent19); // 규칙
fuzzy->addFuzzyRule(fuzzyRule19);

// Building FuzzyRule20
FuzzyRuleAntecedent *antecedent20 = new FuzzyRuleAntecedent(); // 조건식
antecedent20->joinWithAND(Hot, VeryHigh);

FuzzyRuleConsequent *consequent20 = new FuzzyRuleConsequent(); // 결론
consequent20->addOutput(VeryLong);

FuzzyRule *fuzzyRule20 = new FuzzyRule(20, antecedent20, consequent20); // 규칙
fuzzy->addFuzzyRule(fuzzyRule20);

void loop() {
    // get random entrances
    int input1 = random(0, 45); // 랜덤 온도 생성 범위 0~45
    int input2 = random(0, 100); // 랜덤 습도 생성 범위 0~100

    Serial.println("\n\nEntrance: "); // 생성된 온도 값 출력
    Serial.print("\tTemperature: ");
    Serial.print(input1);
    Serial.print(", Humidity: "); // 생성된 습도 값 출력
    Serial.println(input2);
}

fuzzy->fuzzify(); // 퍼지화

Serial.println("Input: "); 
Serial.print("\tTemperature: VeryCold -> "); // 온도 수치 값을 퍼지 언어 값으로 변환 결과 확인
Serial.print(VeryCold->getPertinence());
Serial.print(", Cold -> ");
Serial.print(Cold->getPertinence());
Serial.print(", Good -> ");
Serial.print(Good->getPertinence());
Serial.print(", Hot -> ");
Serial.println(Hot->getPertinence());

Serial.print("\tHumidity: VeryLow -> "); // 습도 수치 값을 퍼지 언어 값으로 변환 결과 확인
Serial.print(VeryLow->getPertinence());
Serial.print(", Low -> ");
Serial.print(Low->getPertinence());
Serial.print(", Normal -> ");
Serial.print(Normal->getPertinence());
Serial.print(", High -> ");
Serial.print(High->getPertinence());
Serial.print(", VeryHigh -> ");
Serial.println(VeryHigh->getPertinence());

float output1 = fuzzy->defuzzify(1); // 역퍼지화 결과 확인

Serial.println("Output: ");
Serial.print("\tExecution Time: VeryShort -> ");
Serial.print(VeryShort->getPertinence());
Serial.print(", Short -> ");
Serial.print(Short->getPertinence());
Serial.print(", General -> ");
Serial.print(General->getPertinence());
Serial.print(", Long -> ");
Serial.print(Long->getPertinence());
Serial.print(", VeryLong -> ");
Serial.println(VeryLong->getPertinence());

Serial.println("Result: ");
Serial.print("\t\tExecution Time: ");
Serial.println(output1);

// wait 12 seconds
delay(12000);



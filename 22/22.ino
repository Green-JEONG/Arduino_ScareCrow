#include <Fuzzy.h>

// Fuzzy
Fuzzy *fuzzy = new Fuzzy();

// FuzzyInput Temperature
FuzzySet *VeryCold = new FuzzySet(0, 10, 10, 20);
FuzzySet *Cold = new FuzzySet(10, 20, 20, 30);
FuzzySet *Good = new FuzzySet(20, 30, 30, 40);
FuzzySet *Hot = new FuzzySet(30, 40, 50, 50);

// FuzzyInput Humidity
FuzzySet *VeryLow = new FuzzySet(0, 20, 20, 40);
FuzzySet *Low = new FuzzySet(20, 40, 40, 60);
FuzzySet *Normal = new FuzzySet(40, 60, 60, 80);
FuzzySet *High = new FuzzySet(60, 80, 80, 100);
FuzzySet *VeryHigh = new FuzzySet(80, 100, 120, 120);

// FuzzyOutput Execution Time
FuzzySet *VeryShort = new FuzzySet(0, 1, 1, 2);
FuzzySet *Short = new FuzzySet(2, 3, 3, 4);
FuzzySet *General = new FuzzySet(3, 4, 4, 5);
FuzzySet *Long = new FuzzySet(4, 5, 5, 6);
FuzzySet *VeryLong = new FuzzySet(5, 6, 6, 7);

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(0));

    // FuzzyInput for Temperature
    FuzzyInput *temperature = new FuzzyInput(1);
    temperature->addFuzzySet(VeryCold);
    temperature->addFuzzySet(Cold);
    temperature->addFuzzySet(Good);
    temperature->addFuzzySet(Hot);
    fuzzy->addFuzzyInput(temperature);

    // FuzzyInput for Humidity
    FuzzyInput *humidity = new FuzzyInput(2);
    humidity->addFuzzySet(VeryLow);
    humidity->addFuzzySet(Low);
    humidity->addFuzzySet(Normal);
    humidity->addFuzzySet(High);
    humidity->addFuzzySet(VeryHigh);
    fuzzy->addFuzzyInput(humidity);

    // FuzzyOutput for Execution Time
    FuzzyOutput *execution = new FuzzyOutput(1);
    execution->addFuzzySet(VeryShort);
    execution->addFuzzySet(Short);
    execution->addFuzzySet(General);
    execution->addFuzzySet(Long);
    execution->addFuzzySet(VeryLong);
    fuzzy->addFuzzyOutput(execution);
}

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

    Serial.print("\n\nEntrance: ");
    Serial.print("\tTemperature: "); // 생성된 온도 값 출력
    Serial.print(input1);
    Serial.print(", Humidity: "); // 생성된 습도 값 출력
    Serial.print(input2);
}

// 5161as
// 8LED数字表示モジュール
#define SEGMENT_A 0
#define SEGMENT_MAX 8
#define PIN_OFFSET 2

int mNum[10][SEGMENT_MAX] = {
//   A,B,C,D,E,F,G,H(DP)
    {1,1,1,1,1,1,0,0},  // 0
    {0,1,1,0,0,0,0,0},  // 1
    {1,1,0,1,1,0,1,0},  // 2
    {1,1,1,1,0,0,1,0},  // 3
    {0,1,1,0,0,1,1,0},  // 4
    {1,0,1,1,0,1,1,0},  // 5
    {1,0,1,1,1,1,1,0},  // 6
    {1,1,1,0,0,1,0,0},  // 7
    {1,1,1,1,1,1,1,0},  // 8
    {1,1,1,1,0,1,1,0},  // 9
};

void setup() {
    // init pin
    for (int i=SEGMENT_A; i<SEGMENT_MAX; i++) { pinMode(i+PIN_OFFSET, OUTPUT); }
    Serial.begin(9600);
}

void loop() {
    for (int j=0; j<10; j++) {
        for (int i=SEGMENT_A; i<SEGMENT_MAX; i++) { digitalWrite((i+PIN_OFFSET),mNum[j][i] ); }
        delay(200);
    }
}

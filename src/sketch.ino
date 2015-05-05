// 5161as
// 8LED数字表示モジュール

enum {
    SEGMENT_A = 2,
    SEGMENT_B,
    SEGMENT_C,
    SEGMENT_D,
    SEGMENT_E,
    SEGMENT_F,
    SEGMENT_G,
    SEGMENT_DP,
    SEGMENT_MAX,
};

#define NUM_OFFSET 2

void setup() {
    // init pin
    for (int i=SEGMENT_A; i<SEGMENT_MAX; i++) { pinMode(i, OUTPUT); }
    Serial.begin(9600);
}

int mNum[10][SEGMENT_MAX-NUM_OFFSET] = {
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

void loop() {
    for (int j=0; j<10; j++) {
        for (int i=SEGMENT_A; i<SEGMENT_MAX; i++) { digitalWrite(i,mNum[j][i-NUM_OFFSET] ); }
        delay(200);
    }
}

// 5161as
// 8LED数字表示モジュール

int A  = 2;
int B  = 3;
int C  = 4;
int D  = 5;
int E  = 6;
int F  = 7;
int G  = 8;
int DP = 9;

void setup() {
    // init pin
    for (int i=0; i<9; i++) { pinMode(i+2, OUTPUT); }
    Serial.begin(9600);
}

void alloff(){
    for (int i=0; i<9; i++) { digitalWrite(i+2, LOW); }
}
void allon(){
    for (int i=0; i<9; i++) { digitalWrite(i+2, HIGH); }
}
void zero(){
    alloff();
    allon();
    digitalWrite(G, LOW);
    digitalWrite(DP, LOW);
}
void one(){
    alloff();
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
}

void two() {
    alloff();
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(D, HIGH);
}

void three() {
    alloff();
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
}

void four() {
    alloff();
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
}

void five() {
    alloff();
    digitalWrite(A, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
}
void six() {
    alloff();
    digitalWrite(A, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
}
void seven() {
    alloff();
    digitalWrite(F, HIGH);
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
}
void eight() {
    alloff();
    allon();
    digitalWrite(DP, LOW);
}
void nine() {
    alloff();
    allon();
    digitalWrite(E, LOW);
    digitalWrite(D, LOW);
    digitalWrite(DP, LOW);
}

void (*pf[])() = {zero, one, two, three, four, five, six, seven, eight, nine};

void loop() {
    for (int i=0; i<(sizeof(pf)/sizeof(pf[0])); i++) {
        pf[i]();
        delay(400);
    }
}

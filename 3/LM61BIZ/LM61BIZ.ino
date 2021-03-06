#define LM61BIZ 25

void setup() {
    Serial.begin(115200);    // シリアルの初期化
    while (!Serial) ;        // シリアル回線が利用可能になるまで待つ
    pinMode(LM61BIZ, INPUT);  // LM61BIZピンのモードを入力モードにする
}

void loop() {
    int e = analogRead(LM61BIZ); // LM61BIZピンの値を読む

    float Vout = e / 4095.0 * 3.3 + 0.1132;  // 補正式を使って電圧を補正する
    float temp = (Vout - 0.6) / 0.01;  // 電圧から温度に変換する
    Serial.println(temp);  // 温度をシリアルに出力する
    delay(1000);  // 1秒待つ
}

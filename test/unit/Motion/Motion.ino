int pir = 3; // เลือกขาอินพุด
int val = 0;  // ตัวแปรไว้อ่านค่าพิน
void setup() {
  Serial.begin(9600);
  pinMode(pir, INPUT); 
}
void loop() {
    val = digitalRead(pir); // อ่านค่าจากเซนเซอร์ PIR
    Serial.print("val : ");
    Serial.println(val); // พิมพ์ค่าที่จับได้จาก PIR
  if (val == 1) { // ถ้าค่า PIR เป็น 1 แสดงว่าตรวจพบวัตถุ สั่งเปิดไฟ LED
    digitalWrite(pir, 1); //ไฟติด
  }else {
    digitalWrite(pir, 0); // ไฟดับ
  }
  delay(100);
} 
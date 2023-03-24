

#define BLYNK_TEMPLATE_ID "TMPLpREmGgei"
#define BLYNK_DEVICE_NAME "Kontrol Lampu"
#define BLYNK_AUTH_TOKEN "lXmJjkoiz1fiOafGEC_eynMuLYNR5xIz"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "lXmJjkoiz1fiOafGEC_eynMuLYNR5xIz";
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;

#define LED 18
int SW_state = 0; //kondisi lampu mati

BLYNK_WRITE (V0)
{
  SW_state = param.asInt();
  if(SW_state == 1){
    digitalWrite(LED, HIGH);
    Serial.println("Lampu telah dihidupkan");
    Blynk.virtualWrite(V0, HIGH);
  }else{
    digitalWrite(LED, LOW);
    Serial.println("Lampu telah dimatikan");
    Blynk.virtualWrite(V0, LOW);
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
}

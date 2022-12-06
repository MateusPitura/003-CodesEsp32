#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enable! Please run `menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

int led = 2;
int ledd = 4;
char recebido;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("RedeESP32");
  pinMode(led, OUTPUT);
}

void loop() {
  if(SerialBT.available()){
    recebido = SerialBT.read();
  }

  if (recebido == 'F'){
    digitalWrite(ledd, HIGH);
  }
  if (recebido == 'B'){
    digitalWrite(ledd, LOW);
  }
  if (recebido == 'L'){
    digitalWrite(led, HIGH);
  }
  if (recebido == 'R'){
    digitalWrite(led, LOW);
  }
  
  delay;
}

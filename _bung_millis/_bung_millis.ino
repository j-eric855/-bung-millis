/*
   Funktion:        Eine LED blinkt im Sekunden Takt die andere alle halbe Sekunde
   Programierer:    Eric Junker
   letzte Änderung: 17.11.2020
   Version:         1.0
   Hardware:        Pin 2 güne LED
                    Pin 6 rote LED
*/

#include <OneButton.h>

unsigned long zeitAnfangRot = 0;
unsigned long zeitAnfangGruen = 0;
unsigned long zeitRot = 1000;
unsigned long zeitGruen = 500;
bool merkerLedRot = false;
bool merkerLedGruen = false;
bool merkerTaster = false;
OneButton taster(10, true);

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  taster.attachClick(Taster_Funktion);

}

void loop()
{
  taster.tick();
  delay(10);

  
  if ((millis() - zeitAnfangRot) > zeitRot)
  {
    if (merkerTaster == true)
    {
      merkerLedRot = !merkerLedRot;
    }
    zeitAnfangRot = millis();
  }
  if (merkerLedRot == true)
  {
    digitalWrite(6, HIGH);
  }
  else
  {
    digitalWrite(6, LOW);
  }

  if ((millis() - zeitAnfangGruen) > zeitGruen)
  {
    if (merkerTaster == true)
    {
      merkerLedGruen = !merkerLedGruen;
    }
    zeitAnfangGruen = millis();
  }
  if (merkerLedGruen == true)
  {
    digitalWrite(2, HIGH);
  }
  else
  {
    digitalWrite(2, LOW);
  }
  if (merkerTaster ==false)
  {
    digitalWrite(2, LOW);
    digitalWrite(6,LOW);
  }

}

void Taster_Funktion()
{
  merkerTaster = !merkerTaster;
}

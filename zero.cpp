#include <Arduino.h>
#include "zero.h"

bool Moteur_config (String Moteur) {
  int MoteurA, MoteurB;

  if (Moteur == "Moteur1")
  {
    MoteurA = 2;
    MoteurB = 3;
  }
  else if (Moteur == "Moteur2")
  {
    MoteurA = 4;
    MoteurB = 5;
  }
  else
  {
    return 1;
  }
  pinMode(MoteurA, OUTPUT);
  pinMode(MoteurB, OUTPUT);
  return 0;
}



bool Moteur (String Moteur, String Pilotage)
{
  int MoteurA, MoteurB;
  if (Moteur == "Moteur1")
  {
    MoteurA = 2;
    MoteurB = 3;
  }

  else if (Moteur == "Moteur2")
  {
    MoteurA = 4;
    MoteurB = 5;
  }
  else
  {
    return 1;
  }

  if ((Pilotage == "Ouverture") || (Pilotage == "Montée"))
  {
    digitalWrite(MoteurA, HIGH);
    digitalWrite(MoteurB, LOW);
    return 0;
  }
  else if ((Pilotage == "Fermeture") || (Pilotage == "Descente"))
  {
    digitalWrite(MoteurA, LOW);
    digitalWrite(MoteurB, HIGH);
    return 0;
  }
  else if (Pilotage == "Arrêt")
  {
    digitalWrite(MoteurA, LOW);
    digitalWrite(MoteurB, LOW);
    return 0;
  }
  else
  {
    return 1;
  }
}

//************************************************************************

bool Bouton (String bouton) {
  
  int bouton1 = A5;
  int bouton2 = A4;
  if (bouton == "Bouton1")
  {
    int BOUTON1 = analogRead(bouton1);
    if (BOUTON1 < 700)
    {
      return 1;
    }
    else
    {
      return 0;
    }
    
  }
  else if (bouton == "Bouton2") {
    int BOUTON2 = analogRead(bouton2);
    if (BOUTON2 < 700)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 1;
  }
}


bool fdc (String fdc) {
  int fdc1 = 10;
  int fdc2 = 11;
  int fdc3 = 12;
  int fdc4 = 13;

  if (fdc == "fdc1") {

    bool etat_fdc1 = !digitalRead(fdc1);
    return etat_fdc1;
  }

  else if (fdc == "fdc2")
  {
    bool etat_fdc2 = !digitalRead(fdc2);
    return etat_fdc2;
  }
  else if (fdc == "fdc3")
  {
    bool etat_fdc3 = !digitalRead(fdc3);
    return etat_fdc3;

  }
  else if (fdc == "fdc4")
  {
    bool etat_fdc4 = !digitalRead(fdc4);
    return etat_fdc4;

  }

}

//*********************************************************************

bool Recepteur_config (String Recepteur) {
  int Recept;
  if (Recepteur == "Récepteur1")
  {
    Recept = 6;
  }
  else if (Recepteur == "Récepteur2")
  {
    Recept = 7;
  }
  else
  {
    return 1;
  }
  pinMode(Recept, INPUT);
  return 0;
}




bool Recepteur (String recepteur)
{ int recepteur1 = 6;
  int recepteur2 = 7;

  if (recepteur == "Récepteur1") {

    bool etat_IR1 = !digitalRead(recepteur1);
    return etat_IR1;
  }

  else if (recepteur == "Récepteur2")
  {
    bool etat_IR2 = !digitalRead(recepteur2);
    return etat_IR2;
  }
}

//***********************************************************************

bool led_config (String led) {
  int ledA, ledB;

  if ((led == "led_haut") || (led == "led_portail"))
  {
    ledA = 8;
  }
  else if (led == "led_bas")
  {
    ledB = 9;
  }
  else
  {
    return 1;
  }
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  return 0;
}


bool Led (String led, String Pilotage)
{
  int ledA, ledB;
  if ((led == "led_haut") || (led == "led_portail"))
  {
    ledA = 8;
  }

  else if (led == "led_bas")
  {
    ledB = 9;
  }
  else
  {
    return 1;
  }

  if ((led == "led_portail") && (Pilotage == "Clignotement"))
  {
    digitalWrite(ledA, HIGH);
    delay(1000);
    digitalWrite(ledA, LOW);
    delay(1000);
  }
  else if ((led == "led_haut") && (Pilotage == "Normal"))
  {
    digitalWrite(ledA, HIGH);

    return 0;
  }
  else if ((led == "led_bas") && (Pilotage == "Normal"))
  {
    digitalWrite(ledB, HIGH);
  }

  else
  {
    return 1;
  }
  if (((led == "led_portail") || (led == "led_haut")) && (Pilotage == "Eteint"))
  {
    digitalWrite(ledA, LOW);

  }
  else if ((led == "led_bas") && (Pilotage == "Eteint"))
  {
    digitalWrite(ledB, LOW);

    return 0;

  }
}
  //************************************************************************

  bool Buzzer_config(String buzzer) {
    int Buzzer = 9;
    if (buzzer == "Buzzer") {
      pinMode(Buzzer, OUTPUT);
      return 0;
    }
    else {
      return 1;
    }
  }

  bool Buzzer (String Pilotage) {
    int Buzzer = 9;
    if (Pilotage == "Beep") {

      tone (Buzzer, 600); // allume le buzzer actif arduino
      delay(500);
      tone(Buzzer, 900); // allume le buzzer actif arduino
      delay(500);
      noTone(Buzzer);  // désactiver le buzzer actif arduino
      delay(500);
      return 0;
    }
    else
    {
      return 1;
    }
  }
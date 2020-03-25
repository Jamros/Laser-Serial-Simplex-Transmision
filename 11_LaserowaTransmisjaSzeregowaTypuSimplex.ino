************************************************************
Autor: Kamil Jamros
Wersja: 1.0
Opis wyprowadzeń:
| arduino uno |   LCD  |  USB->UART  |
|      2      |   RS   |             |
|      3      | Enable |             |
|      4      | Data 4 |             |
|      5      | Data 5 |             |
|      6      | Data 6 |             |
|      7      | Data 7 |             |
|     RX      |        |      TX     |
|     GND     | GND    |     GND     |
Opis programu:
Program służy do odbierania danych wysyłanych za pomocą UART i wyświetlania ich w formie tekstu na wyświetlaczu LCD
*****************************************************************
#include <LiquidCrystal.h> //Dołączenie biblioteki do obsługi LCD
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

//Informacja o podłączeniu nowego wyświetlacza
void setup() {
  lcd.begin(16, 2); //Deklaracja typu LCD
  lcd.setCursor(0, 0); //Ustawienie kursora na pozycji 0,0
  lcd.print("Odebrany tekst:"); //Wyświetlenie tekstu
  lcd.setCursor(0, 1); //Ustawienie kursora na pozycji 0,1
  Serial.begin(57600); // Ustawienie prędkości komunikacji UART na 57600
}
void loop() {
  if(Serial.available())
  {
    lcd.clear();
    lcd.setCursor(0, 0); //Ustawienie kursora na pozycji 0,0
    lcd.print("Odebrany tekst:"); //Wyświetlenie tekstu
    lcd.setCursor(0, 1); //Ustawienie kursora na pozycji 0,1
    String tekst=Serial.readStringUntil('\n'); //odczyt tekstu
    lcd.print(tekst); // Wyświetlenie tekstu
  }
}

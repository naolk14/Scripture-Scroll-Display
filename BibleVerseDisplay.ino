// PROJECT   :Bible Verse Display (Summer Project)
// PURPOSE   :Using work for the glory of God
// AUTHOR    : N. Ketema
// DATE      : 2025 06 06
// MCU       : 328P (Standalone)
// STATUS    : Works

#define verse_scroll A7  // potentiometer

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  delay(50);
  lcd.setCursor(5, 0);
  lcd.print("Glory to God");
  lcd.clear();
}

const char* verses[] = {
  "John 3:16",
  "For God so loved",

  "the world that",
  "He gave His Son.",

  "Psalm 23:1",
  "The Lord is my",

  "shepherd;",
  "I shall not want.",

  "Philippians 4:13",
  "I can do all",

  "things through",
  "Christ who",
  "strengthens me.",

  "Genesis 1:1",
  "In the beginning",

  "God created the",
  "heavens and",
  "the earth.",

  "Psalm 119:105",
  "Your word is a",

  "lamp to my feet",
  "and a light to",
  "my path.",

  "Matthew 5:14",
  "You are",
  "the light",

  "of the world.",

  "Romans 8:28",
  "All things work",
  "together for",
  "good to those", "who love God."
};

int lastIndex = -1;
const int array_length = sizeof(verses) / sizeof(verses[0]);

void loop() {
  int potValue = analogRead(verse_scroll);  // 0 to 1023
  int index = map(potValue, 0, 1023, 0, array_length - 1);

  if (index != lastIndex) {
    lastIndex = index;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(verses[index]);
    if (index + 1 < array_length) {
      lcd.setCursor(0, 1);
      lcd.print(verses[index + 1]);
    }
  }
  delay(100);
}

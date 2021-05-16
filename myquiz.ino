#include <Arduino.h>
#include <SPI.h>
#include <Elegoo_GFX.h>
#include <Elegoo_TFTLCD.h>
#include <TouchScreen.h>

//PINS
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4
#define TS_MINX 120
#define TS_MINY 71
#define TS_MAXX 910
#define TS_MAXY 910
#define YP A3
#define XM A2
#define YM 9
#define XP 8
//COLORI
#define  BLACK     0x0000
#define RED       0xF800
#define GREEN     0x07E0
#define YELLOW    0xFFE0
#define WHITE     0xFFFF
#define BLUE      0x04B3
#define ORANGE    0xFD20
#define GREY      0xB552
#define GREEN2    0xAFE5

//INIZIALIZZAZIONE LIBRERIE
Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);

//VARIABILI
//var. pulsante
boolean buttonState = true;
boolean buttonStateP1 = false;
boolean buttonStateP2 = false;
boolean buttonStateP3 = false;
boolean buttonStateP4 = false;
boolean buttonStateP5 = false;
boolean buttonStateP6 = false;
boolean buttonStateP7 = false;
boolean buttonStateP8 = false;
boolean buttonStateP9 = false;
boolean buttonStateP10 = false;
boolean buttonStateP11 = false;
boolean buttonStateP12 = false;
boolean buttonStateP13 = false;
boolean buttonStateP14 = false;
boolean buttonStateP15 = false;
boolean buttonStateP16 = false;
boolean buttonStateP17 = false;
boolean buttonStateP18 = false;
boolean buttonStateP19 = false;
boolean buttonStateP20 = false;
boolean buttonStateP21 = false;
boolean buttonStateP22 = false;
boolean buttonStateP23 = false;
boolean buttonStateP24 = false;
//numero pagina
int numPage = 0;
//contatori
int x = 0;
int y = 0;
int z = 0;
int a = 0;
int b = 0;
int points = 0;
int ard_points = 0;

//DOMANDE SPAZIO
void question1() {
  tft.fillScreen(BLACK);
  tft.drawRect(0, 0, 320, 240, RED);
  tft.setCursor(10, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Quanti pianeti\n\n ci sono nel\n\n Sistema Solare?");

  tft.fillRect(30, 170, 115, 40, RED);
  tft.drawRect(30, 170, 115, 40, WHITE);
  tft.setCursor(84, 182);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("8");
  tft.fillRect(175, 170, 115, 40, RED);
  tft.drawRect(175, 170, 115, 40, WHITE);
  tft.setCursor(224, 182);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("9");
  numPage = numPage + 1;
  points = 0;
  y = 0;
  z = 1;
  b = 0;
  a = 0;
}

void question2() {
  tft.fillScreen(BLACK);
  tft.drawRect(0, 0, 320, 240, RED);
  tft.setCursor(10, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(String("Quanti km ") + String((char)130) + String("\n\n il diametro\n\n del Sole?"));

  tft.fillRect(30, 170, 115, 40, RED);
  tft.drawRect(30, 170, 115, 40, WHITE);
  tft.setCursor(47, 182);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("1.6 mln");
  tft.fillRect(175, 170, 115, 40, RED);
  tft.drawRect(175, 170, 115, 40, WHITE);
  tft.setCursor(192, 182);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("1.4 mln");
  numPage = numPage + 1;
  a = 1;
}

void question3() {
  tft.fillScreen(BLACK);
  tft.drawRect(0, 0, 320, 240, RED);
  tft.setCursor(10, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Cosa si trova tra\n Marte e Giove?");

  tft.fillRect(30, 115, 260, 40, RED);
  tft.drawRect(30, 115, 260, 40, WHITE);
  tft.setCursor(65, 129);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Polveri cosmiche");
  tft.fillRect(30, 175, 260, 40, RED);
  tft.drawRect(30, 175, 260, 40, WHITE);
  tft.setCursor(45, 188);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Fascia di asteroidi");
  numPage = numPage + 1;
}

void question4() {
  tft.fillScreen(BLACK);
  tft.drawRect(0, 0, 320, 240, RED);
  tft.setCursor(10, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(String("Quale pianeta\n\n ") + String((char)130) + String(" pi") + String((char)163) + String(" grande?"));

  tft.fillRect(30, 115, 260, 40, RED);
  tft.drawRect(30, 115, 260, 40, WHITE);
  tft.setCursor(128, 129);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Urano");
  tft.fillRect(30, 175, 260, 40, RED);
  tft.drawRect(30, 175, 260, 40, WHITE);
  tft.setCursor(115, 188);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Nettuno");
  numPage = numPage + 1;
}

void question5() {
  tft.fillScreen(BLACK);
  tft.drawRect(0, 0, 320, 240, RED);
  tft.setCursor(10, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Quali sono dei\n\n pianeti Nani?");

  tft.fillRect(30, 115, 260, 40, RED);
  tft.drawRect(30, 115, 260, 40, WHITE);
  tft.setCursor(70, 129);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Plutone e Metis");
  tft.fillRect(30, 175, 260, 40, RED);
  tft.drawRect(30, 175, 260, 40, WHITE);
  tft.setCursor(82, 188);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Cerere e Eris");
  numPage = numPage + 1;
}

void question6() {
  tft.fillScreen(BLACK);
  tft.drawRect(0, 0, 320, 240, RED);
  tft.setCursor(10, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Quante missioni\n\n sono state fatte\n sulla Luna?");

  tft.fillRect(30, 170, 115, 40, RED);
  tft.drawRect(30, 170, 115, 40, WHITE);
  tft.setCursor(84, 182);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("5");
  tft.fillRect(175, 170, 115, 40, RED);
  tft.drawRect(175, 170, 115, 40, WHITE);
  tft.setCursor(224, 182);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("6");
  numPage = numPage + 1;
}

void question7() {
  tft.fillScreen(BLACK);
  tft.drawRect(0, 0, 320, 240, RED);
  tft.setCursor(10, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(String("Qual'") + String((char)130) + String(" stata l'\n\n ultima missione\n\n Apollo?"));

  tft.fillRect(30, 170, 115, 40, RED);
  tft.drawRect(30, 170, 115, 40, WHITE);
  tft.setCursor(80, 182);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("17");
  tft.fillRect(175, 170, 115, 40, RED);
  tft.drawRect(175, 170, 115, 40, WHITE);
  tft.setCursor(220, 182);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("16");
  numPage = numPage + 1;
}


//RISPOSTE
void ans_true() {
  tft.fillScreen(BLACK);
  tft.drawRect(0, 0, 320, 240, RED);
  tft.setCursor(100, 100);
  tft.setTextColor(GREEN);
  tft.setTextSize(3);
  tft.print("ESATTO!");
  x = 0;
  numPage = numPage + 1;
  points = points + 1;
}

void ans_false() {
  tft.fillScreen(BLACK);
  tft.drawRect(0, 0, 320, 240, RED);
  tft.setCursor(100, 80);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print("ERRATO!");
  x = 0;
  numPage = numPage + 1;
}

//DOMANDE ARDUINO
void ard_question1() {
  tft.fillScreen(WHITE);
  tft.fillRect(0, 0, 320, 40, BLUE);
  tft.setCursor(10, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(String("Cos'") + String((char)130) + String(" Arduino?"));


  tft.fillRect(30, 66, 260, 60, ORANGE);
  tft.setCursor(50, 79);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Scheda elettronica");
  tft.setCursor(40, 99);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("con microcontrollore");

  tft.fillRect(30, 152, 260, 60, ORANGE);
  tft.setCursor(50, 165);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Scheda elettronica");
  tft.setCursor(45, 185);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("con microprocessore");
  ard_points = 0;
  numPage = numPage + 1;
  z = 1;
  b = 1;
  a = 0;
}

void ard_question1_s() {
  tft.fillScreen(WHITE);
  tft.fillRect(0, 0, 320, 40, BLUE);
  tft.setCursor(10, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(String("Cos'") + String((char)130) + String(" Arduino?"));


  tft.fillRect(30, 66, 260, 60, ORANGE);
  tft.setCursor(50, 79);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Scheda elettronica");
  tft.setCursor(40, 99);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("con microcontrollore");

  tft.fillRect(30, 152, 260, 60, ORANGE);
  tft.setCursor(50, 165);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Scheda elettronica");
  tft.setCursor(45, 185);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("con microprocessore");
  ard_points = 0;
  z = 1;
  b = 1;
  a = 0;
}

void ard_question2() {
  tft.fillScreen(WHITE);
  tft.fillRect(0, 0, 320, 90, BLUE);
  tft.setCursor(10, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(String("Arduino ") + String((char)130) + String(" stato\n\n inventato da un:"));


  tft.fillRect(30, 115, 260, 40, ORANGE);
  tft.setCursor(105, 129);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Americano");
  tft.fillRect(30, 175, 260, 40, ORANGE);
  tft.setCursor(110, 188);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Italiano");
  numPage = numPage + 1;
  a = 1;
}

void ard_question3() {
  tft.fillScreen(WHITE);
  tft.fillRect(0, 0, 320, 90, BLUE);
  tft.setCursor(10, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(String("Arduino ") + String((char)130) + String(" una\n\n piattaforma:"));


  tft.fillRect(30, 115, 260, 40, ORANGE);
  tft.setCursor(90, 129);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Proprietaria");
  tft.fillRect(30, 175, 260, 40, ORANGE);
  tft.setCursor(95, 188);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Open Source");
  numPage = numPage + 1;
}

//RISPOSTE ARDUINO
void ard_ans_true() {
  tft.fillScreen(WHITE);
  tft.drawRect(0, 0, 320, 240, ORANGE);
  tft.setCursor(100, 100);
  tft.setTextColor(GREEN);
  tft.setTextSize(3);
  tft.print("ESATTO!");
  x = 0;
  numPage = numPage + 1;
  ard_points = ard_points + 1;

}

void ard_ans_false() {
  tft.fillScreen(WHITE);
  tft.drawRect(0, 0, 320, 240, ORANGE);
  tft.setCursor(100, 80);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print("ERRATO!");
  x = 0;
  numPage = numPage + 1;
}

//PAGINA FINALE
void final_page() {
  tft.fillScreen(BLACK);
  tft.drawRect(0, 0, 320, 240, RED);
  tft.setCursor(10, 10);
  tft.setTextColor(YELLOW);
  tft.setTextSize(4);
  tft.print("RISULTATO");

  tft.setCursor(10, 70);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Punteggio:");

  tft.setCursor(220, 70);
  tft.setTextColor(YELLOW);
  tft.setTextSize(3);
  tft.print(points);

  tft.setCursor(240, 70);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("/7");

  tft.fillRect(30, 115, 260, 40, RED);
  tft.drawRect(30, 115, 260, 40, WHITE);
  tft.setCursor(57, 129);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Ripeti Space Quiz");
  tft.fillRect(30, 175, 260, 40, RED);
  tft.drawRect(30, 175, 260, 40, WHITE);
  tft.setCursor(90, 188);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Arduino Quiz");
  numPage = numPage + 1;
  z = 0;
  a = 0;
}

//PAGINA FINALE ARDUINO
void ard_final_page() {
  tft.fillScreen(WHITE);
  tft.fillRect(0, 0, 320, 50, BLUE);
  tft.setCursor(10, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.print("RISULTATO");

  tft.setCursor(10, 70);
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.print("Punteggio:");

  tft.setCursor(220, 70);
  tft.setTextColor(ORANGE);
  tft.setTextSize(3);
  tft.print(ard_points);

  tft.setCursor(240, 70);
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.print("/3");

  tft.fillRect(30, 115, 260, 40, ORANGE);
  tft.setCursor(45, 129);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Ripeti Arduino Quiz");
  tft.fillRect(30, 175, 260, 40, ORANGE);
  tft.setCursor(100, 188);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Space Quiz");
  numPage = numPage + 1;
  z = 0;
  a = 0;
}

void chose_page() {
  tft.fillScreen(GREY);
  tft.drawRect(0, 0, 320, 240, WHITE);
  tft.drawRect(1, 1, 318, 238, WHITE);
  tft.drawRect(2, 2, 316, 236, WHITE);
  tft.setCursor(41, 23);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("SCEGLI IL TUO");
  tft.setCursor(120, 63);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("QUIZ:");

  tft.fillRect(30, 115, 260, 40, ORANGE);
  tft.drawRect(30, 115, 260, 40, GREEN2);
  tft.setCursor(100, 129);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Space Quiz");
  tft.fillRect(30, 175, 260, 40, ORANGE);
  tft.drawRect(30, 175, 260, 40, GREEN2);
  tft.setCursor(90, 188);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Arduino Quiz");
  numPage = numPage + 1;
  z = 0;
  a = 0;
}

void logo() {
  tft.fillScreen(GREY);
  tft.drawRect(0, 0, 320, 240, WHITE);
  tft.drawRect(1, 1, 318, 238, WHITE);
  tft.drawRect(2, 2, 316, 236, WHITE);
  tft.setCursor(57, 75);
  tft.setTextColor(ORANGE);
  tft.setTextSize(7);
  tft.print("MY");
  tft.setCursor(130, 85);
  tft.setTextColor(GREEN2);
  tft.setTextSize(6);
  tft.print("Quiz");
  tft.setCursor(175, 140);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.print("by Simone Trucci");
}

void setup(void) {
  Serial.begin(9600);
  Serial.println(F("TFT LCD test"));
  Serial.print("TFT size is ");
  Serial.print(tft.width());
  Serial.print("x");
  Serial.println(tft.height());

  tft.reset();
  uint16_t identifier = tft.readID();
  if(identifier==0x0101) {
    identifier=0x9341;
    Serial.println(F("Found 0x9341 LCD driver"));
  }
  tft.begin(identifier);

  tft.setRotation(1);
  logo();


  numPage = 0;
  x = 0;
  y = 0;
  z = 0;
  a = 0;
  points = 0;
  ard_points = 0;
}

void loop(void) {
  TSPoint p = ts.getPoint();

  if (p.z > ts.pressureThreshhold) {
    //Serial.println(String("x = ") + String(p.x));
    //Serial.println(String("y = ") + String(p.y));
    p.x = map(p.x, TS_MAXX, TS_MINX, 0, 240);
    p.y = map(p.y, TS_MAXY, TS_MINY, 0, 320);
    Serial.println(String("x map = ") + String(p.x));
    Serial.println(String("y map = ") + String(p.y));
    Serial.println(String("z = ") + String(p.z));

//pagina di scelta
if (numPage == 0) {
  if(p.y>0 && p.y<320 && p.x>0 && p.x<240 && buttonState) {
    buttonState = false;

    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    chose_page();
  }
}

else if (numPage == 1) {
  if (x == 0) {
    p.x = 0;
    p.y = 0;
    x = 1;
  }
  buttonStateP1 = true;
  if (p.y>30 && p.y<290 && p.x>115 && p.x<145 && buttonStateP1) {
    buttonStateP1 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    numPage = 2;
    question1();
  }
  else if (p.y>30 && p.y<290 && p.x>175 && p.x<215 && buttonStateP1) {
    buttonStateP1 = false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    numPage = 17;
    y = 1;
    ard_question1_s();

  }
}



//domanda 1
    if (numPage == 2) {
      if(p.y>0 && p.y<320 && p.x>0 && p.x<240 && buttonStateP2) {
        buttonStateP2 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        question1();
      }
    }

    else if (numPage == 3) {
      if (x == 0) {
        p.x = 0;
        p.y = 0;
        x = 1;
      }
      buttonStateP3 = true;
      if (p.y>30 && p.y<145 && p.x>170 && p.x<210 && buttonStateP3) {
        buttonStateP3 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ans_true();
      }
      else if (p.y>175 && p.y<290 && p.x>170 && p.x<210 && buttonStateP3) {
        buttonStateP3 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ans_false();
        tft.setCursor(50, 120);
        tft.setTextColor(WHITE);
        tft.setTextSize(2);
        tft.print("Risposta corretta:\n\n         8 pianeti");
      }
    }

//domanda 2
    else if (numPage == 4) {
      if (x == 0) {
        p.x = 0;
        p.y = 0;
        x = 1;
      }
      buttonStateP4 = true;
      if (p.y>300 && p.y<320 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 0;
        chose_page();
      }
      else if (p.y>0 && p.y<20 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 2;
        question1();
      }
      else if(p.y>0 && p.y<320 && p.x>0 && p.x<240 && buttonStateP4) {
        buttonStateP4 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        question2();
      }
    }

    else if (numPage == 5) {
      buttonStateP5 = true;
      if (p.y>30 && p.y<145 && p.x>170 && p.x<210 && buttonStateP5) {
        buttonStateP5 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ans_false();
        tft.setCursor(50, 120);
        tft.setTextColor(WHITE);
        tft.setTextSize(2);
        tft.print("Risposta corretta:\n\n       1.4 mln di km");
      }
      else if (p.y>175 && p.y<290 && p.x>170 && p.x<210 && buttonStateP5) {
        buttonStateP5 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ans_true();
      }
    }

//domanda 3
    else if (numPage == 6) {
      if (x == 0) {
        p.x = 0;
        p.y = 0;
        x = 1;
      }
      buttonStateP6 = true;
      if (p.y>300 && p.y<320 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 0;
        chose_page();
      }
      else if (p.y>0 && p.y<20 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 2;
        question1();
      }
      else if(p.y>0 && p.y<320 && p.x>0 && p.x<240 && buttonStateP6) {
        buttonStateP6 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        question3();
      }
    }

    else if (numPage == 7) {
      buttonStateP7 = true;
      if (p.y>30 && p.y<290 && p.x>115 && p.x<145 && buttonStateP7) {
        buttonStateP7 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ans_false();
        tft.setCursor(50, 120);
        tft.setTextColor(WHITE);
        tft.setTextSize(2);
        tft.print("Risposta corretta:\n\n    Fascia di asteroidi");
      }
      else if (p.y>30 && p.y<290 && p.x>175 && p.x<215 && buttonStateP7) {
        buttonStateP7 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ans_true();
      }
    }

//domanda 4
    else if (numPage == 8) {
      if (x == 0) {
        p.x = 0;
        p.y = 0;
        x = 1;
      }
      buttonStateP8 = true;
      if (p.y>300 && p.y<320 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 0;
        chose_page();
      }
      else if (p.y>0 && p.y<20 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 2;
        question1();
      }
      else if(p.y>0 && p.y<320 && p.x>0 && p.x<240 && buttonStateP8) {
        buttonStateP8 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        question4();
      }
    }

    else if (numPage == 9) {
      buttonStateP9 = true;
      if (p.y>30 && p.y<290 && p.x>115 && p.x<145 && buttonStateP9) {
        buttonStateP9 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ans_true();
      }
      else if (p.y>30 && p.y<290 && p.x>175 && p.x<215 && buttonStateP9) {
        buttonStateP9 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ans_false();
        tft.setCursor(50, 120);
        tft.setTextColor(WHITE);
        tft.setTextSize(2);
        tft.print("Risposta corretta:\n\n           Urano");
      }
    }

//domanda 5
    else if (numPage == 10) {
      if (x == 0) {
        p.x = 0;
        p.y = 0;
        x = 1;
      }
      buttonStateP10 = true;
      if (p.y>300 && p.y<320 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 0;
        chose_page();
      }
      else if (p.y>0 && p.y<20 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 2;
        question1();
      }
      else if(p.y>0 && p.y<320 && p.x>0 && p.x<240 && buttonStateP10) {
        buttonStateP10 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        question5();
      }
    }

    else if (numPage == 11) {
      buttonStateP11 = true;
      if (p.y>30 && p.y<290 && p.x>115 && p.x<145 && buttonStateP11) {
        buttonStateP11 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ans_false();
        tft.setCursor(50, 120);
        tft.setTextColor(WHITE);
        tft.setTextSize(2);
        tft.print("Risposta corretta:\n\n       Cecere e Eris");
      }
      else if (p.y>30 && p.y<290 && p.x>175 && p.x<215 && buttonStateP11) {
        buttonStateP11 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ans_true();
      }
    }

//domanda 6
    else if (numPage == 12) {
      if (x == 0) {
        p.x = 0;
        p.y = 0;
        x = 1;
      }
      buttonStateP12 = true;
      if (p.y>300 && p.y<320 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 0;
        chose_page();
      }
      else if (p.y>0 && p.y<20 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 2;
        question1();
      }
      else if(p.y>0 && p.y<320 && p.x>0 && p.x<240 && buttonStateP12) {
        buttonStateP12 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        question6();
      }
    }

    else if (numPage == 13) {
      buttonStateP13 = true;
      if (p.y>30 && p.y<145 && p.x>170 && p.x<210 && buttonStateP13) {
        buttonStateP13 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ans_false();
        tft.setCursor(50, 120);
        tft.setTextColor(WHITE);
        tft.setTextSize(2);
        tft.print("Risposta corretta:\n\n        6 missioni");
      }
      else if (p.y>175 && p.y<290 && p.x>170 && p.x<210 && buttonStateP13) {
        buttonStateP13 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ans_true();
      }
    }

//domanda 7
    else if (numPage == 14) {
      if (x == 0) {
        p.x = 0;
        p.y = 0;
        x = 1;
      }
      buttonStateP14 = true;
      if (p.y>300 && p.y<320 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 0;
        chose_page();
      }
      else if (p.y>0 && p.y<20 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 2;
        question1();
      }
      if(p.y>0 && p.y<320 && p.x>0 && p.x<240 && buttonStateP14) {
        buttonStateP14 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        question7();
      }
    }

    else if (numPage == 15) {
      buttonStateP15 = true;
      if (p.y>30 && p.y<145 && p.x>170 && p.x<210 && buttonStateP15) {
        buttonStateP15 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ans_true();
      }
      else if (p.y>175 && p.y<290 && p.x>170 && p.x<210 && buttonStateP15) {
        buttonStateP15 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ans_false();
        tft.setCursor(50, 120);
        tft.setTextColor(WHITE);
        tft.setTextSize(2);
        tft.print("Risposta corretta:\n\n         Apollo 17");
      }
    }

//pagina finale
    else if (numPage == 16) {
      if (x == 0) {
        p.x = 0;
        p.y = 0;
        x = 1;
      }
      buttonStateP16 = true;
      if(p.y>0 && p.y<320 && p.x>0 && p.x<240 && buttonStateP16) {
        buttonStateP16 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        final_page();
      }
    }




//domanda 1 Arduino
    else if (numPage == 17) {
      buttonStateP17 = true;
      if (p.y>30 && p.y<290 && p.x>115 && p.x<145 && buttonStateP17) {
        buttonStateP17 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 2;
        question1();
      }
      else if (p.y>30 && p.y<290 && p.x>175 && p.x<215 && buttonStateP17) {
        buttonStateP17 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        if (y == 1) {
          numPage = numPage + 1;
        }

        if (y == 0) {
          ard_question1();
        }
      }
    }

    else if (numPage == 18) {
      buttonStateP18 = true;
      if (p.y>30 && p.y<290 && p.x>66 && p.x<126 && buttonStateP18) {
        buttonStateP18 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ard_ans_true();
      }
      else if (p.y>30 && p.y<290 && p.x>152 && p.x<212 && buttonStateP18) {
        buttonStateP18 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ard_ans_false();
        tft.setCursor(50, 120);
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
        tft.print("Risposta corretta:\n\n    Scheda elettronica\n   con microcontrollore");
      }
    }

//domanda 2 Arduino
    else if (numPage == 19) {
      if (x == 0) {
        p.x = 0;
        p.y = 0;
        x = 1;
      }
      buttonStateP19 = true;
      if (p.y>300 && p.y<320 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 0;
        chose_page();
      }
      else if (p.y>0 && p.y<20 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 17;
        y = 0;
        ard_question1();
      }
      else if(p.y>0 && p.y<320 && p.x>0 && p.x<240 && buttonStateP19) {
        buttonStateP19 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ard_question2();
      }
    }

    else if (numPage == 20) {
      buttonStateP20 = true;
      if (p.y>30 && p.y<290 && p.x>115 && p.x<145 && buttonStateP20) {
        buttonStateP20 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ard_ans_false();
        tft.setCursor(50, 120);
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
        tft.print("Risposta corretta:\n\n         Italiano");
      }
      else if (p.y>30 && p.y<290 && p.x>175 && p.x<215 && buttonStateP20) {
        buttonStateP20 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ard_ans_true();
      }
    }

//domanda 3 Arduino
    else if (numPage == 21) {
      if (x == 0) {
        p.x = 0;
        p.y = 0;
        x = 1;
      }
      buttonStateP21 = true;
      if (p.y>300 && p.y<320 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 0;
        chose_page();
      }
      else if (p.y>0 && p.y<20 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 17;
        y = 0;
        ard_question1();
      }
      else if(p.y>0 && p.y<320 && p.x>0 && p.x<240 && buttonStateP21) {
        buttonStateP21 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ard_question3();
      }
    }

    else if (numPage == 22) {
      if (x == 0) {
        p.x = 0;
        p.y = 0;
        x = 1;
      }
      buttonStateP22 = true;
      if (p.y>30 && p.y<290 && p.x>115 && p.x<145 && buttonStateP22) {
        buttonStateP22 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ard_ans_false();
        tft.setCursor(50, 120);
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
        tft.print("Risposta corretta:\n\n        Open Source");
      }
      else if (p.y>30 && p.y<290 && p.x>175 && p.x<215 && buttonStateP22) {
        buttonStateP22 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ard_ans_true();
      }
    }

//pagina finale Arduino
    else if (numPage == 23) {
      if (x == 0) {
        p.x = 0;
        p.y = 0;
        x = 1;
      }
      buttonStateP23 = true;
      if(p.y>0 && p.y<320 && p.x>0 && p.x<240 && buttonStateP23) {
        buttonStateP23 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        ard_final_page();
      }
    }

    else if (numPage == 24) {
      if (x == 0) {
        p.x = 0;
        p.y = 0;
        x = 1;
      }
      buttonStateP24 = true;
      if (p.y>30 && p.y<290 && p.x>115 && p.x<145 && buttonStateP24) {
        buttonStateP24 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 17;
        ard_question1();
      }
      else if (p.y>30 && p.y<290 && p.x>175 && p.x<215 && buttonStateP24) {
        buttonStateP24 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 2;
        question1();
      }
    }



//funzioni nascoste
    if (z == 1) {
      if (p.y>300 && p.y<320 && p.x>0 && p.x<20) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 0;
        chose_page();
      }
    }

    if (a == 1) {
      if (p.y>0 && p.y<20 && p.x>0 && p.x<20) {
        if (b == 0) {
          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);

          numPage = 2;
          question1();
        }
        else if (b == 1) {
          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);

          numPage = 17;
          y = 0;
          ard_question1();
        }
      }

    }


  }
}

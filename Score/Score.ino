/*****************************************************************************************************************************
**********************************    Author  : Ehab Magdy Abdullah                      *************************************
**********************************    Linkedin: https://www.linkedin.com/in/ehabmagdyy/  *************************************
**********************************    Youtube : https://www.youtube.com/@EhabMagdyy      *************************************
******************************************************************************************************************************/

#define RESET          4
#define STM32_P1       12
#define STM32_P2       13

#define GREEN_LED      22
#define YELLOW_LED     23
#define RED_LED        14

const uint8_t redBCDPins[4] = {5,18,19,21};
const uint8_t greenBCDPins[4] = {32,26,25,33};

uint8_t red_score = 0;
uint8_t green_score = 0;
uint8_t rec_stm32 = 0;

uint8_t done = 0;

void setup()
{
    for(uint8_t i = 0 ; i < 4 ; i++)
    {
        pinMode(redBCDPins[i], OUTPUT);
        pinMode(greenBCDPins[i], OUTPUT);
    }

    pinMode(RESET, INPUT);
    pinMode(STM32_P1, INPUT);
    pinMode(STM32_P2, INPUT);

    pinMode(GREEN_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
}

void RedScore(uint8_t number)
{
    uint32_t bcd = (number / 10) * 16 + (number % 10);

    for(uint8_t i = 0; i < 4; i++)
        digitalWrite(redBCDPins[i], bitRead(bcd, i));
}

void GreenScore(uint8_t number)
{
    uint32_t bcd = (number / 10) * 16 + (number % 10);

    for(uint8_t i = 0; i < 4; i++)
        digitalWrite(greenBCDPins[i], bitRead(bcd, i));
}

void loop()
{
    rec_stm32 = digitalRead(STM32_P1) & 0x01;
    rec_stm32 |= (digitalRead(STM32_P2) << 1) & 0x02;

    if(HIGH == digitalRead(RESET))
    {
        RedScore(0);
        GreenScore(0);
        red_score = 0;
        green_score = 0;
        Serial.println("pressed");
        delay(300);
    }

    /* Reset Leds */
    if(0 == rec_stm32)
    {
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(RED_LED, LOW);
        done = 0;
    }
    /* Green win */
    else if(1 == rec_stm32)
    {
      if(!done){
        GreenScore(++green_score);
        digitalWrite(GREEN_LED, HIGH);
        done = 1;
      }
    }
    /* Red win */
    else if(2 == rec_stm32)
    {
      if(!done){
        RedScore(++red_score);
        digitalWrite(RED_LED, HIGH);
        done = 1;
      }
    }
    /* Draw */
    else if(3 == rec_stm32)
    {
      if(!done){
        digitalWrite(YELLOW_LED, HIGH);
        done = 1;
      }
    }

    if(red_score == 9 || 9 == green_score)
    {
        RedScore(0);
        GreenScore(0);
        red_score = 0;
        green_score = 0;
    }
}

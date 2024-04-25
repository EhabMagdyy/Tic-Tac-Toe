/*****************************************************************************************************************************
**********************************    Author  : Ehab Magdy Abdullah                      *************************************
**********************************    Linkedin: https://www.linkedin.com/in/ehabmagdyy/  *************************************
**********************************    Youtube : https://www.youtube.com/@EhabMagdyy      *************************************
******************************************************************************************************************************/

#define ESP_P2_Pin GPIO_PIN_15
#define ESP_P2_GPIO_Port GPIOC
#define ESP_P1_Pin GPIO_PIN_15
#define ESP_P1_GPIO_Port GPIOB

#define GREEN_WIN  		1
#define RED_WIN  		2
#define DRAW	  		3


uint8_t no_of_pressed_buttons = 0;
uint8_t new_button_pressed = 0;
uint8_t turn_to_play = 1;				/* Start with Green */

uint8_t buttons[9] = {0};

uint8_t red[9] = {1};
uint8_t green[9] = {0};

uint8_t green_red_draw = 0;


void Reset_Game(void);
void Check_Button_Pressed(void);
void Check_Win_Draw(void);


int main(void)
{
  while (1)
  {
	  /* Reset Game */
	  if(GPIO_PIN_RESET == HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14))
	  {
		  Reset_Game();
	  }
	  /* Game Buttons Pressed */
	  Check_Button_Pressed();
	  /* Check Win or Draw */
	  if(1 == new_button_pressed && 5 <= no_of_pressed_buttons)
	  {
		  Check_Win_Draw();
		  if(green_red_draw)
		  {
			  HAL_GPIO_WritePin(ESP_P1_GPIO_Port, ESP_P1_Pin, (green_red_draw >> 0 & 0x01));
			  HAL_GPIO_WritePin(ESP_P2_GPIO_Port, ESP_P2_Pin, (green_red_draw >> 1 & 0x01));
			  while(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14));
			  /* Reset Score Led */
			  HAL_GPIO_WritePin(ESP_P1_GPIO_Port, ESP_P1_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(ESP_P2_GPIO_Port, ESP_P2_Pin, GPIO_PIN_RESET);
		  }
		  new_button_pressed = 0;
	  }
  }
}

void Reset_Game(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4  | GPIO_PIN_5
					 	 	 	 	 	| GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10
										| GPIO_PIN_11| GPIO_PIN_12 , GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 , GPIO_PIN_RESET);

	no_of_pressed_buttons = 0;
	turn_to_play = 1;
	for(uint8_t i = 0 ; i < 9 ; i++) buttons[i] = 0;
	for(uint8_t i = 0 ; i < 9 ; i++) red[i] = 1;
	for(uint8_t i = 0 ; i < 9 ; i++) green[i] = 0;
	green_red_draw = 0;
}

void Check_Button_Pressed(void)
{
	if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0))
	{
	  /* First Press */
	  if(0 == buttons[0])
	  {
		  HAL_GPIO_WritePin(GPIOA, (GPIO_PIN_0 << turn_to_play), GPIO_PIN_SET);
		  red[0] = turn_to_play;
		  green[0] = turn_to_play;
		  turn_to_play ^= 0x01;
		  buttons[0] = 1;
		  no_of_pressed_buttons++;
		  new_button_pressed = 1;
		  HAL_Delay(250);
	  }
	  else{ /* Already pressed before */ }
	}
	if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1))
	{
	  /* First Press */
	  if(0 == buttons[1])
	  {
		  HAL_GPIO_WritePin(GPIOA, (GPIO_PIN_2 << turn_to_play), GPIO_PIN_SET);
		  red[1] = turn_to_play;
		  green[1] = turn_to_play;
		  turn_to_play ^= 0x01;
		  buttons[1] = 1;
		  no_of_pressed_buttons++;
		  new_button_pressed = 1;
		  HAL_Delay(250);
	  }
	  else{ /* Already pressed before */ }
	}
	if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2))
	{
	  /* First Press */
	  if(0 == buttons[2])
	  {
		  HAL_GPIO_WritePin(GPIOA, (GPIO_PIN_4 << turn_to_play), GPIO_PIN_SET);
		  red[2] = turn_to_play;
		  green[2] = turn_to_play;
		  turn_to_play ^= 0x01;
		  buttons[2] = 1;
		  no_of_pressed_buttons++;
		  new_button_pressed = 1;
		  HAL_Delay(250);
	  }
	  else{ /* Already pressed before */ }
	}
	if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3))
	{
	  /* First Press */
	  if(0 == buttons[3])
	  {
		  HAL_GPIO_WritePin(GPIOA, (GPIO_PIN_6 << turn_to_play), GPIO_PIN_SET);
		  red[3] = turn_to_play;
		  green[3] = turn_to_play;
		  turn_to_play ^= 0x01;
		  buttons[3] = 1;
		  no_of_pressed_buttons++;
		  new_button_pressed = 1;
		  HAL_Delay(250);
	  }
	  else{ /* Already pressed before */ }
	}
	if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4))
	{
	  /* First Press */
	  if(0 == buttons[4])
	  {
		  HAL_GPIO_WritePin(GPIOA, (GPIO_PIN_8 << turn_to_play), GPIO_PIN_SET);
		  red[4] = turn_to_play;
		  green[4] = turn_to_play;
		  turn_to_play ^= 0x01;
		  buttons[4] = 1;
		  no_of_pressed_buttons++;
		  new_button_pressed = 1;
		  HAL_Delay(250);
	  }
	  else{ /* Already pressed before */ }
	}
	if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5))
	{
	  /* First Press */
	  if(0 == buttons[5])
	  {
		  HAL_GPIO_WritePin(GPIOA, (GPIO_PIN_10 << turn_to_play), GPIO_PIN_SET);
		  red[5] = turn_to_play;
		  green[5] = turn_to_play;
		  turn_to_play ^= 0x01;
		  buttons[5] = 1;
		  no_of_pressed_buttons++;
		  new_button_pressed = 1;
		  HAL_Delay(250);
	  }
	  else{ /* Already pressed before */ }
	}
	if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6))
	{
	  /* First Press */
	  if(0 == buttons[6])
	  {
		  if(0 == turn_to_play)
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
		  else
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
		  red[6] = turn_to_play;
		  green[6] = turn_to_play;
		  turn_to_play ^= 0x01;
		  buttons[6] = 1;
		  no_of_pressed_buttons++;
		  new_button_pressed = 1;
		  HAL_Delay(250);
	  }
	  else{ /* Already pressed before */ }
	}
	if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7))
	{
	  /* First Press */
	  if(0 == buttons[7])
	  {
		  if(0 == turn_to_play)
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
		  else
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
		  red[7] = turn_to_play;
		  green[7] = turn_to_play;
		  turn_to_play ^= 0x01;
		  buttons[7] = 1;
		  no_of_pressed_buttons++;
		  new_button_pressed = 1;
		  HAL_Delay(250);
	  }
	  else{ /* Already pressed before */ }
	}
	if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8))
	{
	  /* First Press */
	  if(0 == buttons[8])
	  {
		  if(0 == turn_to_play)
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
		  else
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
		  red[8] = turn_to_play;
		  green[8] = turn_to_play;
		  turn_to_play ^= 0x01;
		  buttons[8] = 1;
		  no_of_pressed_buttons++;
		  new_button_pressed = 1;
		  HAL_Delay(250);
	  }
	  else{ /* Already pressed before */ }
	}
}

void Check_Win_Draw(void)
{
	/* check green win */
	for(uint8_t i = 0 ; i < 3 ; i++)
	{
		/* vertical */
		if(1 == green[i] && 1 == green[i+3] && 1 == green[i+6])
		{
			green_red_draw = GREEN_WIN;
			return;
		}
		/* horizontal */
		if(1 == green[i*3] && 1 == green[i*3+1] && 1 == green[i*3+2])
		{
			green_red_draw = GREEN_WIN;
			return;
		}
	}
	if(1 == green[4] && ((1 == green[0] && 1 == green[8]) || (1 == green[2] && 1 == green[6])))
	{
		green_red_draw = GREEN_WIN;
		return;
	}

	/* check red win */
	for(uint8_t i = 0 ; i < 3 ; i++)
	{
		/* vertical */
		if(0 == red[i] && 0 == red[i+3] && 0 == red[i+6])
		{
			green_red_draw = RED_WIN;
			return;
		}
		/* horizontal */
		if(0 == red[i*3] && 0 == red[i*3+1] && 0 == red[i*3+2])
		{
			green_red_draw = RED_WIN;
			return;
		}
	}
	if(0 == red[4] && ((0 == red[0] && 0 == red[8]) || (0 == red[2] && 0 == red[6])))
	{
		green_red_draw = RED_WIN;
		return;
	}

	/* Check Draw */
	if(9 == no_of_pressed_buttons)
	{
		green_red_draw = DRAW;
	}
}

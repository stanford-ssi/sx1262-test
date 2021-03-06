#include "variant.h"

//Tim's Variants for Space Salmon

const PinDescription g_APinDescription[]=
{
  { PORTB, 00, PIO_NOT_A_PIN, PIN_ATTR_PWM_G, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 30, PIO_DIGITAL, PIN_ATTR_PWM_G, No_ADC_Channel, TCC2_CH0, NOT_ON_TIMER, EXTERNAL_INT_14 },
  { PORTA, 31, PIO_DIGITAL, PIN_ATTR_PWM_G, No_ADC_Channel, TCC2_CH1, NOT_ON_TIMER, EXTERNAL_INT_15 },
  { PORTB, 30, PIO_DIGITAL, PIN_ATTR_PWM_G, No_ADC_Channel, TCC4_CH0, NOT_ON_TIMER, EXTERNAL_INT_14 },
  { PORTB, 31, PIO_DIGITAL, PIN_ATTR_PWM_G, No_ADC_Channel, TCC4_CH1, NOT_ON_TIMER, EXTERNAL_INT_15 },
} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TCC3, TCC4, TC0, TC1, TC2, TC3, TC4, TC5 } ;
const uint32_t GCLK_CLKCTRL_IDs[TCC_INST_NUM+TC_INST_NUM] = { TCC0_GCLK_ID, TCC1_GCLK_ID, TCC2_GCLK_ID, TCC3_GCLK_ID, TCC4_GCLK_ID, TC0_GCLK_ID, TC1_GCLK_ID, TC2_GCLK_ID, TC3_GCLK_ID, TC4_GCLK_ID, TC5_GCLK_ID } ;

SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

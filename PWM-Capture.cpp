
#include "PWM_Capture.h"

volatile uint32_t captured_pulses_PIN2 = 0;
volatile uint32_t captured_ra_PIN2 = 0;
volatile uint32_t captured_rb_PIN2 = 0;

volatile uint32_t captured_pulses_PIN3 = 0;
volatile uint32_t captured_ra_PIN3 = 0;
volatile uint32_t captured_rb_PIN3 = 0;

volatile uint32_t captured_pulses_PIN5 = 0;
volatile uint32_t captured_ra_PIN5 = 0;
volatile uint32_t captured_rb_PIN5 = 0;

volatile uint32_t captured_pulses_PIN11 = 0;
volatile uint32_t captured_ra_PIN11 = 0;
volatile uint32_t captured_rb_PIN11 = 0;

void PWM_Capture::InitAll(void)
{
	Init_PIN2();
	Init_PIN3();
	Init_PIN5();
	Init_PIN11();
}


/*PIN2 */
// timer interrupt handle
void PWM_CAPTURE_Handler_PIN2(void) {
 if ((TC_GetStatus(PWM_CAPTURE_TC_PIN2, PWM_CAPTURE_CHANNEL_PIN2) & TC_SR_LDRBS) == TC_SR_LDRBS) {
   captured_ra_PIN2 = PWM_CAPTURE_TC_PIN2->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN2].TC_RA;
   captured_rb_PIN2 = PWM_CAPTURE_TC_PIN2->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN2].TC_RB;
 }
}

void PWM_Capture::Init_PIN2(void)
{ 
	//Timer0.attachInterrupt(PWM_CAPTURE_Handler_PIN2);

 // configure the PIO pin as peripheral
 const PinDescription *config = &g_APinDescription[2];
	PIO_Configure(
	  config->pPort,
	  config->ulPinType,
	  config->ulPin,
	  config->ulPinConfiguration
	);
   
 // enable timer peripheral clock
 pmc_enable_periph_clk(PWM_CAPTURE_ID_PIN2);
 
 // configure the timer
 TC_Configure(PWM_CAPTURE_TC_PIN2, PWM_CAPTURE_CHANNEL_PIN2,
   PWM_CAPTURE_CLOCK_SELECTION_PIN2 /* Clock Selection */
   | TC_CMR_LDRA_RISING /* RA Loading: rising edge of TIOA */
   | TC_CMR_LDRB_FALLING /* RB Loading: falling edge of TIOA */
   | TC_CMR_ABETRG /* External Trigger: TIOA */
   | TC_CMR_ETRGEDG_FALLING /* External Trigger Edge: Falling edge */
 );
 
 // configure TC interrupts
 NVIC_DisableIRQ(PWM_CAPTURE_IRQn_PIN2);
 NVIC_ClearPendingIRQ(PWM_CAPTURE_IRQn_PIN2);
 NVIC_SetPriority(PWM_CAPTURE_IRQn_PIN2, 0);
 NVIC_EnableIRQ(PWM_CAPTURE_IRQn_PIN2);
 
 // enable interrupts
 PWM_CAPTURE_TC_PIN2->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN2].TC_IER = TC_IER_LDRBS;
 
 // start timer counter
 PWM_CAPTURE_TC_PIN2->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN2].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;
}


/*PIN3*/
// timer interrupt handle
void PWM_CAPTURE_Handler_PIN3() {
	if ((TC_GetStatus(PWM_CAPTURE_TC_PIN3, PWM_CAPTURE_CHANNEL_PIN3) & TC_SR_LDRBS) == TC_SR_LDRBS) {
		captured_ra_PIN3 = PWM_CAPTURE_TC_PIN3->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN3].TC_RA;
		captured_rb_PIN3 = PWM_CAPTURE_TC_PIN3->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN3].TC_RB;
	}
}

void PWM_Capture::Init_PIN3(void)
{
	// configure the PIO pin as peripheral
	const PinDescription *config = &g_APinDescription[3];
	PIO_Configure(
		config->pPort,
		config->ulPinType,
		config->ulPin,
		config->ulPinConfiguration
		);

	// enable timer peripheral clock
	pmc_enable_periph_clk(PWM_CAPTURE_ID_PIN3);

	// configure the timer
	TC_Configure(PWM_CAPTURE_TC_PIN3, PWM_CAPTURE_CHANNEL_PIN3,
		PWM_CAPTURE_CLOCK_SELECTION_PIN3 /* Clock Selection */
		| TC_CMR_LDRA_RISING /* RA Loading: rising edge of TIOA */
		| TC_CMR_LDRB_FALLING /* RB Loading: falling edge of TIOA */
		| TC_CMR_ABETRG /* External Trigger: TIOA */
		| TC_CMR_ETRGEDG_FALLING /* External Trigger Edge: Falling edge */
		);

	// configure TC interrupts
	NVIC_DisableIRQ(PWM_CAPTURE_IRQn_PIN3);
	NVIC_ClearPendingIRQ(PWM_CAPTURE_IRQn_PIN3);
	NVIC_SetPriority(PWM_CAPTURE_IRQn_PIN3, 0);
	NVIC_EnableIRQ(PWM_CAPTURE_IRQn_PIN3);

	// enable interrupts
	PWM_CAPTURE_TC_PIN3->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN3].TC_IER = TC_IER_LDRBS;

	// start timer counter
	PWM_CAPTURE_TC_PIN3->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN3].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;

}

/*PIN5*/

// timer interrupt handle
void PWM_CAPTURE_Handler_PIN5() {
	if ((TC_GetStatus(PWM_CAPTURE_TC_PIN5, PWM_CAPTURE_CHANNEL_PIN5) & TC_SR_LDRBS) == TC_SR_LDRBS) {
		captured_ra_PIN5 = PWM_CAPTURE_TC_PIN5->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN5].TC_RA;
		captured_rb_PIN5 = PWM_CAPTURE_TC_PIN5->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN5].TC_RB;
	}
}

void PWM_Capture::Init_PIN5(void)
{
	// configure the PIO pin as peripheral
	const PinDescription *config = &g_APinDescription[5];
	PIO_Configure(
		config->pPort,
		config->ulPinType,
		config->ulPin,
		config->ulPinConfiguration
		);

	// enable timer peripheral clock
	pmc_enable_periph_clk(PWM_CAPTURE_ID_PIN5);

	// configure the timer
	TC_Configure(PWM_CAPTURE_TC_PIN5, PWM_CAPTURE_CHANNEL_PIN5,
		PWM_CAPTURE_CLOCK_SELECTION_PIN5 /* Clock Selection */
		| TC_CMR_LDRA_RISING /* RA Loading: rising edge of TIOA */
		| TC_CMR_LDRB_FALLING /* RB Loading: falling edge of TIOA */
		| TC_CMR_ABETRG /* External Trigger: TIOA */
		| TC_CMR_ETRGEDG_FALLING /* External Trigger Edge: Falling edge */
		);

	// configure TC interrupts
	NVIC_DisableIRQ(PWM_CAPTURE_IRQn_PIN5);
	NVIC_ClearPendingIRQ(PWM_CAPTURE_IRQn_PIN5);
	NVIC_SetPriority(PWM_CAPTURE_IRQn_PIN5, 0);
	NVIC_EnableIRQ(PWM_CAPTURE_IRQn_PIN5);

	// enable interrupts
	PWM_CAPTURE_TC_PIN5->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN5].TC_IER = TC_IER_LDRBS;

	// start timer counter
	PWM_CAPTURE_TC_PIN5->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN5].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;
}



/*PIN11*/
// timer interrupt handle
void PWM_CAPTURE_Handler_PIN11() {
	if ((TC_GetStatus(PWM_CAPTURE_TC_PIN11, PWM_CAPTURE_CHANNEL_PIN11) & TC_SR_LDRBS) == TC_SR_LDRBS) {
		captured_ra_PIN11 = PWM_CAPTURE_TC_PIN11->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN11].TC_RA;
		captured_ra_PIN11 = PWM_CAPTURE_TC_PIN11->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN11].TC_RB;
	}
}

void PWM_Capture::Init_PIN11(void)
{
	// configure the PIO pin as peripheral
	const PinDescription *config = &g_APinDescription[11];
	PIO_Configure(
		config->pPort,
		config->ulPinType,
		config->ulPin,
		config->ulPinConfiguration
		);

	// enable timer peripheral clock
	pmc_enable_periph_clk(PWM_CAPTURE_ID_PIN11);

	// configure the timer
	TC_Configure(PWM_CAPTURE_TC_PIN11, PWM_CAPTURE_CHANNEL_PIN11,
		PWM_CAPTURE_CLOCK_SELECTION_PIN11 /* Clock Selection */
		| TC_CMR_LDRA_RISING /* RA Loading: rising edge of TIOA */
		| TC_CMR_LDRB_FALLING /* RB Loading: falling edge of TIOA */
		| TC_CMR_ABETRG /* External Trigger: TIOA */
		| TC_CMR_ETRGEDG_FALLING /* External Trigger Edge: Falling edge */
		);

	// configure TC interrupts
	NVIC_DisableIRQ(PWM_CAPTURE_IRQn_PIN11);
	NVIC_ClearPendingIRQ(PWM_CAPTURE_IRQn_PIN11);
	NVIC_SetPriority(PWM_CAPTURE_IRQn_PIN11, 0);
	NVIC_EnableIRQ(PWM_CAPTURE_IRQn_PIN11);

	// enable interrupts
	PWM_CAPTURE_TC_PIN11->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN11].TC_IER = TC_IER_LDRBS;

	// start timer counter
	PWM_CAPTURE_TC_PIN11->TC_CHANNEL[PWM_CAPTURE_CHANNEL_PIN11].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;
}






void PWM_Capture::Capture_PIN2(float * frequency, float * dutyCycle)
{
 // frequency in Hz
*frequency
   = (F_CPU / 2.0000) / captured_rb_PIN2;
 
 // duty cycle in percent
*dutyCycle
   = (captured_rb_PIN2 - captured_ra_PIN2) * 100.0000/ captured_rb_PIN2; 
}


void PWM_Capture::Capture_PIN3(float * frequency, float * dutyCycle)
{
	// frequency in Hz
	*frequency
		= (F_CPU / 2.0000) / captured_rb_PIN3;

	// duty cycle in percent
	*dutyCycle
		= (captured_rb_PIN3 - captured_ra_PIN3) * 100.0000 / captured_rb_PIN3;
}

void PWM_Capture::Capture_PIN5(float * frequency, float * dutyCycle)
{
	// frequency in Hz
	*frequency
		= (F_CPU / 2.0000) / captured_rb_PIN5;

	// duty cycle in percent
	*dutyCycle
		= (captured_rb_PIN5 - captured_ra_PIN5) * 100.0000 / captured_rb_PIN5;
}

void PWM_Capture::Capture_PIN11(float * frequency, float * dutyCycle)
{
	// frequency in Hz
	*frequency
		= (F_CPU / 2.0000) / captured_rb_PIN11;

	// duty cycle in percent
	*dutyCycle
		= (captured_rb_PIN11 - captured_ra_PIN11) * 100.0000 / captured_rb_PIN11;
}

void PWM_Capture::disableAll(void)
{
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(11, OUTPUT);

	 captured_pulses_PIN2 = 0;
	 captured_ra_PIN2 = 0;
	 captured_rb_PIN2 = 0;

	 captured_pulses_PIN3 = 0;
	 captured_ra_PIN3 = 0;
	 captured_rb_PIN3 = 0;

	 captured_pulses_PIN5 = 0;
	 captured_ra_PIN5 = 0;
	 captured_rb_PIN5 = 0;

	 captured_pulses_PIN11 = 0;
	 captured_ra_PIN11 = 0;
	 captured_rb_PIN11 = 0;
}

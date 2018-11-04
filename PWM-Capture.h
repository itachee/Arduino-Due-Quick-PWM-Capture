#ifdef __arm__

#ifndef PWM_Capture_h
#define PWM_Capture_h

#include "Arduino.h"


//PIN 2
#define PWM_CAPTURE_TC_PIN2 TC0
#define PWM_CAPTURE_CHANNEL_PIN2 0
#define PWM_CAPTURE_IRQn_PIN2 TC0_IRQn
#define PWM_CAPTURE_Handler_PIN2 TC0_Handler
#define PWM_CAPTURE_ID_PIN2 ID_TC0
//#define PWM_CAPTURE_PIN 2
#define PWM_CAPTURE_CLOCK_SELECTION_PIN2 TC_CMR_TCCLKS_TIMER_CLOCK1

//PIN 3
#define PWM_CAPTURE_TC_PIN3 TC2
#define PWM_CAPTURE_CHANNEL_PIN3 1
#define PWM_CAPTURE_IRQn_PIN3 TC7_IRQn
#define PWM_CAPTURE_Handler_PIN3 TC7_Handler
#define PWM_CAPTURE_ID_PIN3 ID_TC7
//#define PWM_CAPTURE_PIN 3
#define PWM_CAPTURE_CLOCK_SELECTION_PIN3 TC_CMR_TCCLKS_TIMER_CLOCK1

//PIN 5
#define PWM_CAPTURE_TC_PIN5 TC2
#define PWM_CAPTURE_CHANNEL_PIN5 0
#define PWM_CAPTURE_IRQn_PIN5 TC6_IRQn
#define PWM_CAPTURE_Handler_PIN5 TC6_Handler
#define PWM_CAPTURE_ID_PIN5 ID_TC6
//#define PWM_CAPTURE_PIN 5
#define PWM_CAPTURE_CLOCK_SELECTION_PIN5 TC_CMR_TCCLKS_TIMER_CLOCK1

//PIN 11
#define PWM_CAPTURE_TC_PIN11 TC2
#define PWM_CAPTURE_CHANNEL_PIN11 2
#define PWM_CAPTURE_IRQn_PIN11 TC8_IRQn
#define PWM_CAPTURE_Handler_PIN11 TC8_Handler
#define PWM_CAPTURE_ID_PIN11 ID_TC8
//#define PWM_CAPTURE_PIN 11
#define PWM_CAPTURE_CLOCK_SELECTION_PIN11 TC_CMR_TCCLKS_TIMER_CLOCK1


class PWM_Capture
{
public:
	void InitAll(void);
	void Init_PIN2(void);
	void Capture_PIN2(float * frequency, float * dutyCycle);

	void Init_PIN3(void);
	void Capture_PIN3(float * frequency, float * dutyCycle);

	void Init_PIN5(void);
	void Capture_PIN5(float * frequency, float * dutyCycle);

	void Init_PIN11(void);
	void Capture_PIN11(float * frequency, float * dutyCycle);

	void disableAll(void);
};



#endif

#else
#endif
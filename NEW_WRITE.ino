#define F_CPU 16000000UL
#include <avr/io.h>

int main(void) 
{
    // Set up Timer3 in Fast PWM mode (Mode 14)
    TCCR3A = (1 << COM3A1) | // Non-inverting mode channel A
             (1 << COM3B1) | // Non-inverting mode channel B
             (1 << WGM31);   // Fast PWM mode
             
    TCCR3B = (1 << WGM33) | (1 << WGM32) | // Fast PWM mode
             (1 << CS31);    // Prescaler = 8

    // For 100Hz:
    // F_CPU/(prescaler * F_desired) = ICR3 + 1
    // 16000000/(8 * 100) = 20000
    //ICR3 = 19999;   // TOP value (period - 1)
ICR3 =  3999; 
    // 50% duty cycle
    OCR3A = ICR3/2;  // Channel A
    OCR3B = ICR3/2;  // Channel B

    // Configure pins as outputs
    DDRD |= (1 << PD4);  // OC3A on PD4
    DDRB |= (1 << PB4);  // OC3B on PB4

    while(1) 
    {
        // PWM is handled by hardware
    }

    return 0;
}

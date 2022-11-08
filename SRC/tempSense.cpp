#include "mbed.h"
#include "constants.h"
#include "tempSense.h"

   DigitalOut vdd(THERM_VDD);
    DigitalOut gnd(THERM_GND);
    AnalogIn tempVoltage(THERM_OUT);

    float readTemp() {
// Power up the Thermistor
    vdd = true;
    gnd = false;
// do the measurement 

    float refVoltage = tempVoltage.read() * 2.4; // Range of ADC 0->2*Vref

// turn off the current though the thermistor
    vdd = false;
// and convert to Celcius

    float refCurrent = refVoltage  / 10000.0; // 10k Reference Resistor
    float thermVoltage = 3.3 - refVoltage;    // Assume supply voltage is 3.3v
    float thermResistance = thermVoltage / refCurrent; 
    float logrT = (float32_t)log((float64_t)thermResistance);
    /* Calculate temperature from the resistance of thermistor using Steinhart-Hart Equation */
    float stEqn = (float32_t)((A_COEFF) + ((B_COEFF) * logrT) + 
                             ((C_COEFF) * pow((float64)logrT, (float32)3)));
    float temperatureC = (float32_t)(((1.0 / stEqn) + ABSOLUTE_ZERO)  + 0.05);

    return temperatureC;
}
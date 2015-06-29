
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Adafruit_INA219.h"

int main(int argc, char** argv)
{
	Adafruit_INA219 ina219;
	ina219.begin();

	do{
		float shuntvoltage = 0;
		float busvoltage = 0;
		float current_mA = 0;
		float loadvoltage = 0;

		shuntvoltage = ina219.getShuntVoltage_mV();
		busvoltage = ina219.getBusVoltage_V();
		current_mA = ina219.getCurrent_mA();
		loadvoltage = busvoltage + (shuntvoltage / 1000);

		//Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
		fprintf(stdout, "Bus Voltage:   %.3f V\n", busvoltage);
		fprintf(stdout, "Shunt Voltage: %.3f mV\n", shuntvoltage);
		fprintf(stdout, "Load Voltage:  %.3f V\n", loadvoltage);
		fprintf(stdout, "Current:       %.3f mA\n", current_mA);
		fprintf(stdout, "Watts:         %.3f W\n", (current_mA/1000)*busvoltage);
		fprintf(stdout, "\n");

		usleep(2000000);
	} while(true);

	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#include "Adafruit_INA219.h"

int main(int argc, char** argv)
{
	Adafruit_INA219 ina219;
	struct timeval t0;
	ina219.begin();

	do{
		float shuntvoltage = 0;
		float busvoltage = 0;
		float current_mA = 0;
		float loadvoltage = 0;

		gettimeofday(&t0, 0);
		//busvoltage = ina219.getBusVoltage_V();
		//current_mA = ina219.getCurrent_mA();
		shuntvoltage = ina219.getShuntVoltage_mV();
		busvoltage = ina219.getBusVoltage_V();
		current_mA = ina219.getCurrent_mA();
		loadvoltage = busvoltage + (shuntvoltage / 1000);

		//Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
		//fprintf(stdout, "Bus Voltage:   %.3f V\n", busvoltage);
		//fprintf(stdout, "Current:       %.3f mA\n", current_mA);
		//fprintf(stdout, "Watts:         %.3f W\n", (current_mA/1000)*busvoltage);
		fprintf(stdout, "%.0f %6.3f %6.3f %6.3f\n",
			t0.tv_sec*1e6+t0.tv_usec, 
			(current_mA/1000)*busvoltage,
			current_mA, busvoltage);

		usleep(100000);
	} while(true);

	return 0;
}

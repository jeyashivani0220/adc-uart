#include "sdk_project_config.h"
#include<stdio.h>
int main(void){
	CLOCK_DRV_Init(&clockMan1_InitConfig0);
	PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
	ADC_Init(&adc_pal_1_instance, &adc_pal_1_config);
	LPUART_DRV_Init(INST_LPUART_1, &lpUartState0, &lpuart_0_InitConfig0);
	while(1){
		ADC_StartGroupConversion(&adc_pal_1_instance,0U);
		int AdcStatus=adc_pal_1_results0[0];
		int v ;//=(AdcStatus*4500U/4095U);
		//int final=3300-(int)v;
		static char txBuff[64];
		int len=(int)sprintf(txBuff,"Register value: %d  Voltage value: %d mV \n\r",AdcStatus,v);
		LPUART_DRV_SendDataBlocking(INST_LPUART_1,(const uint8_t*)txBuff,(uint32_t)len,1000U);
	}
}

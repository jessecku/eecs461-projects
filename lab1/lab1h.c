#include <eecs461.h>
#include <serial.h>

void main() { 
	int i; 
	unsigned char op1, op2;
	int result;
	int temp;
	volatile SIUL_PCR_16B_tag *siu_pcr_ptr; /* pointers to registers */ 
	volatile unsigned char *siu_gpdi_ptr; 
	volatile unsigned char *siu_gpdo_ptr; 
	char byte_in;
	
	initEECS461(); /* Call this function with lab number = 1 to init processor */ 
	initUART(9600);
	siu_pcr_ptr = (SIUL_PCR_16B_tag*)(0Xc3f90040); /* SIU_BASE + 0X40 for pcr */ 
	siu_gpdo_ptr = (unsigned char*)(0Xc3f90600); /* SIU_BASE + 0X600 for gpdo */ 
	
	/* configure output leds */ 
	for(i=43; i<48; i++) { 
		siu_pcr_ptr[i].B.APC = 0; /* GPIO */ 
		siu_pcr_ptr[i].B.PA = 0; /* GPIO */ 
		siu_pcr_ptr[i].B.OBE = 1; /* Input */ 
	}
	

	serial_puts("\n\n\n\n\n\n\n\n\rSerial Output Enabled.");
	op1 = 0;
	op2 = 0;
	while (1) {
		if (serial_readyToReceive(1)) {
			byte_in = serial_getchar(1);
			switch (byte_in) {
			case '0':
			op2 = op1;
			op1 = 0;
			break;
			
			case '1':
			op2 = op1;
			op1 = 1;
			break;
			
			case '2':
			op2 = op1;
			op1 = 2;
			break;
			
			case '3':
			op2 = op1;
			op1 = 3;
			break;
			
			case '4':
			op2 = op1;
			op1 = 4;
			break;
			
			case '5':
			op2 = op1;
			op1 = 5;
			break;
			
			case '6':
			op2 = op1;
			op1 = 6;
			break;
			
			case '7':
			op2 = op1;
			op1 = 7;
			break;
			
			case '8':
			op2 = op1;
			op1 = 8;
			break;
			
			case '9':
			op2 = op1;
			op1 = 9;
			break;
			default:
			break;
			}
			
			//add and display on LEDs
			result = (int)op1 + (int)op2;
			 for(i = 43; i <48; i++){
				siu_gpdo_ptr[i] = result & 0x1;
				result = result >>1;
			}
		}
	}
}
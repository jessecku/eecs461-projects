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

	siu_pcr_ptr = (SIUL_PCR_16B_tag*)(0Xc3f90040); /* SIU_BASE + 0X40 for pcr */ 
	siu_gpdo_ptr = (unsigned char*)(0Xc3f90600); /* SIU_BASE + 0X600 for gpdo */ 
	siu_gpdi_ptr = (unsigned char*)(0Xc3f90800); /* SIU_BASE + 0X800 for gpdi */ 
							   /* See Table 47-2 */ 
	/* configure input dipswitches */ 
	for(i=5; i<13; i++) { 
		siu_pcr_ptr[i].B.APC = 0; /* GPIO */ 
		siu_pcr_ptr[i].B.PA = 0; /* GPIO */ 
		siu_pcr_ptr[i].B.IBE = 1; /* Input */ 
	} 
	/* configure output leds */ 
	for(i=43; i<48; i++) { 
		siu_pcr_ptr[i].B.APC = 0; /* GPIO */ 
		siu_pcr_ptr[i].B.PA = 0; /* GPIO */ 
		siu_pcr_ptr[i].B.OBE = 1; /* Input */ 
	}
	initEECS461(); /* Call this function with lab number = 1 to init processor */ 
	 while(1)
	{
		/* get the number contained on DIP 5–8 and 9-12 */
		 /* read the bit
		 shift left 1
		 read the next bit and continue */
		 op1 = 0;
		for(i = 8; i>4; i--){
			temp = siu_gpdi_ptr[i];
			op1 = temp | op1;
			op1 = op1 << 1;
		}
		op1 = op1 >> 1;
		
		op2 = 0;
		for(i = 12; i>8; i--){
			temp = siu_gpdi_ptr[i];
			op2 = temp | op2;
			op2 = op2 << 1;
		}
		op2 = op2 >> 1;
		
		/* calculate the sum */		
		result = (int)op1 + (int)op2;	
		
		 /* display the result on LED 43-48 */
		 /* write result LSB
		 shift right 1
		 write the next bit and continue */
		 for(i = 43; i <48; i++){
			siu_gpdo_ptr[i] = result & 0x1;
			result = result >>1;
		}
	} 	
}
#include <stdint.h>

int main()
{
	uint32_t *ptr;
	
	ptr = (uint32_t*)(0x40023800 + 0x30);
	*ptr |= (0x1 <<0);
	
	// GPIO port mode register S.187 im Reference Manual PA5  => Konfiguriert als 01 General Purpuse
	ptr = (uint32_t*)(0x40020000);
	*ptr |= (0x1 <<10);
	
	// Pointer um 32 Bit weiter schieben
	ptr++;	
	
	// GPIO port output type Register  0 > Push Pull > Standardwert daher egal
	*ptr &= ~(uint32_t)(0x1 << 5); 
	
	
	ptr++;
		// GPIO port output speed register  0 > Push Pull > Standardwert daher egal S.188
	*ptr = 0xC0000300;
	//*ptr &= ~(uint32_t)(0x03 << 10);
	
	// GPIO port pull-up/pull-down register 
	ptr++;
	*ptr |= (0x2 << 10);
	
	// Drei Register überspringen
	ptr++;
	ptr++;
	ptr++;
	
	// GPIO port bit set/reset register S.190
	*ptr |= (1<<5);
	*ptr |= (1<<21);
	
	*ptr |= (1<<5);
	*ptr |= (1<<21);
	
	*ptr |= (1<<5);
	*ptr |= (1<<21);
	
	
	
	
	
	while(1)
	{
	}
	
}
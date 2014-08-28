void InitUART0(unsigned short BaudRate){

	/* Define the Baud Rate and Frequency Clock */

	unsigned short Workspace, NewConfig = 0;
	unsigned short SerialFrequency = SerialFCLK1_25MHz;

	/* if baud rate is 115200 serial frequency need most resolution at 10MHz */

	if(BaudRate == BaudRate10_0MHz115200){
		SerialFrequency = SerialFCLK10_0MHz;
	}

	ST0    = 0x03;				// stop ch0 and ch1 of the serial array unit 0 (UART0)
	RxDD0 = 1;						// RxD0 Pin as input
	TxDD0 = 1;						// TxD0 Pin as input

	/* select the serial clock */

	Workspace = SPS0;				// save de SPS0 register in Workspace
	Workspace &= 0x00F0;        	// modify lsb
	NewConfig = SerialFrequency;	// save the new config
	NewConfig &= 0x000F;        	// modify msb
	SPS0 = NewConfig | Workspace;	// charge the serial frequency in CK0 (bit 3 to 0) without affect the other channels

	/* INTST0 */

	STMK0  = 1;						// Disable INTST0
	STIF0  = 0;						// Clean flag
	STPR00 = 1;			   		    // Interrupt level low

	/* INTSR0 */

	SRMK0  = 1;			 			// Disable INTSR0
	SRIF0  = 0;            			// Clean flag
	SRPR10 = 1;			 			// Interrupt level low

	/* INTSRE0 */

	SREMK0  = 1;		    		// Disable INTSRE0
	SREIF0  = 0;		    		// Clean flag
	SREPR00 = 1;		    		// interrupt level low

	SMR00 = 0x0023;					// UART Mode - Select the CK0 (bit 3 to 0) of SPS0 register ch0
	SCR00 = 0x8097;    				// No Parity - 1 Stop bit - 8bits data lenght ch0
	SDR00 = BaudRate;    			// Charge the Baud Rate ch0
	NFEN0 = 0x15;					// Noise filter Enable
	SIR01 = 0x0007;					// Clean Error flags
	SMR01 = 0x0122;					// UART Mode - Select the CK0 (bit 3 to 0) of SPS0 register ch1
	SCR01 = 0x4093;					// No Parity - 1 Stop bit - 8bits data lenght ch1
	SDR01 = BaudRate;				// Charge the Baud Rate ch1
	//SO0   = 0x0101;					// Serial data output value is “1”.
	SOE0  = 0x01;						// Serial output enable register

	TxD0   = 1;
	TxDD0  = 0;

	SRMK0   = 0;					// Enable Rx Interrupt
	//SS0     = 0x0003;				// start ch0 and ch1 of the serial array unit 0 (UART0)
	STIF0   = 1;					// Serial Transmit interrupt flag
}

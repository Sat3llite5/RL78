#define MaxBufferSize 			 512

#define SerialFCLK1_25MHz     0x0004
#define SerialFCLK10_0MHz     0x0001

#define BaudRate1_25MHz4800   0xFF00				// ~ 4800   bps   = (((1.25MHz*1000)*1000)/0xFF)
#define BaudRate1_25MHz9600   0x8200				// ~ 9600   bps   = (((1.25MHz*1000)*1000)/0x82)
#define BaudRate1_25MHz19200  0x4100				// ~ 19200  bps   = (((1.25MHz*1000)*1000)/0x41)
#define BaudRate10_0MHz115200 0x5700				// ~ 115200 bps   = (((10.0MHz*1000)*1000)/0x57)

#define uart0 0
#define uart1 1
#define uart2 2



struct UART0{
	_UINT  BufferFull		        :1;
	_UINT  CommandReceived	        :1;
	_UINT  ReadytoRead				:1;
	_UINT  RxByteCounter    	      ;
	_UINT  RxReadByteCounter		  ;
	_UBYTE RxBuffer[MaxBufferSize]    ;
	_UBYTE RxReadBuffer[MaxBufferSize];
};
struct UART1{
	_UINT  BufferFull		        :1;
	_UINT  CommandReceived	        :1;
	_UINT  ReadytoRead				:1;
	_UINT  RxByteCounter    	      ;
	_UINT  RxReadByteCounterCopy	  ;
	_UINT  RxReadByteCounter		  ;
	_UBYTE RxBuffer[MaxBufferSize]    ;
	_UBYTE RxReadBuffer[MaxBufferSize];
};
struct UART2{
	_UINT  BufferFull		        :1;
	_UINT  CommandReceived	        :1;
	_UINT  ReadytoRead				:1;
	_UINT  RxByteCounter    	      ;
	_UINT  RxReadByteCounter		  ;
	_UBYTE RxBuffer[MaxBufferSize]    ;
	_UBYTE RxReadBuffer[MaxBufferSize];
};


extern struct UART0 SAU0;
extern struct UART1 SAU1;
extern struct UART2 SAU2;

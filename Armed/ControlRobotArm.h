#define arrSize(x) sizeof(x) / sizeof(x[0])

typedef struct PROGRAM{
	
	uint8_t  angle1;
	uint8_t  angle2;
	uint8_t  angle3; 
	uint16_t del;
	
}PROGRAM;

PROGRAM program[]={

		{0,10,10,100},
    {100,100,10,100},
    {90,10,30,1000},
    {90,134,180,1000},
};

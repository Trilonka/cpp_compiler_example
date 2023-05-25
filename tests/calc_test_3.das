int a = 1;
int b = 10;

a = a + b + 4*2 -3 - 2 * (2+3);

for (int i = 0; i < 4; i = i + 1) 
	b = b - a;

if (a > b)
{ 
	a = a + b; 
	b = b - a;
};

int c = 1;

if(c < 2) 
{
	c = c + 1; 
	int g = 4; 
	g = g + c;
};
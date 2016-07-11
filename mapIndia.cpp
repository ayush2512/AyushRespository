#include<stdio.h>
int main()
{
	int a=10, b=0, c=10;
	char bits[] = "TFy!QJu ROo TNn(ROo)SLq SLq ULo+UHs UJq TNn*RPn/QPbEWS_JSWQAIJO^NBELPeHBFHT}TnALVlBLOFAkHFOuFETpHCStHAUFAgcEAelclcn^r^r\\tZvYxXyT|S~Pn SPm SOn TNn ULo0ULo#ULo-WHq!WFs XDt!";
	a = bits[b];
	while(a != 0)
	{
		a = bits[b];
		b++;
		while(a >= 65)
		{
			a--;
			if(c=='Z')
			{
				c=c/90;
				printf("\n");
			}
			else
			{
				if(b %2 ==0)
					printf("!");
				else
					printf(" ");
			}
		}
	}
	return 0;
}
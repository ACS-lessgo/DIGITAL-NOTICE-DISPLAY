#include<reg51.h>
#define lcdport P2
sbit rs =P1^0;
sbit en =P1^1;
sbit led1 =P2^0;
sbit led2 =P2^1;
sbit led3 =P2^2;
sbit led4 =P2^3;
sbit led5 =P1^2;
sbit led6 =P1^3;
sbit led7 =P1^4;
sbit led8 =P1^5;
sbit led9 =P1^6;
sbit led10 =P1^7;

sbit row1=P3^0;
sbit row3=P3^2;
sbit row2=P3^1;
sbit row4=P3^3;
sbit col1=P3^4;
sbit col2=P3^5;
sbit col3=P3^6;
sbit col4=P3^7;

int c=0;
void delay(int itime)
{
 int i,j;
 for(i=0;i<=itime;i++)
     for(j=0;j<=1000;j++);
}

void daten(void)
{
	rs=1;
	 en=1;
	 delay(10);
	  en=0;
}
void lcddata(unsigned char ch)
{
    lcdport=ch & 0xf0;
	     
	      daten();
	        lcdport=ch<<4 & 0xf0;
	          daten();
}
void cmden(void)
{
rs=0;
 en=1;
  delay(10);
   en=0;
}
void lcdcmd(unsigned char ch)
{
	lcdport=ch & 0xf0;
	cmden();
	 lcdport=ch<<4 & 0xf0;
	cmden();
}
void lcdstring(char *str)
{
	while(*str)
	{
		lcddata(*str);
		str++;
	}
}
void lcd_init(void)
{
	lcdcmd(0x02);
	  lcdcmd(0x28);
	            
	       lcdcmd(0x0e);
	         lcdcmd(0x01);
}
void setCursor(int x,int y)
{
	if(x==0)
	{
		lcdcmd(128+y);
	}
	else
	{
		if(y>15)
		{
			y=0;
			c=0;
		}
			lcdcmd(192+y);
	}
}
void main()
{
	led1=led2=led3=led4=led5=led6=led7=led8=led9=led10=0;
	c=0;
	lcd_init();
	lcdcmd(0x80);
	lcdstring("Press to view Timetable");
	lcdcmd(0xc0);
	while(1)
	{
		col1=0;
		col2=1;
		col3=1;
		col4=1;
		delay(10);
		if(row1==0)
		{
			lcdcmd(0x01);
		lcdstring("ACM OS TLA DS");
			led1=1;
			delay(100);
			   c++;
		}
		else if(row2==0)
		{
          lcdcmd(0x01);
		lcdstring("TLA DSP OS ITC");  			
			led1=1;
			led2=1;
			delay(100);
			    c++;
		}
		else if(row3==0)
		{
			lcdcmd(0x01);
		lcdstring("ITC DS SAP TLA");  			
			led1=1;
			led2=1;
			led3=1;
			delay(100);
			    c++;
		}
		else if(row4==0)
		{
			lcdcmd(0x01);
		lcdstring("TLA-TUT ITC-TUT");  			
			led1=1;
			led2=1;
			led3=1;
			led4=1;
			delay(100);
			    c++;
		}
		col1 =1;
		col2 =0;
		col3 =1;
		col3 =1;
		col4 =1;
		delay(10);
		  
		if(row1==0)
		{
			lcdcmd(0x01);
		lcdstring("DS ACM OS DSP");
			led1=1;
			led2=1;
			led3=1;
			led4=1;
			led5=1;
			delay(100);
			    c++;
		}
		else if(row2==0)
		{
			lcdcmd(0x01);
		lcdstring("IFE ACM");
			led1=1;
			led2=1;
			led3=1;
			led4=1;
			led5=1;
			led6=1;
			delay(100);
			    c++;
		}
		else if(row3==0)
		{
			lcdcmd(0x01);
			lcdstring("SUNDAY");
			led1=1;
			led2=1;
			led3=1;
			led4=1;
			led5=1;
			led6=1;
			led7=1;
			delay(100);
			    c++;
		}
		else if(row4==0)
		{
			lcdcmd(0x01);
			lcdstring("^^^^");
			led1=1;
			led2=1;
			led3=1;
			led4=1;
			led5=1;
			led6=1;
			led7=1;
			led8=1;
			delay(100);
			    c++;
		}
		col1=1;
		col2=1;
		col3=0;
		col4=1;
		delay(10);
		
		 if (row1==0)
		 {
			 lcdcmd(0x01);
			 lcdcmd(0x01);
			lcdstring("^^^^");
			led1=1;
			led2=1;
			led3=1;
			led4=1;
			led5=1;
			led6=1;
			led7=1;
			led8=1;
			delay(100);
			    c++;
		 }
		 else if(row2==0)
		 {
			 lcdcmd(0x01);
			 lcdstring(" 4,5,6 LED OFF");
			 led4=0;
			 led5=0;
			 led6=0;
			    
			    lcdcmd(0x01);
			 lcdstring(" 4,5,6 LED OFF");
			 led4=0;
			 led5=0;
			 led6=0;
			 delay(100);
			 c++;
		 }
		 col1=1;
		 col2=1;
		 col3=1;
		 col4=0;
		 delay(10);
		  if(row1==0)
			{
				lcdcmd(0x01);
			lcdstring(" OFF");
				led7=0;
				led8=0;
				led9=0;
				delay(100);
				c++;
			}
			else if(row2==0)
			{
				lcdcmd(0x01);
				lcdstring("MINI PROJECT");
				lcdcmd(0xc0);
				lcdstring("^^^^");
				led1=led2=led3=led4=led5=led6=led7=led8=led9=led10=0;
			 
				delay(100);
				  c++;
			}
				else if(row3==0)
				{
					lcdcmd(0x01);
				lcdstring("MINI PROJECT");
				lcdcmd(0xc0);
				lcdstring("^^^^");
				led1=led2=led3=led4=led5=led6=led7=led8=led9=led10=0;
			 
				delay(100);
				  c++;
				}
			}
			c++;
		}
	
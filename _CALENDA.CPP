//@Author by Srinivas_chinthapalli
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int last_digit(int year) /* this function indicate for get the year last two digit*/
{
int i,rem=0,a[2],index=1;

	while(year>100)
	{
	rem=year%10;

	year=year/10;
	a[index]=rem;
	index--;
	}

return a[0]*10+a[1];
}


int count_day(int month,int year)
{
int month_code[]={0,3,3,6,1,4,6,2,5,0,3,5}; /*month code*/
int digit=last_digit(year);
int result;
month=month-1;

int c_code=0;
	if(year>=1700 &&year<=1799)
	{
	c_code=4;

	}
	if(year>=1800 &&year<=1899)
	{
	c_code=2;

	}
	if(year>=1900 &&year<=1999)
	{
	c_code=0;

	}
	if(year>=2000 &&year<=2099)
	{
	c_code=6;

	}
result=(digit+(digit/4)+1+month_code[month]+c_code);
result=result%7;
if((year%400==0)||(year%4==0)&&month+1==2)
	{

	result=result-1;

	if(result<0)
	result=6;
	}


return (result);
}
int count_total_days(int month,int year)
{
int m_days[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(month==2)
	{
	if((year%400==0)||(year%4==0))
	{

	return 29;
	}
	else
	return m_days[month-1];
	}
	else
	 {

	 return m_days[month-1];
	 }

}
show_calendar(int month,int _year)
{
int year,i;
char months[40][40]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
char days[7][7]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
int tabs=count_day(month,_year);
int day=1;
int s=tabs+1;
int total_days=count_total_days(month,_year);

printf("Author by Srinivas_chinthapalli\n\n");
printf("\n            %s,%d",months[month-1],_year);
printf("\n---------------------------------\n");

for(i=0;i<7;i++)
{
printf("%s  ",days[i]);

}
printf("\n---------------------------------\n");
for(i=1;i<=tabs;i++)
{
printf("     ");
}
for(i=1;i<=total_days;i++)
{

  if(day<10)
  cprintf("0%d   ",day);
  else
  cprintf("%d   ",day);
  if((s)%7==0)
  {
  printf("\n");
  /*s=s+tabs;*/

  tabs=0;
  }
  day++;
  s++;
}
printf("\n---------------------------------\n");
}
main()
{
int i;
int month,year;
char ch='a';
clrscr();

show_calendar(4,2022);
printf("\n\n");
/*show_calendar(5,2022);*/
year=2022;
month=1;

while(ch!='q')
{
clrscr();
textcolor(15);
if(ch=='n')
month++;
if(ch=='p')
month--;
if(month<1)
{
month=1;
year--;
}
if(month>12)
{
month=1;
year++;
}

show_calendar(month,year);

printf("\n\nPress '\N\' next ,Press '\P\' privious,");
printf("\n\t Press '\Q\' exit");
ch=getch();
}

}
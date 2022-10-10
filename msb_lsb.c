#include <stdio.h>
#include <string.h>

int toBinary(int);
int lsb(int);
int msb(int);

int main()
{
  unsigned int num;
  printf("Please input a positive non-zero integer");
  scanf("%d", &num);

  int converted,lsb,msb;

  converted= toBinary(num); //converting it with recursion function call here

  printf("Binary of the following number is :%d \n",converted);//Print it

  lsb=lsb(converted);
  msb=msb(converted);

  printf("LSB is : %d \n",lsb);
  printf("MSB is : %d \n",msb);

  printf("The distance between lsb and msb is : %d",msb-lsb );//print distance here

return 0;

}


int toBinary(int decimal_number)// Decimal to binary conversion
{
  if (decimal_number == 0)
    return 0;
  else
    return (decimal_number % 2 + 10 *

  toBinary(decimal_number / 2));//return recursion function it self here and then back to return main

}

int lsb(int s)
{
  char str[50];//Declare String

  unsigned int i,j=0;//declare variable here

  sprintf(str, "%d", s); //convert integer to string

  for(i=strlen(str)-1;0<=i;i--)//Operation for find out lsb
  {
    if(str[i]=='1')
    {
      break;
    }
    j++;
  }

  return j;

}


int msb(int s)
{

  char str[50];//Declare String

  unsigned int i,j;//declare variable here

  sprintf(str, "%d", s); //convert integer to string

  j=strlen(str);

  for(i=0;i<strlen(str);i++)//Operation for find out lsb
  {
    if(str[i]=='1')
    {
      break;
    }

    j--;
  }

  return j-1;

}


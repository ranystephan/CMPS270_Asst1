// Github: ranystephan/CMPS270_Asst1


#include <stdio.h>
#include <string.h>

// Prototyping
int toBinary(int);
int lsb(int);
int msb(int);

int main()
{
  unsigned int num;
  printf("Please input a positive non-zero integer: ");
  scanf("%d", &num);

  int converted,converted_lsb,converted_msb;

  converted= toBinary(num);

  printf("Binary of the following number is :%d \n",converted);

  converted_lsb=lsb(converted);
  converted_msb=msb(converted);

  printf("The LSB is : %d \n",converted_lsb);
  printf("The MSB is : %d \n",converted_msb);

  printf("The distance between lsb and msb is : %d",converted_msb-converted_lsb ); //Printing the dsired distance required by the function

return 0;

}


int toBinary(int decimal_number)// Decimal to binary conversion
{
  if (decimal_number == 0)
    return 0;
  else
    return (decimal_number % 2 + 10 * toBinary(decimal_number / 2)); // Returns the recursion function

}

int lsb(int s)
{
  char str[50];

  unsigned int i,j=0;

  sprintf(str, "%d", s); 

  for(i=strlen(str)-1;0<=i;i--)
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

  char str[50];

  unsigned int i,j;

  sprintf(str, "%d", s);

  j=strlen(str);

  for(i=0;i<strlen(str);i++)
  {
    if(str[i]=='1')
    {
      break;
    }

    j--;
  }

  return j-1;

}


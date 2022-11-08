// Github: ranystephan/CMPS270_Asst1

#include <stdio.h>

// Prototyping
int hammingDistance(int, int);


int main()
{
  int number1;
  int number2;

  do
  {
    printf("Please input a pair of two integers: ");
    scanf("%d", &number1);
    if(number1 < 0){break;};
    scanf("%d", &number2);
    printf("%d\n", hammingDistance(number1, number2));


  }while(number1 >= 0 && number2 >= 0);
  
}

// Function to calculate the hamming distance between two integers
// Requires: two integers
// Returns: the hamming distance between the two integers
// Testing Strategy: input two integers and compare the output to the expected output
int hammingDistance(int n1, int n2)
{
  int x = n1 ^ n2;
  int bits = 0;

  while (x > 0)
    {
      bits += x & 1;
      x >>= 1;
    }

  return bits;
}

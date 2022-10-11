#include <stdio.h>
#define SIZE 10 // Symbolic constant with value 10 to be used to refer to the size of the array when needed

void printArray(int[]); // Takes 1D array and prints it as Index\tValue
void arrayHistogram(int[]); //Takes an array anc computes its histogram
void swapValues(int[], int, int); // Takes an array and two indices, then swaps the values at these indices
void bubbleSort(int[]); // Sorts taken array using bubble sort algorithm
float median(int[]); // Calculates the median of an array
int mode(int[]); // Returns the mode of an array (most existing value)
int isSorted(int[], int); // Takes 1D array of integers, and its size, and returns 1 if the array is sorted in ascending order and 0 otherwise

void printArray(int arr[])
{
  printf("Index\tValue\n");
  for (int i = 0; i < SIZE; i++)
    {
      printf("%d\t%d\n", i, arr[i]); //prints iterated index along with iterated value of array at index i
    }
}

void arrayHistogram(int arr[])
{
  int frequency[3] = {0};


  for(int i = 0; i < SIZE; i++)
    {
      frequency[arr[i] - 1]++;
    }


  printf("Value\tFrequency\tHistogram\n");

  for(int i = 0; i<3; i++)
    {
      printf("%d\t%d\t\t", i+1, frequency[i]);
      for(int j = 0; j<frequency[i]; j++)
        {
          printf("*");
        }
      printf("\n");
    }
}

void swapValues(int arr[], int first, int second) 
{
  int temp = arr[first]; // Stores first index value in a temp to input it in the second index later

  // Swapping the two values
  arr[first] = arr[second];
  arr[second] = temp;
}



void bubbleSort(int arr[])
{
  for(int i=0; i<SIZE-1; i++) 
    {
      for(int j=0; j<SIZE-1; j++) 
        {
          if(arr[j] >= arr[j+1])
          {
            swapValues(arr, j, j+1);
          }
        }
    }
}


float median(int arr[])
{
  if(SIZE%2==0)
  {
    return (arr[SIZE/2-1] + arr[SIZE/2])/2; // Average of the two middle values in case Size is even
  }
  else 
  {
    return arr[(SIZE-1)/2]; // Good to have else case in case of change of SIZE to odd value
  }
}



int mode(int arr[]) // Similar to arrayHitogram function
{
  int frequency[3] = {0};

  for(int i=0; i<SIZE; i++) 
  {
    frequency[arr[i]-1]++;
  }
    
  int mx = 0;

  for(int i=0; i<3; i++)
    {
      mx = (mx > frequency[i])? mx:frequency[i];
    }
    
  return mx;
}

int isSorted(int arr[], int n)
{
  int ans = 1;
  for(int i=0; i<n-1; i++) 
    {
      if(arr[i] > arr[i+1])
        ans = 0;
    }
    
  return ans;
}

int main()
{
  int test_array[SIZE] = {1, 1, 1, 1, 1, 2, 2, 2, 3, 3}; // Same array as example in instruction
    
  printArray(test_array);
  arrayHistogram(test_array);
    
  printf("Here is the array before the swap: %d\t%d\n", test_array[4], test_array[7]);
  swapValues(test_array, 2, 5);
  printf("Here is the array after the swap: %d\t%d\n", test_array[4], test_array[7]); // Same indices different values shows effective swap
  printf("As you can see, the values are the same and so the swap was effective!");
    
  bubbleSort(test_array);
    
  float med = median(test_array);
  printf("The median of the test_array is:  %.2f\n", med);
    
  int mod = mode(test_array);
  printf("The mode of the test_array is:  %d\n", mod);
    
  int issorted = isSorted(test_array, SIZE);
  if(issorted)
    printf("test_array is sorted\n");
  else
    printf("test_array is not sorted\n");
    
  return 0;
}


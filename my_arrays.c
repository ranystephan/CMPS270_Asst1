#include <stdio.h>

#define SIZE 10

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
  int temp = arr[first];
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
      return (arr[SIZE/2-1] + arr[SIZE/2])/2;
  else 
      return arr[(SIZE-1)/2];
}

int mode(int arr[]) 
{
  int freq[3] = {0};
  for(int i=0; i<SIZE; i++) 
    {
      freq[arr[i]-1]++;
    }
    
  int mx = 0;
  for(int i=0; i<3; i++)
    {
      mx = (mx > freq[i])? mx:freq[i];
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
  int arr[SIZE] = {2,3,1,3,1,2,1,1,3,2};
    
  printArray(arr);
    
  arrayHistogram(arr);
    
  printf("before swap \n%d %d\n", arr[2], arr[5]);
  swapValues(arr, 2, 5);
  printf("after swap \n%d %d\n", arr[2], arr[5]);
    
  bubbleSort(arr);
    
  float MEDIAN = median(arr);
  printf("median of array - %.2f\n", MEDIAN);
    
  int MODE = mode(arr);
  printf("mode of the array - %d\n", MODE);
    
  int sorted = isSorted(arr, SIZE);
  if(sorted)
    printf("array is sorted\n");
  else
    printf("array is not sorted\n");
    
  return 0;
}


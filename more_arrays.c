// Github: ranystephan/CMPS270_Asst1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Prototyping
char** merge(char *arr1[], int size1, char *arr2[], int size2);
char** concat(char *arr1[], int size1, char *arr2[], int size2); //takes 2D array of strings as input and returns a 1D array containing the concatenation of elements in each element of the 2D array with space seperation

// Requires: two arrays of strings and their sizes
// Returns: a new array of strings containing the elements of the two arrays
// Testing Strategy: input two arrays of strings and compare the output to the expected output
char** merge(char *arr1[], int size1, char *arr2[], int size2)
{
  char **result = (char **)malloc((size1+size2)*sizeof(char *));

  for(int i=0; i<(size1+size2); i++)
    result[i] = (char *)malloc(100 * sizeof(char));

  int i = 0, j=0, k=0;

  while(i<size1 && j<size1)
  {
    if(strcmp(arr1[i], arr2[i])>0)
    {
      strcpy(result[k], arr1[i]);
      i++;
    }
    else
    {
      strcpy(result[k], arr2[j]);
      j++;
    }
    k++;
  }

  while(i<size1)
  {
    strcpy(result[k], arr1[i]);
    i++;
    k++;
  }

  while(j<size2)
  {
    strcpy(result[k], arr2[j]);
    j++;
    k++;
  }

  return result;
}


// Requires: two arrays of strings and their sizes
// Returns: a new array of strings containing the concatenation of elements in each element of the 2D array with space seperation
// Testing Strategy: input two arrays of strings and compare the output to the expected output
char** concat(char *arr1[], int size1, char *arr2[], int size2)
{
  char **result = (char **)malloc(2*sizeof(char *));

  for(int i=0; i<2; i++)
  {
    result[i] = (char *)malloc(100 * sizeof(char));
  }

  int k=0;

  for(int i=0; i<size1; i++)
  {
    strcat(result[0], arr1[i]);
    if(i!=size1-1)
      strcat(result[0], " ");

  }

  for(int i=0; i<size2; i++)
  {
    strcat(result[1], arr2[i]);
    
    if(i!=size2-1)
      strcat(result[1], " ");

  }

  return result;

}



int main()
{
  char *s_one[] = {"ab", "ac"};
  char *s_two[] = {"za", "zb", "zzzzc"};
  char **result = merge(s_one, 2, s_two, 3);

  for(int i=0; i<5; i++)
  {
    printf("%s\n", result[i]);
  }

  char *s_three[] = {"I", "LOVE", "CODING"};
  char *s_four[] = {"THIS", "IS", "SPARTA"};

  char **result_two = concat(s_three, 3, s_four, 3);

  printf("%s, %s\n", result_two[0], result_two[1]);

  return 0;

}

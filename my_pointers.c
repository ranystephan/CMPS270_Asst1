// Github: ranystephan/CMPS270_Asst1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Prototyping
char** merge(int, int, char**, char**);



char** merge(int number1, int number2, char** a, char** b){

    int i=0, j=0, k=0;

    char **result = malloc(100 * sizeof(char*));

    for (int i = 0 ; i < 10; ++i)
        result[i] = malloc(20 * sizeof(char));

    while(i<number1 && j<number2)
    {
      if(strcmp(a[i], b[j]) <= 0) strcpy(result[k++], a[i++]);
      else strcpy(result[k++], b[j++]);
    }

    while(i<number1)
      strcpy(result[k++], a[i++]);

    while(j<number2)
      strcpy(result[k++], b[j++]);
    return ans;
}
int main(){
    char *a[3] = {"ab", "ac", "zd"}, *b[4] = {"za", "zb", "zzzzc"};
    char **answer = merge(3, 3, a, b);
    for(int i=0; i<6; i++) printf("%s\n", answer[i]);
    return 0;
}

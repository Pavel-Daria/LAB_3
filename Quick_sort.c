#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10
 
int main() 
{
  int num[size];
  int  next_num;

  srand(time(NULL));

  for (int i = 0; i < size; i++) 
  {
    num[i] = rand() % 100;
    printf("%d ", num[i]);
  }
  printf("\n");

  for (int i = 0; i < size - 1; i++) 
  {
    for (int j = 0; j < size - i - 1; j++) 
    {
      if (num[j] > num[j + 1]) 
      {
        next_num = num[j];
        num[j] = num[j + 1];
        num[j + 1] = next_num;
      }
    }
  }

  for (int i = 0; i < size; i++)
  {
    printf("%d ", num[i]);
  }

  printf("\n");
}

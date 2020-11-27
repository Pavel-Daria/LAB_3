#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10

void quick_sort(int *numbers, int left, int right);

int main()
{
  int numbers[size];
  srand(time(NULL));
  for (int i = 0; i < size; i++)
  {
    numbers[i] = rand() % 201 - 100;
    printf("%d ", numbers[i]);
  }
  printf("\n");
  quick_sort(numbers, 0, size-1);
  for (int i = 0; i < size; i++)
  {
    printf("%d ", numbers[i]);
  }

  return 0;
}

void quick_sort(int numbers[], int left, int right)
{
  int left_hold = left;
  int right_hold = right;
  int cache = numbers[left];
  while (left < right)
  {
    while ((numbers[right] >= cache) && (left < right))
    {
      right--;
    }
    if (left != right)
    {
      numbers[left] = numbers[right];
      left++;
    }
    while ((numbers[left] <= cache) && (left < right))
    {
      left++;
    }
    if (left != right)
    {
      numbers[right] = numbers[left];
      right--;
    }
  }
  numbers[left] = cache;
  cache = left;
  left = left_hold;
  right = right_hold;
  if (left < cache)
  {
    quick_sort(numbers, left, cache - 1);
  }
  if (right > cache)
  {
    quick_sort(numbers, cache + 1, right);
  }
}

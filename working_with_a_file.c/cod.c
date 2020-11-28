#include <stdio.h>
#include <stdlib.h>
#define size 10

int maximum(int a[]);
int minimum(int a[]);
float middle(int a[]);
int mediana(int a[]);

int main(void)
{
  int a[size];
  FILE *f;
  f = fopen("file.txt", "r");

  if (f == NULL)
  {
    printf("Error");
  }

  else
  {
    for (int j = 0; j < size; j++)
    {
      fscanf(f, "%d", &a[j]);
    }

    fclose(f);
  }

  f = fopen("file.txt", "a");

  fprintf(f, "\nMaximal number in the array = %d\n", maximum(a));
  fprintf(f, "Minimal number in the array = %d\n", minimum(a));
  fprintf(f, "Middle number in the array = %.1f\n", middle(a));
  fprintf(f, "Median of the array = %d\n", mediana(a));

  fclose(f);
}

int minimum(int a[])
{
  int min = a[0];

  for (int i = 1; i < size; i++)
  {
    if (a[i] < min)
    {
      min = a[i];
    }
  }

  return min;
}

int maximum(int a[])
{
  int max = a[0];

  for (int i = 1; i < size; i++)
  {
    if (a[i] > max)
    {
      max = a[i];
    }
  }

  return max;
}

float middle(int a[])
{
  double middle = 0;

  for (int i = 0; i < size; i++)
  {
    middle += a[i];
  }

  return middle / size;
}

int mediana(int a[])
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int i = 0; i < size - i - 1; i++)
    {
      if (a[i] > a[i + 1])
      {
        a[i] = a[i] + a[i + 1];
        a[i + 1] = a[i] - a[i + 1];
        a[i] = a[i] - a[i + 1];
      }
    }
  }

  if (size % 2 != 0)
  {
    return a[size / 2];
  }

  else
  {
    return (a[size / 2] + a[size / 2 - 1]) / 2;
  }
}

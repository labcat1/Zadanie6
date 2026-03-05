#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max 100
bool theInput(int* array, int size) {
   int temp = 0;
   while (temp < size) {
      printf("Enter a number: ");
      scanf("%d", &array[temp]);
      temp++;
   }
   return true;
}

int Max(int* array, int size) {
   int temp = 0;
   int current_maximum=array[0];
   while (temp < size) {
      if (array[temp] > current_maximum) {
         current_maximum = array[temp];
      }
      temp++;
   }
   return current_maximum;
}

int Min(int* array, int size) {
   int temp = 0;
   int current_minimum= array[0];
   while (temp < size) {
      if (array[temp] < current_minimum) {
         current_minimum = array[temp];
      }
      temp++;
   }
   return current_minimum;
}

float Mean(int* array, int size) {
   int temp = 0;
   int sum = 0;
   while (temp < size) {
      sum = sum + array[temp];
      temp++;
   }
   return ((float)sum)/((float)size);
}

float RMS(int* array, int size) {
   int temp = 0;
   int sum = 0;
   while (temp < size) {
      sum = sum + array[temp]* array[temp];
      temp++;
   }
   float squared_sum = sqrt((float)sum/(float)size);
   return squared_sum;
}

int main(void) {
   int size;
   printf("Input number of elements:");
   scanf("%d", &size);
   if (size > max) {
      printf("Your array is too big!");
   }
   else {
      int* array = (int*)malloc(size*sizeof(int));
      if (array == 0) {
         printf("ERROR: COULDN'T ALLOCATE MEMORY");
      }
      theInput(array, size);
      printf("Maxinum:%d", Max(array, size));
      printf("\nMinimum:%d", Min(array, size));
      printf("\nMean:%f", Mean(array, size));
      printf("\nRMS:%f", RMS(array, size));
      free(array);
   }
}
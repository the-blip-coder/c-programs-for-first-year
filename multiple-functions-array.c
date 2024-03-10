/*
  Author - Dhruv Varshney
  Date - 29.02.2024
*/

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
int N = 0;
void printArray(int arr[],int n) {
  printf("\nTHE ARRAY IS : -\n");
  for(int i = 0; i < n ; i++) {
    printf("%d ",arr[i]);
  }
  printf("\n");
}
int fillcheck(int arr[],int n) {
  if(n == 0) {
    printf("Error: Please Implement fill function before using this function");
    return 1;
  }
  return 0;
}

void swp(int *a,int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void fill(int arr[]) {
  printf("Enter the size of the array required : ");
  scanf("%d",&N);
  if(N > 40) {
    printf("Max. size limit - 40");
    return;
  }
  for(int i = 0; i < N ; i++) {
    arr[i] = rand() % 900 + 100;
  }
  printArray(arr,N);
}

void exchange(int arr[], int n) {
  if(fillcheck(arr,n)) return;
  printArray(arr,n);
  for(int i = 0; i < (n / 2) ; i++) {
    swp(&arr[i],&arr[i + (n / 2)]);
  }
  printArray(arr,n);
}

void rotate_right(int arr[],int n) {
  if(fillcheck(arr,n)) return;
  printArray(arr,n);
  int t = arr[0];
  for(int i = 1; i < n; i++) {
    int temp = arr[i];
    arr[i] = t;
    t = temp;
  }
  arr[0] = t;
  printArray(arr,n);
}

void rotate_left(int arr[],int n) {
  if(fillcheck(arr,n)) return;
  printArray(arr,n);
  int t = arr[0];
  for(int i = 1; i < n ; i++) {
    arr[i - 1] = arr[i];
  }
  arr[n - 1] = t;

  printArray(arr,n);
}

void segregate(int arr[],int n) {
  if(fillcheck(arr,n)) return;
  printArray(arr,n);
  int end = n - 1;
  for(int i = 0; i < n/2 ; i++) {
    if(arr[i] % 2 == 0) {
      while(arr[end] % 2 == 0) {
	end--;
      }	
      swp(&arr[i],&arr[end]);
      end--;
    }
  }
  printArray(arr,n);
}
void search(int arr[],int n) {
  if(fillcheck(arr,n)) return;
  printArray(arr,n);
  int num,flag = 0,idx;
  printf("Enter the number to be searched : ");
  scanf("%d",&num);
  for(int i = 0; i < n ; i++) {
    if(num == arr[i]) {
      flag = 1;
      idx = i;
      printf("Element found at %d",idx);
      printf("\n");
    }
  }
  if(flag == 0) {
    printf("Not Found");
  }
}

void analyze(int arr[],int n) {
  if(fillcheck(arr,n)) return;
  printArray(arr,n);
  int c = 0;
  for(int i = 0; i < (n - 3) ; i++) {
    if(arr[i] < arr[i + 1] && arr[i + 2] > arr[i + 3]) {
      c++;
      printf("%d, %d, %d, %d\n",arr[i],arr[i + 1],arr[i + 2],arr[i + 3]);
    }
  }
  if(c == 0) {
    printf("No such pattern of numbers present");
  }
}

int main() {

  int a[40];

  int option;  

  while(1) {
    printf("\nMenu choices:\n\ti.\t1 ---- Fill\n\tii.\t2 ---- Exchange\n\tiii.\t3 ---- Rotate right\n\tiv.\t4 ---- Rotate left\n\tv.\t5 ---- Sort\n\tvi.\t6 ---- Search\n\tvii.\t7 ---- Analyze\n\tviii.\t0,8 or any higher number ---- Exit\n");
    printf("\nEnter choice of function: ");
    scanf("%d",&option);

    switch(option) {
    case 1 :
      fill(a);
      break;
    case 2 :
      exchange(a,N);
      break;
    case 3 :
      rotate_right(a,N);
      break;
    case 4 :
      rotate_left(a,N);
      break;
    case 5 :
      segregate(a,N);
      break;
    case 6 :
      search(a,N);
      break;
    case 7 :
      analyze(a,N);
      break;
    }
    if(option  > 7 || option == 0) {
      printf("Exiting the program\n");
      break;
    }
  }
}

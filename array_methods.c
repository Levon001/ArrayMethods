#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

///concat()
int* concat(int* ch1, int* ch2, int size1, int size2)
{
    int * tmp = (int*)malloc(size1 + size2);
    int j = 0;
    for (int i = 0; i < size1 ; ++i)
    {
        tmp[j] = ch1[i];
        ++j;
    }
    for (int i = 0; i < size2; ++i)
    {
        tmp[j] = ch2[i];
       ++j;
    }
    return tmp;
}


// forEach
void foo(int *num) {
  *num += 1;
}

void forEach(int *arr, int size, void (*callback)(int *)) {
  for (int i = 0; i < size; ++i) {
    callback(arr + i);
  }
}

// every
int test(int num) {
  return num <= 5;
}

int every(int *arr, int size, int (*test)(int)) {
  for (int i = 0; i < size; ++i) {
    if (!test(*(arr + i))) {
      return -1;
    }
  }
  return 0;
}
// filter

int cmp(int num) {
  return num % 2 == 0;
}

int *filter(int *arr, int size, int (*cmp)(int)) {
  int *newArr = (int *)calloc(size, sizeof(int));
  int count = 0;
  for (int i = 0; i < size; ++i) {
    if (cmp(arr[i])) {
      newArr[count++] = arr[i];
    }
  }
  newArr = (int *)realloc(newArr, sizeof(int) * count);
  return newArr;
}

// flat
//?????????????????????????

// indexOf

int indexOf(int *arr, int size, int elem) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] == elem) {
      return i;
    }
  }
  return -1;
}

// lastindex

int lastIndexOf(int *arr, int size, int elem) {
  for (int i = size - 1; i >= 0; --i) {
    if (arr[i] == elem) {
      return i;
    }
  }
  return -1;
}

// map

int change(int num) {
  return num * 3;
}

int *map(int *arr, int size, int (*change)(int)) {
  int *newArr = (int *)calloc(size, sizeof(int));
  for (int i = 0; i < size; ++i) {
    newArr[i] = change(arr[i]);
  }
  return newArr;
}

/// reduce............
/////??????????????????????????????????????????????????????????????????????????????????????????????///////

/// reverse
int *reverse(int *arr, int size) {
  int *newArr = (int *)calloc(size, sizeof(int));

  for (int i = 0; i < size; ++i) {
    newArr[i] = arr[size - 1 - i];
  }

  return newArr;
}

////slice

int *slice(int *arr, int size, int index) {
   int newSize;
   if (index >= 0) { 
        newSize = size - index;
   } else {
        newSize = size + index;
        index = size + index;
   }
  int *newArr = (int *)calloc(newSize, sizeof(int));
  int j = 0;

  for (int i = index; i < size; ++i) {
    newArr[j++] = arr[i];
  }
  return newArr;
}

int *slice1(int *arr, int size, int startIndex, int endIndex) {
  int newSize = endIndex - startIndex;
  int *newArr = (int *)malloc(newSize * sizeof(int));
  int j = 0;
  for (int i = startIndex; i < endIndex; ++i) {
    newArr[j++] = arr[i];
  }
  return newArr;
}

///some

int tes(int num) {
  return num % 2 == 1;
}

int some(int *arr, int size, int (*tes)(int)) {
  for (int i = 0; i < size; ++i) {
    if (tes(*(arr + i))) {
      return 1;
    }
  }
  return -1;
}

//sort
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int *arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
      bool correct = false;
      for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
          swap(arr + i, arr + i + 1);
          correct = true;
        }
      }
      if(!correct) {
        break;
      }
    }
}

////splice
int* splice(int* arr, int size, int index, int count) {
    if (index < 0) {
      return NULL;
    }
    int* newArr = (int*)calloc(sizeof(int),(size - count));
    int j = 0;
    for (int i = 0; i < size; ++i) {
      if (i >= index && i < (index + count)) {
        continue;
      }
      newArr[j++] = arr[i];
    }
    return newArr;
}

int* splice1(int* arr, int size, int index, int count, int element) {
    int newSize;
    if (count >= 0) {
      newSize = size - count + 1;
    } else {
      return NULL;
    }
    int* newArr = (int*)calloc(sizeof(int),newSize);
    int j = 0;
    for (int i = 0; i < size; ++i) {
      if (i > index && i < (index + count)) {
        continue;
      }
      newArr[j++] = arr[i];
    }
    newArr[index] = element;
    return newArr;
}

//// fill()
int* fill(int* arr, int size,int element, int index, int index2) {
    if(index > size) {
      return arr;
    } 
    if(index < -size) {
      index = 0;
    } else if (index < 0) {
      index += size;
    }
        
    for (int i = index; i < index2; ++i) {
      arr[i] = element;
    }
    return arr;
}

// find

int prov(int num) {
  return num > 2;
}

int find(int* arr, int size,int(*callback)(int)) {
  for (int i = 0; i < size; ++i) {
    if (callback(arr[i])) {
      return arr[i];
    }
  }
  return -1;
}

//// findIndex()
int findIndex(int* arr, int size,int(*callback)(int)) {
  for (int i = 0; i < size; ++i) {
    if (callback(arr[i])) {
      return i;
    }
  }
  return -1;
}

//// findLastIndex()

int findLastIndex(int* arr, int size,int(*callback)(int)) {
  for (int i = size - 1; i >= 0; ++i) {
    if (callback(arr[i])) {
      return i;
    }
  }
  return -1;
}

/// includes()
bool Includes(int * arr, int size, int index , int num)
{
    if (index >= size)
    {
        return false;
    }
    if (arr[index] == num)
    {
        return true;
    }
    if (index < 0 && arr[index + size] == num )
    {
        return true;
    }
    if (index < -size)
    {
        for (size_t i = 0; i < size; ++i)
        {
            if (arr[i] = num)
            {
                return true;
            }
        }
        return false;
    }
}

//// join()
 char* join(int* arr, int size, char symbol) {
    int resultLength = size + size - 1;

    char* newArr = (char*)calloc(resultLength + 1, sizeof(char));
    int index = 0;
    for (int i = 0; i < size ; ++i) {
        newArr[index] = (char)arr[i];
        newArr[index + 1] = symbol;
        ++index;
    }
    
    return newArr;
}


//reduce 
int sumReducer(int accumulator, int current) {
    return accumulator + current;
}


int reduce(int array[], int size, int (*reducer)(int accumulator, int current)) {
    int accumulator = array[0]; 

    for (int i = 1; i < size; i++) {
        accumulator = reducer(accumulator, array[i]);
    }

    return accumulator;
}

// 

int main()
{

  // int arr[] = {0,0,0, 2, 1, 1, 3, 5,0,0, 6,0, 0 , 0};
  // int size = sizeof(arr) / sizeof(arr[0]);

  // sort(arr,size);
  int arr[] = {1,2,3,4};
  char* var = joinn(arr,4,'-');


  // int a = findLastIndex(arr, size, prov);
  // printf("%d" ,a);
   
  // int* a = slice(arr,size,-2);

  // int *a = filter(arr, size, cmp);
  // int sie = sizeof(a) / sizeof(a[0]);
  // // printf("%d" , size);
  for (int i = 0; var[i] != '\0'; i++) {
        printf("%c", var[i]);
    }
    printf("\n");
  


  // int i = some(arr, size, tes);
  // printf("%d ", i);
  // printf("%d ", lastIndexOf(arr,size,1));
  return 0;
}

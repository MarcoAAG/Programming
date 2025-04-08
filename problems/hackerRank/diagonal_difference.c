#include <stdio.h>
#include <stdlib.h>  // abs()

/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(int arr_rows, int arr_columns, int** arr)
{
  int left=0;  
  int right=0;  
  int it;
  int res;
  for(it=0; it<arr_rows; it++)
  {
    left += arr[it][it];
    right += arr[it][arr_columns-it-1];
  }
  res = left - right;
  if(res < 0)
  {
    res *= -1;
  }
  return abs(left - right);
}
 

void main()
{
  int arr1[] = {1,2,3};
  int arr2[] = {4,5,6};
  int arr3[] = {7,8,9};

  int *arr[] = {arr1, arr2, arr3};

  printf("%d\n",diagonalDifference(3,3,arr));

}
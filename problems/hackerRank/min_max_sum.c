/*
  Mini-Max Sum
  ==Inputs==
  -An array of 5 integers ( 1<= arr <= 10⁹)
  ==Outputs==
  - Print two space-separate long integers (can be greater than 32bits)
*/
#include <stdio.h>

// HackerRank function
void miniMaxSum(int arr_count, long long* arr) 
{
  long long sumMin;
  long long sumMax=0;
  long long sumTmp;

  sumTmp = arr[1] + arr[2] + arr[3] + arr[4]; //0 
  sumMin = sumTmp;
  if(sumTmp > sumMax)
  {
    sumMax = sumTmp;
  }
  if(sumTmp < sumMin)
  {
    sumMin = sumTmp;
  }
  sumTmp = arr[0] + arr[2] + arr[3] + arr[4]; //1
  if(sumTmp > sumMax)
  {
    sumMax = sumTmp;
  }
  if(sumTmp < sumMin)
  {
    sumMin = sumTmp;
  }
  sumTmp = arr[0] + arr[1] + arr[3] + arr[4]; //2
  if(sumTmp > sumMax)
  {
    sumMax = sumTmp;
  }
  if(sumTmp < sumMin)
  {
    sumMin = sumTmp;
  }
  sumTmp = arr[0] + arr[1] + arr[2] + arr[4]; //3
  if(sumTmp > sumMax)
  {
    sumMax = sumTmp;
  }
  if(sumTmp < sumMin)
  {
    sumMin = sumTmp;
  }
  sumTmp = arr[0] + arr[1] + arr[2] + arr[3]; //4
  if(sumTmp > sumMax)
  {
    sumMax = sumTmp;
  }
  if(sumTmp < sumMin)
  {
    sumMin = sumTmp;
  }
  printf("%lld %lld\n",sumMin, sumMax);
}

int main()
{
  long long arrInput[] = {256741038 ,623958417 ,467905213 ,714532089 ,938071625};
  int arr_countInput = 5;

  miniMaxSum(arr_countInput,arrInput);

  return 0;
}
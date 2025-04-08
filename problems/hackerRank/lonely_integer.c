#include <stdio.h>

/*
 * Complete the 'lonelyinteger' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */
int lonelyinteger(int a_count, int* a)  //O(n^2)
{
  int res;
  int index=0;
  int it;
  int oc;
  while(index < a_count)
  {
    it=0;
    oc=0;
    while(it < a_count)
    {
      if(index != it)
      {
        if(a[index] == a[it])
        {
          it = a_count;
          oc++;
        }
        else
        {
          it++;
        }
      }
      else
      {
        it++;
      }
    }
    if(oc==1)
    {
      index++;
    }
    else
    {
      res = a[index];
      index = a_count;
    }
  }
  return res;
}

int lonelyintegerEnhanced(int a_count, int* a) // O(n)
{
  int res = 0;
  for (int i = 0; i < a_count; i++) 
  {
      res ^= a[i];
  }
  return res;
}


void main()
{
  int arr[] = {1,2,3,4,3,2,1};
  printf("%d\n",lonelyintegerEnhanced(7,arr)); 

}
/*
  Mini-Max Sum
  ==Inputs==
  -An array of 5 integers ( 1<= arr <= 10⁹)
  ==Outputs==
  - Print two space-separate long integers (can be greater than 32bits)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// HackerRank function
void miniMaxSum(vector<long long> arr) 
{
  long long sumMin, sumMax;
  sort(arr.begin(),arr.end());
  sumMin = arr[0] + arr[1] + arr[2] + arr[3]; 
  sumMax = arr[4] + arr[1] + arr[2] + arr[3]; 

  cout << sumMin << " " << sumMax << "\n";
}

int main()
{
  vector<long long> arrInput = {256741038 ,623958417 ,467905213 ,714532089 ,938071625};
  

  miniMaxSum(arrInput);

  return 0;
}
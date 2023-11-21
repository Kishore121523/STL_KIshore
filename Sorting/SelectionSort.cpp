#include<bits/stdc++.h>

using namespace std;

int main(){
  // Selection sort - we select minimums
  // Step 1 - get the minimum element in the array and swap it with the first element
  // Step 2 - From second element, find minimum of the array and swap it with second element
  // Step 3 - From the third element, repeat the same steps till end of the array

  // 13,46,24,52,20,9 - Input 
  // 9,46,24,52,20,13 - Step 1
  // 9,13,24,52,20,46 - Step 2
  // 9,13,20,52,24,46 - Step 3
  // 9,13,20,24,52,46 - Step 4
  // 9,13,20,24,46,52 - Step 5 - sorted
  // 6 elements, sorted in 5 stepes - n-1 steps where n is number of elements in input array
  return 0;
}
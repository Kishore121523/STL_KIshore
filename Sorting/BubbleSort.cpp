#include<bits/stdc++.h>

using namespace std;

int main(){
  // Pushes the maximum to the last by adjacent swapping

  // First round of adjacent swaps - after step 1 last 1 element is maximum
  // 13, 46, 24, 52, 20, 9 - Input from user
  // 13, 46, 24, 52, 20, 9 - Compare [13,46] no swap
  // 13, 24, 46, 52, 20, 9 - Compare [46,24] swap
  // 13, 24, 46, 52, 20, 9 - Comapre [46,52] no swap
  // 13, 24, 46, 20, 52, 9 - Compare [52,20] swap
  // 13, 24, 46, 20, 9, 52 - Compare [52,9] swap

  // Second round - after second round last 2 elemetns are in correct order
  // 13, 24, 46, 20, 9, 52 - Input from round 1
  // 13, 24, 46, 20, 9, 52 - Compare [13,24] no swap
  // 13, 24, 46, 20, 9, 52 - Compare [24,46] no swap
  // 13, 24, 20, 46, 9 ,52 - Compare [46,20] swap
  // 13, 24, 20, 9, 46, 52 - Compare [46,9] swap

  // Third round - After third round last 3 elements will be in correct order
  // 13, 24, 20, 9, 46, 52 - Input from round 2
  // 13, 24, 20, 9, 46, 52 - Compare [13,24] no swap
  // 13, 20, 24, 9, 46, 52 - Compare [24,20] swap
  // 13, 20, 9, 24, 46, 52 - Compare [24,9] swap

  // Fourth round - After fourth round last 4 elements will be in correct order
  // 13, 20, 9, 24, 46, 52 - Input from round 3
  // 13, 20, 9, 24, 46, 52 - Compare [13,20] no swap
  // 13, 9, 20, 24, 46, 52 - Compare [20,9] swap

  // Fifth round - After fifth round last 5 elements will be in correct order
  // 13, 9, 20, 24, 46, 52 - Input from round 4
  // 9, 13, 20, 24, 46, 52 - Compare [13,9] swap

  return 0;
}
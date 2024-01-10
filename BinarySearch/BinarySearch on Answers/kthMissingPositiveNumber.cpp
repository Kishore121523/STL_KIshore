#include<bits/stdc++.h>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        while(low<=high){
            int mid = low + (high-low)/2;
            int missing = arr[mid] - (mid+1);

            if(missing < k){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }

        }
        return low+k;
    }


int main(){
  vector<int> arr = {2,3,4,7,11};
  int k = 5;

  // arr[i-1] < arr[i] > arr[i+1] - arr[i] is the peak element
  cout << findKthPositive(arr,k); // TC = O(log2N)
  cout << "\n";

  return 0;
}
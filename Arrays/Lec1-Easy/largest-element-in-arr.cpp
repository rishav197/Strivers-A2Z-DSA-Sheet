class Solution {
  public:
    int largest(vector<int> &arr) {
        int n = arr.size();
        int mx = INT_MIN;
        
        for(int idx=0; idx<n; idx++){
            if(arr[idx]>mx){
                mx = arr[idx];
            }
        }
        
        return mx;
    }
};


class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        
        int n = arr.size();
        
        //step1: build max heap for first K elements 
        priority_queue<int> mxheap;
        for(int idx=0; idx<k; idx++){
            mxheap.push(arr[idx]);
        }
        
        //step2: for rest elements
        for(int idx=k; idx<n; idx++){
            int element = arr[idx];
            
            if(element<mxheap.top()){
                mxheap.pop();
                mxheap.push(element);
            }
        }
        
        int ans = mxheap.top();
        return ans;
    }
};
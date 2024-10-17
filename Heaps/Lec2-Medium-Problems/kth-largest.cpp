class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        // step1: build min heap from first k elements
        priority_queue<int, vector<int>, greater<int>> minhp;
        for(int idx=0; idx<=k-1; idx++){
            minhp.push(nums[idx]);
        }

        //step 2: processing rest elements 
        for(int idx=k; idx<n; idx++){
            if(nums[idx] > minhp.top()){
                minhp.pop();
                minhp.push(nums[idx]);
            }
        }

        int ans = minhp.top();
        return ans;
    }
};
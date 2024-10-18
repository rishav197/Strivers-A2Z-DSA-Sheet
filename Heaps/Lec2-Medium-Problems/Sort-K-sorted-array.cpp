
/*approach-1: without using heap*/
#include<algorithm>

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        int n = K*K;
        vector<int> ans;
        
        for(int idx=0; idx<K; idx++){
            
            for(auto e : arr[idx]){
                ans.push_back(e);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
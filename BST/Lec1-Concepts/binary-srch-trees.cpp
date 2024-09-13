/*
tc - O(N), sc - O(1)
*/

class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
  
        int n = arr.size();
        
        for(int idx=1; idx<n; idx++){
            if(arr[idx-1]>=arr[idx]){
                return false;
            }
        }
        
        return true;
    }
};


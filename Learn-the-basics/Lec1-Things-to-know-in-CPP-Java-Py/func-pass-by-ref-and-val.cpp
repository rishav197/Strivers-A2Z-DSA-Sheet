// User function Template for C++

class Solution {
  public:
    vector<int> passedBy(int a, int &b) {
        // code here
        a += 1;
        b += 2;
        
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        
        return ans;
    }
};
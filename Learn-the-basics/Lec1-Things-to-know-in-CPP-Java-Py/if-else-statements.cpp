//User function Template for C++

class Solution {
  public:
    string compareNM(int n, int m){
        string ans;
        
        if(n<m){
            ans = "lesser";
        }
        else if(n>m){
            ans = "greater";
        }
        else{
            ans = "equal";
        }
        
        return ans;
    }
};
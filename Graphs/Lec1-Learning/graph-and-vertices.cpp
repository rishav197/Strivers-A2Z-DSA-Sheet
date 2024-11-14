// User function Template for C++
class Solution {
  public:
    long long count(int n) {

        long long totalCount = pow(2, (n*(n-1)/2));
        
        return totalCount;
    }
};
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        priority_queue<long long, vector<long long>, greater<long long>> minhp;
        
        for(int idx=0; idx<arr.size(); idx++){
            minhp.push(arr[idx]);
        }
        
        long long cost = 0;
        
        while(minhp.size()>1){
            long long e1 = minhp.top();
            minhp.pop();
            
            long long e2 = minhp.top();
            minhp.pop();
            
            long long sum = e1+e2;
            cost += sum;
            
            minhp.push(sum);
        }
        
        return cost;
    }
};
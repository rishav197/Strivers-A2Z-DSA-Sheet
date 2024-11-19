/* approach 1: using freq[] array */

class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& arr) {
        // code here
        int n = arr.size();
        int N = n+1;
        
        vector<int> freq(N, 0);
        
        for(int i=0; i<n; i++){
            freq[arr[i]] += 1;
        }
        
        //final answer
        vector<int> ans;
        for(int i=1; i<N; i++){
            ans.push_back(freq[i]);   
        }
        
        return ans;
    }
};




/* approach 2: using map */

class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& arr) {
        
        unordered_map<int, int> mp;
        int N = arr.size();
        
        for(int i=0; i<N; i++){
            mp[arr[i]]++;
        }
        
        for(int i=1; i<=N; i++){
            arr[i-1] = mp[i];
        }
        
        return arr;
        
    }
};

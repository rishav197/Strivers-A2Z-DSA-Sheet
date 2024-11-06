/*approach1 : without using heap and map is used */

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        
        vector<int> sorted = arr;
        unordered_map<int, int> mapping;
        sort(sorted.begin(), sorted.end());
        
        int rank=1;
        for(int idx=0; idx<N; idx++){
            if(mapping.find(sorted[idx])==mapping.end()){
                mapping[sorted[idx]] = rank;
                rank++;
            }
        }
        
        for(int idx=0; idx<N; idx++){
            arr[idx] = mapping[arr[idx]];
        }
        
        return arr;
    }

};


/*approach2 : using heap */
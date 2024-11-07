class Solution {
public:
    class compare{
    public:
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;

        //step1: make (val, count) table
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]] += 1;
        }

        //step2: make min heap
        for(auto it : mp){
            pq.push(make_pair(it.first, it.second));

            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;

    }
};
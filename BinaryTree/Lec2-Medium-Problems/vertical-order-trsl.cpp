class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,vector<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;
        vector<vector<int>> ans;

        if(root==NULL){
            return ans;
        }

        q.push(make_pair(root, make_pair(0,0)));

        while(!q.empty()){
            pair<TreeNode*, pair<int,int>> top = q.front();
            q.pop();

            TreeNode* topNode = top.first;
            int hd = top.second.first;
            int lvl = top.second.second;

            nodes[hd][lvl].push_back(topNode->val);

            if(topNode->left){
                q.push(make_pair(topNode->left, make_pair(hd-1,lvl+1)));
            }
            if(topNode->right){
                q.push(make_pair(topNode->right, make_pair(hd+1,lvl+1)));
            }
        }

        //prepare final answer and stores them in the ans vector
        for(auto it1:nodes){
            vector<int> out;
            for(auto it2:it1.second){
                vector<int> values=it2.second;
                sort(values.begin(),values.end());
                out.insert(out.end(),values.begin(),values.end());
            }
            ans.push_back(out);
        }
        return ans;
    }
};
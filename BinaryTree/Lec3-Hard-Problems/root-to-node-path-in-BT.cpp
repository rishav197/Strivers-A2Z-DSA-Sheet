

class Solution {
  public:
    void solve(Node* root, vector<vector<int>> &ans, vector<int> path){
        //base case
        if(root==NULL){
            return;
        }
        if(root->left==NULL and root->right==NULL){
            //add curr path to the answer vector
            path.push_back(root->data);
            ans.push_back(path);
            return;
        }
        
        path.push_back(root->data); 
        
        //call for left and right
        solve(root->left,ans,path);
        solve(root->right,ans,path);

        
        path.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> path;
        
        solve(root,ans,path);
        
        return ans;
    }
};
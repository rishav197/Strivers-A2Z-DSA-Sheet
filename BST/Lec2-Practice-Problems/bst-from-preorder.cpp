/*
tc -> O(N), sc -> O(N)
*/
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int mini, int maxi, int &idx){
        //
        if(idx >= preorder.size()){
            return NULL;
        }

        if(preorder[idx]<mini or preorder[idx]>maxi){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[idx++]);
        //build left
        root->left = solve(preorder, mini, root->val, idx);
        //build right 
        root->right = solve(preorder, root->val, maxi, idx);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxi = INT_MAX;

        int idx = 0;
        
        return solve(preorder, mini, maxi, idx);
    }
};
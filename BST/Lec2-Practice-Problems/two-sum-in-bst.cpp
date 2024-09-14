/*
tc - O(N), sc - O(N)
 */
class Solution {
public:
    void inorderTrsl(TreeNode* root, vector<int> &inorder){
        //base case
        if(root==NULL){
            return;
        }

        //LNR
        inorderTrsl(root->left, inorder);
        inorder.push_back(root->val);
        inorderTrsl(root->right, inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        //step-1 : store inorder in a vector
        vector<int> inorder;
        inorderTrsl(root, inorder);

        //step-2: two pointer algo
        int st = 0;
        int ed = inorder.size()-1;

        while(st<ed){
            if(inorder[st]+inorder[ed]==k){
                return true;
            }
            else if(inorder[st]+inorder[ed] > k){
                ed-=1;
            }
            else{
                st+=1;
            }
        }

        return false;
    }
};
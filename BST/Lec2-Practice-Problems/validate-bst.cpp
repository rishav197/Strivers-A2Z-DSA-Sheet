/*
tc - O(N), sc - O(ht)

approach : keep a valid range for each node 
 */
class Solution {
public:
    bool isBST(TreeNode* root, long minVal, long maxVal){
        //base case
        if(root==NULL){
            return true;
        }

        if(root->val<=minVal or root->val>=maxVal){
            return false;
        }


        bool ltAns = isBST(root->left, minVal, root->val);
        bool rtAns = isBST(root->right, root->val, maxVal);

        return ltAns and rtAns;
    }

    bool isValidBST(TreeNode* root) {

        return isBST(root, LONG_MIN, LONG_MAX);
    }
};
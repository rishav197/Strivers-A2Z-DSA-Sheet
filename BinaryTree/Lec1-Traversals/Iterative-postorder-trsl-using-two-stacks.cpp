/*approach: using two stacks */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;

        if(root==NULL){
            return postorder;
        }

        stack<TreeNode*> st1,st2;
        st1.push(root);

        while(!st1.empty()){
            root = st1.top();
            st1.pop();

            st2.push(root);

            if(root->left){
                st1.push(root->left);
            }
            if(root->right){
                st1.push(root->right);
            }

        }

        //storing answer back to the postorder vect
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }

        return postorder;
    }
};
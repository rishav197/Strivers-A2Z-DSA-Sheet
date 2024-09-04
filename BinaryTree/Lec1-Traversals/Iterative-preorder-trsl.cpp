
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){

            TreeNode* topNode = st.top();
            st.pop();
            ans.push_back(topNode->val);

            if(topNode->right){
                st.push(topNode->right);
            }
            if(topNode->left){
                st.push(topNode->left);
            }
        }

        return ans;

    }
};
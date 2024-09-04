/* approach: using single stack, tc->(2N), sc->O(N) */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root==NULL){
            return postorder;
        }

        stack<TreeNode*> st;
        TreeNode* cur = root;

        while(cur!=NULL or !st.empty()){
            if(cur!=NULL){
                st.push(cur);
                cur=cur->left;
            }
            else{
                TreeNode* tmp = st.top()->right;
                if(tmp==NULL){
                    tmp=st.top();
                    st.pop();
                    postorder.push_back(tmp->val);

                    while(!st.empty() and tmp==st.top()->right){
                        tmp=st.top();
                        st.pop();
                        postorder.push_back(tmp->val);
                    }
                }
                else{
                    cur=tmp;
                }
            }
        }

        return postorder;
    }
};
/*
Algo :
if num==1:
    preorder
    ++ 
    left
if num==2:
    inorder
    ++ 
    right
if num==3:
    postorder

*/
class Solution {
public:
    vector<int> preInPostTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>> st;
        st.push({root, 1}); //pair of [node_val,num]

        vector<int> pre, in, post;
        if(root==NULL){
            return;
        }

        while(!st.empty()){
            auto it = st.top();
            st.pop();

            //this is part of pre 
            //increment 1 to 2
            //push the left side of the tree
            if(it.second==1){
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);

                if(it.first->left!=NULL){
                    st.push({it.first->left, 1});
                }
            }
            else if(it.second==2){
                //this is a part of in 
                //increment 2 to 3
                //push right
                in.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->right !=NULL){
                    st.push({it.first->right, 1});
                }
            }
            else{
                //dont push it back again
                post.push_back(it.first->val);
            }

        }
        


    }
};
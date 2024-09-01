
class Solution {
public:
    void createParentMapping(TreeNode* root, map<TreeNode*,TreeNode*> &nodeToParent){
        queue<TreeNode*> q;
        q.push(root);

        nodeToParent[root]=NULL;
        
        //traversing in the tree
        while(!q.empty()){
            TreeNode* topNode = q.front();
            q.pop();

            //check left child
            if(topNode->left){
                nodeToParent[topNode->left]=topNode;
                q.push(topNode->left);
            }
            //check right child
            if(topNode->right){
                nodeToParent[topNode->right]=topNode;
                q.push(topNode->right);
            }
        }
    }

    void solve(TreeNode* root, map<TreeNode*,TreeNode*> &nodeToParent, vector<int> &ans, int k){
        queue<TreeNode*> q;
        q.push(root);

        map<TreeNode*, bool> visited;
        visited[root]=true;

        int count=0;
        while(!q.empty()){
            int size=q.size();
            bool flag=false;
            ans.clear();

            //process neighbouring nodes (Parent,Left,Right child)
            for(int i=0; i<size; i++){
                TreeNode* topNode=q.front();
                q.pop();

                //left
                if(topNode->left and !visited[topNode->left]){
                    flag=1;
                    q.push(topNode->left);
                    visited[topNode->left]=true;
                    ans.push_back(topNode->left->val);
                }

                //right
                if(topNode->right and !visited[topNode->right]){
                    flag=1;
                    q.push(topNode->right);
                    visited[topNode->right]=true;
                    ans.push_back(topNode->right->val);
                }

                //parent
                if(nodeToParent[topNode] and !visited[nodeToParent[topNode]]){
                    flag=1;
                    q.push(nodeToParent[topNode]);
                    visited[nodeToParent[topNode]]=true;
                    ans.push_back(nodeToParent[topNode]->val);
                }
            }

            
            if(flag==true){
                count+=1;
                if(count>=k){
                    return;
                }
            }

        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        if(k==0){
            ans.push_back(target->val);
            return ans;
        }
        map<TreeNode*,TreeNode*> nodeToParent;
        createParentMapping(root,nodeToParent);
        solve(target,nodeToParent,ans,k);

        return ans;
    }
};
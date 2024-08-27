
class Solution {
public:
    void createMapping(vector<int> inorder, map<int,int> &nodeToIdx, int n){
        for(int i=0; i<n; i++){
            nodeToIdx[inorder[i]]=i;
        }
    }
    
    TreeNode* solve(vector<int> inorder, vector<int> preorder, int &idx, int inorderSt, int inorderEd, int n, map<int,int> &nodeToIdx){
        //base case
        if(idx>=n or inorderSt>inorderEd){
            return NULL;
        }
        
        int element = preorder[idx++];
        TreeNode* root = new TreeNode(element);
        int pos = nodeToIdx[element];
        
        //recursive calls (Call for left and Right)
        root->left = solve(inorder,preorder,idx,inorderSt,pos-1,n,nodeToIdx);
        root->right = solve(inorder,preorder,idx,pos+1,inorderEd,n,nodeToIdx);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderidx =0;
        int n = inorder.size();
        map<int,int> nodeToIdx;
        
        //create node to idx mapping
        createMapping(inorder, nodeToIdx, n);
        TreeNode* ans = solve(inorder, preorder, preOrderidx, 0, n-1, n, nodeToIdx);
        return ans;
    }
};
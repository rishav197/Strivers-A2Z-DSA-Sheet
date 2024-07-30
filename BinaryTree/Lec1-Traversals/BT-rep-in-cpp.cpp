class Solution{
public:
    
    void buildTree(node* root, vector<int> &vec, int idx){
        //base case 
        if(root==NULL){
            return;
        }
        
        int n = vec.size();
        int lt_child = 2*idx+1;
        int rt_child = 2*idx+2;
        
        //create left
        if(lt_child<n){
            node* lnode = newNode(vec[lt_child]);
            root->left = lnode;
        }
        
        
        //create right
        if(rt_child<n){
            node* rnode = newNode(vec[rt_child]);
            root->right = rnode;
        }
        
        buildTree(root->left, vec, 2*idx+1);
        buildTree(root->right, vec, 2*idx+2);
        
    }
    
    void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
        buildTree(root0, vec, 0);
    }

};
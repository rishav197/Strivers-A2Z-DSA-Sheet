

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    
    queue<pair<Node*,int>> q;
    
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        pair<Node*,int> tmp = q.front();
        q.pop();
        
        Node* topNode = tmp.first;
        int lvl = tmp.second;
        
        if(lvl==ans.size()){ //check for entered into new level
            ans.push_back(topNode->data);
        }
        
        //call for left and right
        if(topNode->left){
            q.push(make_pair(topNode->left, lvl+1));
        }
        if(topNode->right){
            q.push(make_pair(topNode->right, lvl+1));
        }
        
    }
    
    return ans;
   
}
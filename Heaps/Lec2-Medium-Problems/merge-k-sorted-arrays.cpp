//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    class node{
    public:
        int data;
        int i;
        int j;
        
        node(int data, int row, int col){
            this->data = data;
            i=row;
            j=col;
        }
    };
    
    class compare{
        public:
        bool operator()(node* a, node* b){
            return a->data>b->data;
        }
    };
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<node*, vector<node*>, compare> minhp;
        
        //step1: stores all arrays' first element 
        for(int i=0; i<K; i++){
            node* temp = new node(arr[i][0], i, 0);
            minhp.push(temp);
        }
        
        vector<int> ans; 
        
        //step2: store all arrays' next element if they exist
        while(minhp.size()>0){
            node* temp = minhp.top();
            ans.push_back(temp->data);
            minhp.pop();
            
            int i=temp->i;
            int j=temp->j;
            
            if(j+1 < arr[i].size()){
                node* nextNode = new node(arr[i][j+1], i, j+1);
                minhp.push(nextNode);
            }
            
        }
        
        return ans;
        
    }
};
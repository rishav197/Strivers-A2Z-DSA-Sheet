/* tc - O(N), SC - O(1)
*/
class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        bool ans = true;
        
        //Just need to process the nodes till second last level
        for(int idx=0; idx<=n/2-1; idx++){
            // cout<<idx<<endl;   
            
            int ltidx = 2*idx+1;
            int rtidx = 2*idx+2;
            
            //check for left child
            if(ltidx<n and arr[ltidx]>arr[idx]){
                ans=false;
            }
            
            //check for right child
            if(rtidx<n and arr[rtidx]>arr[idx]){
                ans=false;
            }
        }
        
        return ans;
    }
};
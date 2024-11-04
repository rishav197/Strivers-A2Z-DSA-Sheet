//User function Template for C++

class Solution{
public:
    void heapify(vector<int> &arr, int n, int idx){
        int largest = idx;
        int ltIdx = 2*idx+1;
        int rtIdx = 2*idx+2;
        
        if(ltIdx<n and arr[ltIdx]>arr[largest]){
            largest = ltIdx;
        }
        
        if(rtIdx<n and arr[rtIdx]>arr[largest]){
            largest = rtIdx; 
        }
        
        if(largest!=idx){
            swap(arr[idx], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    
    void convertMinToMaxHeap(vector<int> &arr, int N){
        
        //non leaf nodes
        for(int i=N/2-1; i>=0; i--){
            heapify(arr, N, i);
        }
    }
    
};
class Solution {
public:

    bool isPalindrome(int x) {
        string num = to_string(x);
        // cout<<num<<endl;

        int n = num.size();
        int mid = n/2;

        bool ans = true;
        for(int i=0; i<=mid; i++){
            if(num[i]!=num[n-1-i]){
                ans = false;
                break;
            }
        }

        return ans;
    }
};


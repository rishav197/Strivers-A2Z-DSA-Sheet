#include<bits/stdc++.h>
using namespace std;

int getFunc(int n){     
        if(n==1 or n==2){
                return 1;
        }

        return getFunc(n-1) + getFunc(n-2);
}

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin>>n;

        vector<int> ans(n+1);
        for(int i=1; i<=n; i++){
                int fibo = getFunc(i);
                ans[i] = fibo;
        }

        cout<<ans[n];
}
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    
    long long int largestPrimeFactor(int N){
        // code here
        // vector<bool> prime(n+1,1);
        // prime[0] = 0, prime[1] = 0;
        
        // for(int i = 2;i*i<=n;i++){
        //     if(prime[i] == 1){
        //         for(int j = i*i;j<=n;j+=i){
        //             prime[j] = 0;
        //         }
        //     }
        // }
        
        // for(int i = sqrt(n);i>=1;i--){
        //     if(n%i==0){
        //         int f1 = n/i;
        //         int f2 = i;
        //         if(prime[f1] && prime[f2]){
        //             return f1>f2 ? f1 : f2;
        //         }
        //         if(prime[f1]) return f1;
        //         if(prime[f2]) return f2;
        //     }
        // }
        
        // return -1;
        
        long i = 2;
        while(i*i<=N){
            if(N%i == 0){
                N /= i;
            }
            else{
                i++;
            }
        }
        return N;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
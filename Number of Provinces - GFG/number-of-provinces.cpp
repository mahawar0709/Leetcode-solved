//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int i,int visited[],vector<int> ls[]){
        visited[i] = 1;
        for(auto it: ls[i]){
            if(!visited[it]){
                dfs(it,visited,ls);
            }
        }
        
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> ls[V+1];
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[0].size();j++){
                if(adj[i][j]){
                    ls[i+1].push_back(j+1);
                    ls[j+1].push_back(i+1);
                }
            }
        }
        int visited[V+1] = {0};
        int count = 0;
        
        for(int i=1;i<V+1;i++){
             if(!visited[i]){
                 count++;
                 dfs(i,visited,ls);
                 
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
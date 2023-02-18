//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         count[i][j] = grid[i][j];
        //     }
        // }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int f = source.first;
        int s = source.second;
        pq.push({f,{s,0}});
        dist[f][s]=0;
        int r[4]={0,-1,0,1};
        int c[4]={-1,0,1,0};
        while(!pq.empty()){
            int row = pq.top().first;
            int col = pq.top().second.first;
            int d = pq.top().second.second;
            
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow = row+r[i];
                int ncol = col+c[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                    if(dist[nrow][ncol] > d+1){
                        dist[nrow][ncol]= d+1;
                        pq.push({nrow,{ncol,d+1}});
                    }
                }
            }
        }
        if(dist[destination.first][destination.second] == 1e9){
            return -1;
        }
        return dist[destination.first][destination.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
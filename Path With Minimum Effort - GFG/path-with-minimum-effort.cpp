//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include<bits/stdc++.h>
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        int drow[4]={0,-1,0,1};
        int dcol[4]={-1,0,1,0};
        int diff = 0;
        dist[0][0] = 0;
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int diff = pq.top().first;
            pq.pop();
            if(row==n-1 && col==m-1){
              return diff;
            }
            
            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newdiff = max(abs(heights[row][col] - heights[nrow][ncol]),diff);
                    if(newdiff < dist[nrow][ncol]){
                         dist[nrow][ncol] = newdiff;
                        pq.push({ dist[nrow][ncol],{nrow,ncol}});
                    } 
                    
                }
            }
        }
        
        return 0;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> v(n,vector<int> (m,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    v[i][j]=2;
                    q.push({i,{j,0}});
                }
            }
        }
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        int maxCount = 0;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second.first;
            int count = q.front().second.second;
            maxCount = max(maxCount,count);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && v[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({nrow,{ncol,count+1}});
                    v[nrow][ncol] = 2;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && v[i][j]!=2){
                    return -1;
                }
            }
        }
        return maxCount;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
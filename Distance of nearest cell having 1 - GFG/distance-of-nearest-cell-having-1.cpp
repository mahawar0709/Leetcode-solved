//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> visited(n,vector<int>(m,0));
	    vector<vector<int>> distance(n,vector<int>(m,0));
	    
	    queue<pair<int,pair<int,int>>> q;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push({i,{j,0}});
	                visited[i][j] = 1;
	                distance[i][j] = 0;
	            }
	        }
	    }
	    int drow[4] = {-1,0,1,0};
	    int dcol[4] = {0,1,0,-1};
	    while(!q.empty()){
	        int row = q.front().first;
	        int col = q.front().second.first;
	        int count = q.front().second.second;
	        distance[row][col] = count;
	        q.pop();
	        for(int i=0;i<4;i++){
	            int nrow = row + drow[i];
	            int ncol = col + dcol[i];
	            
	            if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && !grid[nrow][ncol] && !visited[nrow][ncol]){
	                visited[nrow][ncol] = 1;
	                q.push({nrow,{ncol,count+1}});
	            }
	        }
	        
	    }
	    return distance;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
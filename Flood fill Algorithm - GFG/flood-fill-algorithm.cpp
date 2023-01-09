//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>>& image,int sr,int sc,int newColor,int initial,int row[],int col[],vector<vector<int>>& ans){
        ans[sr][sc]= newColor;
        for(int i=0;i<4;i++){
            int n = image.size();
            int m = image[0].size();
            int nrow = sr+row[i];
            int ncol = sc+col[i];
            if(nrow < n && nrow >=0 && ncol < m && ncol >= 0 && ans[nrow][ncol]!=newColor && image[nrow][ncol]==initial ){
                dfs(image,nrow,sc+col[i],newColor,initial,row,col,ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int initial = image[sr][sc];
        int row[4] = {0,-1,0,1};
        int col[4] = {-1,0,1,0};
        vector<vector<int>> ans = image;
      
        dfs(image,sr,sc,newColor,initial,row,col,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
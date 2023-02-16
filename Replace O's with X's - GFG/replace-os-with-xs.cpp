//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> res(n,vector<int> (m,0));
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            //first column
            if(mat[i][0]=='O'){
                q.push({i,0});
                res[i][0]=1;
                visited[i][0]=1;
            }
            //last column
            if(mat[i][m-1]=='O'){
                q.push({i,m-1});
                res[i][m-1]=1;
                visited[i][m-1]=1;
            }
        }
        
        for(int i=0;i<m;i++){
            //first row
            if(mat[0][i]=='O'){
                q.push({0,i});
                res[0][i]=1;
                visited[0][i]=1;
            }
            //last row
            if(mat[n-1][i]=='O'){
                q.push({n-1,i});
                res[n-1][i]=1;
                visited[n-1][i]=1;
            }
        }
        int drow[4]={0,-1,0,1};
        int dcol[4]={-1,0,1,0};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            res[row][col] = 1;
            visited[row][col] = 1;
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]=='O' && !visited[nrow][ncol]){
                    q.push({nrow,ncol});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(res[i][j]!=1){
                    mat[i][j]='X';
                }
            }
        }
        
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
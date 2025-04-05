//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void bfs(int row, int col,vector<vector<char>>&grid,vector<vector<int>>&vis) {
       vis[row][col]=1;
       queue<pair<int,int>>pq;
       pq.push({row,col});
       int n=grid.size();
       int m=grid[0].size();
       while(!pq.empty()) {
             int row=pq.front().first;
             int col=pq.front().second;
             pq.pop();
             for(int i=-1; i<=1; i++) {
                  for(int j=-1; j<=1; j++) {
                        int nRow=row+i;
                        int nCol=col+j;
 if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]=='L') {
                vis[nRow][nCol]=1;
               pq.push({nRow,nCol});

 }
                  }
             }
       }
  }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
           int n=grid.size();
           int m=grid[0].size();
           vector<vector<int>>vis(n,vector<int>(m,0));
           int cnt=0;
           for(int row=0; row<n; row++) {
                 for(int col=0; col<m; col++) {
                       if(grid[row][col]=='L' && !vis[row][col]) {
                             cnt++;
                             bfs(row,col,grid,vis);
                       }
                 }
           }
           return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
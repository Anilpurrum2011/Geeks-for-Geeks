//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>adj[V];
        vector<int>indegree(V, 0);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<int>q;
        
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }
        int cnt=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            
            for(auto &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        return cnt!=V;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends
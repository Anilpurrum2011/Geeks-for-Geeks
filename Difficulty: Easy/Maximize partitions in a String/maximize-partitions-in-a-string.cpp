//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        ap<int,int>m;
       for(auto &i:s)m[i]++;
       int ans=0,j=0;
       for(int i=0;i<s.size();i++){
           m[s[i]]--;
           while(j<=i&&m[s[j]]==0)j++;
           if(j==i+1){ans++;}
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<vector<long long>>> memo;

  long long dp(int index, bool buy, vector<int>& prices, int k) {
      if (index == prices.size() || k == 0) { 
          return 0;
      }
      
      if (memo[index][buy][k] != -1) {
          return memo[index][buy][k];
      }

      long long ans = dp(index + 1, buy, prices, k);

      if (buy) {
          ans = max(ans, -1LL * prices[index] + dp(index + 1, false, prices, k));
      } else {
          ans = max(ans, 1LL * prices[index] + dp(index + 1, true, prices, k - 1));
      }

      return memo[index][buy][k] = ans;
  }

  long long maxProfit(vector<int>& prices, int k) {
      int n = prices.size();
      memo.assign(n, vector<vector<long long>>(2, vector<long long>(k + 1, -1))); 
      return dp(0, true, prices, k);
  }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findExtra(vector<int>& a, vector<int>& b) {
        // add code here.
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;
        
        while(i < n && j < m){
            if(a[i] != b[j]){
                return i;
            }
            i++;
            j++;
        }
        return (i != n) ? n-1 : m-1;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr1, arr2;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr2.push_back(number1);
        }

        Solution ob;
        int ans = ob.findExtra(arr1, arr2);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
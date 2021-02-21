#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numDp(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    dp[i] = i == 1 ? 1 : dp[i - 2];
                } else
                    return 0;
            } else if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6' && s[i] >= '1') {
                dp[i] = i == 1 ? 1 + dp[i - 1] : dp[i - 2] + dp[i - 1];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n - 1];
    }
    // DFS 超时
    int numDfs(string s, int index) {
        int res = 0, res1 = -1, res2 = -1;
        int n = s.length();
        if (n == 0) return 0;
        if (index == n) return 1;
        int num = s[index] - '0';
        if (num) {
            res += numDfs(s, index + 1);
        }
        if (num && index < n - 1) {
            num = num * 10 + s[index + 1] - '0';
            if (num <= 26) {
                res += numDfs(s, index + 2);
            }
        }
        return res;
    }
    int numDecodings(string s) {
        return numDp(s);
        // return numDfs(s, 0);
    }
};

int main() {
    string s;
    Solution mySolution;
    while (cin >> s) {
        cout << mySolution.numDecodings(s) << endl;
    }
    return 0;
}
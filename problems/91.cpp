#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
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
        int res = numDfs(s, 0);
        if (res == -1) return 0;
        return res;
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
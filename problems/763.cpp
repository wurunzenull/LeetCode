#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> partitionLabels(string S) {
        int n = S.length();
        if (n == 1) return {1};
        vector<int> res;
        vector<int> cnt(26, 0);
        vector<bool> has(26, false);
        for (auto c : S) {
            cnt[c - 'a']++;
        }
        int left = 0, right = 0;
        int curNum = 0;
        while (right < n) {
            char x = S[right] - 'a';
            if (!has[x]) {
                has[x] = true;
                curNum++;
            }
            cnt[x]--;
            right++;
            if (cnt[x] == 0) {
                has[x] = false;
                curNum--;
            }
            if (curNum == 0) {
                res.push_back(right - left);
                // cout << S.substr(left, right - left) << endl;
                left = right;
            }
        }
        return res;
    }
};

int main() {
    string s;
    Solution mySolution;
    while (cin >> s) {
        vector<int> res = mySolution.partitionLabels(s);
        for (auto num : res) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
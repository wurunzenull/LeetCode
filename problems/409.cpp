#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestPalindrome(string s) {
        if (s.length() <= 1) return s.length();
        int lower[26] = {0};
        int upper[26] = {0};
        for (auto c : s) {
            if (c >= 'a' && c <= 'z')
                lower[c - 'a']++;
            else
                upper[c - 'A']++;
        }
        int res = 0;
        bool singleFlag = false;
        for (int i = 0; i < 26; i++) {
            if (lower[i] >= 2) res += (lower[i] / 2 * 2);
            if (upper[i] >= 2) res += (upper[i] / 2 * 2);
            if (lower[i] % 2) singleFlag = true;
            if (upper[i] % 2) singleFlag = true;
        }
        if (singleFlag) res++;
        return res;
    }
};

int main() {
    string s;
    Solution mySolution;
    while (cin >> s) {
        cout << mySolution.longestPalindrome(s) << endl;
    }
    return 0;
}
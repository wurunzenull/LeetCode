#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, len = s.length();
        bool hasChar[256] = {0};
        int left = 0, right = 0;
        for (; left <= right && left < len;) {
            while (left <= right && hasChar[s[right]]) {
                hasChar[s[left]] = false;
                left++;
            }
            while (right < len && !hasChar[s[right]]) {
                hasChar[s[right]] = true;
                right++;
            }
            res = max(res, right - left);
            if (right >= len || left + res >= len) break;
        }
        return max(res, right - left);
    }
};

int main() {
    string s;
    Solution mySolution;
    while (cin >> s) {
        cout << mySolution.lengthOfLongestSubstring(s) << endl;
    }
    return 0;
}
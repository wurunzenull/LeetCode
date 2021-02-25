#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        int sLen = s.length(), tLen = t.length();
        int minL = sLen, minR = 2 * sLen + 1;
        if (sLen < tLen) return "";
        int needTable[256] = {0};
        int needNum = 0;
        for (auto c : t) {
            if (!needTable[c]) needNum++;
            needTable[c]++;
        }
        int satisfyNum = 0;
        int satisfyTable[256] = {0};
        int left = 0, right = 0;
        for (; right < sLen;) {
            while (right < sLen && satisfyNum < needNum) {
                if (needTable[s[right]]) {
                    satisfyTable[s[right]]++;
                    if (satisfyTable[s[right]] == needTable[s[right]]) satisfyNum++;
                }
                right++;
            }
            while (left < sLen && satisfyNum == needNum) {
                if (right - left < minR - minL) {
                    minR = right;
                    minL = left;
                }
                if (needTable[s[left]]) {
                    satisfyTable[s[left]]--;
                    if (satisfyTable[s[left]] + 1 == needTable[s[left]]) satisfyNum--;
                }
                left++;
            }
        }
        return s.substr(minL, minR - minL);
    }
};

int main() {
    string s, t;
    Solution mySolution;
    while (cin >> s >> t) {
        cout << mySolution.minWindow(s, t) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        int needTable[26] = {0};
        for (auto c : p) {
            needTable[c - 'a']++;
        }
        int freqTable[26] = {0};
        int left = 0, right = 0;
        vector<int> res;
        for (; right < sLen;) {
            if (!needTable[s[right] - 'a']) {
                left = ++right;
                for (auto c : p) {
                    freqTable[c - 'a'] = 0;
                }
                continue;
            }
            while (left < right && freqTable[s[right] - 'a'] == needTable[s[right] - 'a']) {
                freqTable[s[left] - 'a']--;
                left++;
            }
            freqTable[s[right] - 'a']++;
            right++;
            if (right - left == pLen) {
                assert(freqTable[s[left] - 'a'] == needTable[s[left] - 'a']);
                res.push_back(left);
                freqTable[s[left] - 'a']--;
                left++;
            }
        }
        return res;
    }
};

int main() {
    string s, p;
    Solution mySolution;
    while (cin >> s >> p) {
        vector<int> res = mySolution.findAnagrams(s, p);
        for (auto num : res) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
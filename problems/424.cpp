#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int res = 0, len = s.length();
        int left = 0, right = 0;
        int maxCount = 0;
        for (; right < len;) {
            freq[s[right] - 'A']++;
            maxCount = max(maxCount, freq[s[right] - 'A']);
            right++;
            if (right - left > maxCount + k) {
                freq[s[left] - 'A']--;
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};

int main() {
    string s;
    int k;
    Solution mySolution;
    while (cin >> s >> k) {
        cout << mySolution.characterReplacement(s, k) << endl;
    }
    return 0;
}
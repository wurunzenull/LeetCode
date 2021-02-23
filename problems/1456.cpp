#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxVowels(string s, int k) {
        if (k <= 0 || s.length() == 0) return 0;
        int len = s.length();
        vector<int> preSum(len + 1, 0);
        int vowels[26] = {0};
        vowels['a' - 'a'] = 1;
        vowels['e' - 'a'] = 1;
        vowels['i' - 'a'] = 1;
        vowels['o' - 'a'] = 1;
        vowels['u' - 'a'] = 1;
        for (int i = 1; i <= len; i++) {
            preSum[i] = preSum[i - 1] + vowels[s[i - 1] - 'a'];
        }
        int maxCount = INT32_MIN;
        for (int i = 0; i <= len - k; i++) {
            maxCount = max(maxCount, preSum[i + k] - preSum[i]);
        }
        return maxCount;
    }
};

int main() {
    string s;
    int k;
    Solution mySolution;
    while (cin >> s >> k) {
        cout << mySolution.maxVowels(s, k) << endl;
    }
    return 0;
}
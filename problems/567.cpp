#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) return false;
        vector<int> cnt(26, 0);
        int diff = 0;
        for (int i = 0; i < n; i++) {
            cnt[s1[i] - 'a']--;
            cnt[s2[i] - 'a']++;
        }
        for (int num : cnt) {
            if (num != 0) diff++;
        }
        if (diff == 0) return true;
        for (int i = n; i < m; i++) {
            char x = s2[i - n], y = s2[i];
            if (x != y) {
                cnt[x - 'a']--;
                if (cnt[x - 'a'] == 0)
                    diff--;
                else if (cnt[x - 'a'] == -1)
                    diff++;
                cnt[y - 'a']++;
                if (cnt[y - 'a'] == 0)
                    diff--;
                else if (cnt[y - 'a'] == 1)
                    diff++;
                if (diff == 0) return true;
            }
        }
        return false;
    }
    bool checkInclusion2(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) return false;
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; i++) {
            cnt[s1[i] - 'a']--;
        }
        int left = 0, right = 0;
        for (; right < m;) {
            cnt[s2[right] - 'a']++;
            right++;
            while (cnt[s2[right - 1] - 'a'] > 0) {
                cnt[s2[left] - 'a']--;
                left++;
            }
            if (right - left == n) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    string s1, s2;
    Solution mySolution;
    while (cin >> s1 >> s2) {
        cout << setiosflags(ios::boolalpha) << mySolution.checkInclusion2(s1, s2) << endl;
    }
    return 0;
}
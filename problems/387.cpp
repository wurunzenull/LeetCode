#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for (auto c : s) {
            count[c - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};

int main() {
    string s;
    Solution mySolution;
    while (cin >> s) {
        cout << mySolution.firstUniqChar(s) << endl;
    }
    return 0;
}
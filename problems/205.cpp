#include <bits/stdc++.h>

#include <iomanip>
using namespace std;

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashTable;
        unordered_map<char, char> reverseTable;
        int n = s.length(), m = t.length();
        if (m != n) return false;
        for (int i = 0; i < n; i++) {
            char ori = s[i], dst = t[i];
            if (hashTable.find(ori) != hashTable.end()) {
                if (hashTable[ori] != dst) return false;
            } else {
                if (reverseTable.find(dst) != reverseTable.end()) return false;
                hashTable[ori] = dst;
                reverseTable[dst] = ori;
            }
        }
        return true;
    }
};

int main() {
    string s, t;
    Solution mySolution;
    while (cin >> s >> t) {
        cout << setiosflags(ios::boolalpha) << mySolution.isIsomorphic(s, t) << endl;
    }
    return 0;
}
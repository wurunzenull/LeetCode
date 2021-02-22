#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool judgeVowel(char c) {
        if (c >= 'A' && c <= 'Z') {
            c = c + 'a' - 'A';
        }
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
    }
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        for (; i < j;) {
            while (i < j && !judgeVowel(s[i])) i++;
            while (i < j && !judgeVowel(s[j])) j--;
            if (i >= j)
                break;
            else {
                char tem = s[i];
                s[i] = s[j];
                s[j] = tem;
                i++, j--;
            }
        }
        return s;
    }
};

int main() {
    string s;
    Solution mySolution;
    while (cin >> s) {
        cout << mySolution.reverseVowels(s) << endl;
    }
    return 0;
}
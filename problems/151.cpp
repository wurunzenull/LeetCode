#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void reverseToDst(string &s, int index, string swap) {
        int len = swap.length();
        for (int i = 0; i < len; i++) {
            s[index + i] = swap[len - 1 - i];
        }
    }
    void reverse(string &s, int len) {
        for (int i = 0; i < len / 2; i++) {
            char c = s[i];
            s[i] = s[len - 1 - i];
            s[len - 1 - i] = c;
        }
    }
    string reverseWords(string s) {
        int n = s.length();
        int index = 0;
        string swap = "";
        for (auto c : s) {
            if (c == ' ') {
                if (swap.length() == 0)
                    continue;
                else {
                    if (index) s[index++] = ' ';
                    reverseToDst(s, index, swap);
                    index += swap.length();
                    swap = "";
                }
            } else {
                swap.push_back(c);
            }
        }

        if (swap.length()) {
            if (index) s[index++] = ' ';
            reverseToDst(s, index, swap);
            index += swap.length();
        }

        reverse(s, index);
        return s.substr(0, index);
    }
};

int main() {
    string s;
    Solution mySolution;
    while (getline(cin, s)) {
        cout << mySolution.reverseWords(s) << endl;
    }
    return 0;
}
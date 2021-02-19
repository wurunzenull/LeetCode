#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int romanToInt(string s) {
        int length = s.length();
        int res = 0;
        int state = 0;
        unordered_map<char, int> hashTable{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                           {'C', 100}, {'D', 500}, {'M', 1000}};
        unordered_set<char> tranSet{'I', 'X', 'C'};
        for (int i = 0; i < length; i++) {
            switch (state) {
                case 0:
                    if (tranSet.find(s[i]) != tranSet.end())
                        state = hashTable[s[i]];
                    else
                        res += hashTable[s[i]];
                    break;
                case 1:
                    if (s[i] == 'X' || s[i] == 'V') {
                        res += hashTable[s[i]] - state;
                        state = 0;
                    } else if (tranSet.find(s[i]) != tranSet.end()) {
                        res += state;
                        state = hashTable[s[i]];
                    } else {
                        res += (state + hashTable[s[i]]);
                        state = 0;
                    }
                    break;
                case 10:
                    if (s[i] == 'L' || s[i] == 'C') {
                        res += hashTable[s[i]] - state;
                        state = 0;
                    } else if (tranSet.find(s[i]) != tranSet.end()) {
                        res += state;
                        state = hashTable[s[i]];
                    } else {
                        res += (state + hashTable[s[i]]);
                        state = 0;
                    }
                    break;
                case 100:
                    if (s[i] == 'D' || s[i] == 'M') {
                        res += hashTable[s[i]] - state;
                        state = 0;
                    } else if (tranSet.find(s[i]) != tranSet.end()) {
                        res += state;
                        state = hashTable[s[i]];
                    } else {
                        res += (state + hashTable[s[i]]);
                        state = 0;
                    }
                    break;
            }
        }
        res += state;
        return res;
    }
};

int main() {
    string s;
    while (cin >> s) {
        Solution mySolution;
        cout << mySolution.romanToInt(s) << endl;
    }
    return 0;
}
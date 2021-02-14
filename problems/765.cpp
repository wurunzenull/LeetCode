#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void swap(vector<int> &nums,int a,int b)
    {
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
    //贪心算法，每次只交换最近的一对情侣
    int minSwapsCouples(vector<int> &row)
    {
        int swapCount = 0;
        vector<int> pos(row.size());
        for(int i=0;i<row.size();i++) {
            pos[row[i]] = i;
        }
        for(int i=0;i<row.size()-1;i+=2) {
            int a = row[i];
            int b = a^0x1;
            if(row[i+1]!=b) {
                int ori=row[i+1];
                swap(row,i+1,pos[b]);
                pos[ori] = pos[b];
                pos[b] = i+1;
                swapCount++;
            }
        }
        return swapCount;
    }
};

vector<int> readArrays()
{
    vector<int> nums;
    string input;
    getline(cin, input);
    istringstream in(input);
    int num;
    while (in >> num)
    {
        nums.push_back(num);
    }
    in.clear();
    return nums;
}

int main()
{
    vector<int> row = readArrays();
    Solution mySolution;
    cout << mySolution.minSwapsCouples(row) << endl;
    return 0;
}
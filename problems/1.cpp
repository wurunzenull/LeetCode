#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = hashtable.find(target-nums.at(i));
            if (it != hashtable.end())
            {
                return {(*it).second,i};
            }
            hashtable[nums.at(i)]=i;
        }
        return {};
    }
};
int main()
{
    vector<int> nums;
    int target;
    string input;
    getline(cin, input);
    istringstream in(input);
    int num;
    while (in >> num)
        nums.push_back(num);
    cin >> target;
    in.clear();
    //for(auto num:nums){
    //    cout<<num<<" ";
    //}
    //cout<<endl<<target<<endl;

    Solution mySolution;
    vector<int> result;
    result = mySolution.twoSum(nums, target);
    for (auto num : result)
    {
        cout << num << " ";
    }
    return 0;
}

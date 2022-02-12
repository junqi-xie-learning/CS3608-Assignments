#include "../leetcode.h"

int lengthOfLIS(vector<int> &nums)
{
    vector<int> tails;
    for (int i : nums)
    {
        auto tail = lower_bound(tails.begin(), tails.end(), i);
        if (tail == tails.end())
            tails.push_back(i);
        else
            *tail = i;
    }
    return tails.size();
}

int main()
{
    vector<int> nums;
    cin >> nums;
    cout << lengthOfLIS(nums) << endl;
    return 0;
}

#include "../leetcode.h"

int findTargetSumWays(vector<int> &nums, int target)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > sum)
        return 0;
    for (int &i : nums)
        i *= 2;
    target = abs(sum + target);

    vector<int> prev, current(target + 1);
    current[0] = 1;
    for (int i = 0; i < nums.size(); ++i)
    {
        prev = current;
        current.clear();
        for (int w = 0; w <= target; ++w)
        {
            if (nums[i] > w)
                current.push_back(prev[w]);
            else
                current.push_back(prev[w] + prev[w - nums[i]]);
        }
    }
    return current[target];
}

int main()
{
    vector<int> nums;
    int target = 0;
    cin >> nums >> target;
    cout << findTargetSumWays(nums, target) << endl;
    return 0;
}

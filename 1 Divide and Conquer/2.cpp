#include "../leetcode.h"

int merge(vector<int> &nums, int begin, int end)
{
    int count = 0;
    vector<int> temp;
    temp.reserve(end - begin);

    int mid = (begin + end) / 2, l = begin, r = mid;
    while (l < mid)
    {
        while (r < end && nums[l] > 2L * nums[r])
            ++r;
        count += r - mid;
        ++l;
    }

    l = begin, r = mid;
    while (l < mid && r < end)
    {
        if (nums[l] < nums[r])
            temp.push_back(nums[l++]);
        else
            temp.push_back(nums[r++]);
    }
    while (l < mid)
        temp.push_back(nums[l++]);
    copy(temp.begin(), temp.end(), nums.begin() + begin);
    return count;
}

int reversePairs(vector<int> &nums, int begin, int end)
{
    if (end - begin < 2)
        return 0;

    int count = 0;
    int mid = (begin + end) / 2;
    count += reversePairs(nums, begin, mid);
    count += reversePairs(nums, mid, end);
    count += merge(nums, begin, end);
    return count;
}

int reversePairs(vector<int> &nums)
{
    return reversePairs(nums, 0, nums.size());
}

int main()
{
    vector<int> nums;
    cin >> nums;
    cout << reversePairs(nums) << endl;
    return 0;
}

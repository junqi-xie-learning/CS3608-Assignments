#include "../leetcode.h"

int partition(vector<int> &nums, int begin, int end)
{
    static default_random_engine random;
    int pivot = uniform_int_distribution{begin, end - 1}(random);
    swap(nums[begin], nums[pivot]);

    int i = begin + 1, j = begin + 1;
    while (i < end)
    {
        if (nums[i] < nums[begin])
        {
            swap(nums[i], nums[j]);
            ++j;
        }
        ++i;
    }
    swap(nums[begin], nums[j - 1]);
    return j - 1;
}

int findKthLargest(vector<int> &nums, int begin, int end, int k)
{
    int mid = partition(nums, begin, end);
    if (end - mid == k)
        return nums[mid];
    else if (end - mid > k)
        return findKthLargest(nums, mid + 1, end, k);
    else
        return findKthLargest(nums, begin, mid, k - (end - mid));
}

int findKthLargest(vector<int> &nums, int k)
{
    return findKthLargest(nums, 0, nums.size(), k);
}

int main()
{
    vector<int> nums;
    int k = 0;
    cin >> nums >> k;
    cout << findKthLargest(nums, k) << endl;
    return 0;
}

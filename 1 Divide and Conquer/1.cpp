#include "../leetcode.h"

void merge(vector<int> &nums, int begin, int end)
{
    vector<int> temp;
    temp.reserve(end - begin);

    int mid = (begin + end) / 2, l = begin, r = mid;
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
}

void mergeSort(vector<int> &nums, int begin, int end)
{
    if (end - begin < 2)
        return;

    int mid = (begin + end) / 2;
    mergeSort(nums, begin, mid);
    mergeSort(nums, mid, end);
    merge(nums, begin, end);
}

vector<int> sortArray(vector<int> &nums)
{
    mergeSort(nums, 0, nums.size());
    return nums;
}

int main()
{
    vector<int> nums;
    cin >> nums;
    cout << sortArray(nums) << endl;
    return 0;
}

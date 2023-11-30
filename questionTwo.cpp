#include <iostream>
#include <vector>

using namespace std;

vector<int> findErrorNums(vector<int> &nums)
{
    vector<int> result(2);

    int n = nums.size();

    // Find the duplicate
    for (int i = 0; i < n; ++i)
    {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0)
        {
            result[0] = abs(nums[i]);
        }
        else
        {
            nums[index] = -nums[index];
        }
    }

    // Find the missing number
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] > 0)
        {
            result[1] = i + 1;
            break;
        }
    }

    return result;
}

int main()
{
    vector<int> nums1 = {1, 2, 2, 4};
    vector<int> result1 = findErrorNums(nums1);
    cout << "Output for nums1: [" << result1[0] << ", " << result1[1] << "]" << endl;

    vector<int> nums2 = {1, 1};
    vector<int> result2 = findErrorNums(nums2);
    cout << "Output for nums2: [" << result2[0] << ", " << result2[1] << "]" << endl;

    return 0;
}

/*
output : - Output for nums1: [2, 3]
Output for nums2: [1, 2]
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;

    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        int index = abs(nums[i]) - 1;

        if (nums[index] < 0) {
            result.push_back(index + 1);
        } else {
            nums[index] = -nums[index];
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result1 = findDuplicates(nums1);
    cout << "Output for nums1: [";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << "]" << endl;

    vector<int> nums2 = {1, 1, 2};
    vector<int> result2 = findDuplicates(nums2);
    cout << "Output for nums2: [";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << "]" << endl;

    return 0;
}


/*
Output for nums1: [2 3 ]
Output for nums2: [1 ]
*/
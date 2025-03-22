#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Pointers for nums1, nums2, and the merged array
    int i = m - 1;  // Pointer for the last element in nums1's valid part
    int j = n - 1;  // Pointer for the last element in nums2
    int k = m + n - 1;  // Pointer for the last position in nums1

    // Merge the arrays starting from the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // If there are remaining elements in nums2, copy them
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }

    // No need to check for remaining elements in nums1, they are already in place
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3;  // The number of elements in nums1
    int n = 3;  // The number of elements in nums2

    merge(nums1, m, nums2, n);

    // Output the merged array
    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
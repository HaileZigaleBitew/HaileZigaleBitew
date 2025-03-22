#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map; // map to store the element and its index
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // Check if complement is already in the map
        if (map.find(complement) != map.end()) {
            // Found the solution, return the indices
            result.push_back(map[complement]);
            result.push_back(i);
            return result;
        }
        
        // If not found, store the current element and its index in the map
        map[nums[i]] = i;
    }

    return result; // This line will never be reached because there's always exactly one solution
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    cout << "Indices of the two numbers that add up to " << target << " are: ";
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}


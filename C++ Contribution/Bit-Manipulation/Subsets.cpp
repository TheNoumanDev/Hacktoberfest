class Solution {
public:
    void subsetsum(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        subsetsum(index + 1, nums, subset, result);
        subset.pop_back();
        subsetsum(index + 1, nums, subset, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> result;
        subsetsum(0, nums, subset, result);
        return result;
    }
};

class Solution {
  int findNextGretest(vector<int> &nums, int targetIndex) {
    reverse(nums.begin()+targetIndex+1, nums.end());
    auto it = upper_bound(nums.begin()+targetIndex+1, nums.end(), nums[targetIndex]);
    if (it == nums.end()) {
      return -1;
    }
    return it - nums.begin();
  }
public:
  void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    while(i>=0 && nums[i] >= nums[i+1]) {
      i--;
    }
    if (i < 0) {
      reverse(nums.begin(), nums.end());
      return;
    }
    int nextGreatestIndex = findNextGretest(nums, i);
    swap(nums[i], nums[nextGreatestIndex]);
    sort(nums.begin() + i + 1, nums.end());
  }
};
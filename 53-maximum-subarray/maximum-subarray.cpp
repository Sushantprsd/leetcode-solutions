class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int ans = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (currentSum + nums[i] < nums[i]) {
        currentSum = 0;
      }
      currentSum += nums[i];
      ans = max(ans, currentSum);
    }

    return ans;
  }
};
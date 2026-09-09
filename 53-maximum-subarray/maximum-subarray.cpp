class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int ans = INT_MIN;
    int currentSum = 0;

    for (int num: nums) {
      if (num > currentSum + num) {
        currentSum = 0;
      }
      currentSum += num;
      ans = max(ans, currentSum); 
    }

    return ans;
  }
};
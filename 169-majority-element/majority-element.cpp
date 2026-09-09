class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int currentMaxElement = nums[0];
    int currentMaxElementCount = 1;

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != currentMaxElement) {
        currentMaxElementCount--;
      } else {
        currentMaxElementCount++;
      }
      if (currentMaxElementCount == 0) {
        currentMaxElement = nums[i];
        currentMaxElementCount = 1;
      }
    }
    return currentMaxElement;
  }
};
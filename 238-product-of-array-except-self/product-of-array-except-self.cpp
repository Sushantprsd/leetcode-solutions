class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int zeroCount = 0;
    int product = 1;

    for (auto num: nums) {
      if (num == 0) zeroCount++;
      else product *= num;
      
      if (zeroCount > 1) {
        product = 0;
        break;
      }
    }
    vector<int> ans(nums.size(), 0);
    if (product == 0) return ans;
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] == 0) {
        ans[i] = product;
      } else {
        if (zeroCount) {
          ans[i] = 0;
        } else {
          ans[i] = product/nums[i];
        }
      }
    }
    return ans;
  }
};
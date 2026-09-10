class Solution {
public:
  void sortColors(vector<int>& nums) {
    int e0 = 0;
    int e1 = 0;
    int e2 = nums.size() - 1;

    while (e0 <= e2) {
      if (nums[e0] == 2) {
        swap(nums[e0], nums[e2]);
        e2--;
      } else if (nums[e0] == 0) {
        swap(nums[e1], nums[e0]);
        e1++;
        e0++;
      } else {
        e0++;
      }
    }
  }
};
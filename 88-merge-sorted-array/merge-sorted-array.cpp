class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int currentPos = nums1.size() - 1;
    int e1 = m - 1;
    int e2 = n - 1;
    while (e2 >= 0) {
      if (e1 >= 0 && nums1[e1] >= nums2[e2]) {
        nums1[currentPos--] = nums1[e1--];
      } else {
        nums1[currentPos--] = nums2[e2--];
      }
    }
  }
};

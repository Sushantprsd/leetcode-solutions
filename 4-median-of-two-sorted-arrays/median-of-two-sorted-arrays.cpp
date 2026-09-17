class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n2 < n1) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int low = 0;
    int high = n1;
    int midPos = (n1 + n2 + 1) / 2;
    while (low <= high) {
      int mid1 = (low + high) / 2;
      int mid2 = midPos - mid1;

      int l1 = mid1 - 1 < 0 ? INT_MIN : nums1[mid1-1];
      int r1 = mid1 >= nums1.size() ? INT_MAX: nums1[mid1];

      int l2 = mid2 - 1 < 0 ? INT_MIN: nums2[mid2-1];
      int r2 = mid2 >= nums2.size() ?  INT_MAX: nums2[mid2];

      if (l1 > r2) {
        high = mid1 - 1;
      } else if (l2 > r1) {
        low = mid1 + 1;
      } else {
        if ((n1+n2)%2 == 0) {
          return double((max(l1, l2) + min(r1,r2))/ 2.0);
        } else {
          return max(l1, l2);
        }
      }
    }
    return 0;

  }
};
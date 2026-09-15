class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int sum = 0;
    int ans = 0;

    unordered_map<int, int> hashMap;
    hashMap.insert({0, 1}); 

    for (auto num: nums) {
      sum += num;
      if (hashMap.find(sum - k) != hashMap.end()) {
        ans += hashMap[sum - k];
      }
      if (hashMap.find(sum) == hashMap.end()) {
        hashMap.insert({sum , 1});
      } else {
        hashMap[sum]++;
      }
      
    }
    return ans;
  }
};


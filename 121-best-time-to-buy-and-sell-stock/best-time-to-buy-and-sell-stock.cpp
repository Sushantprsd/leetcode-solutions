class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    int buyPrice = prices[0];
    for (int price: prices) {
      int currentProfit = price - buyPrice;
      ans = max(ans, currentProfit);
      if (price < buyPrice) {
        buyPrice = price;
      }
    }
    return ans;
  }
};
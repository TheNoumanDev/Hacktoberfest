/**********************************
QUESTION: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
***********************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), r = 0, t = 0;
    if(n == 0) 
        return 0;
    vector<int> mini(n), maxi(n);
    mini[0] = prices[0];
    for(int i = 1; i < n; i++) 
        mini[i] = min(mini[i-1], prices[i]);
    maxi[n-1] = prices[n-1];
    for(int i = n - 2; i >= 0; i--)
        maxi[i] = max(maxi[i+1], prices[i]);
    for(int i = 0; i < n; i++)
    {
        t = max(t, prices[i] - mini[i]);
        r = max(r, t + maxi[i] - prices[i]);
    }
    return r;
    }
};

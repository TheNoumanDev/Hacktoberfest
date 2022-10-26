/****************************************************************************************************************
QUESTION: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
APPROACH: for every (i+1)th term greater than ith day price we see a profit. (*if only one day data given no profit or loss can happen) 
 ****************************************************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), sum = 0;
        if(n==1)
            return 0;
        for(int i =0; i<n-1; i++)
        {
           if(prices[i]<prices[i+1])
            {
                sum  = sum + prices[i+1] - prices[i];
            }
        }
        return sum;
    }
};

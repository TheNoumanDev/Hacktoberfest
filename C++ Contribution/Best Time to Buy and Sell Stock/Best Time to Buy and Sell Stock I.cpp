/*********************************************************************************************
QUESTION: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/        
APPROACH: If next element is smaller than the current element we upgrade the current element with the next one else we store the difeerence of Next and current and 
          store and go on checking till we get maximum difference satisfying all conditions.         
**********************************************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size(), d = 0;
        if(n==1)
            return 0;
         int current = prices[0];
        for(int i = 1; i< n;i++)
        {
            if( prices[i]-current > d)
            {
                d = prices[i]-current;
            }
            else if(current>prices[i])
                current = prices[i];
        }
        return d;
    }
};

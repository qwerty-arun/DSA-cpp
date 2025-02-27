// Imagine each day as selling day
#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
  std::vector<int> prices= {7,2,5,3,9,4};
  int maxProfit{};
  int bestBuy = prices[0];
  for(int i=1;i<prices.size();i++)
  {
    if(prices[i]>bestBuy)
    {
      maxProfit = std::max(maxProfit,prices[i]-bestBuy);
    }
    bestBuy = std::min(bestBuy,prices[i]);
  }
  std::cout<<"Max Profit: "<<maxProfit<<'\n';
  return 0;
}

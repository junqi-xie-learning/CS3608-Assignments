#include "../leetcode.h"

int maxProfit(vector<int> &prices, int fee)
{
    int current = numeric_limits<int>::max(), profit = 0;
    for (int price : prices)
    {
        if (price < current)
            current = price;
        else if (price > current + fee)
        {
            profit += price - current - fee;
            current = price - fee;
        }
    }
    return profit;
}

int main()
{
    vector<int> prices;
    int fee = 0;
    cin >> prices >> fee;
    cout << maxProfit(prices, fee) << endl;
    return 0;
}

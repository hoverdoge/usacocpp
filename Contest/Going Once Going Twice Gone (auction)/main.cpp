#include <iostream>

using namespace std;

int main() {
    int max_revenue = 0, best_price = 0;
    int amt_hay, amt_farmers;
    cin >> amt_hay; cin >> amt_farmers;

    int prices [amt_farmers];
    int max_price = 0;
    for (int i = 0; i < amt_farmers; i++)
    {
        cin >> prices[i];
        if (prices[i] > max_price) {max_price = prices[i];}
    }

    // basically just test for price of highest to lowest, compare against max revenue
    for (int price_tested = max_price; price_tested > 0; price_tested--)
    {
        int loop_max_revenue = 0;
        int amt_prices = 0;
        for (int i = 0; i < amt_farmers; i++) // get how many prices are at or above tested price
        {
            if (prices[i] >= price_tested)
            {
                amt_prices++;
            }
        }

        if (amt_prices > amt_hay)
        {
            amt_prices = amt_hay;
        }

        loop_max_revenue = amt_prices * price_tested;

        if (loop_max_revenue > max_revenue)
        {
            max_revenue = loop_max_revenue; best_price = price_tested;
        }

    }

    cout << best_price << " " << max_revenue;

}

/*
5 4
2
8
10
7

 */
#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
struct Item {
    int profit;
    int weight;
};
bool compareItems(const Item& item1, const Item& item2) {
    double ratio1 = (double)item1.profit / item1.weight;
    double ratio2 = (double)item2.profit / item2.weight;
    return ratio1 > ratio2;
}
double fractionalKnapsack(int W, const vector<Item>& items) {
    double totalProfit = 0.0;
    int remainingCapacity = W;
    sort(items.begin(), items.end(), compareItems);
    for (const Item& item : items) {
        if (remainingCapacity >= item.weight) {
            totalProfit += item.profit;
            remainingCapacity -= item.weight;
        } else {
            double fraction = (double)remainingCapacity / item.weight;
            totalProfit += item.profit * fraction;
            break;
        }
    }
    return totalProfit;
}
int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<Item> items(n);
    cout << "Enter the profit and weight of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].profit >> items[i].weight;
    }
    int W;
    cout << "Enter the knapsack capacity: ";
    cin >> W;
    double maxProfit = fractionalKnapsack(W, items);
    cout << "Maximum total profit: " << maxProfit << endl;
    return 0;
}

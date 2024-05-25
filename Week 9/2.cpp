/*
    Q-02 Given a knapsack of maximum capacity w. N items are provided, each having its own value and
weight. You have to Design an algorithm and implement it using a program to find the list of the
selected items such that the final selected content has weight w and has maximum value. You can
take fractions of items,i.e. the items can be broken into smaller pieces so that you have to carry
only a fraction xi of item i, where 0 ≤xi≤ 1.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    double weight;
    double value;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

pair<double, vector<pair<double, double>>> fractional_knapsack(int n, vector<double>& weights, vector<double>& values, double capacity) {
    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        items[i] = {weights[i], values[i], values[i] / weights[i]};
    }
    sort(items.begin(), items.end(), compare);

    double total_value = 0.0;
    vector<pair<double, double>> knapsack_contents;

    for (const auto& item : items) {
        if (capacity > 0) {
            if (item.weight <= capacity) {
                total_value += item.value;
                capacity -= item.weight;
                knapsack_contents.push_back({item.weight, 1.0});
            } else {
                double fraction = capacity / item.weight;
                total_value += item.value * fraction;
                knapsack_contents.push_back({item.weight, fraction});
                break;
            }
        } else {
            break;
        }
    }

    return {total_value, knapsack_contents};
}

int main() {
    int n;
    cout<<"Enter Size :";
    cin >> n;
    vector<double> weights(n);
    vector<double> values(n);
    double capacity;
    cout<<"Enter Weights :";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    cout<<"Enter Values :";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    cout<<"Enter Capacity :";
    cin >> capacity;

    auto result = fractional_knapsack(n, weights, values, capacity);

    cout << "Maximum value that can be achieved: " << result.first << endl;
    cout << "List of items selected with their fraction:" << endl;

    for (const auto& item : result.second) {
        cout << "Weight: " << item.first << ", Fraction: " << item.second << endl;
    }

    return 0;
}


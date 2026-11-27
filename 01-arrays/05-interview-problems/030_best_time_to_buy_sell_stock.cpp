/*
 * 030 - Best time to buy and sell stock (one transaction)
 * Type: IMPLEMENTATION EXERCISE (starter template - implement it yourself)
 *
 * Problem: prices[i] is the price on day i. Choose ONE day to buy and a LATER day to sell. Return the maximum profit, or 0 if no profit is possible.
 * Constraints: 0 <= n <= 10^5; 0 <= prices[i] <= 10^4.
 * Examples:
 *   {7, 1, 5, 3, 6, 4} -> 5 (buy at 1, sell at 6)
 *   {7, 6, 4, 3, 1} -> 0
 *
 * Target complexity: time O(n), auxiliary space O(1)
 * Your task: replace the TODO below. Run the file; every FAIL line is a case you missed.
 * Think about the edge cases listed in the tests BEFORE you write code.
 *
 * Compile & run:
 *   g++ -std=c++17 -Wall -Wextra -Wpedantic 030_best_time_to_buy_sell_stock.cpp -o 030_best_time_to_buy_sell_stock
 *   ./030_best_time_to_buy_sell_stock      (Windows PowerShell: .\030_best_time_to_buy_sell_stock.exe)
 */
#include <iostream>
#include <string>
#include <vector>

// Brute force is O(n^2) pairs. Can you answer "best profit if I sell today" in O(1) per day?
int maxProfit(const std::vector<int>& prices) {
    (void)prices;  // delete once you use `prices`
    // TODO: your implementation
    return -1;
}

// ---- test helper (no need to modify) ----
int failures = 0;
void check(bool condition, const std::string& label) {
    if (!condition) {
        std::cout << "FAIL: " << label << '\n';
        ++failures;
    }
}

int main() {
    check(maxProfit({7, 1, 5, 3, 6, 4}) == 5, "classic");
    check(maxProfit({7, 6, 4, 3, 1}) == 0, "strictly decreasing");
    check(maxProfit({}) == 0, "empty");
    check(maxProfit({5}) == 0, "single day");
    check(maxProfit({2, 2, 2}) == 0, "all identical");
    check(maxProfit({1, 2}) == 1, "two days");
    check(maxProfit({3, 3, 5, 0, 0, 3, 1, 4}) == 4, "lowest price comes after an earlier peak");
    check(maxProfit({1, 2, 3, 4, 5}) == 4, "increasing");

    if (failures == 0) std::cout << "All tests passed.\n";
    return failures == 0 ? 0 : 1;
}

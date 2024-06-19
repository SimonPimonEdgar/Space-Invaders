#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

#include <vector>
#include <algorithm>
#include <iostream>

int closestLowerSum(const std::vector<int>& nums, int target) {
    // Initialize a DP array of size target + 1, filled with false.
    // dp[i] will be 'true' if there is a subset of nums[] with sum equal to i, otherwise 'false'.
    std::vector<bool> dp(target+1, false);
    dp[0] = true;  // There is always a subset with sum 0 in any array, which is the empty subset.

    // 2D vector to store the actual numbers that form the sum i
    std::vector<std::vector<int>> nums_used(target+1);

    // For each number in nums
    for(const auto& num: nums) {
        // For each possible sum (starting from target down to num)
        for(int i = target; i >= num; --i) {
            // If dp[i - num] is true and dp[i] is false, then set dp[i] to true
            // because it means we can form the sum 'i' by including 'num'.
            // Also store the numbers that form the sum i in nums_used[i]
            if (!dp[i] && dp[i - num]) {
                dp[i] = true;
                nums_used[i] = nums_used[i - num]; // copy the numbers that form the sum (i - num)
                nums_used[i].push_back(num); // include 'num' in the numbers that form the sum 'i'
            }
        }
    }

    // Iterate from target to 0
    for(int i = target; i >= 0; --i) {
        // If there is a subset with sum 'i', print the numbers and return 'i'
        if(dp[i]) {
            std::cout << "Numbers used: ";
            for(const auto& num : nums_used[i]) {
                std::cout << num << " ";
            }
            std::cout << "\n";
            return i;
        }
    }

    // If no sum is possible, print "No numbers used." and return 0
    std::cout << "No numbers used.\n";
    return 0;
}


BOOST_AUTO_TEST_SUITE(ClosestLowerSumTest)

/*
 * Aufgabe: Einsetzen von Unit Tests. Dazu sollte wieder eine 
 *   BOOST_AUTO_TEST_CASE( testcases ) { ... } eingefuehrt werden
 * und darin verschiedene Tests ueber
 *   BOOST_TEST( ... );
 * oder ueber BOOST_CHECK_EQUAL(function, 20); - Test: return of function == 20?
 * durchgefuehrt werden.
 */

BOOST_AUTO_TEST_SUITE_END()

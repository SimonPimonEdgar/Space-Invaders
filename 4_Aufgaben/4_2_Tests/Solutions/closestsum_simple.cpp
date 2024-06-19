#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

#include <vector>
#include <algorithm>
#include <iostream>

/*
A simpler, yet more inefficient way to approach this problem is 
to generate all possible subsets of the input array and keep track
of the maximum sum that does not exceed the target. 
This approach is simpler in terms of understanding, 
but it's less efficient since generating all subsets of a set 
takes O(2^n) time where n is the size of the set.
*/

void findSubsets(int index, std::vector<int>& ds, int& ans, std::vector<int>& best, const std::vector<int>& nums, int target) {
    int sum = std::accumulate(ds.begin(), ds.end(), 0);
    if (sum <= target) {
        if(sum > ans) {
            ans = sum;
            best = ds;
        }
        if(ans == target) // If we reach the target, no need to continue as this is the best possible solution
            return;
    }
    
    // Do not continue if sum is already larger than target or if we have used all numbers
    if(sum >= target || index == nums.size()) 
        return;
    
    // Include current number and proceed to the next
    ds.push_back(nums[index]);
    findSubsets(index + 1, ds, ans, best, nums, target);
    
    // Exclude current number and proceed to the next
    ds.pop_back();
    findSubsets(index + 1, ds, ans, best, nums, target);
}

int closestLowerSum(const std::vector<int>& nums, int target) {
    std::vector<int> ds; // ds will hold current subset of numbers
    std::vector<int> best; // best will hold the best subset of numbers
    int ans = 0;
    findSubsets(0, ds, ans, best, nums, target);
    
    // Print out the numbers used
    std::cout << "Numbers used: ";
    for (const auto& num : best) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    
    return ans;
}

BOOST_AUTO_TEST_SUITE(ClosestLowerSumTest)

BOOST_AUTO_TEST_CASE(TestCases)
{
    std::vector<int> testVector = {2, 5, 6, 7, 10};
    BOOST_TEST(closestLowerSum(testVector, 9) == 9); 
    BOOST_CHECK_EQUAL(closestLowerSum(testVector, 20), 20); 
    BOOST_CHECK_EQUAL(closestLowerSum(testVector, 6), 6); 
    BOOST_CHECK_EQUAL(closestLowerSum(testVector, 0), 0); 
    std::vector<int> emptyVector = {};
    BOOST_CHECK_EQUAL(closestLowerSum(emptyVector, 10), 0); 
}

BOOST_AUTO_TEST_SUITE_END()

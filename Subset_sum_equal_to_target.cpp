/*
DP

Subset sum equal to target

Difficulty: MediumAccuracy: 32.0%Submissions: 433K+Points: 4
Given an array of positive integers arr[] and a value sum, determine 
if there is a subset of arr[] with sum equal to given sum. 

Eg 01:
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

Eg 02:
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.

Eg 03:
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
*/

class Solution {
  public:
    bool helper(vector<int>& arr, int target, int idx){
        // base cases
        if(target == 0) return true;
        if(idx >= arr.size()) return false;
        
        // include
        if(arr[idx] <= target){
            if(helper(arr, target - arr[idx], idx+1)){
                return true;
            }
        }
        // exclude
        if(helper(arr, target, idx+1)){
            return true;
        }
        return false;
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        bool ispossible = helper(arr, target, 0);
        return ispossible;
    }
};
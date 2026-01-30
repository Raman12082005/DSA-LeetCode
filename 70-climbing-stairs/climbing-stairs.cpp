class Solution {
public:
    int climbStairs(int n) {
        // base cases
        if(n == 1 || n == 2) return n;

        vector<int> stair(n+1);
        stair[1] = 1;
        stair[2] = 2;

        int steps = 3;
        while(steps <= n){
            stair[steps] = stair[steps-1] + stair[steps-2];
            steps++;
        }
        return stair[n];
    }
};
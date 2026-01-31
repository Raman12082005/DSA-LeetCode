/*
DP

Geek's Training

Difficulty: MediumAccuracy: 49.98%Submissions: 144K+Points: 4Average Time: 20m
Geek is going for a training program for n days. He can perform any of these 
activities: Running, Fighting, and Learning Practice. Each activity has some 
point on each day. As Geek wants to improve all his skills, he can't do the same 
activity on two consecutive days. Given a 2D matrix mat[][], where mat[i][0], 
mat[i][1], and mat[i][2] represent the merit points for Running, Fighting, and 
Learning on the i-th day, determine the maximum total merit points Geek can 
achieve .

Eg 01:
Input: mat[][]= [[1, 2, 5],
               [3, 1, 1], 
               [3, 3, 3]]
Output: 11
Explanation: Geek will learn a new move and earn 5 point then on second day he 
will do running and earn 3 point and on third day he will do fighting and earn 
3 points so, maximum merit point will be 11.

Eg 02:
Input: mat[][]= [[1, 1, 1],
               [2, 2, 2],
               [3, 3, 3]]
Output: 6
Explanation: Geek can perform any activity each day while adhering to the 
constraints, in order to maximize his total merit points as 6.

Eg 03:
Input: mat[][]= [[4, 2, 6]]
Output: 6
Explanation: Geek will learn a new move to make his merit points as 6.
*/

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> prev(m+1, 0);
        prev[0] = max(mat[0][1], mat[0][2]);
        prev[1] = max(mat[0][0], mat[0][2]);
        prev[2] = max(mat[0][0], mat[0][1]);
        prev[3] = max(mat[0][0], max(mat[0][1], mat[0][2]));
        
        for(int days=1; days<n; days++){
            vector<int> temp(m+1, 0);
            
            for(int last = 0; last <= 3; last++){
               temp[last] = 0;
                
                for(int task = 0; task <3; task++){
                   if(task != last){
                      temp[last] = max(temp[last], mat[days][task] + prev[task]);
                   }
                }
                
            }
            prev = temp;
        }
        
        return prev[3];
    }
};

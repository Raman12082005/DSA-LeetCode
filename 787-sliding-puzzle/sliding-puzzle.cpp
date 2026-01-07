class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                start += to_string(board[i][j]);
            }
        }
        string target = "123450";
        // base cases
        if(target == start) return 0;

        vector<vector<int>> neighbour{
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };

        queue<string> q;
        unordered_map<string, bool> visited;
        q.push(start);
        visited[start] = true;

        int moves = 0;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                string curr = q.front();
                q.pop();

                // check for ans
                if(curr == target) return moves;

                int zeroIndex = curr.find('0');

                for(auto neigh : neighbour[zeroIndex]){
                    string next = curr;
                    swap(next[zeroIndex], next[neigh]);

                    if(!visited[next]){
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
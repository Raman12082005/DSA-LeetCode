class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // base cases
        if(n == 1) return 1;
        if(trust.size() == 0) return -1;

        vector<int> comein(n+1, 0);
        for(int i=0; i<trust.size(); i++){
            vector<int> vec = trust[i];
            comein[vec[1]]++;
        }
        int judge = max_element(comein.begin(), comein.end()) - comein.begin();
        if(comein[judge] != n-1) return -1;

        for(int i=0; i<trust.size(); i++){
            if(trust[i][0] == judge){
                return -1;
            }
        }
        return judge;
    }
};
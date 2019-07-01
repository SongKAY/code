class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(answers.empty())
            return 0;
        vector<int> s;
        map<int,int> m;
        for(auto a:answers){
            m[a]+=1;
            if(m[a]==1){
                s.push_back(a);
            }
        }
        sort(s.begin(),s.end());
        int cnt = 0;
        for(auto a:s){
            if(m[a]<=a+1){
                cnt += a+1;
            }
            else{
                int k = m[a] / (a+1);
                int left = m[a] % (a+1);
                cnt += k*(a+1);
                if(left)
                    cnt += (a+1);
            }
        }
        return cnt;
    }
};

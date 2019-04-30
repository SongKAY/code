class Solution {
public:
    bool judgeCircle(string moves) {
        int u = 0;
        int d = 0;
        int l = 0;
        int r = 0;
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='U')
                u++;
            if(moves[i]=='D')
                d++;
            if(moves[i]=='L')
                l++;
            if(moves[i]=='R')
                r++;
        }
        if(u!=d)
            return false;
        if(l!=r)
            return false;
        return true;
    }
};

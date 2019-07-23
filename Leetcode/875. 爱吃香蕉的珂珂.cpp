class Solution {
public:
    bool valid(int k,vector<int>piles,int H){
        int cnt = 0;
        for(auto i:piles){
            cnt += i/k;
            cnt += i%k?1:0;
            if(cnt>H)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        if(piles.empty())
            return 0;
        sort(piles.begin(),piles.end());
        int l = 1;
        int r = piles[piles.size()-1];
        while(l<=r){
            int mid = l + (r-l)/2;
            if(valid(mid,piles,H))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};

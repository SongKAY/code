class Solution {
public:
    int reachNumber(int target) {
        if(target<0)
            target = -target;
        if(target==0)
            return 0;
        for(int i=1;;i++){
            int s = (1+i)*i/2;
            if(s>=target&&(s - target)%2==0)
                return i;
        }
        return 0;
    }
};

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        temp.push_back(c);
        sort(temp.begin(),temp.end());
        vector<int> result(2,0);
        if(temp[2]-temp[1]==1&&temp[1]-temp[0]==1)
            return result;
        result[1] = temp[2] - temp[1] + temp[1] - temp[0] - 2;
        if(temp[2]-temp[1]==2||temp[2]-temp[1]==1||temp[1]-temp[0]==2||temp[1]-temp[0]==1)
            result[0] = 1;
        else
            result[0] = 2;
        return result;
    }
};

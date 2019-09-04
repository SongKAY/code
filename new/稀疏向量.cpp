

struct Node{
    int index;
    int value;
};
 
int func(Node[] v1, Node[] v2){
    int p1 = 0, p2 = 0;
    int ret = 0;
    int len1 = sizeof(v1) / sizeof(Node);
    int len2 = sizeof(v2) / sizeof(Node)；
    while(p1<len1 && p2<len2){
        int index1 = v1[p1].index, index2 = v2[p2].index;
        if(index1 == index2){
            ret += v1[p1].value * v2[p2].value;
            p1++;
            p2++;
        }else if (index1 < index2){
            p1++;
        }else{
            p2++;
        }
    }
    return ret;
}

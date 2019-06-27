class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        result = []
        dic = {}
        dic[C] = []
        for idx, i in enumerate(S):
            if i == C:
                dic[C].append(idx)
        for idx, i in enumerate(S):
            if i == C:
                result.append(0)
            else:
                temp = dic[C]
                temp.append(idx)
                temp.sort()
                num = temp.index(idx)
                left = 10010
                right = 10010
                if num + 1 < len(temp):
                    right = temp[num+1] - temp[num]
                if num - 1 >= 0 :
                    left = temp[num] - temp[num-1]
                result.append(min(right,left))
                temp.remove(idx)
        return result

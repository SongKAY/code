class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        s = str.split(' ')
        d = {}
        flag = {}
        if len(pattern) != len(s):
            return False
        for idx, i in enumerate(pattern):
            if i not in d.keys():
                if s[idx] in flag.keys():
                    return False
                else:
                    d[i] = s[idx]
                    flag[s[idx]] = 1
                    continue
            if s[idx] != d[i]:
                return False
        return True

class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        if str1 not in str2 and str2 not in str1:
            return ""
        else:
            result = ""
            temp = str1
            if len(str1) > len(str2):
                temp = str2
            i = 1
            while(i<=len(temp)):
                flag = 0
                minstr = temp[:i]
                if len(str1) % len(minstr)!=0 or len(str2) % len(minstr)!=0:
                    i += 1
                    continue
                j = 0
                while j+len(minstr) <= len(str1):
                    s = str1[j:j+len(minstr)]
                    if s == minstr:
                        j += len(minstr)
                    else:
                        flag = 1
                        break
                j = 0 
                while j+len(minstr) <=  len(str2):
                    s = str2[j:j+len(minstr)]
                    if s == minstr:
                        j+= len(minstr)
                    else:
                        flag = 1
                        break
                if flag == 0:
                    result = minstr
                i += 1
            return result
                
        

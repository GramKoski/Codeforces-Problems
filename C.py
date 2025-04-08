

while True:
    try:
        s = input()
        u = set()
        for e in s:
            u.add(e)

        res = 0
        found = set()
        c = {}
        curr = 0
        g = len(u)
        r = 0 
        if s == "":
            break
        for l in range(len(s)):
            if l > 0:
                c[s[l-1]] -= 1
                if (c[s[l-1]] == 0):
                    curr -= 1
                    if curr == g-1 and s[l:r] not in found and s[l:r] != s[1:]:
                        res += 1
                        found.add(s[l:r])
            while (curr < g and r < len(s)):
                
                if s[r] not in c:
                    c[s[r]] = 1
                else:
                    c[s[r]] += 1
                if s[r] in u and c[s[r]] == 1:
                    curr += 1
                r += 1
            #print(l, r, curr, s[l:r], flush = True)

            
 
                
        print(res, flush = True)
    except Exception as e:
        print(e)
        break
            

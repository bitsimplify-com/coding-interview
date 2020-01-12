def simplify(A):
    st = []
    dir = ""
    res = ""
    res += "/"
    len_A = len(A)
    i = 0
    while i < len_A:
        dir_str = ""
        while (i < len_A and A[i] == '/'):
            i += 1
        while (i < len_A and A[i] != '/'):
            dir_str += A[i]
            i += 1
        if dir_str == "..":
            if len(st):
                st.pop()
        elif dir_str == '.':
            continue
        elif len(dir_str) > 0:
            st.append(dir_str)
        i += 1

    st1 = []
    while len(st):
        st1.append(st[-1])
        st.pop()

    while len(st1):
        temp = st1[-1]

        if (len(st1) != 1):
            res += (temp + "/")
        else:
            res += temp
        st1.pop()

    return res


string=input()
res = simplify(string)
print(res)

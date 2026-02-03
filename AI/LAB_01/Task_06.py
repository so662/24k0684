str = input("Enter a string: ")
max_len = 1
temp_len = 1
lsstr = str[0]
for i in range(1, len(str)):
    if str[i] == str[i - 1] :
        temp_len += 1
    else:
        if temp_len >= max_len:
            max_len = temp_len
            lsstr = str[i - 1] * temp_len
        temp_len = 1
if temp_len >= max_len:
            max_len = temp_len
            lsstr = str[i - 1] * temp_len

print("Longest substring of consecutive identical characters:", lsstr)
print("Length of the longest substring:", max_len)


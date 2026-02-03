def find_duplicates(x):
    z = [0] * len(x)
    for i in range(0, len(x)):
        y = x[i]
        for j in range(0, len(x)):
            if y == x[j]:
                z[i] += 1
    
    duplicates = []
    for i in range(0, len(x)):
        if z[i] > 1 and x[i] not in duplicates:
            duplicates.append(x[i])
    
    return duplicates
numbers = [0] * 10
for i in range(0, 10):
    numbers[i] = (int(input("Enter number" + str(i) + ": ")))
    
result = find_duplicates(numbers)
for num in result:
    print("Number", num, "is repeated more than once.")
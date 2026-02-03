name = input("Enter your name: ")
def xyz(n):
    no_of_characters = len(n)
    no_of_uppercase = 0
    no_of_lowercase = 0
    no_of_digits = 0
    for i in range(no_of_characters):
        if n[i].isupper():
            no_of_uppercase += 1
        elif n[i].islower():
            no_of_lowercase += 1
        elif n[i].isdigit():
            no_of_digits += 1
    data = {
        "Name": name,
        "Number of characters": no_of_characters,
        "Number of uppercase letters": no_of_uppercase,
        "Number of lowercase letters": no_of_lowercase,
        "Number of digits": no_of_digits
    }
    return data
d = xyz(name)

print(d)
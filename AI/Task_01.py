
username = input("Enter your username: ")
password = input("Enter your password: ")
age = int(input("Enter your age: "))
users = {
    "username": username,
    "password": password,
    "age": age
}
if age < 13:
    print("Access denied: You must be at least 13 years old.")
else:
    print("Access granted: Welcome,", username + "!") 
    print("User name : ", username)
    print("User age : ", age)
    print("User password : ", password) 

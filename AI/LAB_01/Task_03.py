n = int(input("How many numbers do you want to enter? "))
numbers = [0] * n

for i in range(n):
    numbers[i] = int(input(f"Enter number{i+1}: "))


print("\nAll numbers in the list:")
for num in numbers:
    print(num)


even_count = 0
odd_count = 0

for num in numbers:
    if num % 2 == 0:
        even_count += 1
    else:
        odd_count += 1

print(f"\nTotal even numbers: {even_count}")
print(f"Total odd numbers: {odd_count}")


if len(numbers) > 0:
    print(f"Current list: {numbers}")
    
    print(f"Valid indexes: 0 to {len(numbers)-1}")
    
    index = int(input("Enter the index you want to replace: "))
    
    if 0 <= index < len(numbers):
        numbers[index] = int(input(f"Enter new value for index {index}: "))
        print(f"Updated list: {numbers}")
    else:
        print("Invalid index! No changes made.")
else:
    print("List is empty, cannot replace any element.")
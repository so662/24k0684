Name = Soofiyan Imran
Roll NUmber = k24-0684
Section = C
Date = September 19 2024
Description = Asking the input from user checking if the last digit of numbers are 90 and removing zero of 90 by multiplying it one less than its place if its at hundreth place it will be multiplied by and added to the previous total and if not 

Psedocode
START
INPUT n,
sum = 1, total = 0
WHILE n > 0
    IF n%100 = 90 
        total = total + 9 * sum
        n = n/100 // removing last two digits
    ELSE 
        last_digit = n%10
        total = total + last_ digit * sum
        n = n/10
    sum = sum * 10
END WHILE
END

![WhatsApp Image 2024-09-18 at 4 37 45 PM (1)](https://github.com/user-attachments/assets/eda31851-4b36-45be-9f6c-32471930a5be)


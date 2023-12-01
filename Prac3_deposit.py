def deposit(num):
    global balance
    balance = balance + num

def withdrawal(num):
    global balance
    if balance >= num:  # Allowing withdrawal even if the balance is zero
        balance = balance - num
    else:
        print("Insufficient funds for withdrawal.")

lst = []
balance = 0

while True:
    data = input("Enter the amount (Type 'Q' to quit): ")
    if data == 'Q':
        break
    lst.append(data.split())

for i in lst:
    if len(i) != 2 or not i[1].isdigit():  # Check if input format is valid
        print("Invalid input format:", i)
        continue

    if i[0] == 'D':
        deposit(int(i[1]))
    elif i[0] == 'W':
        withdrawal(int(i[1]))

print("The final balance is:", balance)

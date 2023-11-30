def deposit(num):
    global balance
    balance = balance + num

def withdrawal(num):
    global balance
    if balance > 0:
        balance = balance - num
    else:
        print("You cannot withdraw because the balance is less.")

lst = []
balance = 0

while True:
    data = input("Enter the amount (Type 'Q' to quit): ")
    if data == 'Q':
        break
    lst.append(data.split())

for i in lst:
    if i[0] == 'D':
        deposit(int(i[1]))
    elif i[0] == 'W':
        withdrawal(int(i[1]))

print("The final balance is:", balance)

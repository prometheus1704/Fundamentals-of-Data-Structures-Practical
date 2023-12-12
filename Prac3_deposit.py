def deposit(num):
    global balance
    balance +=num


def withdrawal(num):
    global balance 

    if balance>=num:
        balance-=num
    else:
        print("Not enough balance")
        

lst=[]
balance=0

while True:
    print("Enter")
    data=input()
    if data=='Q':
        break


    lst=data.split()

    if lst[0]=='D':
        deposit(int(lst[1]))

    elif lst[0]=='W':
        withdrawal(int(lst[1]))

print(balance)

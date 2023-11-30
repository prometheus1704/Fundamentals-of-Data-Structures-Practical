def deposit(num):
    global balance
    balance=balance+num
def withdrawal(num):
    global balance
    if(balance>0):
        balance=balance-num
    else:
        print("You cannot Withdraw because the Balance is Less")

lst=[]
balance=0
while True:
    data=input("Enter the Amount...")
    if(data=='Q'):
        break
    lst.append(data.split())
for i in lst:
    if(i[0]=='D'):
        deposit(int(i[1]))
    elif(i[0]=='W'):
        withdrawal(int(i[1]))


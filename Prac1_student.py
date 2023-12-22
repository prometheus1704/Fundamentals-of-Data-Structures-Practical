def rmvd(lst):
    lst3=[]
    for i in lst:
        if i not in lst3:
            lst3.append(i)
    return lst3

def uni(lst1,lst2):
    lst3=[]
    for i in lst1:
        lst3.append(i)
    for i in lst2:
        if i not in lst3:
            lst3.append(i)
    return lst3

def inter(lst1,lst2):
    lst3=[]
    for i in lst1:
        if i in lst2:
            lst3.append(i)
    return lst3


def dif(lst1,lst2):
    lst3=[]
    for i in lst1:
        if i not in lst2:
            lst3.append(i)

    return lst3

def symdif(lst1,lst2):
    lst3=[]
    j=dif(lst1,lst2)
    k=dif(lst2,lst1)
    lst3=uni(j,k)
    return lst3


stu=[]
n=int(input("Enter no.of std:"))
for i in range(n):
    ele=input()
    stu.append(ele)

cric=[]
c=int(input("no.of cric std:"))
for i in range(c):
    ele=input()
    cric.append(ele)

foot = []
f = int(input("no.of foot std:"))
for i in range(f):
    ele = input()
    foot.append(ele)

badm = []
f = int(input("no.of badm std:"))
for i in range(f):
    ele = input()
    badm.append(ele)

print(stu)
print("The list of stud by removing duplicate:  ",rmvd(stu))
print(cric)
print("The list of cric by removing duplicate:  ",rmvd(cric))
print(foot)
print("The list of foot by removing duplicate:  ",rmvd(foot))
print(badm)
print("The list of badm by removing duplicate:  ",rmvd(badm))

flag=1
while(flag==1):

    print("********Menu***********")

    print("1.stud play both cric and badm")
    print("2.stud play either cric or badm not both")
    print("3.stud play neither cric nor badm")
    print("4.stud play  cric and foot but not badm")
    print("5.Exit")

    print()
    a=int(input("Enter choice: "))
    if(a==1):
        print("1. stud play both cric and bad: ")
        v = inter(cric, badm)
        print(v)
        w=int(input("Want to continue hit 1:"))
        if(w==1):
            flag=1
        else:
            flag=0

    elif (a == 2):
        print("2. stud play either cric or badm but not both: ")
        g = dif(uni(cric, badm), inter(cric, badm))
        print(g)
        w = int(input("Want to continue hit 1:"))
        if (w == 1):
            flag = 1
        else:
            flag = 0

    elif (a == 3):
        print("3. stud play no cric no badm: ")
        h = dif(stu, uni(cric, badm))
        print(h)
        w = int(input("Want to continue hit 1:"))
        if (w == 1):
            flag = 1
        else:
            flag = 0

    elif (a == 4):
        print("4. stud play cric and foot but no bad: ")
        j = dif(inter(cric, foot), badm)
        print(j)
        w = int(input("Want to continue hit 1:"))
        if (w == 1):
            flag = 1
        else:
            flag = 0


    elif (a == 5):
        print("Thank you!")
        break

if(flag==0):
    print("Thanks")



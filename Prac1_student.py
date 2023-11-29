def removeduplicate(d):
    lst = []
    for i in d:
        if i not in lst:
            lst.append(i)
    return lst


def intersection(lst1,lst2):
    lst3 = [ ]
    for i in lst1:
        if i in lst2:
            lst3.append(i)
    return lst3

def union(lst1,lst2):
    lst3 =[]
    for i in lst1:
        lst3.append(i)
        for i in lst2:
            if i not in lst1:
                lst3.append(i)
    return lst3

def difference(lst1,lst2):
    lst3 = []
    for  i in lst1:
        if i not in lst2:
            lst3.append(i)
    return lst3

# def bCnF(lst1,lst2):
#     lst3 =[]
#     lst3 =intersection(lst1, lst2)
#     print("The list of students who play both Cricket and Football are:",lst3)
#     return  lst3

def bCnB(lst1,lst2):
    lst3=[]
    lst3= intersection(lst1, lst2)
    print("The list of students who play both Cricket and Badminton are:", lst3)
    return lst3













#############################################################

SECOMP = [ ]
n = int(input("Enter the number of students in SECOMP:  "))
print("Enter the names of ",n,"students : ")

for i in range (0, n):
    ele = input()
    SECOMP.append(ele)
print("Original list of students ",(SECOMP))

#############################################################

Cricket = [ ]
c = int(input("\nEnter the number of students who plays Cricket:  "))
print("\nEnter the names of ",c,"students : ")

for i in range (0, c):
    ele = input()
    Cricket.append(ele)

print("Original list of students who plays Cricket: ",(Cricket))

Cricket = removeduplicate(Cricket)
print("\nThe list of students after removing duplicates is:", Cricket)

#############################################################

Football = [ ]
f = int(input("\nEnter the number of students who plays Football:  "))
print("\nEnter the names of ",f,"students : ")

for i in range (0, f):
    ele = input()
    Football.append(ele)
print("\nOriginal list of students who plays Football: ",(Football))

Football = removeduplicate(Football)
print("The list of students after removing duplicates is:", Football)

#############################################################

Badminton = [ ]
f = int(input("\nEnter the number of students who plays Badminton:  "))
print("\nEnter the names of ",f,"students : ")

for i in range (0, f):
    ele = input()
    Badminton.append(ele)
print("\nOriginal list of students who plays Badminton: ",(Badminton))

Badminton = removeduplicate(Badminton)
print("The list of students after removing duplicates is:\n", Badminton)


x =difference(union(Cricket, Badminton), intersection(Cricket, Badminton))
y =difference(SECOMP,union(Cricket,Badminton))



# MENU

flag = 1
while flag ==1:
    print("---------------------------------------------MENU------------------------------------------")
    print("1.List of students who play both Cricket and Badminton ")
    print("2.List of students who play either Cricket or Badminton but not both")
    print("3.List of students who play neither Cricket nor Badminton")
    print("4.List of students who play Cricket and Football but not Badminton")


    op=int(input("Enter your choice: "))
    if(op == 1):
        print("The list of students who play both Cricket and Badminton is",bCnB(Cricket,Badminton) )
        a = input("Do you want to continue(yes/no:)")
        if (a =='yes'):
            flag = 1
        else:
            flag = 0

    elif(op == 2):
        print("List of students who play Cricket or Badminton but not both",x)
        a = input("Do you want to continue(yes/no:)")
        if (a =='yes'):
            flag = 1
        else:
            flag = 0

    # elif (op == 3):
    #     print("List of students who play neither Cricket nor Badminton"),
    #     a = input("Do you want to continue(yes/no:)")
    #     if (a =='yes'):
    #         flag = 1
    #     else:
    #         flag = 0
    #
    # elif(op==4):
    #     print("List of students who play Cricket and Football but not Badminton"),
    #     a = input("Do you want to continue(yes/no:)")
    #     if (a == 'yes'):
    #         flag = 1
    #     else:
    #         flag = 0

    # elif(op == 5):
    #     print("Thank You!")
    #     break

if (flag == 0):
    print("Thank you!")

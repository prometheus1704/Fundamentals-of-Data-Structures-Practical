 #Function for removing absent students
def remvduplicate(d):
    lst = []
    for i in d:
        if i !='ab':
            lst.append(i)
    return lst

# Function for average marks
def average(lst):
    total = 0
    for i in lst:
        total = total+int(i)
    return (total/len(lst))

# Function for absent students
def absent(lst):
    count =0
    for i in lst:
        if i=='ab':
            count+=1
    return count

# Function to find max and min
def maximum(lst):
    max = int(lst[0])
    for i in lst:
        if(max<int(i)):
            max=int(i)
    return max

def minimum(lst):
    min = int(lst[0])
    for i in lst:
        if(min>int(i)):
            min = int(i)
    return  min


# Function to find frequency

def freq(lst):
    count =0
    max = maximum(lst)
    for i in lst:
        if (max==int(i)):
            count+=1
    return count


secomp = []

n = int(input("Enter no. of students:  "))
print("Enter the marks of students: ")
for i in range(0, n):
    ele = input()
    secomp.append(ele)

print("The list of students marks is : ", secomp)
y=remvduplicate(secomp)
print("The list of students marks after removing absent students is : ", y)

# --------------------  Menu ---------------------------------------

flag =1
while flag == 1:
    print("---------------------------------------MENU----------------------------------------------------")
    print("1.The average score of students in class")
    print("2.The highest and lowest marks in a class of secomp")
    print("3.The number of absent students in secomp")
    print("4.The frequency of highest marks in secomp")
    print("5.EXIT")



    ch = int(input("Enter your choice : "))

    if (ch==1):
        print("The average score of students in class: ",average(y))
        print("Do you want to continue(yes/no): ")
        a = input().lower()
        if (a =='yes'):
            flag =1
        else:
            flag = 0

    elif(ch==2):
        print("The highest marks in a class is: ",maximum(y))
        print("The lowest marks in a class is: ",minimum(y))

        print("Do you want to continue(yes/no): ")
        a = input().lower()
        if (a == 'yes'):
            flag = 1
        else:
            flag = 0

    elif(ch==3):
        print("The number of absent students in class: ",absent(secomp))
        print("Do you want to continue(yes/no): ")
        a = input().lower()
        if (a == 'yes'):
            flag = 1
        else:
            flag = 0

    elif(ch==4):
        print("The frequency of highest marks in secomp: ",freq(y))
        print("Do you want to continue(yes/no): ")
        a = input().lower()
        if (a == 'yes'):
            flag = 1
        else:
            flag = 0

    elif(ch==5):
        print("Thank You")
        break


if(flag==0):
    print("Thank You")

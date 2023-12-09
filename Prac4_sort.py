def bubble_sort(list1,n):
    for i in range(n-1):
        for j in range(n-i-1):
            if(list1[j]>list1[j+1]):
                temp=list1[j]
                list1[j]=list1[j+1]
                list1[j+1]=temp
    print("The mark list by bubble sorted Method is:")
    print(list1)
    
def selection_sort(list1,n):
    sel_list=[]
    for i in range(n):
        list1_idx=i
        for j in range(i+1,n):
            if(list1[list1_idx]>list1[j]):
                #list1_idx=j this is not required 
                (list1[list1_idx],list1[j])=(list1[j],list1[list1_idx])
                 
    for j in range(n):
        sel_list.append(list1[j])
    print("The list by selection algorithim is: ")
    print(sel_list)
    
def top_5(list1,n):
    list1.sort()
    list1.reverse()
    print("The top marks obtain by student are:")
    print(list1[:5])


n=int(input("Enter the number of student:"))
marks_list=[]
for i in range(n):
    ele=int(input())
    marks_list.append(ele)
print("The marks of student is:")
print(marks_list)

flag=1
while flag==1:
    print("-----------MENU------------")
    print("1:Bubble sorting")
    print("2:Selection sorting")
    print("3:top 5 student")
    print("4:Exit")
    choice=int(input("Enter your choice:"))
    if(choice==1):
        bubble_sort(marks_list,n)
    elif(choice==2):
        selection_sort(marks_list,n)
    elif(choice==3):
        top_5(marks_list,n)
    elif(choice==4):
        print("Thank you")
        break
    else:
        print("Incorrect choice")
        

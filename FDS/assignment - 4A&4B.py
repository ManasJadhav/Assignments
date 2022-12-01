# storing all roll numbers in list.


def all_student(x):
    for i in range(x):
        roll_no = int(input("Enter the roll_number: "))
        list_of_students.append(roll_no)


def linear_search(x):
    linearsearch_list = list_of_students
    print("* * * LINEAR SEARCH * * *")
    for i in linearsearch_list:
        if x == i:
            print("Roll Number ", x, " exist")
            print(" ")
            break
    else:
        print("Not Found")
        print(" ")


def sentinel_linear_search(x):
    sentilineal_list = list_of_students
    sentilineal_list.append(x)
    last_number = len(sentilineal_list) - 1
    print("* * * SENTINEL LINEAR SEARCH * * *")
    i = 0
    while i < last_number:
        if sentilineal_list[i] == x:
            print("Roll Number ", x, " exist")
            print(" ")
            break
        else:
            i += 1
    else:
        print("Not Found")
        print(" ")


def binary_search(x):
    print("* * * BINARY SEARCH * * *")
    binary_list = list_of_students
    binary_list.sort()
    lower_bound = 0
    upper_bound = len(binary_list)-1
    while lower_bound <= upper_bound:
        midpoint = (upper_bound + lower_bound)//2

        if binary_list[midpoint] < x:
            lower_bound = midpoint + 1
        elif binary_list[midpoint] > x:
            upper_bound = midpoint - 1
        else:
            return 0
    return -1


def fib_search(searchele):
    fib_list = list_of_students
    fib_list.sort()
    length = len(fib_list)
    print("* * * FIBONACCI SEARCH * * *")

    start = -1
    x0 = 0
    x1 = 1
    x2 = 1
    while x2 < length:
        x0 = x1
        x1 = x2
        x2 = x1+x0
    while x2 > 1:
        eleindex = min(start + x0, length-1)
        if fib_list[eleindex] < searchele:
            x2, x1 = x1, x0
            x0 = x2-x1
            start = eleindex
        elif fib_list[eleindex] > searchele:
            x2 = x0
            x1 = x1 - x0
            x0 = x2 - x1
        else:
            return 0
    if x1 and (fib_list[length-1] == searchele):
        return 0
    return -1

    # def fibo(self,n):
    #     if(n < 0):
    #         return 0
    #     elif(n == 1):
    #         return 1
    #     else: 
    #         return self.fibo(n-1) + self.fibo(n-2)
        
        
    # '''Searching'''
    # def fibonacciSearch(self,Element):
    #     tempArr = self.sortedArr.copy()
    #     m = 0
    #     while(self.fibo(m) < self.length):
    #         m = m + 1
    #     offset  = -1
    #     while(self.fibo(m) > 1):
    #         i = min(offset + self.fibo(m-2),self.length -1)
    #         if(Element > tempArr[i]):
    #             offset = i
    #             m = m - 1
    #         elif(Element < tempArr[i]):
    #             m = m - 2
    #         else: 
    #             return i
            
    #         if((self.fibo(m - 1) and tempArr[offset + 1]) == Element):
    #             return offset + 1
    #     return  -1


Number_of_student = int(input("Enter the number of student: "))
list_of_students = []
all_student(Number_of_student)

while True:
    print("1.For linear search\n2.For Sentilineal linear search\n3.For Binary_search\n4.For Fibonacci Search")
    choice = int(input("Enter the option you want to search for: "))

    if choice == 1:
        roll = int(input("Enter the roll Number you want to search for: "))
        linear_search(roll)
    elif choice == 2:
        roll = int(input("Enter the roll Number you want to search for: "))
        sentinel_linear_search(roll)
    elif choice == 3:
        roll = int(input("Enter the roll Number you want to search for: "))
        result = binary_search(roll)
        if result == 0:
            print("Roll Number ", roll, " exist")
        elif result == -1:
            print("Not found")
    elif choice == 4:
        roll = int(input("Enter the roll Number you want to search for: "))
        result = fib_search(roll)
        if result == 0:
            print("Roll Number ", roll, " exist")
        elif result == -1:
            print("Not Found")
    elif choice == 5:
        print("Exiting")
        break
    else:
        print("Enter correct choice.")


# def linear_search(x):
#     linearsearch_list = list_of_students
#     if x in linearsearch_list:
#         print("Roll Number ", x, " exist")
#         print(" ")
#     else:
#         print("Not found")
#         print(" ")


# def sentinel_linear_search(x):
#     sentilineal_list = list_of_students
#     sentilineal_list.append(x)
#     last_number = len(sentilineal_list)-1
#     if x in sentilineal_list and sentilineal_list.index(x) < last_number:
#         print("Roll Number ", x, " exist")
#         print(" ")
#     else:
#         print("Not found")
#         print(" ")



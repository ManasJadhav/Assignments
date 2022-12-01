class Sort:
    def __init__(self):
        self.arr = []
        for i in range(n):
            percentage = float(input(f"Enter the percentage of student {i+1}: "))
            if(percentage > 100):
                print("percentage cannot be greater than 100")
                percentage = int(input(f"Enter the percentage of student {i+1}: "))
            elif(percentage < 0):
                print("percentage cannot be negetive")
                percentage = int(input(f"Enter the percentage of student {i+1}: "))
            self.arr.append(percentage)
        print(self.arr)

    def insertion_sort(self):
        tempArr = self.arr.copy()
        for i in range(1, len(self.arr)):
            x = tempArr[i]
            k = i
            for j in range(i - 1, -1, -1):
                if x < tempArr[j]:
                    tempArr[j], tempArr[k] = tempArr[k], tempArr[j]
                else:
                    break
                k = k - 1
        print(tempArr)

    def shell_sort(self):
        tempArr = self.arr.copy()
        gap = len(tempArr) // 2
        while gap > 0:
            for i in range(gap, len(tempArr)):
                key = tempArr[i]
                j = i
                while j >= gap and tempArr[j - gap] > key:
                    tempArr[j] = tempArr[j - gap]
                    j = j - gap
                    tempArr[j] = key

            gap = gap // 2
        print(tempArr)


n = int(input("Enter Total Number Of Students: "))
s = Sort()
while True:

    print("1. INSERTION SORT")
    print("2. SHELL SORT")
    print("3. EXIT")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        s.insertion_sort()
    elif choice == 2:
        s.shell_sort()
    elif choice == 3:
        break

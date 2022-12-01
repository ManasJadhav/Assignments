class Percentage:
    def __init__(self):
        self.arr = []
        self.n = 0

    def input_List(self):
        self.n = int(input("Enter the number of  students in Second year :"))
        if self.n <= 5:
            print("Number of Students SHould be greater than 5")
            self.n = int(input("Enter the number of students in second year: "))
        print("Enter the Percentages :")
        for i in range(self.n):
            elem = float(input())
            if elem > 100:
                    print("The value of Percentage is below 100. So please enter value below 100")
                    elem = float(input())
            self.arr.append(elem)
        print("The list of Students Before Sorting is : ", self.arr)

    def display(self):
        print("\n Sorted array of percentages :", self.arr)
        print("\n Top five Percentages are :")
        for i in range(1, 6):
            print(i, " ", self.arr[-i])

    def quickSort(self, start, end):

        if (start >= end):
            return
        else:
            pivot = self.arr[start]
            i = start
            j = end
            while (i < j):
                while i <=end and self.arr[i] <= pivot:
                    i = i + 1
                while j >= start and self.arr[j] >pivot:
                    j = j - 1
                if i < j:
                    temp = self.arr[i]
                    self.arr[i] = self.arr[j]
                    self.arr[j] = temp
                print("Quick Sort : ", self.arr)

            temp = self.arr[start]
            self.arr[start] = self.arr[j]
            self.arr[j] = temp
            Percentage.quickSort(self,start, j - 1)
            Percentage.quickSort(self,j + 1, end)
        

obj = Percentage()
obj.input_List()
obj.quickSort(0, obj.n - 1)
obj.display()
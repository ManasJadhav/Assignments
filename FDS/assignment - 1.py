
class set():
    def __init__(self ,n):
        self.lst = []
        self.n =n
        self.creation(n)

    def length(self,lst):
        count = 0
        for i in lst:
            count+=1
        return count

    def add_element(self,item):
        self.lst += [item]

    def is_exist(self,name):
        for i in range(0,self.length(self.lst)):
            if(self.lst[i] == name):
                return True
        return False

    def creation(self, n):
        for i in range(n):
            student = input("Enter name of student : ")
            if (self.is_exist(student) == False):
                self.add_element(student)
            else:
                print("Name already exists.. enter another name")
                student = input("Enter name of student: ")
                self.add_element(student)

    def difference(self, Grp1, Grp2):
        diff = []
        for i in range(self.length(Grp1)):
            count = 0
            for j in range(self.length(Grp2)):
                if (Grp1[i] != Grp2[j]):
                    count += 1
            if (count == self.length(Grp2)):
                diff += [Grp1[i]]
        return diff

    def display_set(self, lst):  # this function print given lst in format of set
        print("{", end=" ")
        for i in range(0, self.length(lst)):
            if (lst[i] != lst[len(lst) - 1]):
                print(lst[i], end=" , ")
            else:
                print(lst[i], end=" ")
        print("}")

    def intersection(self, Grp2):  # returns intersection of Grp1 and Grp2
        Intersection = []
        m = self.length(self.lst)
        n = self.length(Grp2)
        for i in range(m):
            for j in range(n):
                if (self.lst[i] == Grp2[j]):
                    Intersection += [Grp2[j]]
        return Intersection

    def union(self, Grp2):      # returns union of Grp1 and Grp2
        Union_list = []
        for i in range(self.length(self.lst)):
            Union_list += [self.lst[i]]
        for i in range(self.length(Grp2)):
            for i in range(self.length(Grp2)):
                count = 0
                for j in range(self.length(Union_list)):
                    if (Grp2[i] != Union_list[j]):
                        count = count + 1
                if (count == self.length(Union_list)):
                        Union_list += [Grp2[i]]
        return Union_list

N1 = int(input("Enter Number of student Who plays Cricket:"))
cricket = set(N1)
N2 = int(input("Enter Number of student Who plays Badminton:"))
badminton = set(N2)
N3 = int(input("Enter Number of student Who plays Football:"))
football=set(N3)

print("\n")
print("*"*30)

print("Grp1:",end=" ")
cricket.display_set(cricket.lst)
print("Grp2:", end=" ")
badminton.display_set(badminton.lst)
print("Grp3:", end=" ")
football.display_set(football.lst)

print("\n")
print("*"*30)

print("MAIN MENU \n1.Students playing cricket and badminton \n2.Students playing cricket or badminton but not both")
print("3.Number of students playing neither cricket nor badminton \n4.Number of students playing cricket and football but not badminton")

while(True):
    choice=int(input("Enter choice:"))
    if(choice == 1):
        Ans1 = cricket.intersection(badminton.lst)
        print("Students playing cricket and badminton:", end=" ")
        cricket.display_set(Ans1)
        print("\n")
    elif(choice == 2):
        Grp1 = cricket.union(badminton.lst)
        Grp2 = cricket.intersection(badminton.lst)
        Ans2 = cricket.difference(Grp1,Grp2)
        print("Students playing cricket or badminton but not both:", end=" ")
        cricket.display_set(Ans2)
        print("\n")
    elif(choice == 3):
        Grp1 = football.lst
        Grp2 = cricket.union(badminton.lst)
        Ans3 = cricket.difference(Grp1,Grp2)
        print("Number of students playing neither cricket nor badminton:", cricket.length(Ans3))
        cricket.display_set(Ans3)
        print("\n")
    elif(choice == 4):
        Grp1 = cricket.intersection(football.lst)
        Grp2 = badminton.lst
        Ans4 = cricket.difference(Grp1,Grp2)
        print("Number of students playing cricket and football but not badminton:", cricket.length(Ans4))
        cricket.display_set(Ans4)
        print("\n")

    elif(choice == 5):
        print("EXITING")
        break
    else:
        print("Enter correct choice!!")
        












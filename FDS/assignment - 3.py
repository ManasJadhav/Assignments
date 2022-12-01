class matrix:
    def __init__(self,rows,columns):
        self.rows=rows
        self.columns=columns
        self.marr=[[0 for x in range(columns)] for y in range(rows)]


    def create_matrix(self):

        for i in range(self.rows):
            print(f'enter elements of row {i+1}')
            for j in range(self.columns):
                self.marr[i][j]=int(input())
                
    def display_matrix(self):
        for i in range(self.rows):
            for j in range(self.columns):
                print(self.marr[i][j],end=" ")
            print("")

    def add(self,m):
        m1=matrix(rows=self.rows,columns=self.columns)
        for i in range(self.rows):
            for j in range(self.columns):
                m1.marr[i][j]=self.marr[i][j]+m.marr[i][j]
        print("THE ADDITION OF MATRICES IS ")
        m1.display_matrix()
    def subtract(self,m):
        m1 = matrix(rows=self.rows, columns=self.columns)
        for i in range(self.rows):
            for j in range(self.columns):
                m1.marr[i][j] = self.marr[i][j] - m.marr[i][j]
        print("THE SUBTRACTION OF MATRICES IS ")
        m1.display_matrix()

    def transpose(self):
        m1 = matrix(rows=self.columns, columns=self.rows)
        for i in range(self.columns):
            for j in range(self.rows):
                m1.marr[i][j]=self.marr[j][i]
        print("THE TRANSPOSE OF MATRIX IS ")
        m1.display_matrix()


    def multiply(self,m):
        m1 = matrix(rows=self.rows, columns=m.columns)
        for i in range(self.rows):

            # iterating by column by B
            for j in range(m.columns):

                # iterating by rows of B
                for k in range(m.rows):
                    m1.marr[i][j] += self.marr[i][k] * m.marr[k][j]

        print("THE MULTIPLICATION OF MATRICES IS ")
        m1.display_matrix()




print("Enter the numbers of rows and columns in the first matrix")
rows1=int(input())
columns1=int(input())
m1=matrix(rows1,columns1)
m1.create_matrix()
print("THE FIRST MATRIX IS")
m1.display_matrix()
print("Enter the numbers of rows and columns in the second matrix")
rows2=int(input())
columns2=int(input())
m2=matrix(rows2,columns2)

m2.create_matrix()

print("THE SECOND MATRIX IS")
m2.display_matrix()
while(True):
    print("Enter the number of operation you want to perform on the matrices")
    print("1.Addition")
    print("2.Subtraction")
    print("3.Transpose")
    print("4.Multiplication")
    choice = int(input())
    if(choice==1):
        if m1.rows==m2.rows and m1.columns==m2.columns:
            m1.add(m2)
        else:
            print("The two matrices cannot be added as their orders are not the same.")

    elif(choice==2):
        if m1.rows == m2.rows and m1.columns == m2.columns:
            m1.subtract(m2)
        else:
            print("The two matrices cannot be subtracted as their orders are not the same. ")

    elif(choice==3):
        c=int(input("Choose the matrix of which you want to find transpose(1 or 2): "))
        if(c==1):
            m1.transpose()
        elif(c==2):
            m2.transpose()
        else:
            print("Invalid input given.")

    elif(choice==4):
        if m1.rows==m2.columns:
            m1.multiply(m2)
        else:
            print("The matrices are not compatible for multiplication.")
    else:
        print("Invalid input entered.")

    x=input("Do you want to continue(y/n): ")
    if x=='n':
        print("THANK YOU !!!!!!")
        break
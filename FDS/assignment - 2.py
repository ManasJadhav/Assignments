def longest_word(x):  # function to find longest word in string.
    long_word = ""
    max_length = 0
    for i in x:
        if len(i) > max_length:
            max_length = len(i)
            long_word = i
    print("The longest word in given string is: ", long_word)
    print("Length of the longest word in a string is: ", max_length)


def char_occurrence(x):  # function to find occurrence of particular character in a string
    char = input("Enter the character: ")
    count = 0
    for i in x:
        if char == i:
            count += 1
    print("frequency of occurrence of character in string is: ", count)

#
# def whole_string_palindrome(x):  # function to check if string is palindrome
#     rev_lst = []
#
#     for i in range(1, len(x)+1):
#         rev_lst.append(x[-i])
#     rev_str = " ".join(rev_lst)
#     if rev_str == rev_str:
#         print("It is a palindrome")
#     else:
#         print("It is not palindrome")


def appearance(x):
    sub_str = input("Enter the sub-string: ")
    for i in range(len(x)):
        if x[i] == sub_str[0]:
            index = i
            flag = ""
            for j in range(index, index+len(sub_str)):
                flag = flag + x[j]
            if flag == sub_str:

                return 'The index of first appearance of substring is: ', index
            else:
                pass
    else:
        print("Not found")


# print(appearance(sentence))

def word_occurrence(x):  # Function to calculate the number of times all elements occur in string.
    new_lst = []
    for i in x:
        if i not in new_lst:
            new_lst.append(i)
    for j in new_lst:
        occur = 0
        for i in x:
            if j == i:
                occur += 1
        print("The word ", j, " occurs ", occur, " times.")


def palindrome(x):
    rev_str = ""
    char = ""
    for i in x:
        if i == " ":
            x.remove(" ")

    for j in range(len(x)):
        char = char + x[j]

    for k in range(1, len(x)+1):
        rev_str = rev_str + x[-k]
    if rev_str == char:
        print("It is a palindrome")
    else:
        print("It is not palindrome")


String = input("Enter your string here: ")

word_lst = String.split(" ")  # list containing words of string

char_lst = []  # list containing every single character of string
for i in String:
    char_lst.append(i)


while True:
    print("************************************************MENU*********************************************")
    print(" ")  # creating space
    print("1. To display word with the longest length.")
    print("2. To determine the frequency of occurrence of a particular character in the string.")
    print("3. To count the occurrence of each word in a given string.")
    print("4. To display index of first appearance of substring.")
    print("5. To check whether given string is palindrome or not.")
    print("6. Exit")

    print(" ")  # creating space
    choice = int(input("Enter your choice: "))

    if choice == 1:
        print("\n")
        longest_word(word_lst)
    elif choice == 2:
        print("\n")
        char_occurrence(String)
    elif choice == 3:
        print("\n")
        word_occurrence(word_lst)
    elif choice == 4:
        print("\n")
        print(appearance(String))
    elif choice == 5:
        print("\n")
        palindrome(char_lst)
    elif choice == 6:
        print("\n")
        print("Exit")
        break
    else:
        print("Enter correct choice")

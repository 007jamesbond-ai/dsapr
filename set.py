def add_set1(set1):
    n = int(input("Enter total number of elements you want to add to set1: "))
    for i in range(n):
        ele = input(f"Enter element {i + 1}: ")
        set1.add(ele)

def add_set2(set2):
    n = int(input("Enter total number of elements you want to add to set2: "))
    for i in range(n):
        ele = input(f"Enter element {i + 1}: ")
        set2.add(ele)

def remove_set1(set1):
    display_set1(set1)
    ele = input("Enter element you want to remove from set1: ")
    set1.remove(ele)
    print(f"{ele} removed from set1.")

def remove_set2(set2):
    display_set2(set2)
    ele = input("Enter element you want to remove from set2: ")
    set2.remove(ele)
    print(f"{ele} removed from set2.")

def search_set1(set1):
    display_set1(set1)
    ele = input("Enter element you want to search in set1: ")
    if ele in set1:
        print(f"{ele} is present in set1.")
    else:
        print(f"{ele} is not present in set1.")

def search_set2(set2):
    display_set2(set2)
    ele = input("Enter element you want to search in set2: ")
    if ele in set2:
        print(f"{ele} is present in set2.")
    else:
        print(f"{ele} is not present in set2.")

def display_set1(set1):
    print("Elements in set1:")
    for i in set1:
        print(i)

def display_set2(set2):
    print("Elements in set2:")
    for i in set2:
        print(i)

def size_set1(set1):
    s = len(set1)
    print(f"Size of set1 is {s}.")

def size_set2(set2):
    s = len(set2)
    print(f"Size of set2 is {s}.")

def intersec(set1, set2):
    s3 = set1 & set2
    print("Intersection of sets is: ", s3)

def union(set1, set2):
    s3 = set1 | set2
    print("Union of sets is: ", s3)

def diff(set1, set2):
    s3 = set1 - set2
    print("Difference of sets is: ", s3)

def subset(set1, set2):
    s3 = set1 <= set2
    print("Is set1 a subset of set2? ", s3)


set1 = set()
set2 = set()
    
while True:
        print("\nMenu:")
        print("1. Add elements to set1")
        print("2. Add elements to set2")
        print("3. Remove element from set1")
        print("4. Remove element from set2")
        print("5. Search element in set1")
        print("6. Search element in set2")
        print("7. Display set1")
        print("8. Display set2")
        print("9. Size of set1")
        print("10. Size of set2")
        print("11. Intersection of set1 and set2")
        print("12. Union of set1 and set2")
        print("13. Difference of set1 and set2")
        print("14. Check if set1 is a subset of set2")
        print("15. Exit")
        
        choice = input("Enter your choice (1-15): ")
        
        if choice == '1':
            add_set1(set1)
        elif choice == '2':
            add_set2(set2)
        elif choice == '3':
            remove_set1(set1)
        elif choice == '4':
            remove_set2(set2)
        elif choice == '5':
            search_set1(set1)
        elif choice == '6':
            search_set2(set2)
        elif choice == '7':
            display_set1(set1)
        elif choice == '8':
            display_set2(set2)
        elif choice == '9':
            size_set1(set1)
        elif choice == '10':
            size_set2(set2)
        elif choice == '11':
            intersec(set1, set2)
        elif choice == '12':
            union(set1, set2)
        elif choice == '13':
            diff(set1, set2)
        elif choice == '14':
            subset(set1, set2)
        elif choice == '15':
            break

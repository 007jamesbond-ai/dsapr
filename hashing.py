def hashf(key, size):
    return hash(key) % size

def insert_data(table, name, phone):
    index = hashf(name, len(table))
    while table[index] is not None:
        if table[index][0] == name:
            table[index][1] = phone  
            return
        index = (index + 1) % len(table)
    table[index] = [name, phone]

def display(table):
    print("\nRecords in table:")
    for entry in table:
        if entry is not None:
            print(f"Name: {entry[0]}   Phone Number: {entry[1]}")
    print("End of records....")
    
    

def search_data(table, name):
    index = hashf(name, len(table))
    comparisons = 0
    while table[index] is not None:
        comparisons += 1
        if table[index][0] == name:
            return table[index][1], comparisons
        index = (index + 1) % len(table)
    return None, comparisons




size = int(input("Enter the size of the hash table: "))
chaining_table = [[] for _ in range(size)]  
probing_table = [None] * size
while True:
    print("\nOptions:")
    print("1. Insert client")
    print("2. Search client")
    print("3. Display records")
    print("4. Exit")
    choice = input("Choose an option: ")

    if choice == '1':
        name = input("Enter client name: ")
        phone = input("Enter client phone number: ")
        insert_data(probing_table, name, phone) 
        print(f"Inserted {name} with phone number {phone}.")

    elif choice == '2':
        name = input("Enter client name to Search: ")
        phone_probing, comparisons_probing = search_data(probing_table, name)
           
        if phone_probing is not None:
            print(f"Linear Probing: Found {name} with phone number {phone_probing} after {comparisons_probing} comparisons.")
        else:
            print(f"Linear Probing: {name} not found after {comparisons_probing} comparisons.")
    
    elif  choice == '3':
        display(probing_table)

    elif choice == '4':
        print("Exiting...")
        break

    else:
        print("Invalid option. Please try again.")
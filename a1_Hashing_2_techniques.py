size = 3
client_list_linear = [None] * size
client_list_quadratic = [None] * size

def insert_linear():
    id = int(input("Enter the client id : "))
    name = input("Enter the client name: ")
    tele = int(input("Enter the client telephone: "))
    detail = [id, name, tele]
    index = id % size
    while client_list_linear[index] is not None:
        index = (index + 1) % size
    client_list_linear[index] = detail
    print("Client is added at index ", index)

def insert_quadratic():
    id = int(input("Enter the client id : "))
    name = input("Enter the client name: ")
    tele = int(input("Enter the client telephone: "))
    detail = [id, name, tele]
    index = id % size
    step = 1
    while client_list_quadratic[index] is not None:
        index = (index + step**2) % size
        step += 1
    client_list_quadratic[index] = detail
    print("Client is added at index ", index)

def search_linear(id):
    index = id % size
    while client_list_linear[index] is not None:
        if client_list_linear[index][0] == id:
            print("Client found at index ", index)
            return
        index = (index + 1) % size
    print("Client not found")

def search_quadratic(id):
    index = id % size
    step = 1
    while client_list_quadratic[index] is not None:
        if client_list_quadratic[index][0] == id:
            print("Client found at index ", index)
            return
        index = (index + step**2) % size
        step += 1
    print("Client not found")

def delete_linear(id):
    index = id % size
    while client_list_linear[index] is not None:
        if client_list_linear[index][0] == id:
            print("Client deleted")
            client_list_linear[index] = None
            return
        index = (index + 1) % size
    print("Client not found")

def delete_quadratic(id):
    index = id % size
    step = 1
    while client_list_quadratic[index] is not None:
        if client_list_quadratic[index][0] == id:
            print("Client deleted")
            client_list_quadratic[index] = None
            return
        index = (index + step**2) % size
        step += 1
    print("Client not found")

def main():
    while True:
        print("1. Insert the client (linear probing)")
        print("2. Insert the client (quadratic probing)")
        print("3. Display the client list (linear probing)")
        print("4. Display the client list (quadratic probing)")
        print("5. Search the client (linear probing)")
        print("6. Search the client (quadratic probing)")
        print("7. Delete the client (linear probing)")
        print("8. Delete the client (quadratic probing)")
        print("9. Exit")
        ch = int(input("Enter the choice : "))
        if ch == 1:
            insert_linear()
        elif ch == 2:
            insert_quadratic()
        elif ch == 3:
            print(client_list_linear)
        elif ch == 4:
            print(client_list_quadratic)
        elif ch == 5:
            id = int(input("Enter the client id to be searched: "))
            search_linear(id)
        elif ch == 6:
            id = int(input("Enter the client id to be searched: "))
            search_quadratic(id)
        elif ch == 7:
            id = int(input("Enter the client id to be deleted: "))
            delete_linear(id)
        elif ch == 8:
            id = int(input("Enter the client id to be deleted: "))
            delete_quadratic(id)
        elif ch == 9:
            break
        else:
            print("Incorrect input")
main()
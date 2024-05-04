print("\nPrepared By:----Khushaboo Somvanshi ----")
print("\n----DSAL PRACTICAL -02(A-04)----")
print("\n----SET OPERATION----")

def main():
    set1 = set()
    set2 = set()
    while(True):
        
        print("\n1:Insert\n2:Size\n3:Remove\n4:Search\n5:Union\n6:Intersection\n7:Subset\n8:Difference\n9.Exit")
        choice = int(input("\nEnter choice:"))
        if (choice == 1):
            n1 = int(input("Enter the number of elements in set1: "))
            # set1 = set([set1.insert(x) for x in n1])
            for i in range(n1):
                data_name = input("Enter the element in set1: ")
                # insert
                set1.add(data_name)
            n2 = int(input("Enter the number of elements in set2: "))
            for i in range(n2):
                data_name = input("Enter the elements in set2: ")
                # insert
                set2.add(data_name)
            print("Set1 :",set1,"\nSet2 :",set2)
            print("------------------------------------------------------------------")
        elif (choice == 2):
            print("Size of set1: ", len(set1))
            print("Size of set2: ", len(set2))
            print("------------------------------------------------------------------")
        elif (choice == 3):
            print("Remove element from set1 and set2 (1 for set1 & 2 for set2)")
            inp = int(input())
            if inp==1:
                set1.pop()
                print(set1)
            if inp==2:
                set2.pop()
                print(set2)
            print("------------------------------------------------------------------")
        elif (choice == 4):
            ip = input("Enter element you want to search: ")
            if ip in set1:
                print("set1 contains the element ",ip)
            if ip in set2:
                print("set2 contains the element ",ip)
            print("------------------------------------------------------------------")
        elif (choice == 5):
            print("Union :", set1.union(set2))
            print("------------------------------------------------------------------")
        elif (choice == 6):
            print("Intersection: ", set1.intersection(set2))
            print("------------------------------------------------------------------")
        elif (choice == 7):
            print("Subset :", set1.issubset(set2))
            print("------------------------------------------------------------------")
        elif (choice == 8):
            differ = set2.difference(set1)
            print(differ)
            print("------------------------------------------------------------------")
        elif (choice == 9):
        	break
        else:
            print("Invalid Choice")
            print("------------------------------------------------------------------")
        c = input("Do you want to continue(Y/N): ")
        if(c=='N'):
            break
main()
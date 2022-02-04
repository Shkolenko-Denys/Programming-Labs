import sys

from Task_1.buy_ticket import buy_ticket
from Task_1.view_ticket import view_ticket

if __name__ == "__main__":
    while True:
        print("\nMenu:\n"
              "1 -- buy a ticket\n"
              "2 -- buy a ticket for student\n"
              "3 -- view my ticket by unique number\n"
              "0 -- exit")

        while True:
            try:
                option = int(input("Enter the number: "))

                if option == 1:
                    buy_ticket()
                    break
                elif option == 2:
                    buy_ticket(is_student=True)
                    break
                elif option == 3:
                    view_ticket()
                    break
                elif not option:
                    print("\n  Bye!")
                    sys.exit()
                else:
                    print("  Error: expected number from the menu. Try again.")
            except (ValueError, FileNotFoundError) as error:
                print("  Error:", error)

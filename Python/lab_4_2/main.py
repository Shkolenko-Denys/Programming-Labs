import sys

from software_academy import software_academy
from classes.factories import CourseFactory


if __name__ == "__main__":
    print("*** Software Academy Manager ***")

    while True:
        print("\nMenu:\n"
              "1 -- create a new local course\n"
              "2 -- view all local courses\n"
              "3 -- create a new offsite course\n"
              "4 -- view all offsite courses\n"
              "5 -- create a new teacher\n"
              "6 -- view all teachers\n"
              "7 -- view all programs\n"
              "0 -- exit")
        try:
            option = int(input("\nEnter the number: "))

            if option == 1:
                name = input("\nName: ")
                block = int(input("Block: "))
                audience_number = int(input("Audience number: "))
                print("All teachers:")
                i = 1
                for teacher in software_academy.get_teachers():
                    print(str(i) + ".", teacher)
                    i += 1
                id_teacher = int(input("Choose id of the teacher: "))
                print("All programs:")
                i = 1
                for program in software_academy.get_programs():
                    print(str(i) + ".", program)
                    i += 1
                id_program = int(input("Choose id of the program: "))

                software_academy.add_local_course(
                    CourseFactory.create_local_course(
                        name, block, audience_number,
                        *software_academy.get_topics(id_program)
                    ), id_program, id_teacher
                )
                print("\nSuccessfully!\n")
            elif option == 2:
                print("\nAll local courses:")
                print(software_academy.get_local_courses_str())
            elif option == 3:
                name = input("\nName: ")
                address = input("Address: ")
                print("All programs:")
                i = 1
                for program in software_academy.get_programs():
                    print(str(i) + ".", program)
                    i += 1
                id_program = int(input("Choose id of the program: "))
                print("All teachers:")
                i = 1
                for teacher in software_academy.get_teachers():
                    print(str(i) + ".", teacher)
                    i += 1
                id_teacher = int(input("Choose id of the teacher: "))

                software_academy.add_offsite_course(
                    CourseFactory.create_offsite_course(
                        name, address, *software_academy.get_topics(id_program)
                    ), id_program, id_teacher
                )
                print("\nSuccessfully!\n")
            elif option == 4:
                print("\nAll offsite courses:")
                print(software_academy.get_offsite_courses_str())
            elif option == 5:
                name = input("\nName: ")
                surname = input("Surname: ")
                software_academy.add_teacher(name, surname)
                print("\nSuccessfully!\n")
            elif option == 6:
                print("\nAll teachers:")
                for teacher in software_academy.get_teachers():
                    print("-", teacher)
                print()
            elif option == 7:
                print("\nAll programs:")
                for program in software_academy.get_programs():
                    print("-", program)
                print()
            elif not option:
                print("\nBye!")
                sys.exit()
            else:
                print("\n  Error: expected number from the menu. Try again.")
        except Exception as error:
            print("\n  Error:", error)

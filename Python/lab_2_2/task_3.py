class Student:
    """Class that describes an information about student.

    Attributes:
        number (int): An individual number of the student.
    """

    def __init__(self, surname, name, record_book, *grades):
        """Sets data about student.

        Args:
            surname (str): Student surname.
            name (str): Student name.
            record_book (str): Student record book number.
            *grades (int): Student grades.
        """
        self.number = None
        self.surname = surname
        self.name = name
        self.record_book = record_book
        self.grades = grades

    def __str__(self):
        """Return information about student in one string."""
        return f"{self.surname}\t{self.name}\t{self.record_book}\t" \
               f"{self.grades}\t{self.average_grade()}"

    @property
    def surname(self):
        """Student surname."""
        return self.__surname

    @surname.setter
    def surname(self, surname):
        """Sets the student surname.

        Args:
            surname (str): Student surname.

        Raises:
            TypeError: If surname is not a string.
        """
        if not isinstance(surname, str):
            raise TypeError("surname must be a string")
        self.__surname = surname

    @property
    def name(self):
        """Student name."""
        return self.__name

    @name.setter
    def name(self, name):
        """Sets the student name.

        Args:
            name (str): Student surname.

        Raises:
            TypeError: If name is not a string.
        """
        if not isinstance(name, str):
            raise TypeError("name must be a string")
        self.__name = name

    @property
    def record_book(self):
        """Student record book number."""
        return self.__record_book

    @record_book.setter
    def record_book(self, record_book):
        """Sets the student record book number.

        Args:
            record_book (str): Student record book number.

        Raises:
            TypeError: If record book number is not a string.
        """
        if not isinstance(record_book, str):
            raise TypeError("record_book must be a string")
        self.__record_book = record_book

    @property
    def grades(self):
        """The list of student grades."""
        return self.__grades

    @grades.setter
    def grades(self, grades):
        """Sets the list of grades.

        Args:
            grades (tuple): The tuple of grades.

        Raises:
            ValueError: If the tuple of grades is empty.
            TypeError: If at least one grade is not integer.
            ValueError: If at least one grade is out of range.
        """
        if not grades:
            raise ValueError("the tuple of grades is empty")
        if not all(isinstance(item, int) for item in grades):
            raise TypeError("the each grade must be an integer")
        if not all(0 < item <= 5 for item in grades):
            raise ValueError("the each grade must be in range (0; 5]")
        self.__grades = list(grades)

    def average_grade(self):
        """Return the average grade of the student."""
        return sum(self.grades) / len(self.grades)


class Group:
    """Class that describes a group of students."""

    def __init__(self, *students):
        """Sets the list of students in the group.

        Each student is assigned his own individual number.

        Args:
            *students (Student): A tuple of students.

        Raises:
            ValueError: If amount of students equals zero.
            OverflowError: If added more than 20 students.
        """
        if not students:
            raise ValueError("must be at least one student in group")
        if len(students) > 20:
            raise OverflowError("cannot be more than 20 students in group")
        self.students = list(students)

        number = 0
        for student in self.students:
            number += 1
            student.number = number

    def get_top5(self):
        """Display to console the top 5 students by average grade."""
        self.students.sort(key=lambda x: x.average_grade(), reverse=True)
        return self.students[:5]


if __name__ == "__main__":
    student1 = Student("Школенко", "Денис", "ТВ-0188", 4, 5, 4, 5)
    student2 = Student("Іванов1", "Іван1", "ТВ-0189", 2, 5, 4, 4)
    student3 = Student("Іванов2", "Іван2", "ТВ-0190", 4, 2, 1, 5)
    student4 = Student("Іванов3", "Іван3", "ТВ-0191", 3, 2, 1, 3)
    student5 = Student("Іванов4", "Іван4", "ТВ-0192", 5, 5, 5, 5)
    student6 = Student("Іванов5", "Іван5", "ТВ-0193", 4, 4, 4, 4)
    student7 = Student("Іванов6", "Іван6", "ТВ-0194", 5, 5, 5, 4)
    student8 = Student("Іванов7", "Іван7", "ТВ-0195", 4, 4, 2, 1)

    tv01 = Group(student1, student2, student3, student4, student5, student6,
                 student7, student8)

    for student in tv01.get_top5():
        print(student.number, student.__str__())

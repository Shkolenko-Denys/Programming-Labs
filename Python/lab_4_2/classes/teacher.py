from interfaces.iteacher import ITeacher
from classes.local_course import LocalCourse
from classes.offsite_course import OffsiteCourse


class Teacher(ITeacher):
    """The class that describes teacher."""

    def __init__(self, name, surname, *courses):
        self.name = name
        self.surname = surname
        self.courses = courses

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, name):
        if not isinstance(name, str):
            raise TypeError("the name must be a string")
        if not name:
            raise ValueError("the name cannot be empty")
        self.__name = name

    @property
    def surname(self):
        return self.__surname

    @surname.setter
    def surname(self, surname):
        if not isinstance(surname, str):
            raise TypeError("the surname must be a string")
        if not surname:
            raise ValueError("the surname cannot be empty")
        self.__surname = surname

    @property
    def courses(self):
        return self.__courses

    @courses.setter
    def courses(self, courses):
        if not courses:
            raise ValueError("the courses is empty")
        if not all(isinstance(course, (LocalCourse, OffsiteCourse))
                   for course in courses):
            raise TypeError(
                "the each course must be an LocalCourse or OffsiteCourse type")
        self.__courses = list(courses)

from interfaces.ifactories import ITeacherFactory, ICourseFactory
from classes.teacher import Teacher
from classes.local_course import LocalCourse
from classes.offsite_course import OffsiteCourse


class TeacherFactory(ITeacherFactory):
    """The factory class that create a new teacher."""

    @staticmethod
    def create_teacher(name, surname, *courses):
        return Teacher(name, surname, *courses)


class CourseFactory(ICourseFactory):
    """The factory class that create a new course."""

    @staticmethod
    def create_local_course(name, block, audience_number, *program):
        return LocalCourse(name, block, audience_number, *program)

    @staticmethod
    def create_offsite_course(name, address, *program):
        return OffsiteCourse(name, address, *program)

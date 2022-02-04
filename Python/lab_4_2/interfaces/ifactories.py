from abc import ABC, abstractmethod


class ITeacherFactory(ABC):
    """An interface of the teachers factory."""

    @staticmethod
    @abstractmethod
    def create_teacher(name, surname, *courses):
        """Return new Teacher object."""
        pass


class ICourseFactory(ABC):
    """An interface of the courses factory."""

    @staticmethod
    @abstractmethod
    def create_local_course(name, block, audience_number, *program):
        """Return new LocalCourse object."""
        pass

    @staticmethod
    @abstractmethod
    def create_offsite_course(name, address, *program):
        """Return new OffsiteCourse object."""
        pass

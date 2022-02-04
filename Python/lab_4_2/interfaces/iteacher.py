from abc import ABC, abstractmethod


class ITeacher(ABC):
    """An interface of the teacher in the software academy."""

    @property
    @abstractmethod
    def name(self):
        """Get the name of teacher."""
        pass

    @name.setter
    @abstractmethod
    def name(self, name):
        """Set the name of teacher."""
        pass

    @property
    @abstractmethod
    def courses(self):
        """Get the teacher's courses."""
        pass

    @courses.setter
    @abstractmethod
    def courses(self, courses):
        """Set the teacher's courses."""
        pass

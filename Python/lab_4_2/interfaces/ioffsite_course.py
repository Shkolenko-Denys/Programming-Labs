from abc import abstractmethod

from interfaces.icourse import ICourse


class IOffsiteCourse(ICourse):
    """The interface of the offsite course in the software academy."""

    @property
    @abstractmethod
    def name(self):
        pass

    @ICourse.name.setter
    @abstractmethod
    def name(self, name):
        pass

    @property
    @abstractmethod
    def program(self):
        pass

    @ICourse.program.setter
    @abstractmethod
    def program(self, program):
        pass

    @property
    @abstractmethod
    def address(self):
        """Get the address where the course is going."""
        pass

    @address.setter
    @abstractmethod
    def address(self, address):
        """Set the address where the course is going."""
        pass

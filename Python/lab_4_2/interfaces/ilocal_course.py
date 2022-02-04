from abc import abstractmethod

from interfaces.icourse import ICourse


class ILocalCourse(ICourse):
    """The interface of the local course in the software academy."""

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
    def block(self):
        """Get the number of the building where the course is going."""
        pass

    @block.setter
    @abstractmethod
    def block(self, block):
        """Set the number of the building where the course is going."""
        pass

    @property
    @abstractmethod
    def audience_number(self):
        """Get the audience number of course."""
        pass

    @audience_number.setter
    @abstractmethod
    def audience_number(self, audience_number):
        """Set the audience number of course."""
        pass

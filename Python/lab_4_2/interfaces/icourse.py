from abc import ABC, abstractmethod


class ICourse(ABC):
    """The interface of the course in the software academy."""

    @property
    @abstractmethod
    def name(self):
        """Get the name of course."""
        pass

    @name.setter
    @abstractmethod
    def name(self, name):
        """Set the name of course."""
        pass

    @property
    @abstractmethod
    def program(self):
        """Get the sequence of topics."""
        pass

    @program.setter
    @abstractmethod
    def program(self, program):
        """Set the sequence of topics."""
        pass

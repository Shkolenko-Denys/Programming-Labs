from interfaces.ioffsite_course import IOffsiteCourse


class OffsiteCourse(IOffsiteCourse):
    """The class that describes offsite course."""

    def __init__(self, name, address, *program):
        self.name = name
        self.address = address
        self.program = program

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
    def address(self):
        return self.__address

    @address.setter
    def address(self, address):
        if not isinstance(address, str):
            raise TypeError("the address must be a string")
        if not address:
            raise ValueError("the address cannot be empty")
        self.__address = address

    @property
    def program(self):
        return self.__program

    @program.setter
    def program(self, program):
        if not program:
            raise ValueError("the program is empty")
        if not all(isinstance(topic, str) for topic in program):
            raise TypeError("the each topic must be a string")
        self.__program = list(program)

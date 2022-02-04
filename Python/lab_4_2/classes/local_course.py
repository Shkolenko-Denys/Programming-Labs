from interfaces.ilocal_course import ILocalCourse


class LocalCourse(ILocalCourse):
    """The class that describes local course."""

    def __init__(self, name, block, audience_number, *program):
        self.name = name
        self.block = block
        self.audience_number = audience_number
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
    def block(self):
        return self.__block

    @block.setter
    def block(self, block):
        if not isinstance(block, int):
            raise TypeError("the block must be an integer")
        if block <= 0:
            raise ValueError("the block must be positive")
        self.__block = block

    @property
    def audience_number(self):
        return self.__audience_number

    @audience_number.setter
    def audience_number(self, audience_number):
        if not isinstance(audience_number, int):
            raise TypeError("the audience_number must be an integer")
        if audience_number <= 0:
            raise ValueError("the audience_number must be positive")
        self.__audience_number = audience_number

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

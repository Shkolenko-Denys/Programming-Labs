import sys


class Rectangle:
    """Rectangle with sides less than 20.

    The class contains methods that calculate and return the perimeter
    and area. Also the length and width are stored as floating-point
    numbers.
    """

    def __init__(self, length=1.0, width=1.0):
        """Sets the length and width values.

        Args:
            length (float): A length of the rectangle (defaults to 1.0).
            width (float): A width of the rectangle (defaults to 1.0).
        """
        self.length = length
        self.width = width

    @property
    def length(self):
        """The length of the rectangle."""
        return self.__length

    @length.setter
    def length(self, length):
        """Sets the length of the rectangle.

        Args:
            length (float): The length of the rectangle.

        Raises:
            TypeError: If the length is not a floating-point number.
            ValueError: If the length is out of range.
        """
        if not isinstance(length, float):
            raise TypeError("the length must be float")
        if not 0.0 < length < 20.0:
            raise ValueError("must be 0.0 < length < 20.0")
        self.__length = length

    @property
    def width(self):
        """The width of the rectangle."""
        return self.__width

    @width.setter
    def width(self, width):
        """Sets the width of the rectangle.

        Args:
            width (float): The width of the rectangle.

        Raises:
            TypeError: If the width is not a floating-point number.
            ValueError: If the width is out of range.
        """
        if not isinstance(width, float):
            raise TypeError("the width must be float")
        if not 0.0 < width < 20.0:
            raise ValueError("must be 0.0 < width < 20.0")
        self.__width = width

    def perimeter(self):
        """Return the perimeter of the rectangle."""
        return (self.length + self.width) * 2

    def area(self):
        """Return the area of the rectangle."""
        return self.length * self.width


if __name__ == "__main__":
    try:
        obj = Rectangle(14.2, 18.5)
    except (TypeError, ValueError) as e:
        print("Error:", e)
        sys.exit(1)

    print("Length =", obj.length, "\nWidth =", obj.width,
          "\nPerimeter =", obj.perimeter(), "\nArea =", obj.area())

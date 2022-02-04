from math import isclose


class Product:
    """Class that describes a product with name and price."""

    def __init__(self, name, price):
        self.name = name
        self.price = price

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
    def price(self):
        return self.__price

    @price.setter
    def price(self, price):
        if not isinstance(price, float):
            raise TypeError("the price must be a float")
        if price < 0.0:
            raise ValueError("the price cannot be negative")
        self.__price = price

    def __add__(self, other):
        if isinstance(other, (int, float)):
            return Product(self.name, self.price + other)
        return NotImplemented

    def __sub__(self, other):
        if isinstance(other, (int, float)):
            return Product(self.name, self.price - other)
        return NotImplemented

    def __mul__(self, other):
        if isinstance(other, (int, float)):
            return Product(self.name, self.price * other)
        return NotImplemented

    def __truediv__(self, other):
        if isinstance(other, (int, float)):
            if not other:
                raise ZeroDivisionError("dividing by zero is undefined")
            return Product(self.name, self.price / other)
        return NotImplemented

    def __radd__(self, other):
        if isinstance(other, (int, float)):
            return self.__add__(other)
        return NotImplemented

    def __rsub__(self, other):
        if isinstance(other, (int, float)):
            return -self.__sub__(other)
        return NotImplemented

    def __rmul__(self, other):
        if isinstance(other, (int, float)):
            return self.__mul__(other)
        return NotImplemented

    def __rtruediv__(self, other):
        if isinstance(other, (int, float)):
            if not self.price:
                raise ZeroDivisionError("dividing by zero is undefined")
            return Product(self.name, other / self.price)
        return NotImplemented

    def __lt__(self, other):
        if isinstance(other, Product):
            return self.price < other.price
        if isinstance(other, (int, float)):
            return self.price < other
        return NotImplemented

    def __gt__(self, other):
        if isinstance(other, Product):
            return self.price > other.price
        if isinstance(other, (int, float)):
            return self.price > other
        return NotImplemented

    def __le__(self, other):
        return not self.__gt__(other)

    def __ge__(self, other):
        return not self.__lt__(other)

    def __eq__(self, other):
        if isinstance(other, Product):
            return self.name == other.name and isclose(self.price, other.price)
        return NotImplemented

    def __ne__(self, other):
        return not self.__eq__(other)

    def __hash__(self):
        return hash((self.name, self.price))

    def __str__(self):
        return f"{self.name} ${self.price}"

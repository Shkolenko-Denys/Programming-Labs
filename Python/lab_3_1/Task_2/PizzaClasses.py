class Pizza:
    """Pizza class."""

    def __init__(self):
        self.price = 80.00
        self.dough = 250
        self.cheese = 75

    def __iter__(self):
        for key, value in self.__dict__.items():
            i = str(key).find("__")
            if i != -1:
                key = str(key)[i + 2:]
            yield key, value

    def __str__(self):
        s = ""
        for ingredient, weight in dict(self).items():
            s += "  " + ingredient + ": " + str(weight) + "\n"
        return s

    @property
    def price(self):
        return self.__price

    @price.setter
    def price(self, price):
        if not isinstance(price, float):
            raise TypeError("the price must be a float")
        if price < 0:
            raise ValueError("the price cannot be negative")
        self.__price = price

    @property
    def dough(self):
        return self.__dough

    @dough.setter
    def dough(self, dough):
        if not isinstance(dough, int):
            raise TypeError("the weight of the dough must be an integer")
        if dough <= 0:
            raise ValueError("the weight of the dough must be positive")
        self.__dough = dough

    @property
    def cheese(self):
        return self.__cheese

    @cheese.setter
    def cheese(self, cheese):
        if not isinstance(cheese, int):
            raise TypeError("the weight of the cheese must be an integer")
        if cheese <= 0:
            raise ValueError("the weight of the cheese must be positive")
        self.__cheese = cheese


class NeapolitanPizza(Pizza):
    """Neapolitan Pizza."""

    def __init__(self):
        super().__init__()
        self.price = 100.00
        self.salami = 50
        self.tomatoes = 30

    @property
    def salami(self):
        return self.__salami

    @salami.setter
    def salami(self, salami):
        if not isinstance(salami, int):
            raise TypeError("the weight of the salami must be an integer")
        if salami <= 0:
            raise ValueError("the weight of the salami must be positive")
        self.__salami = salami

    @property
    def tomatoes(self):
        return self.__tomatoes

    @tomatoes.setter
    def tomatoes(self, tomatoes):
        if not isinstance(tomatoes, int):
            raise TypeError("the weight of the tomatoes must be an integer")
        if tomatoes <= 0:
            raise ValueError("the weight of the tomatoes must be positive")
        self.__tomatoes = tomatoes


class ChicagoPizza(NeapolitanPizza):
    """Chicago Pizza."""

    def __init__(self):
        super().__init__()
        self.price = 300.00
        self.salami = 150


class SicilianPizza(Pizza):
    """Sicilian Pizza."""

    def __init__(self):
        super().__init__()
        self.price = 50.00
        self.onion = 10
        self.beef = 30

    @property
    def onion(self):
        return self.__onion

    @onion.setter
    def onion(self, onion):
        if not isinstance(onion, int):
            raise TypeError("the weight of the onion must be an integer")
        if onion <= 0:
            raise ValueError("the weight of the onion must be positive")
        self.__onion = onion

    @property
    def beef(self):
        return self.__beef

    @beef.setter
    def beef(self, beef):
        if not isinstance(beef, int):
            raise TypeError("the weight of the beef must be an integer")
        if beef <= 0:
            raise ValueError("the weight of the beef must be positive")
        self.__beef = beef


class GreekPizza(NeapolitanPizza):
    """Greek Pizza."""

    def __init__(self):
        super().__init__()
        self.price = 50.00
        self.salami = 40
        self.tomatoes = 5


class CaliforniaPizza(SicilianPizza):
    """California Pizza."""

    def __init__(self):
        super().__init__()
        self.price = 200.00
        self.dough = 350
        self.cheese = 60
        self.onion = 5
        self.beef = 35


class DetroitPizza(Pizza):
    """Detroit Pizza."""

    def __init__(self):
        super().__init__()
        self.dough = 350
        self.mushrooms = 50

    @property
    def mushrooms(self):
        return self.__mushrooms

    @mushrooms.setter
    def mushrooms(self, mushrooms):
        if not isinstance(mushrooms, int):
            raise TypeError("the weight of the mushrooms must be an integer")
        if mushrooms <= 0:
            raise ValueError("the weight of the mushrooms must be positive")
        self.__mushrooms = mushrooms


class PepperoniPizza(DetroitPizza):
    """Pepperoni Pizza."""

    def __init__(self):
        super().__init__()
        self.price = 500.00
        self.mushrooms = 200

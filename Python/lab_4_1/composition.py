from math import isclose

from product import Product


class Composition:
    """Class that describes a composition of products."""

    def __init__(self):
        self.products = dict()
        self.__total = 0

    @property
    def products(self):
        return self.__products

    @products.setter
    def products(self, products):
        if not all(isinstance(item, Product) for item in products):
            raise TypeError("expected Product objects")
        self.__products = dict(products)

    @property
    def total(self):
        return self.__total

    def __contains__(self, item):
        if isinstance(item, Product):
            return item in self.products
        if isinstance(item, str):
            return item in (obj.name for obj in self.products)
        if isinstance(item, float):
            return item in (obj.price for obj in self.products)
        if isinstance(item, int):
            return item in (quantity for quantity in self.products.values())
        return NotImplemented

    def __iadd__(self, other):
        if isinstance(other, Product):
            if other not in self:
                self.products[other] = 1
            else:
                self.products[other] += 1
            self.__total += 1
            return self
        return NotImplemented

    def __isub__(self, other):
        if isinstance(other, Product):
            if other in self:
                if self.products[other] > 1:
                    self.products[other] -= 1
                else:
                    self.products.pop(other, None)
                self.__total -= 1
            return self
        return NotImplemented

    def __iter__(self):
        for product, quantity in self.products.items():
            yield product, quantity

    def report_by_name(self, name):
        """Return report by name of product in the composition."""
        if not isinstance(name, str):
            raise TypeError("the name must be a string")
        result = ""
        for product, quantity in self:
            if product.name == name:
                result += str(product) + " x" + str(quantity) + "\n"
        return result

    def report_by_price(self, price):
        """Return report by price of product in the composition."""
        if not isinstance(price, float):
            raise TypeError("the price must be a float")
        result = ""
        for product, quantity in self:
            if isclose(product.price, price):
                result += str(product) + " x" + str(quantity) + "\n"
        return result

    def report_by_quantity(self, quantity):
        """Return report by quantity of products in the composition."""
        if not isinstance(quantity, int):
            raise TypeError("the quantity must be an integer")
        result = ""
        for product, q in self:
            if q == quantity:
                result += str(product) + " x" + str(quantity) + "\n"
        return result

    def __str__(self):
        result = ""
        for product, quantity in self.products.items():
            result += str(product) + " -- " + str(quantity) + " items\n"
        return result

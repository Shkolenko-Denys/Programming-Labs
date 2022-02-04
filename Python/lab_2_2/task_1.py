import sys

import phonenumbers


class Product:
    """Class that describes a product of online store."""

    def __init__(self, price, description=""):
        """Sets the price and description of the product.

        Args:
            price (float): A price of the product.
            description (str): An additional product description
                (defaults to "").
        """
        self.price = price
        self.description = description

    @property
    def price(self):
        """The price of the product."""
        return self.__price

    @price.setter
    def price(self, price):
        """Sets the price of the product.

        Args:
            price (float): A price of the product.

        Raises:
            TypeError: If the price is not a floating-point number.
            ValueError: If the price is negative.
        """
        if not isinstance(price, float):
            raise TypeError("the price must be a floating-point number")
        if price < 0:
            raise ValueError("the price cannot be negative")
        self.__price = price

    @property
    def description(self):
        """The description of the product."""
        return self.__description

    @description.setter
    def description(self, description):
        """Sets the description of the product.

        Args:
            description (str): A description of the product.

        Raises:
            TypeError: If the description is not a string.
        """
        if not isinstance(description, str):
            raise TypeError("the description must be a string")
        self.__description = description


class Customer:
    """Class that describes a customer in the online store."""

    def __init__(self, name, mobile_phone):
        """Sets the name and mobile phone number of the customer.

        Args:
            name (str): A name of the customer.
            mobile_phone (str): A mobile phone number of the customer.
        """
        self.name = name
        self.mobile_phone = mobile_phone

    @property
    def name(self):
        """The name of the customer."""
        return self.__name

    @name.setter
    def name(self, name):
        """Sets the name of the customer.

        Args:
            name (str): A name of the customer.

        Raises:
            TypeError: If the name is not a string.
        """
        if not isinstance(name, str):
            raise TypeError("the name must be a string")
        self.__name = name

    @property
    def mobile_phone(self):
        """The mobile phone number of the customer."""
        return self.__mobile_phone

    @mobile_phone.setter
    def mobile_phone(self, mobile_phone):
        """Sets the mobile phone number of the customer.

        Args:
            mobile_phone (str): A mobile phone number of the customer.

        Raises:
            TypeError: If the mobile_phone is not a string.
            ValueError: If the phone number is incorrect.
        """
        if not isinstance(mobile_phone, str):
            raise TypeError("mobile_phone must be a string")

        phone_number = phonenumbers.parse(mobile_phone)
        if phonenumbers.is_possible_number(phone_number):
            self.__mobile_phone = mobile_phone
        else:
            raise ValueError("the phone number is incorrect")


class Order:
    """Class that describes an order in the online store."""

    def __init__(self, customer, *products):
        """Sets the customer and products of the order.

        Args:
            customer (Customer): The customer who carried it out.
            *products (Product): The tuple of products in the order.
        """
        self.customer = customer
        self.products = products

    @property
    def customer(self):
        """The customer of the order."""
        return self.__customer

    @customer.setter
    def customer(self, customer):
        """Sets the customer of the order.

        Args:
            customer (str): A customer of the order.

        Raises:
            TypeError: If customer is not Customer type.
        """
        if not isinstance(customer, Customer):
            raise TypeError("customer must be Customer type")
        self.__customer = customer

    @property
    def products(self):
        """The list of products in the order."""
        return self.__products

    @products.setter
    def products(self, products):
        """Sets the products of the order.

        Args:
            products (tuple): A tuple of the products. Each product is
                Product type.

        Raises:
            TypeError: If at least one element is not Product type.
        """
        if not all(isinstance(item, Product) for item in products):
            raise TypeError("expected Product objects after customer")
        self.__products = list(products)

    def add(self, *products):
        """Extend the list of products in the order with a new products.

        Args:
            *products (Product): A tuple of products.
        """
        self.products.extend(products)

    def remove(self, product):
        """Removes the product from the order.

        Args:
            product (Product): The product that will be removed.

        Raises:
            NameError: If the product is not in the list of products.
        """
        self.products.remove(product)

    def total(self):
        """Return the total order value."""
        total = 0
        for product in self.products:
            total += product.price
        return total


if __name__ == "__main__":
    try:
        book = Product(70.0, "History of the World")
        pen = Product(5.0)
        laptop = Product(30000.0, "MacBook Air")
        bob = Customer("Bob", "+38099-123-45-67")
        order1 = Order(bob, book, pen, laptop)

        order2 = Order(bob)
        order2.add(laptop, book)
    except (TypeError, ValueError) as e:
        print("Error:", e)
        sys.exit(1)

    print("Order #1: total =", order1.total(),
          "\nOrder #1: total =", order2.total())

    try:
        order2.remove(laptop)
    except NameError as e:
        print("Error:", e)
        sys.exit(1)

    print("\nOrder #1: total =", order1.total(),
          "\nOrder #1: total =", order2.total())

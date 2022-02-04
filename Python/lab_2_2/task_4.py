class Product:
    """Class that describes the product code and price."""

    def __init__(self, code, price):
        """Sets the product code and price.

        Args:
            code (int): Product code in store.
            price (float): Product price.
        """
        self.code = code
        self.price = price

    @property
    def code(self):
        """The product code."""
        return self.__code

    @code.setter
    def code(self, code):
        """Sets the product code.

        Args:
            code (int): A product code

        Raises:
            TypeError: If code is not an integer.
        """
        if not isinstance(code, int):
            raise TypeError("code must be an integer")
        self.__code = code

    @property
    def price(self):
        """The product price."""
        return self.__price

    @price.setter
    def price(self, price):
        """Sets the product price.

        Args:
            price (int): A product price.

        Raises:
            TypeError: If price is not integer number.
            ValueError: If price is negative.
        """
        if not isinstance(price, int):
            raise TypeError("price must be integer number")
        if price < 0:
            raise ValueError("price cannot be negative")
        self.__price = price


class BinaryTree:
    """Class that describes binary tree of products."""

    def __init__(self, product):
        self.left = None
        self.right = None
        self.product = product

    @property
    def product(self):
        return self.__product

    @product.setter
    def product(self, product):
        if not isinstance(product, Product):
            raise TypeError("the product must be a Product type.")
        self.__product = product

    def insert(self, product):
        """Insert the product in the binary tree."""
        if self.product:
            if product.code < self.product.code:
                if not self.left:
                    self.left = BinaryTree(product)
                else:
                    self.left.insert(product)
            elif product.code > self.product.code:
                if not self.right:
                    self.right = BinaryTree(product)
                else:
                    self.right.insert(product)
            else:
                raise ValueError("product with this code already exists")
        else:
            self.product = product

    def search(self, product):
        """Find and return the product in the binary tree."""
        if not isinstance(product, Product):
            raise TypeError("product must be Product type")

        if product.code < self.product.code:
            if not self.left:
                raise ValueError("product is not in tree of products")
            return self.left.search(product)
        elif product.code > self.product.code:
            if not self.right:
                raise ValueError("product is not in tree of products")
            return self.right.search(product)
        else:
            return self.product


if __name__ == "__main__":
    products = []
    amount = int(input("Enter the amount of products: "))
    print("Enter products:")
    for _ in range(amount):
        product_code, product_price = map(int, input().split())
        products.append(Product(product_code, product_price))

    tree = BinaryTree(products[0])
    for item in products[1:]:
        tree.insert(item)

    for item in products:
        print("Product: ", tree.search(item).code)
        quantity = int(input("Quantity: "))
        print("Total:", tree.search(item).price * quantity)

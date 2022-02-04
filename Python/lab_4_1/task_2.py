from product import Product
from composition import Composition


if __name__ == "__main__":
    composition = Composition()

    composition += Product("Macbook", 1500.00)
    composition += Product("Macbook", 1500.00)
    composition += Product("Macbook", 1500.00)
    composition += Product("Macbook", 1400.00)
    composition += Product("Macbook", 1400.00)
    composition += Product("Macbook", 1400.00)
    composition += Product("Macbook", 2000.00)
    composition += Product("Macbook", 1600.00) - 100.00
    composition += Product("Dell", 500.00) * 2
    composition += Product("Dell Mini", 1000.00) / 2
    composition += Product("Dell Pro", 1000.00) + 500
    print(composition)

    composition -= Product("Dell Mini", 500.00)
    composition -= Product("Macbook", 1500.00)
    print(composition)

    print(composition.report_by_name("Macbook"))
    print(composition.report_by_price(1500.00))
    print(composition.report_by_quantity(3))

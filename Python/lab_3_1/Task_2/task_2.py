import json
import sys
from datetime import datetime

from Task_2.PizzaClasses import *


def write_order(pizza_name, pizza_obj):
    """Write the pizza data to text file."""
    with open("purchased_pizzas.txt", "a") as purchased_pizzas:
        purchased_pizzas.write(pizza_name + ", " + datetime.now().
                               strftime("%d.%m.%Y %H:%M:%S") + "\n"
                               + pizza_obj.__str__() + "\n")
    print("  Bon Appetit!")


if __name__ == "__main__":
    try:
        with open("pizza_week.json") as pizza_week:
            week = json.load(pizza_week)
    except FileNotFoundError as error:
        print("  Error:", error)
        sys.exit(1)

    weekday = datetime.today().isoweekday()
    pizza_day = week[str(weekday)]
    pizza = eval(pizza_day + "()")

    print("*** Pizzeria ***"
          "\nPizza-of-the-day:", pizza_day,
          "\nIngredients:", ', '.join(attr for attr in dir(pizza)
                                      if "__" not in attr and attr != "price"),
          "\nPrice:", pizza.price)

    while True:
        print("\nMenu:\n"
              f"1 -- buy a {pizza_day}\n"
              "2 -- add extra ingredient\n"
              "0 -- exit")
        try:
            option = int(input("Enter the number: "))

            if option == 1:
                write_order(pizza_day, pizza)

            elif option == 2:
                with open("extra_ingredients.json") as extra_ingredients:
                    ingredients_dict = json.load(extra_ingredients)
                for key, value in ingredients_dict.items():
                    print(key, "--", value)

                ingredient = input("Enter the number: ")
                if ingredient not in ingredients_dict.keys():
                    raise ValueError("expected number from the "
                                     "ingredients list")
                weight = int(input("Enter the weight in grams: "))
                if weight <= 0:
                    raise ValueError("the weight must be positive")
                pizza.__setattr__(ingredients_dict[ingredient], weight)

                answer = input("Buy this new pizza? [Y/n]: ")
                if answer == "Y" or answer == "y":
                    write_order(pizza_day, pizza)

            elif not option:
                print("  Bye!")
                sys.exit()
            else:
                print("  Error: expected number from the menu. Try again.")
        except (ValueError, FileNotFoundError) as error:
            print("  Error:", error)

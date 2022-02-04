import json
from datetime import datetime, date


class RegularTicket:
    """Regular ticket."""

    def __init__(self, unique_number, topic, price, event_date, *args):
        self.unique_number = unique_number
        self.topic = topic
        self.price = price
        self.event_date = event_date
        self.__purchase_date = date.today().strftime("%d.%m.%Y")
        self.__type = self.__class__.__name__

    def __str__(self):
        return f"\nUnique number: {self.unique_number}\n" \
               f"Topic: {self.topic}\n" \
               f"Price: {self.price} ₴\n" \
               f"Event date: {self.event_date}\n" \
               f"Purchase date: {self.purchase_date}\n" \
               f"Type: {self.type}\n"

    def __iter__(self):
        for key, value in self.__dict__.items():
            key = str(key).removeprefix("_RegularTicket__")
            yield key, value

    @property
    def unique_number(self):
        return self.__unique_number

    @unique_number.setter
    def unique_number(self, unique_number):
        if not isinstance(unique_number, int):
            raise TypeError("the unique number must be an integer")
        if unique_number <= 0:
            raise ValueError("the unique number must be positive")
        self.__unique_number = unique_number

    @property
    def topic(self):
        return self.__topic

    @topic.setter
    def topic(self, topic):
        if not isinstance(topic, str):
            raise TypeError("the topic must be a string")
        if not topic:
            raise ValueError("the topic cannot be empty")
        self.__topic = topic

    @property
    def price(self):
        return self.__price

    @price.setter
    def price(self, price):
        if not isinstance(price, float):
            raise TypeError("the price must be a float")
        if price < 0:
            raise ValueError("the price cannot be negative")
        self.__price = round(price, 2)

    @property
    def event_date(self):
        return self.__event_date

    @event_date.setter
    def event_date(self, event_date):
        if not isinstance(event_date, str):
            raise TypeError("the event date must be a string")
        try:
            datetime.strptime(event_date, "%d.%m.%Y")
        except ValueError:
            raise ValueError("Incorrect date format, should be DD.MM.YYYY")
        self.__event_date = event_date

    @property
    def purchase_date(self):
        return self.__purchase_date

    @property
    def type(self):
        return self.__type


class AdvanceTicket(RegularTicket):
    """Advance ticket.

    Purchased 60 or more days before the event.
    Discount 40% of the regular ticket price.
    """

    def __init__(self, unique_number, topic, price, event_date, *args):
        with open("coefficients.json") as coefficients_file:
            coefficients = json.load(coefficients_file)
        super().__init__(unique_number, topic,
                         coefficients["AdvanceTicket"] * price, event_date, args)


class LateTicket(RegularTicket):
    """Late ticket.

    Purchased fewer than 10 days before the event.
    Additional 10% to the regular ticket price.
    """

    def __init__(self, unique_number, topic, price, event_date, *args):
        with open("coefficients.json") as coefficients_file:
            coefficients = json.load(coefficients_file)
        super().__init__(unique_number, topic,
                         coefficients["LateTicket"] * price, event_date, args)


class StudentTicket(RegularTicket):
    """Student ticket.

    Discount 50% of the regular ticket price.
    """

    def __init__(self, unique_number, topic, price, event_date, *args):
        with open("coefficients.json") as coefficients_file:
            coefficients = json.load(coefficients_file)
        super().__init__(unique_number, topic,
                         coefficients["StudentTicket"] * price, event_date,
                         args)

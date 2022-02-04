from Task_1.TicketClasses import *


def print_events_list(events, is_student):
    """Print to console list of IT-events.

    Additionally, all information about the event is displayed.
    """

    today = datetime.today()
    with open("coefficients.json") as coefficients_file:
        coefficients = json.load(coefficients_file)

    print("\nIT-events:")
    i = 0
    for event in events:
        if is_student:
            coefficient = coefficients["StudentTicket"]
        else:
            event_date = datetime.strptime(event["date"], "%d.%m.%Y")
            days_before_event = (event_date - today).days
            if days_before_event < 10:
                coefficient = coefficients["LateTicket"]
            elif days_before_event >= 60:
                coefficient = coefficients["AdvanceTicket"]
            else:
                coefficient = 1
        i += 1
        print(i, "--", event["topic"] + ",", event["date"] + ",",
              event["tickets"], "available tickets,",
              round(coefficient * event["price"], 2), "₴")

    print("0 -- back to menu")


def buy_ticket(is_student=False):
    """Buying a ticket.

    Creates one object of the ticket classes.
    Removes events that have already passed.
    """

    with open("Events.json") as events_file:
        events = json.load(events_file)

    today = datetime.today()

    for event in events:
        if datetime.strptime(event["date"], "%d.%m.%Y") <= today:
            events.remove(event)

    print_events_list(events, is_student)

    number = 0
    while True:
        try:
            number = int(input("Enter the number: "))
        except ValueError as err:
            print("  Error:", err)
            continue

        if not 0 <= number <= len(events):
            print("  Error: expected number from the list. Try again.")
            continue
        if not number:
            return
        if not events[number - 1]["tickets"]:
            print("  Error: There are no tickets for this event. "
                  "Choose another event.")
            continue
        break

    with open("PurchasedTickets.json") as purchased_tickets_file:
        purchased_tickets = json.load(purchased_tickets_file)

    unique_number = len(purchased_tickets) + 1
    ticket_data = (unique_number, events[number - 1]["topic"],
                   events[number - 1]["price"], events[number - 1]["date"])

    if is_student:
        ticket = StudentTicket(*ticket_data)
    else:
        event_date = datetime.strptime(events[number - 1]["date"], "%d.%m.%Y")
        days_before_event = (event_date - today).days

        if days_before_event < 10:
            ticket = LateTicket(*ticket_data)
        elif days_before_event >= 60:
            ticket = AdvanceTicket(*ticket_data)
        else:
            ticket = RegularTicket(*ticket_data)

    purchased_tickets.append(dict(ticket))
    with open("PurchasedTickets.json", "w") as purchased_tickets_file:
        json.dump(purchased_tickets, purchased_tickets_file, indent=4)

    print("Successfully. Your unique number is", ticket.unique_number)

    events[number - 1]["tickets"] -= 1
    with open("Events.json", "w") as events_file:
        json.dump(events, events_file, indent=4)

from Task_1.TicketClasses import *


def ticket_decoder(ticket):
    """Return one of Ticket objects.

    Creates an object in the standard way. Needs to decode a class
    object from a JSON-file.
    """

    if ticket["type"] == "RegularTicket":
        return RegularTicket(*ticket.values())
    if ticket["type"] == "AdvanceTicket":
        return AdvanceTicket(*ticket.values())
    if ticket["type"] == "LateTicket":
        return LateTicket(*ticket.values())
    if ticket["type"] == "StudentTicket":
        return StudentTicket(*ticket.values())
    return ticket


def view_ticket():
    """Print to the console the ticket data.

    Decodes a class object and uses __str__ method of the ticket class
    for printing to console.
    """

    with open("PurchasedTickets.json") as purchased_tickets_file:
        purchased_tickets = json.load(purchased_tickets_file)

    while True:
        try:
            unique_number = int(input("Enter the unique number: "))
            break
        except ValueError as err:
            print("  Error:", err)

    if 0 < unique_number <= len(purchased_tickets):
        # for key, value in purchased_tickets[unique_number - 1].items():
        #     print(key + ":", value)
        ticket_string_data =\
            json.dumps(purchased_tickets[unique_number - 1])
        ticket = json.loads(ticket_string_data, object_hook=ticket_decoder)
        print(ticket)
    else:
        print("  Error: ticket with this unique number not found.")

import sys

from rational import Rational


if __name__ == "__main__":
    try:
        rational_1 = Rational(4, -6)
        rational_2 = Rational(3, 4)
    except (ZeroDivisionError, TypeError) as e:
        print("Error:", e)
        sys.exit(1)

    print(f"{rational_1}  +  {rational_2}  =  {rational_1 + rational_2}\n"
          f"{rational_1}  -  {rational_2}  =  {rational_1 - rational_2}\n"
          f"{rational_1}  *  {rational_2}  =  {rational_1 * rational_2}\n"
          f"{rational_1}  /  {rational_2}  =  {rational_1 / rational_2}\n\n"

          f"{rational_1}  +  2  =  {rational_1 + 2}\n"
          f"{rational_1}  -  3  =  {rational_1 - 3}\n"
          f"{rational_1}  *  4  =  {rational_1 * 4}\n"
          f"{rational_1}  /  5  =  {rational_1 / 5}\n\n"

          f"2  +  {rational_2}  =  {2 + rational_2}\n"
          f"3  -  {rational_2}  =  {3 - rational_2}\n"
          f"4  *  {rational_2}  =  {4 * rational_2}\n"
          f"5  /  {rational_2}  =  {5 / rational_2}\n")

    print(f"{rational_1}  +=  {rational_2}  =>  ", end="")
    rational_1 += rational_2
    print(rational_1)
    print(f"{rational_2}  -=  {rational_1}  =>  ", end="")
    rational_2 -= rational_1
    print(rational_2)
    print(f"{rational_1}  *=  {rational_2}  =>  ", end="")
    rational_1 *= rational_2
    print(rational_1)
    print(f"{rational_2}  /=  {rational_1}  =>  ", end="")
    rational_2 /= rational_1
    print(rational_2, end="\n\n")

    print(f"{rational_1}  +=  2  =>  ", end="")
    rational_1 += 2
    print(rational_1)
    print(f"{rational_2}  -=  2  =>  ", end="")
    rational_2 -= 2
    print(rational_2)
    print(f"{rational_1}  *=  3  =>  ", end="")
    rational_1 *= 3
    print(rational_1)
    print(f"{rational_2}  /=  3  =>  ", end="")
    rational_2 /= 3
    print(rational_2, end="\n\n")

    print(f"{rational_1}  <  {rational_2}  =>  {rational_1 < rational_2}")
    print(f"{rational_1}  <=  {rational_2}  =>  {rational_1 <= rational_2}")
    print(f"{rational_1}  ==  {rational_2}  =>  {rational_1 == rational_2}")
    print(f"{rational_1}  !=  {rational_2}  =>  {rational_1 != rational_2}")
    print(f"{rational_1}  >  {rational_2}  =>  {rational_1 > rational_2}")
    print(f"{rational_1}  >=  {rational_2}  =>  {rational_1 >= rational_2}")

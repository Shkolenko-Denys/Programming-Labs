import os.path
import sys

from nltk.tokenize import sent_tokenize


class TextFile:
    """Class that performs statistical processing of a text file."""

    def __init__(self, user_file):
        """Sets the name of user file.

        Args:
            user_file (str): A file name for statistical processing.
        """
        self.user_file = user_file

    @property
    def user_file(self):
        """The user file that used for statistical processing."""
        return self.__user_file

    @user_file.setter
    def user_file(self, user_file):
        """Sets the name of user file if the file exists.

        Args:
            user_file (str): A file name for statistical processing.

        Raises:
            FileNotFoundError: If the file not found.
        """
        if not os.path.exists(user_file):
            raise FileNotFoundError("the file not found")
        self.__user_file = user_file

    def count_chars(self):
        """Return amount of chars in the file."""
        count = 0
        with open(self.user_file) as infile:
            for line in infile:
                count += len(line)
        return count

    def count_words(self):
        """Return amount of words in the file."""
        count = 0
        with open(self.user_file) as infile:
            for line in infile:
                count += len(line.split())
        return count

    def count_sentences(self):
        """Return amount of sentences in the file."""
        count = 0
        with open(self.user_file) as infile:
            for line in infile:
                count += len(sent_tokenize(line))
        return count


if __name__ == "__main__":
    try:
        file1 = TextFile("text.txt")
    except FileNotFoundError as e:
        print("Error:", e)
        sys.exit(1)

    print("Chars =", file1.count_chars(),
          "\nWords =", file1.count_words(),
          "\nSentences =", file1.count_sentences())

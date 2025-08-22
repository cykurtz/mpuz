I first encountered this game in emacs years ago.
Imagine a long multiplication. You are multiplying a three digit number and a two tigit number. It will look like this:

        1 2 3
    x     4 5
    _________
      0 6 1 5
    0 4 9 5
    __________
    0 5 5 3 5

    For this puzzle the first multiplier(mult1) is a random three digit integer greater than 99 and less than 1000
    The second multiplier(mult2) is a random two digit integer greater than 9 and less than 100.
    prod1 is the product of mult1 and the ones digit of mult2.
    prod2 is the product of mult1 and the tens digit of mult2.
    prodsum is the sum of prod1 and prod2.

    This program generates mult1 and mult2. It then calculates prod1, prod2, and prodsum.
    An array of letters([A, B, C, D, E, F, G, H, I, J]) is shuffled and each number is now represented by the letter at the index of the number.

    The player's task is to discover which number is represented by each letter.

    Trapping the user input is incomplete. If the user inputs a letter that is out of range or a number that is out of range the program stops abruptly.

    Also, there is no 'again(y/n)?' so the user must restart the game for each puzzle.

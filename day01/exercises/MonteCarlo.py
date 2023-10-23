import random

def monte_carlo_pi(nsamples):
    pi = 0.
   # Implement your code here
    circle_points = 0
    square_points = 0
    interval = 0
    for interval in range (nsamples):
        x = random.random()
        y = random.random()
        d = x * x + y * y
        if d <= 1:
            circle_points += 1
        interval += 1
        square_points += 1
    pi = 4 * (circle_points / square_points)
    return pi

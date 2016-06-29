cc7.2: There are three ants on different vertices of a triangle. What is the probability of
       collision (between any two or all of them) if they start walking on the sides of the
       triangle? Assume that each ant randomly picks a direction, with either direction being 
       equally likely to be chosen, and that they walk at the same speed.
       Similarly, find the probability of collison with n ants on an n-vertex polygon.

IDEA:    The probabilty of non-collision is three ants are either walking clockwise or counter 
       clockwise. Since the probability of choosing either direction is 1/2, the probability 
       of collision is 1-2(1/2)^3=3/4.
         For n-vertex polygon, the probability of collision is 1-2(1/2)^n=1-(1/2)^(n-1).

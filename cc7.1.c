cc7.1: You have a basketball hoop and someone says that you can play one of two games.
       Game 1: You get one shot to make the hoop.
       Game 2: You get three shots and you have to make two of three shots.
       If p is the probability of making a particular shot, for which values of p should 
       you pick one game or the other?

IDEA:  Game 1--The probability is p.
       Game 2--1st shot(p), 2nd shot(p); 
               1st shot(p), 2nd shot(1-p), 3rd shot(p);
               1st shot(1-p), 2nd shot(p), 3rd shot(p);
               total is 3p^2-2p^3.


               3p^2-2p^3=p
             =>p(2p^2-3p+1)=0
             =>(2p-1)(p-1)=0
             =>p=1/2


       For 0<p<1/2, choose Game 1; for 1/2<p<1, choose Game 2.
       If p=0, 0.5 or 1, it doesn't matter which game we play.
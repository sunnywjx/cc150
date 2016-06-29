cc6.5: There is a building of 100 floors. If an egg drops from the Nth floor or above, it 
       will break. If it's dropped from any floor below, it will not break. You're given 
       two eggs. Find N, while minimizing the number of drops for the worst case.


IDEA:  At the first try, we drop Egg 1 from 10th, 20th, ..., 100th floor.
         If Egg 1 breaks at 10th floor, we need to drop Egg 2 from 1st to 9th floor; thus, 
       at most, 10 drops in total. ( Drop(Egg1)=1, Drop(Egg2)=9 )
         If Egg 1 breaks at 20th floor, we need to drop Egg 2 from 11st to 19th floor; thus, 
       at most, 11 drops in total. ( Drop(Egg1)=2, Drop(Egg2)=9 )
         If Egg 1 breaks at 30th floor, we need to drop Egg 2 from 21st to 29th floor; thus, 
       at most, 12 drops in total. ( Drop(Egg1)=3, Drop(Egg2)=9 )
         If Egg 1 breaks at 40th floor, we need to drop Egg 2 from 31st to 39th floor; thus, 
       at most, 13 drops in total. ( Drop(Egg1)=4, Drop(Egg2)=9 )
                                                 .
                                                 .
                                                 .
         If Egg 1 breaks at 100th floor, we need to drop Egg 2 from 91st to 99th floor; 
       thus, at most, 19 drops in total. ( Drop(Egg1)=10, Drop(Egg2)=9 )

         In order to minimize the number of drops for the worst case, we should do some 
       "load balancing", which means that we want Drop(Egg1)+Drop(Egg2)=constant.
         Therefore, Egg 1 must start at floor x, then go up by x-1 floors, then x-2 
       floors,..., until it gets to 100. 
                          x+(x-1)+(x-2)+...+1=100
                        =>(x+1)*x/2=100
                        =>x=13.65
         If we choose x=14, then we go up by 14, 13, 12, and so on. The last increment would
       be 4, and it would happen at floor 99. If Egg 1 broke on floor 99 or any of the prior 
       floors, the total number of drops is 14. If Egg 1 did not break on floor 99, then we 
       need to check whether it will break on floor 100, thus the total drops is 12<14.
         If we choose x=13, then we go up by 13, 12, 11, and so on. The last increment would
       be 1, and it would happen at floor 91. If Egg 1 broke on floor 91 or any of the prior 
       floors, the total number of drops is 13. If Egg 1 did not break on floor 91, then we 
       need to check whether it will break on floor 92, 93,...,99, 100, thus the total drops 
       is 13+9>13.

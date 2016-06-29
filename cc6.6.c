cc6.6: There are 100 closed lockers in a hallway. A man begins by opening all 100 lockers.
       Next, he closes every second locker. Then, on his third pass, he toggles every third
       locker (closes it if it is open or opens it if it is closed). This process continues 
       for 100 passes, such that on each pass i, the man toggles every ith locker. After his
       100th pass in the hallway, in which he toggles only locker #100, how many lockers are
       open?

IDEA:  1st pass--open all lockers;
       2nd pass--close 2, 4, 6,..., 100 lockers;
       3rd pass--toggle 3, 6, 9,..., 99 lockers;
                        .
                        .
                        .
       ith pass--toggle i, 2i, 3i,... lockers;
                        .
                        .
                        .
       100th pass--toggle 100 locker.

       factor 1: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
       factor 2:   2   4   6   8   10    12    14    16    18    20
       factor 3:     3     6     9       12       15       18
       factor 4:       4       8         12          16          20
       factor 5:         5         10             15             20
       factor 6:           6             12                18
       factor 7:             7                 14
       factor 8:               8                     16
       factor 9:                 9                         18
       factor 10:                  10                            20


       As we can see that:
          #1 locker, it will toggle at factor 1;
          #2 locker, it will toggle at factor 1, factor 2;
          #3 locker, it will toggle at factor 1, factor 3;
          #4 locker, it will toggle at factor 1, factor 2, factor 4;
          #5 locker, it will toggle at factor 1, factor 5;
          #6 locker, it will toggle at factor 1, factor 2, factor 3, factor 6;
          .
          .
          .
         The locker n will be open if it has odd factors, we know that perfect squares will 
       have odd factors!! Because by pairing n's factors by their complements, (6,6) will only 
       contribute one factor.
         18:(1,18)(2,9)(3,6)=>1,2,3,6,9,18=>even=>closed!
         36:(1,36)(2,18)(3,12)(4,9)(6,6)=>1,2,3,4,6,9,12,18,36=>odd=>open!

       There are 10 lockers are open, #1, #4, #9, #16, #25, #36, #49, #61, #81, #100.

cc6.1: You have 20 bottles of pills. 19 bottles have 1.0 gram pills, but one has pills of
       weight 1.1 grams. Given a scale that provide an exact measurement, how would you 
       find the heavy bottle? You can only use the scale once.


Note: Each pill is either 1.0 gram or 1.1 grams. Every bottle has the same number of pills.

Solution: Take one pill from bottle #1, two pills from bottle #2,..., 20 pills from botlle
          #20. If all the pills are 1.0 gram, then the total weight should be (1+2...+20)=
          210 grams. If bottle #n has 1.1 gram pill, we take n pills from bottle #n, then
          the total weight will be (1+2...+n...+20)+(n*1.1-n)=210+0.1*n. Suppose the final
          weight is 211.5, then we know that bottle #15 has the heavier pills.


 
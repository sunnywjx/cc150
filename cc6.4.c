cc6.4: A bunch of people are living on an island, when a visitor comes with a strange order: 
       all blue-eyed people must leave the island as soon as possbile. There will be a flight 
       out at 8:00 pm every evening. Each person can see everyone else's eye color, but they 
       do not know their own (nor is anyone allowed to tell them). Additionally, they do not 
       know many people have blue eyes, although they do know that at least one person does. 
       How many days will it take the blue-eyed people to leave?

IDEA:  Assume that there are n people on the island and c of them have blue eyes.
       
       Case c=1: Exactly one person has blue eyes.
         The blue-eyed person will look around and realize that no one has blue eyes. Since 
       he knows that at least one person has blue eyes, then he will conclude that it is he 
       who has blue eyes. Therefore, he will leave at the 1st evening.

       Case c=2: Exactly two person have blue eyes.
         The person A will look around and find that n-2 people have non-blue eyes and 1 
       people has blue eyes. If c=1, then the blue-eyed person will leave at the 1st evening.
       If he did not leave at the 1st evening, then person A will conclude that c=2 (which 
       means that he himself has blue eyes). Both men will leave at the 2nd evening.

       Case c=3: Exactly three person have blue eyes.
         The person A will look around and find that n-3 people have non-blue eyes and 2 
       people have blue eyes. If c=2, then the two blue-eyed persons will leave at the 2nd 
       evening. If they did not leave at the 2nd evening, then person A will conclude that 
       c=3 (which means that he himself has blue eyes). All of three men will leave at the 
       3rd evening.

         This pattern extends up to any value of c. Therefore, if c men have blue eyes, all 
       of them will leave at the cth evening.


/*
cc12.5: How would you test a pen?

Such problem need us:
    1. understanding the constraints;
    2. approaching it in a structured manner.

    #1: To understand the constraints, you should ask some questions such
as "who, what, where, when, how and why" and so on.

e.g., Let us guide you through a mock conversation.
    Interviewer: How would you test a pen?
    Candidate: Let me find out a bit about the pen. Who is going to use 
               the pen?
    Interviewer: Probably children.
    Candidate: Okay, that's interesting. What will they be doing with it?
               Will they be writing, drawing, or doing something else with
               it?
    Interviewer: Drawing.
    Candidate: Ok, great. On what? Paper? Clothing? Walls?
    Interviewer: On clothing.
    Candidate: Great. What kind of tip does the pen have? Felt? Ball point?
               Is it intended to wash off, or is it intended to be 
               permanent?
    Interviewer: It's intended to wash off.
    Candidate: Okay, so as I understand it, we have a pen that is being 
               targeted at 5 to 10 year olds. The pen has a felt tip and 
               comes in red, green, blue and black. It's intended to wash
               off when clothing is washed. Is that correct?

    #2: Structure
    • Fact check: Check the pen is felt tip and ink is one of the allowed 
      colors.
    • Intended use: Drawing. Does the pen write properly on clothing? 
      Washing. Does it wash off of clothing (even for a long time)? Does it
      wash off in hot, warm and cold water?
    • Safety: Is the pen safe (non-toxic) for children?
    • Unintended uses: How else might children use the pen? They might 
      write on other surfaces, so we need to check whether the behavior 
      there is correct. They might also stomp on the pen, throw it, and so
      on. We will need to make sure that the pen holds up under these 
      conditions.

NOTE: In any testing question, you need to test both the intended and 
      unintended scenarios!!

*/
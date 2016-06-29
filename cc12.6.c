/*
cc12.6: How would you test an ATM in a distributed banking system?

#1: Understanding the constraints. Ask the following questions:
    • Who is going to use the ATM? Anyone or blind people and so on. 
    • What are they going to use it for? Withdrawing money, transferring
      money, checking balance and so on.
    • What tools do we have to test? Do we have access to the code, or just
      to the ATM?
#2: Structure in manner. These components include:
    • Logging in
    • Withdrawing money
    • Depositing money
    • Checking balance
    • Transferring money
    • convenient service such as languge selection, etc.
    We want to use a mix of manual and automated testing.
    Manual testing involves going through the steps above, making sure to
check for all the error cases (low balance, new account, nonexistent 
account, and so on).
    Automated testing is a bit complex. We want to automate all the 
standard scenarios, as shown above, and we also want to look for some very 
specific issues, such as race conditions (it happens when two or more 
threads manipulate a shared data item and the results depend upon timing of
the excution). 

    Above all, we need to prioritize security and reliability. 

*/
/*
cc12.4: How would you load test a webpage without using any test tools?

    Load testing helps to identify a web application's maximum operating
capacity, as well as any bottlenecks that may interfere with its 
performance. Similarly, it can check how an application responds to 
variations in load.
    Typical criteria include:
        • Response time
        • Throughput
        • Resource utilization
        • Maximum load that the system can bear
    Then, we design tests to simulate the load to measure each criterion.
e.g., create thousands of virtual users by writing multi-threaded program 
where each thread act as a real-world user loading webpages. For each user,
we would programmatically measure response time, data I/O, etc. We would 
then analyze the results based on the data gathered during the tests and
compare it with the accepted values.

*/
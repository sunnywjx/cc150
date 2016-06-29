/*
cc10.5: Web Crawler starts with one page (seed page), find all the links on that page, follow them to find other 
        pages and then on those other pages it will follow the links on those pages, and then recursively do the 
        same thing.If you were designing a web crawler, how would you avoid getting into infinite loops? 

    How an infinite loop might occur? The simplest answer is that, if we picture the web as a graph of links, an 
infinite loop will occur when a cycle occurs(e.g., page A include link of page B, page B include link of page A).
    1. Web crawler is similar to BFS, we can use a hash table to flag a visited page.
    2. How to define a page?
        a. by URL? we can append URL parameters arbitrarily to any URL without truly changing the page, provided 
           it's not a parameter that the web application recognizes and handles.
        b. by Contents? Suppose I have some randomly generated content, then it is a different page each time I
           visit.
        c. Degree of similarity? Create a signature based on subsections of its URL and contents. If the current
           page signature (crawled page may has the same signature as the current page) has not been crawled, then
           crawler the current page; otherwise, lower the priority of the current page.

*/
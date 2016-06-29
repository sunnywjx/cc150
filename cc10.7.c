/*
cc10.7: Imagine a web server for a simplified search engine. This system has 100 machines to respond to search 
        queries, which may then call out using processSearch (string query) to another cluster of machines to 
        actually get the result. The machine which responds to a given query is chosen at random, so you can not 
        guarantee that the same machine will always respond to the same request. The method processSearch is very
        expensive. Design a caching mechanism to cache the results of the most recent queries. Be sure to explain
        how you would update the cache when data changes.


Assumptions:
• Other than calling out to processSearch as necessary, all query processing happens on the initial machine that
  was called.
• The number of queries we wish to cache is large (millions).
• Calling between machines is relatively quick.
• The result for a given query is an ordered list of URLs, each of which has an associate 50 character title and 
  200 character summary.
• Most popular queries should always appear in the cache.

System Requirements:
When designing the cache, we know we'll need to support two primary functions:
• Efficient lookups given a key.
• Clear and update data.

Step 1: Design a Cache for a Single System
    Create a data structure that can easily purge old data and efficiently look up a value based on a key. 
    Just combine linked list and hash table!!
    1. Insert fresh node at the front, define the size of linked list, then non-fresh node will be deleted if run
       out of size.
    2. Use hash table to map a query to a node. 

Step 2: Expand to Many Machines
    What extent the cache is shared across machines? 
    1. Each machine has its own cache. If query sent to machine 1 twice, then the result will be recalled from
       the cache on the second time. But if it sent to machine 1 and 2, then will be treated as new query.
    2. Each machine has a copy of the cache. Common query will appear in every cache and update need to go over
       all machines.
    3. Each machine stores a segment of the cache. Assign query results in each machine cache based on 
       hash(query) % N. when machine i needs the results of a query, it will figure out which machine holds this
       value, then ask that machine. Increase the number of machine-to-machine calls.

Step 3: Updating results when contents change
    When will contents change?
    1. The content at a page changes.
    2. The ordering of pages change.
    3. New pages appear related to a particular query.
    Implement an "automatic time-out" on the cache that we'd impose a time out where no query, regardless of how 
popular it is, can sit in the cache for more than x minutes. This will ensure that all data is periodically 
refreshed.


*/
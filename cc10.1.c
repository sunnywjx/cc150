/*
cc10.1: Imagine you are building some sort of service that will be called by
        up to 1,000 client applications to get simple end-of-day stock price
        information(open, close, high, low). You may assume that you already 
        have the data, and you can store it in any format you wish. How would 
        you design the client-facing service that provide the imformation to 
        the client applications? You are responsible for the development,
        rollout, and ongoing monitoring and maintenance of the feed. Descibe 
        the different methods you considered and why you would recommend your
        approach. Your service can use any technologies you wish, and can 
        distribute the information to the client applications in any 
        mechanism you choose.


We should start with the following aspects for a given proposal:
• Client Ease of Use: We want the service to be easy for the clients to 
  implement and useful for them.
• Ease for Ourselves:This service should be as easy as possible for us to 
  implement, as we shouldn't impose unnecessary work on us. We need to 
  consider in this not only the cost of implementing, but also the cost of 
  maintenance.
• Flexibility for Future Demands: This problem is stated in a "what would you 
  do in the real world"way, so we should think like we would in a real-world 
  problem. Ideally, we do not want to overly constrain ourselves in the 
  implementation, such that we can't be flexible if the requirements or 
  demands change.
• Scalability and Efficiency: We should be mindful of the efficiency of our
  solution, so as not to overly burden our service.

Proposal #1 (may be a bad choice)
    We could keep the data in simple text files and let clients download the 
data through some sort of FTP server. This would be easy to maintain in some
sense, since files can be easily viewed and backed up, but it would require 
more complex parsing to do any sort of query. And, if additional data were 
added to our text file, it might break the clients'parsing mechanism.

Proposal #2
    We could use a standard SQL database, and let the clients plug directly
into that. This would provide the following benefits:
• Facilitates an easy way for the clients to do query processing over the 
  data, in case there are additional features we need to support. For 
  example, we could easily and efficiently perform a query such as "return 
  all stocks having an open price greater than N and a closing price less 
  than M."
• Rolling back, backing up data, and security could be provided using 
  standard database features. We don't have to 'reinvent the wheel," so 
  it's easy for us to implement.
• Reasonably easy for the clients to integrate into existing applications. 
  SQL integration is a standard feature in software development environments.
  
What are the disadvantages of using a SQL database?
• It's much heavier weight than we really need. We don't necessarily need all 
  the complexity of a SQL backend to support a feed of a few bits of 
  information.
• It's difficult for humans to be able to read it, so we'll likely need to 
  implement an additional layer to view and maintain the data. This increases 
  our implementation costs.
• Security: While a SQL database offers pretty well-defined security levels,
  we would still need to be very careful to not give clients access that 
  they shouldn't have. Additionally, even if clients aren't doing anything 
  "malicious," they might perform expensive and inefficient queries, and our 
  servers would bear the costs of that.

These disadvantages don't mean that we shouldn't provide SQL access. Rather, 
they mean that we should be aware of the disadvantages.

Proposal #3
    XML is another great option for distributing the information. Our data 
has fixed format and fixed size: company_name, open, high, low, closing 
price.The XML could look like this:

<root>
	<date value="2008-l0-12">
		<company name="foo">
			<open>126.23</open>
			<high>138.27</high>
			<low>122.83</low>
			<closingPrice>127.30</closingPrice>
		</company>
		<company name="bar">
			<open>52.73</open>
			<high>60.27</high>
			<low>50.29</low>
			<closingPrice>54.91</closingPrice>
		</company>
	</date>
	<date value="2088-10-ll"> . . . </date>
</root>

The advantages of this approach include the following:
• It's very easy to distribute, and it can also be easily read by both 
  machines and humans.This is one reason that XML is a standard data model 
  to share and distribute data.
• Most languages have a library to perform XML parsing, so it's reasonably 
  easy for clients to implement.
• We can add new data to the XML file by adding additional nodes. This would 
  not break the client's parser (provided they have implemented their parser 
  in a reasonable way).
• Since the data is being stored as XML files, we can use existing tools for 
  backing up the data. We don't need to implement our own backup tool.

The disadvantages may include:
• This solution sends the clients all the information, even if they only 
  want part of it. It is inefficient in that way.
• Performing any queries on the data requires parsing the entire file.

*/
/*
cc11.4: Imagine you have a 20GB file with one string per line. Explain how you would sort the file.

IDEA:     When the interviewer gives a size limit of 20 gigabytes, it should tell you that they don't want you to
      bring all the data into memory.
          What we do is to bring part of the data into memory!!
          We will divide the file into k chunks with x megabytes each, where x is the amount of memory we have
      available. We draw one chunk each time to sort it and then saved back to the file system. Once all the 
      chunks are sorted, we merge the chunks, one by one. 
          This is called external sort. It is a term for a class of sorting algorithms that can handle massive
      amounts of data. External sort is required when the data being sorted do not fit into the main memory of a
      computing device (usually RAM) and instead they must reside in the slower external memory (usually a hard 
      drive).


*/
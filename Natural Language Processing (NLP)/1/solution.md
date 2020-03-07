Natural Language Processing is the branch of AI which deals with making the machine understand the natural language. Natural language, in sense, the language we humans read or speak in. It can be anything from English, Hindi, Japanese, Korean, etc. It is not an easy task for the computer to understand this. Computers can very well understand structures languages like tables, CSV, etc but they face difficulty while learning natural languages.

The 3 steps which we generally follow while dealing with NLP Problems are:

**i)Tokenization**
  It means breaking the paragraphs into sentences and sentences into words.
  For example if we have a paragraph like “ I am reading ML interview questions from Github. Github is a nice source to find about open source projects”.
	
  It will be tokenized into – a) I am reading ML interview questions from Github. b) Github is a nice source to find about open source projects.
  This is called sentence tokenization. Further, it will be tokenized into words like
  {am, reading, ML. interview, questions, from,github} and {Github, is, a, nice, source, to, find, about, open, source, projects}.

**ii)Removal of stop words**

  There are certain words whose meanings do not change the semantic of the sentence. These words are called stop-words and include examples like a, an, the, is, are, etc. Removing them will not change the meaning of the sentence. In the above example if we remove stop words then we will have the revised text as

  {reading, ML, interview, questions, github} and {Github, nice, source, find, about, open, source, projects}. There are different libraries available for stop words removing and depending upon their contents they will remove the stop words.

**iii)Lemmatization**

  It means changing the grammar form into one category to reduce the size of the data. For example, if we have word forms like {read, reads and reading}, what lemmatization does is that it converts it into a single verb form like {read}.
	

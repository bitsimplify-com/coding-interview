Let us consider 3 documents

Doc 1: I am learning about Machine Learning.

Doc 2: I love Deep Learning.

Doc 3: Data Science is a very interesting field.

**TF for Doc 1**

**Frequency of the following words**

I – 1

Am-1

Learning-2

About-1

Machine-1

Hence vector is [1,1,2,1,1]. Note that ordering of words here is not important

**For Doc 2**

I-1

Love-1

Deep-1

Learning-1

Hence vector is [1,1,1,1].

**For Doc 3**

Data-1

Science-1

Is-1

a-1

very-1

Interesting-1

Field-1

Hence vector is [1,1,1,1,1,1,1]

Normalised TF is ie divinding frequency by total words

Doc 1 =[1/6,1/6,2/6,1/6,1/6]

Doc 2=[1/4,1/4,1/4,1/4]

Doc 3=[1/7,1/7,1/7,1/7,1/7,1/7]

**IDF= log(Total Number of Documents/ Number of Documents with the term t]**

**Calculation of IDF**

I= log(3/2)

Am=log(3/1)

Learning = log(3/2)

Machine=log(3/1)

Love=log(3/1)

Deep=log(3/1)

Data=log(3/1)

Science=log(3/1)

Is=log(3/1)

A=log(3/1)

Interesting=log(3/1)

Field=log(3/1)

We can now calculate TF-IDF as= TFXIDF for that particular word in the particular document.

Stop-words are those words which don’t affect the meaning of the sentence even after removing those words. There are certain stop words in the English language which we can remove to reduce the size of the dataset. To view a list of all such stop-words, we need to follow the following steps in a python stell.

Import nltk

From nltk.corpus import stopwords

Set(stopwords.words(‘English’)))

This will give us a list of stop words in English. Before copying these instruction make sure you have the nltk library installed, otherwise, an error will be prompted.

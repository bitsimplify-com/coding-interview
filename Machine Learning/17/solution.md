The first step is to build the dataset. We will have a dataset of emails containing both spam and non-spam emails and they will have to be correctly labeled. For the good performance of the model, the number of entries in the dataset should be large and there should be an almost equal number of e-mails from both the categories.

The next step is to split the data into training and testing parts. Let us suppose the testing part is 30%.

Following which we will use the ML algorithms. For our convenience, we will directly use the scikit learn library.  We can use algorithms like Naïve Bayes or Decision Tree or Random Forest for this type of problem.

The last step is to create a confusion matrix. From the confusion matrix, we can know the accuracy of the particular algorithm and the chose the best one among them.

If memory is a constraint, the best way to solve this problem is to close all running applications and only let the machine learning code run. Another good idea is to use Google Colab so that the dataset is not directly loaded to your PC and this will also save computation time due to its GPU+TPU power.

1000 features is still a very large amount. Using the business understanding of the problem, you can definitely scale out some features. However, this is not always the right thing to do. Another way is to use Dimension Reducability concepts to find out the correlated data and this may scale down the dataset.

The concepts of parallel computing can be used like we divide the dataset into 3 datasets each containing say 33,000 rows and then apply the algorithm. After this, we can merge the result to get a complete understanding and the solution of the problem.

Feature Scaling is used during pre-processing and is a technique to standardize the independent features present in the data.

Suppose we have a dataset that contains the age, salary, requirement of the type of vehicle and class (which is yes or no) ie whether the individual can afford the car or not. We need to train a model that can predict the same.
Here what happens is that the salary feature will dominate every other and the person’s salary is independent of his age and what type of car he/she wants. This means that there is a high chance that the model will give wrong predictions.
Therefore we use feature scaling which will scale all the parameters or features of this dataset in the range 
[0,1] or something similar so that it doesn’t happen that any feature will dominate the other.

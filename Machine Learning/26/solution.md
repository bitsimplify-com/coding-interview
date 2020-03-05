K is the number of clusters we want to divide our dataset into. Generally speaking, we can plot the points in the graph and look for the optimal number of clusters. But this method is only valid when we can clearly differentiate between the points in the graph. Otherwise, the number of clusters in the majority of the cases will not be optimal.

The general algorithm which we use for finding the optimal number of clusters is known as the Elbow method. It works in a way like it calculates the value of inertia which is the sum of squared distances of sample to their closet cluster center. We then iterate over the values of k  in the range say 1-7 and calculate the value of inertia for each value of k in the given range. The optimal value of k will be more clear from the given example

Image here.
Source:  https://www.geeksforgeeks.org/elbow-method-for-optimal-value-of-k-in-kmeans/

In the given example, the optimal value of k will be 3 as this is the elbow point. Elbow point is the point after which inertia starts decreasing in the linear fashion.

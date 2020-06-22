Gradient Descent is an optimization algorithm used to minimize certain functions iteratively. Gradient Descent is quite similar to differentiating a function to obtain its minima. It is generally used to reduce the error in algorithms like Linear Regression.
Let us understand this mathematically.

Suppose you have plotted a linear regression curve and at a particular point, you obtain a value called **‘y_obtained’**. The actual value at that point is **‘y_actual’**. Therefore the error will be given as

Error= y_actual- y_obtained

Squaring this error we get Error^2= (y_actual-y_obtained)^2.

If you closely observe then this is the equation of a parabola. To get the minimum error, we actually differentiate it and equate it to 0. However, in the Gradient Descent Algorithm, we take small steps to the zero error and arrive at the particular point. The small steps taken is known as the learning rate.

![Gradient Descent Example](https://github.com/hiraditya/coding-sajal/blob/master/Machine%20Learning/10/gradient_example.PNG)

Image Credits:  https://towardsdatascience.com/understanding-the-mathematics-behind-gradient-descent-dde5dc9be06e

It is like you are at the green point and you need to arrive at the red point. The small steps you take to arrive at the final stage is called the learning rate while the complete algorithm is called the gradient descent algorithm.

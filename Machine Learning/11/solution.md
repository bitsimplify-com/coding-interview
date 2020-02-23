Decision Tree is a supervised Machine Learning Algorithm. Its meaning is quite evident from its name. It is a tree-like structure where at every node you need to take a decision to arrive at the possible solution. Let us understand this with the help of an example.

![Decision Tree Example](https://github.com/hiraditya/coding-sajal/blob/master/Machine%20Learning/11/decision_tree_example.PNG)

Image Source: https://towardsdatascience.com/decision-tree-classification-de64fc4d5aac

In this example, we need to find out whether the given features correspond to males or to females. So a decision tree was created.

•	If the height is greater than 180 cm, then it is obvious that the given sample is of a male.

•	If the height is less than 180 cm, we need to determine the sex based on the weight.

•	If the weight is greater than 80 kg, the sex is male otherwise the sex is female.

So if you are given the following features {172cm, 56 kg} you can determine the gender as female. If the given feature is like {190cm,72 kg} you can determine the gender as male.
 
Therefore the decision tree model is very easy to understand and use because at the end of the day you can see on what basis the decision was made. This is one of the reasons why this model is widely used.

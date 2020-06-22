Missing data is a common problem when dealing with real world dataset. If the entire row or column is missing, it is a good idea to all together to drop that particular row or column. However, majority of times this is not the case. When we talk about missing value, we generally mean a particular column for a particular row is missing. Now, this is dealt in 2 steps.

First we need to find the exact place of the missing value. And then apply certain operations to fill the missing value.

**Step1**: Let us suppose you have a missing value in say column 1. We are using dataframe as ‘df’.

We are first finding out the missing value.

null_values=df [‘column1’]. isnull()

print(null_values)

If there is a null value or NaN present, then it will give the result as true. Otherwise it will print false.

**Step2**: Replacing NaN with some value.

Now depending upon your assumptions and knowledge of the algorithms used, you would like to replace NaN with something like mean,0 or median. Here’s a quick example on how to do this.

// Replacing with mean

df[‘column1’]=df[‘column1’].fillna(df[‘column1’].mean(),inplace=True)

//Replacing with 0

df[‘column1’].fillna(0,inplace=True)

Likewise, you can replace NaN with anything of your choice.


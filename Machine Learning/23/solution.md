This is a fairly easy process in Python. All you need to do is to assign a LabelEncoder to each of the value of the gender.The code for the given problem is described below

**from sklearn.preprocessing import LabelEncoder**

**le=LabelEncoder()**

**df[‘gender’]=le.fit_transform(df[‘gender’])**

This will randomly assign a value to males and to females and convert it to numerical data. However, it comes with own set of disadvantage. Since it randomly assigns numbers to the categorical data, it can deflect the result by assigning a higher value to similar kinds of data. For example, if there are 7 cities and we use LabelEncoding then it will assign values from 0-6. So while using ML algorithms results can be deflected due to the higher value assigned to some city and a lower value to some other city.

Another way is to use a dictionary and convert the categorical data into numerical form. We can also use OneHot Encoding.

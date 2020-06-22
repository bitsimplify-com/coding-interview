There is no definite answer to this question. Both of these methods come with their own set of advantages and disadvantages. However, OneHotEncoder slightly performs better than its counterpart. This will be very clear with the help of this example given below.
Suppose you have a list of 4 countries- India, Japan, South Korea, and the USA. You want to convert this into numerical data. So we first use LabelEncoder. It randomly assigns India as 0, Japan as 1, South Korea as 2 and USA as 3. So this may confuse our ML model to think that these numbers are some kind of order or hierarchy when in actual practice this is not the case.

This is where OneHot Encoder comes into play.

What one hot encoding does is, it takes a column which has categorical data, which has been label encoded and then splits the column into multiple columns. The numbers are replaced by 1s and 0s, depending on which column has which value.
 In our example, we’ll get four new columns, one for each country — India, Japan, South Korea, and the US.
The column which contains India will be replaced by 1 whereas others will be replaced by 0s. Similarly, when it is the case of Japan, the Japan column will be replaced by 1 and all other by 0. So it essentially maintains a balance between similar kinds of values in the categorical format and doesn’t let hierarchy affect the result of the algorithm

# Quaternion

## Introduction 
C++ implementation of the quaternion. Class quaternion inhereted from complex numbers.

Each class contain real and imaginary part. Both classes __Quaternion__ and __Complex__ contain following mathematical operators: addition, subtraction, multiplication, division. Division uses [reciprocal, norm and conjugation,](https://en.wikipedia.org/wiki/Quaternion#Conjugation,_the_norm,_and_reciprocal) based on that division operator for quaternion looks beautiful.

Formulas:


```
x = [r_1, i_1]
y = [r_2, i_2]

x+y = [r_1 + r_2, i_1 + i_2]
x-y = [r_1 - r_2, i_1 - i_2]
x*y = 	[
	r_1*r_2 - i_1*i_2, 
	r_1*i_2 + r_2*i_1 + i_1*i_2
	]
x/y = x * y^{-1} = x * y^{*}/(||y||)^{2}
```

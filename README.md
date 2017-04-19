All code written specifically for Math 540: Elementary Number Theory
Taken Spring 2017 at KU.
All code exclusive written by Zachary Bruennig

The current project is about Greatest Common Divisors of Gaussian Integers.
Gaussian Integers are complex numbers with integer-valued real and imaginary parts.

A question was posed to us: For any integers a,b =/= 0, is it always true that the GCD(a+bi, a-bi) = 1?
Note if the GCD of two Gaussian Integers is 1, then the GCD is also -1, i, and -i, since the GCD can always be multiplied by a factor of i.

It turns out, it's not true at all. For the times it isn't true, there are a few cases:

Case 1: a = b. Then the gcd of a+bi, a-bi is the gcd(a+ai, a-ai). Note a+ai = i(a-ai). Therefore the gcd(a+ai, a-ai) = a-ai.

Case 2: gcd(a,b) =/= 1. Suppose it equals d =/= 1. Then d is a common divisor of a+bi and a-bi, since d|a and d|b => d|bi => d|a+bi.

Case 3: gcd(a,b) = 1, gcd(a+bi, a-bi) =/= 1. Sometimes, and without many patterns, the gcd(a+bi, a-bi) = 1+i. I do not know what causes this, and this would be an area where I could do further research.

Case 4: A combination of Case 2 and Case 3, where gcd(a,b) =/= 1, but removing that common divisor still leaves you in case 3, where the gcd([a+bi / d],[a-bi / d]) = 1+i. Then, gcd(a+bi, a-bi) = d+id.

The output files in this folder try to list these out, considering only certain cases. The rows and columns represent the a and b components, respectively. An asterisk means that the gcd(a+bi, a-bi) =/= 1

output.txt shows all those in Case 3.

output2.txt shows all those in Case 3, and all multiples of those.

output3.txt shows all cases.

bigOutput.txt shows all those in Case 3, for a wider range of a and b. Opening this file MAY slow down your computer.

Although output2 and output3 may look visually appealing, the most interesting one is output3.txt. There appear to be some patterns to the asterisks, although it's hard to pin down exactly what they are.

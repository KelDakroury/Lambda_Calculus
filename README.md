# Lambda_Calculus
A program that takes a file input.txt as an input containing a string and returns another file output.txt containing one or two lines:
  * The first line is: "YES" if the input is an element of the set Λ of lambda-terms defined by the following grammar:
      Λ ::= V | (Λ)Λ | \V.Λ
    where V is the set of non-empty strings build from latin letters and digits; "NO" otherwise. Notice that the ‘\’ character is used instead of ‘λ’.
  * If the first line was "NO", then there is no other line. If it was "YES", then the second line is the number of β-redexes of the input.
  
Example 1:
input.txt
(\x.x)(y)
output.txt
NO

Example 2:
input.txt
(\x.x)y
output.txt
YES
1

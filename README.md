# poc_teg

**Synopsis** 

Various programs used to create the software needed for developing a point-of-care thromboelastography device 
+      Conjoint analysis using methods based on http://tolstoy.newcastle.edu.au/R/e10/help/att-8876/DCE_with_R.pdf. Involves "conjointA.R," "conjointB.R", and "survey.py" 
+      



**Methods:** 

###Conjoint analysis

*1. Download csv file from Typeform*

A.	File format: ID	question1	question 2	...	date  ...	network ID

       csv data from POC_TEG.2.3.csv: 
       9da13677f8860b210b46b16e0d51b97e	A	B	C	B	B	B	B	C	2015-09-21 19:20:07	2015-09-21 19:20:24	c8426baa42
       d8153470f7cdc01dacc47e34511ff1bf	B	C	C	C	A	B	B	C	2015-09-21 19:20:26	2015-09-21 19:20:40	c8426baa42
       85f68f9033ed14a016557ad62488b84c	A	B	C	B	A	B	A	A	2015-09-21 19:20:46	2015-09-21 19:21:02	c8426baa42
       

*2. Run conjointA.R in R*

  + Make a full factorial design with four attributes ("PORT","DURA","BLOD","QUIK"), 
each with two levels 
  + Create a fractional full factorial design ("des") , taking 8 combinations
  + Take "des," rename (alt1), create a copy (alt2), jumble up the list
  + Write csv files of alt1 and alt2, where the first line of alt1 and the first line of alt2 together form the first question
  

*3. Run survey.py with Python*
  + This script takes the above csv files and formats them in this manner:

```
       STR	RES	ASC	PORT	DURA	BLOD	QUIK
       101	1	1	0	1	0	0
       101	0	1	0	1	0	0
       101	0	0	0	0	0	0
       102	1	1	1	0	0	0
       102	0	1	1	0	0	0
       102	0	0	0	0	0	0
       103	0	1	0	1	1	1
       103	1	1	0	1	1	1
       103	0	0	0	0	0	0
```
  + STR = 100 * (respondent #) + (question #)
```
RES = response 
response = A => 
STR	RES
101	1
101	0	
101	0

response = B => 
STR	RES
101	0
101	1	
101	0

response = C => 
STR	RES
101	0
101	0	
101	1
```
ASC= the first two lines of a question = 1, the last line = 0 
```
STR	RES	ASC
101	1	1	
101	0	1	
101	0	0
```
[PORT	DURA	BLOD	QUIK] = attributes for a given question.. if good, 1, if bad, 0

*4. Run conjointB.R in R*

  + "clogit" performs conditional logistic regression 

*5. Correlations are found in clogout1* 

```
       coef exp(coef) se(coef)     z     p
ASC   3.300    27.109    1.297  2.54 0.011
PORT -0.313     0.731    0.695 -0.45 0.653
DURA -0.300     0.740    0.780 -0.38 0.700
BLOD -1.034     0.355    0.723 -1.43 0.152
```

"exp(coef)" is e^coef 
"se(coef)" is the standard error of coef 

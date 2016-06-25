# conjointB.R
#
# Fits a conditional logistic regression model 
#
# Adapted from Hideo Aizaki and Kazushi Nishiura
# See: http://tolstoy.newcastle.edu.au/R/e10/help/att-8876/DCE_with_R.pdf


data1 <- read.delim("cojoint.txt")

library(survival)
clogout1<- clogit(RES~ASC+COST+VOLM+CMPX+QUIK+strata(STR),data=data1)


# Plot results  
colors=c("royalblue4","red","orange2","darkslategray4")
qrichtot <- floor((clogout1$coefficients + 3)*25)
total <- barplot(qrichtot, main="Conjoint Analysis Survey Results", xlab="Device Attribute",ylab="Desirability (a.u.)",names.arg=c("ASC","Cheap","Small Samples","Simple","Quick"), border="black", col=colors)
text(total, 0, round(qrichtot, 1), cex=1, pos=3)  
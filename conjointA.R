# conjointA.R
#
# Generates factor combinations for fractional factorial design
#
# Adapted from Hideo Aizaki and Kazushi Nishiura
# See: http://tolstoy.newcastle.edu.au/R/e10/help/att-8876/DCE_with_R.pdf

library(AlgDesign)
ffd <- gen.factorial(c(2,2,2,2), varNames=c("COST","VOLM","CMPX","QUIK"),factors="all")

set.seed(88321)
des <- optFederov(~.,ffd,8)

alt1 <- des$design
alt2 <- alt1
alt1 <- transform(alt1, r1=runif(8))
alt2 <- transform(alt2, r2=runif(8))
alt1_sort <- alt1[order(alt1$r1),]
alt2_sort <- alt2[order(alt2$r2),]

write.csv(alt1_sort,file="alt1_sort.csv")
write.csv(alt2_sort,file="alt2_sort.csv")


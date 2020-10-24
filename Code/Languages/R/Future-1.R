# Kevin Tran
# Problem given by professor

# Load data from csv file
setwd('/home/fridaysky/Downloads')
myFutureData <- read.csv("Future-500.csv", header=TRUE)

# First, replace all NA values in the revenue, expenses, and profit columns with the means of the non-NA data in those columns.
# Second, sort the data set based on the values in Profit (ascending order).
solve <- function(fin=myFutureData) {
  mean(fin[fin$Industry == "Revenue","Expenses","Profit"], na.rm=TRUE)
  fin <- fin[order(fin$profit)]
}

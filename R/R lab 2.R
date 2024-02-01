#load necessary libraries
libray(dplyr)
#set seed for reproducibility
set.seed(123)
#generate sample data
months<-c("jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec")
revenue<-round(runif(12,min=800,max=1200),2)*1000 #random monthly revenue.
expenses<-round(runif(12,min=600,max=1000),2)*1000 #random monthly expenses.

profit <-revenue - expenses

#calculate profit_aftertax for each month(taxrateis 30%)
tax_rate<-0.30
profit_after_tax<-profit*(1-tax_rate)
profit_margin<-(profit_after_tax/revenue)*100
mean_profit_after_tax<-mean(profit_after_tax)

good_months<-months[profit_after_tax>mean_profit_after_tax]
bad_months<-months[profit_after_tax<mean_profit_after_tax]
best_months<-months[which.max(profit_after_tax)]
worst_months<-months[which.min(profit_after_tax)]

profit<-format(profit/1000,nsmall=2)
profit_after_tax<-format(profit_after_tax/1000,nsmall=2)
profit_margin<-format(profit_margin,nsmall=0)


#create a dataframe with the results
results<-data.frame (
  Month=months,
  profit=paste("$",profit),
  profit_After_Tax=paste("$",profit_after_tax),
  profit_Margin=paste(profit_margin,"%"),
  good_Months=paste(good_months,collapse=","),
  bad_Months=paste(bad_months,collapse=","),
  best_Month=best_month,
  worst_Month=worst_month
)

#save results to a csv file
write.csv(results,file="F:/financial_metrics_results.csv",row.names=FALSE)

#display the results
print(results)
)

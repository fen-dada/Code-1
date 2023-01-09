#!/usr/bin/env python3
year = int(input("请输入年份："))
month = int(input("请输入月份："))
day = int(input("请输入日期："))
sum_day = 0
months=[31,28,31,30,31,30,31,31,30,31,30,31]
# 判断几月份 然后加到变量里，开头是0的就不用了
for i in range(month-1):
    sum_day += months[i]
sum_day += day

#判断二月
leap = 0
if (year % 400 == 0) or (year % 4 == 0 and year % 100 != 0):
    leap = 1
if leap == 1 and month > 2:
    sum_day += 1
print(sum_day)

'''
在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。

火车票有 三种不同的销售方式 ：

一张 为期一天 的通行证售价为 costs[0] 美元；
一张 为期七天 的通行证售价为 costs[1] 美元；
一张 为期三十天 的通行证售价为 costs[2] 美元。
通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张 为期 7 天 的通行证，那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天。

返回 你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费 。



示例 1：

输入：days = [1,4,6,7,8,20], costs = [2,7,15]
输出：11
解释：
例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划：
在第 1 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 1 天生效。
在第 3 天，你花了 costs[1] = $7 买了一张为期 7 天的通行证，它将在第 3, 4, ..., 9 天生效。
在第 20 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 20 天生效。
你总共花了 $11，并完成了你计划的每一天旅行
'''
from math import inf
from typing import List


class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        n = len(days)#
        dp = [inf] * n#
        dp[0] = min(costs)#
        d = [1,7,30]#
        for i in range(1,n):#
            for k in range(0,3):
                j = i
                while j >= 0 and days[j] + d[k] > days[i]:
                    j -= 1#
                if j < 0 :
                    dp[i] = min(dp[i],costs[k])
                else:
                    dp[i] = min(dp[i],dp[j] + costs[k])
        return dp[n - 1]
    #这里是float类型，但一般会被覆盖，也可以用自定义极大数
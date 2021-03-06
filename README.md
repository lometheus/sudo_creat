# Sudoku
**博客园地址**[http://www.cnblogs.com/](http://www.cnblogs.com/ "博客地址")

老师发布了作业要求做一个数独，首先我先了解一下数独的游戏规则，数独一共九九八十一个小方格，要求1-9九个数字在每一行，每一列，每个3x3的小格子都只出现一次，编程的那么问题就变得极其粗暴了，遍历每一个格子，查看它行和列和3x3小格的数字，存储可能的数字，然后一点一点尝试。所以说暂时看来O(n^4)复杂度的代码是少不了了

**优化可能性**

1、由于要遍历多个点，所以可以尝试采用多线程的方法尝试为计算加速

2、在遍历数组查看是否在1—9时可采用位运算的方式，减少内存且加快了运算速度

过程中可能存在的问题

1、用户输入的问题，在进行实际运算的时候必须考虑用户输入的问题，用户可能输入一个错误或无法解出的数独，此时需要做预判，判断数独是否正确
![avatar](/htp.png "作业流程图")
## 算法 ##
![avatar](/arithmetic.png "算法流程图")
解数独使用的是回溯的方法，生成数独采用的是随机变换的方法，根据每次移动随机数目的随机数字获得输出。

![avatar](/creat.png)

##代码优化##
代码最终优化由1000 000组数独2000秒优化到了现在的5秒1000 000组数独，关键优化有关于数独产生方法的优化、数独产生后输入文件的优化，以整形一个一个存入极其费时，将数组化为一个字符串一次性输入，大幅度降低了时间损耗。
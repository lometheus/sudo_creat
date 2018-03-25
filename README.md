# Sudoku
作业
老师发布了作业要求做一个数独，首先我先了解一下数独的游戏规则，数独一共九九八十一个小方格，要求1-9九个数字在每一行，每一列，每个3*3的小格子都只出现一次，编程的那么问题就变得极其粗暴了，遍历每一个格子，查看它行和列和3*3小格的数字，存储可能的数字，然后一点一点尝试。所以说暂时看来O(n^4)复杂度的代码是少不了了

优化可能性

1、由于要遍历多个点，所以可以尝试采用多线程的方法尝试为计算加速

2、在遍历数组查看是否在1—9时可采用位运算的方式，减少内存且加快了运算速度

过程中可能存在的问题

1、用户输入的问题，在进行实际运算的时候必须考虑用户输入的问题，用户可能输入一个错误或无法解出的数独，此时需要做预判，判断数独是否正确
![avatar](/htp.png "作业流程图")
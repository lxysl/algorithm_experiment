# 《算法分析与设计》实验

---

## 1. 实验内容
本次实验内容由基础实验和迁移实验两部分组成。基础实验都是教材或视频上都有讲到的内容或者包含伪码，迁移实验则是对书本上内容的迁移。


### 基础实验：


* 实验1

随机产⽣⼀个包含100个元素的正整数序列，分别采⽤快速排序算法和插⼊排序算法完成序列从⼩到⼤的排序，排序完成后显示排序结果。


* 实验2

令P=<50,35,25,10,60,70,3,5,10>,相对应的矩阵链是： A1(50 * 35), A2(35 * 25), A3(25 * 10), A4(10 * 60), A5(60 * 70), A6(70 * 3), A7(3 * 5), A8(5 * 10), 括号内为矩阵的维度，请⽤动态规划算法确定⼀种乘法⽅式，使得A1 * A2 * A3 * A4 * A5 * A6 * A7 * A8总的基本运算量（只算乘法，不算加法）最少。


* 实验3 

分别⽤Prim算法和Kruskal算法找到⽆向带权图的⼀条最⼩⽣成树。


* 实验4

随机⽣成10个球的半径⻓长度（都为正数），要求⽤分⽀限界算法计算其具有最短排列排列⻓长度的圆排列。


### 迁移实验：


* 实验1

⼿动输⼊包含元素为n(n>=10)的⼀个数字序列，这n个元素中可能有相同值，要求设计算法输出显示这n个元素的不同排列和排列总数。


* 实验2

设围棋⽐赛有m=2p 位参赛者。现要设计⼀个满⾜以下要求的循环⽐赛⽐赛⽇程表：


(1)每位选⼿必须与其他m-1位选⼿各赛⼀次；


(2)每位选⼿⼀天只能参赛⼀次；


(3)循环赛在m-1天内结束。


请按此要求将⽐赛⽇程表设计成有m⾏和m-1列的表格。在表中的第i⾏，第j列处填⼊第i个选⼿在第j天所遇到的选⼿。其中1≤i≤n，1≤j≤n1。8个选⼿的⽐赛⽇程表如下图所示：

* 实验3

随机给出⼀个含有m个(m>10)的正整数序列, 规定其中元素只能和其左右相邻的元素中某⼀个进⾏归并求和，将和值代替刚才⽤来求和的两个元素，放置在序列⾥，并将该和记录下来，记为n，要求设计算法 求出所有数合为⼀个数后所有的n值中的最⼤和最⼩值，并给出相应的归并求和顺序。


* 实验4

⽤两台机器加⼯10个零件。这⾥既不能将⼀个零件分开由2台机器处理，也没有⼀台机器能同时处理2个零件。这10个零件交给第⼀台机器处理需要时间为[1 3 5 7 4 2 8 4 9 9]，交给第⼆台机器处理需要时间 [1.5 2 6 8 2 1 3 8 11 4]。这⾥假设两台机器都连续⼯作，没有休息时间，请设计⼀个动态规划算法，使得这两台机器处理完这10个零件的时间最短，并显示两台机器所处理零件的具体顺序。


* 实验5

给定n位正整数a，去掉其中任意k个数字后，剩下的数字按原次序排列组成⼀个新的正整数。对于给定的n和k，设计⼀个算法，找出剩下数字组成的新数最少的删数⽅案。


* 实验6

给定p个排好序的序列l1 , ... , lp，⽤两路合并算法将这p个序列合并成⼀个序列。假设所采⽤的两路合并算法合并任意两个⻓长度分别为f1和f2的序列需要f1 + f2 − 1次⽐较。试设计⼀个算法确定合并这个序列的最优合并顺序，使所需要的总⽐较次数最少。


* 实验7

⽤回溯算法求解任意的9*9的数独问题。（数独问题描述：标准的数独游戏是在⼀个 9 X 9 的棋盘上填写 1 – 9 这 9 个数字，规则是这样的：棋盘分成下图所示的 9 个区域（不同区域由⿊⾊粗线标出，每个区域是 3 * 3 的⼦棋盘），在每个⼦棋盘中填充 1 – 9 且不允许重复，下⾯简称块重复每⼀⾏不许有重复值，每⼀列不许有重复值）


* 实验8

现有k种不同形状的图形，每种图形数量有⾜够多。欲将这些图形排列成m⾏n列的⼀个矩阵，m<=n，使矩阵中每⼀⾏和每⼀列的图形都没有相同的形状。试设计⼀个算法，计算出对于给定的m和n，有多少种不同的图形排列⽅案。


## 2.实验要求：

1. 实验内容中基础实验每项都需完成，迁移实验在（1，3，6，7）和（2，4，5，8）中选⼀组完成；
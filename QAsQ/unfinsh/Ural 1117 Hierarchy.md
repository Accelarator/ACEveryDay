# Ural 1117 Hierarchy

这个题说的是

给一个满二叉树，按照中序遍历的顺序给二叉树的节点从1开始编号

从一个点到另一个点传送所花费的时间定义为这两个点之间路径的节点个数

并且一个点只能直接传送到和这个点编号相邻的点，比如$x$直接传送到$x-1$或$x+1$

问需要多少时间才能从给出的起点传送到终点

-----

ural的题真长啊。。。又臭又长。。。

----

然后怎么做呢？

-----

我们注意到有一半的节点是叶子节点（满二叉树の性质

由题中给出的要求，其实每一步是从叶子到非叶子到叶子到非叶子的一个循环（想一想，为什么

每一步所消耗的时间就是这两步之间的层深度差-1

这样的话我们已经有一个$O(abs(n-m))$的暴力模拟了

-----

这一题的数据范围是$O(2^{31}-1)$，所以模拟还不够，需要考虑优化

----

具体的，我们重新定义一下两点之间传送的时间的花费为这两个点之间的路径的数目（为了方便处理不花费时间的情况，而且这样定义之后我们的时间

---

说了这么多，代码倒是很短

```cpp
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define LL long long

bool jud(LL n){
    n--;
    if(n <= 2) return false;
    return n % 4 == 0;
}

LL cal(LL n){
    LL ret = 1-n;
    while(n>1){
        ret += n-1;
        n = n/2 + jud(n);
    }
    return ret;
}

int main(){
    LL l,r;
    while(~scanf("%lld %lld",&l,&r)){
        if(l>r) swap(l,r);
        printf("%lld\n",cal(r)-cal(l));
    }
    return 0;
}
```
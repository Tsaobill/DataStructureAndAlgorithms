# 拼多多算法岗笔试

## 1.数字山谷

数字山谷：从每个位置向向两边扩展，找到最大山谷，注意边界即可

```python
xx = raw_input()[1:-1]
if xx == '':
    print 0
else:
    x = map(int,xx.split(','))
    n = len(x)
 
    if n < 3:
        print 0
    else:
        res = 0
        for i in xrange(1,n-1):
            l = i
            while l > 0 and x[l-1]>x[l]:
                l -= 1
            r = i
            while r < n-1 and x[r+1]>x[r]:
                r += 1
            if l < i and r > i:
                res = max(res,r-l+1)
        print res if res >= 3 else 0
```

```c++
#pragma once
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

void
solve() 
{
    //vector<int> A;
    //int a;
    //while (cin >> a)
    //    A.push_back(a);
    vector<int> A{ 4,3,2,5,3,1,4,8 };
    int n = A.size();
    int maxN = 0;

    if (n < 3) cout << maxN;

    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j + 1 < n && A[j + 1] < A[j])    // 改成 A[j + 1] > A[j] 即找山脉
            j++;
        int k = j;
        while (k + 1 < n && A[k + 1] > A[k])    // 改成 A[k + 1] < A[k] 即找山脉
            k++;
        if (j > i && k > j)                     //  注意只有上坡或下坡不算山谷
            maxN = max(maxN, k - i + 1);
    }
    
    cout << maxN;
}

//int main() {
//
//    solve();
//    return 0;
//}
```





## 2.字符串构造

问题描述：一个长串由一个字串循环构成,即 s[i]=t[i%n],比如 "abcabc" 由 "abc" 构成

注意："abcabcab" 也是由 "abc" 构成的，答题时没注意这个又只过了一部分

字符串构造：假设总串s长度为n，基串base长度为k，如果s/k * base + base[:s%k]==s，则返回（应该有更好的解法）

```python

```

## 3.到达指定位置

分情况讨论：到target与到abs(target)的情况是一样的

1. total = 1+2+...+k，求total刚好大于等于n的k，可知到达target至少要用k步，此时超出d=total-k
2. 如果d为偶数，则只需将d/2步反向即可，k步即可到达target
3. 如果d为奇数，则k步不可能到达，因为任何反转都会改变偶数距离，不可能消去d，则再走一步判断d+k+1是否为偶数
4. 如果为偶数，说明k+1步可到
5. 如果d+k+1为奇数，且已知d为奇数，说明k+1为偶数，不可能在k+1步走到，再走一步，d+k+1+k+2必为偶数，k+2步可到



```c++
#pragma once
#include <cstdio>
#include <cmath>

int minStep(int x) {
    if (x == 0) return 0;
    if (x<0) x = -x;

    int n = sqrt(2 * x);    // 这里相当于选了一个下界， n=1 开始也能过

    while ((n + 1)*n / 2 - x & 1 || (n + 1)*n / 2 < x)
        ++n;
    return n;
}

void
solve()
{
    int x;
    while (scanf("%d", &x))
        printf("%d\n", minStep(x));
}
```



```python
def solve(target):
    import math
    n = abs(target)
    k = int(math.ceil(((8*n+1)**0.5-1)/2.))
    total = k*(k+1)/2
    d = total - n
    if d % 2 == 0:
        return k
    elif (d+k+1) % 2 == 0:
        return k + 1
    else:
        return k + 2
 
n = input()
print solve(n)
```



## 4.靓号

题目描述：
​    A国的手机号码由且仅由N位十进制数（0-9）组成，可以有前导0，比如000123456.一个手机号码中至少有K位数相同则被定义为靓号（不要求连续）。
​    如果想把自己的手机号修改为一个靓号，修改一个数字的金额为新数字与旧数字之间的差的绝对值，比如1修改为6或6修改为1都要花5块钱。
​    求对给定手机号，修改为靓号最少要花的钱数以及新的号码（如果有多个，输出字典序最小的）。

统计每个数字出现次数counter，以每个数字为基准，按照与基准差值对counter排序，优先替换差值小的数字；关于字典序的问题，如果替换的数比基准大则从前向后替换，如果替换的数比基准大，则从后向前替换，得到的就是字典序最小的字符串，时间复杂度O(n)  



```python
/*
输入：
    第一行包含两个整数 N 和 K，分别表示 手机号码的位数和靓号要求的位数
    第二行为 N 个数字，数字之间没有空白符
    数据范围 2 <= K <= N <= 10000
示例：
    输入：
        6 5
        785785
    输出：
        4
        777577
    说明: 777577 比 777775 字典序小
*/
n,k = map(int,raw_input().split())
x = raw_input()
 
dic = Counter(map(int,x))
 
 
res = float('inf')
ans = []
for num,cnt in dic.items():
    need = k - cnt
    if need <= 0:
        print 0
        print x
        break
    else:
        tmp = [[xx,dic[xx]] for xx in dic if xx != num]
        tmp.sort(key=lambda y:abs(num-y[0]))
        w = 0
        cur = {}
        ii = 0
        while need > 0:
            act = min(tmp[ii][1], need)
            cur[tmp[ii][0]] = act
            need -= act
            w += abs(num-tmp[ii][0]) * act
            ii += 1
        if w <= res:
            x_cp = x
            for g,gn in cur.items():
                if g > num:
                    x_cp = x_cp.replace(str(g),str(num),gn)
                if g < num:
                    x_cp = x_cp[::-1].replace(str(g),str(num),gn)[::-1]
 
            if w == res:
                ans.append(x_cp)
            else:
                ans = [x_cp]
                res = w
 
print res
print sorted(ans)[0]
```


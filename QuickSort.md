```java
/**
*前后指针法，i代表当j为某值时小于等于i的元素的最后一个，
*那么i+1就是第一个大于主元的元素，因此碰到下一个小于等于的要先把i+1然后和j交换
*最后i+1(第一个大于主元的元素)要和主元交换，然后返回i+1
*优点：这种方式可以用于链表这种非顺序结构的快速排序
*缺点：1、碰到相同元素就停下来交换，不必要
*	  2、虽然停下，但是当所有元素都相同的时候，快拍
*	  的时间复杂度仍然退化到n方
*/
public static int part1(int[] arr, int lo, int hi) {
    int i = lo - 1;
    int v = arr[hi];
    for (int j = lo; j < hi; j++) {
        if (arr[j] <= v) swap(arr, ++i, j);
    }
    swap(a, i + 1, hi);
    return i + 1;
}

/**
*左右指针 ：
*right右边的都大于等于主元，停下时right小于主元
*left 左边的都小于等于主元，停下时left的元素大于主元，
*然后交换left和right 
*退出循环时 left==right，然后将temp和他们交换，返回其索引
*优点：碰到相等的时候不停，这样就少做不必要的交换
*缺点：因此如果输入数字元素全部相等时间复杂度则会降到n方
*/
private static int part2(int[] arr, int lo, int hi) {
    int v = arr[lo];
    while (lo < hi) {
        while (lo < hi && arr[hi] >= v) {
            hi--;
        }
        arr[lo] = arr[hi];
        while (lo < hi && arr[lo] <= v) {
            lo++;
        }
        arr[hi] = arr[lo];
    }
    arr[hi] = v;
    return hi;
}

/**
*左右指针：
*i左边的都小于主元，i为第一个 大于 等于主元的元素
*j的右边都大于主元，j为第一个 小于 等于主元的元素
*先判断i是否和j相遇或者交叉，是的话就退出循环。
*相遇i==j没必要交换，
*交叉不能换，换了可能(当i停下的时候是等于主元不会出错，是大于就)会出错
*退出循环之后，由于i处大于等于主元，j处小于等于主元，而主元在前隐藏要和j交换并返回j
*缺点：相等就停下，进行一些不必要的交换
*优点：当数组元素全部相同的时候仍然为nlogn；
*/
private static int part3(int[] a, int lo, int hi) {
    int i = lo;
    int j = hi + 1;
    int v = a[lo];
    while (true) {
        while (a[++i] < v) {
            if (i == hi) {
                break;
            }
        }
        while (a[--j] > v) {
        }
        if (i >= j) {
            break;
        }
        swap(a, i, j);
    }
    swap(a, lo, j);
    return j;
}
/**
*三路划分快排：
*lt左边都小于主元，lt的元素一直等于主元
*gt右边都大于主元，gt的元素最终等于主元
*循环结束时，lt的元素和gt相等，但并不一定是lt==gt
*而i=gt+1, lt左边的都小于主元，gt右边都大于主元，lt到gt之间的元素都等于主元
*因此，对lo到lt-1之间[lo...lt-1] 和gt+1到hi之间[gt+1..hi] 调用sort函数，
*缺点：
*优点：当数组元素全部相同的时候时间为n；
*/
    private static void sort(int[] a, int lo, int hi) {
        if (hi <= lo) {
            return;
        }
        int lt = lo, i = lo + 1, gt = hi;
        int v = a[lo];
        while (i <= gt) {
            if (a[i] < v) {
                swap(a, lt++, i++);
            } else if (a[i] > v) {
                swap(a, i, gt--);
            } else {
                i++;
            }
        }
        sort(a, lo, lt - 1);
        sort(a, gt + 1, hi);
    }

```


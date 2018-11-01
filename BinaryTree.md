## BinaryTree

包含静态方法，输入数组，该数组为将一棵树从上往下从左往右放入数组中，

方法可以获得目标节点的左右子节点和父节点；

``` java
public class BinaryTrees {
    public static int Left(int[] a, int i) {
        return 2 * i + 1;
    }

    public static int Right(int[] a, int i) {
        return 2 * (i + 1);
    }

    public static int Parent(int[] a, int i) {
        return (i - 1) / 2;
    }
}
```


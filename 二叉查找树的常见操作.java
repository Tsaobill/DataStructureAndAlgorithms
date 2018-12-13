public class BinarySearchTree<T extends Comparable<? super T>>{

	// 私有内部类供内部方法使用
	private static class BinaryNode<T>{
		//Constructors
		BinaryNode(T theElement){
			this(theElement,null,null);
		}

		BinaryNode(T theElement, BinaryNode<T> lt,BinaryNode<T> rt,){
			element = theElement; left = lt; right = rt;
		}

		T element;
		BinaryNode<T> left;
		BinaryNode<T> right;
	}

	private BinaryNode<T> root;

	public BinarySearchTree(){
		root = null;
	}

	public void makeEmpty(){
		root = null;
	}
	public boolean isEmpty(){
		return root == null;
	}

	public boolean contains(T x){
		return contains(x,root);
	}

	public T findMin(){
		if (isEmpty()) {
			throw new UnderflowException();
		}
		return findMin(root).element;
	}

	public T findMax(){
		if (isEmpty()) {
			throw new UnderflowException();
		}
		return findMax(root).element;
	}

	public void insert(T x){
		root = insert(x,root);
	}

	public remove(T x){
		root = remove(x,root);
	}

	public void printTree(){
		/*  
		TODO 
		*/
	}

	private boolean contains(T x ,BinaryNode<T> t){
		if (t == null) {
			return false;
		}
		int comResult = x.compareTo(t.element);

		if (comResult < 0) {
			return contains(x, t.left);
		}else if (comResult > 0) {
			return contains(x, t.right);
		}else{
			return true;//Match
		}
	}

	private BinaryNode<T> findMin(){
		//递归实现
		if (t == null || t.left == null) {
			return t;
		}
		return findMin(t.left);
	}

	private BinaryNode<T> findMax(){
		//类似于findMin，也可递归实现，
		//由于是尾递归因此可以很容易用while循环代替
		if (t == null) {
			return null;
		}
		while (t.right != null){
			t = t.right;
		}

		return t;
	}

	private BinaryNode<T> insert(T x, BinaryNode<T> t){
		//找到合适的位置新建节点并连接，返回新的树根
		if (t == null) {
			return new BinaryNode<>(x,null,null);
		}

		int comResult = x.compareTo(t.element);

		if (comResult < 0) {
			t.left = insert(x, t.left);
		}else if (comResult > 0) {
			t.right = insert(x, t.right);
		}else{
			// Duplicate; do nothing
		}

		return t;

	}

	private BinaryNode<T> remove(T x, BinaryNode<T> t){
		//稍微复杂一点。先找x,找x的过程类似前面的contains方法；
		//找到以后，判读x有几个孩子，如果有一个孩子，则直接将返回其孩子索引
		//如果有两个孩子，找到其右子树中最小(也可用左子树最大的)的元素将其替换，
		//然后递归对那个节点进行删除，
		
		if (t == null) {
			return t;
		}

		int comResult = x.compareTo(t.element);

		if (comResult < 0) {
			t.left = remove(x, t.left);
		}else if (comResult > 0) {
			t.right = remove(x, t.right);
		}
		else if (t.left != null && t.right != null) {
			t.element = findMin(t.right).element;
			t.right = remove(t.element, t.right);
		}else{
			// 这里包括了没有孩子和有一个孩子的情况：
			// 1.如果左子树不为空 有一个孩子，返回左子树
			// 2.如果左子树为空，返回右子树：
			//     a.右子树不为空有一个孩子将其返回，
			//     b.右子树为空没有孩子返回空
			t = (t.left != null) ? t.left : t.right;
		}

		return t;
	}

	private void printTree(BinaryNode<T> t){

	}
} 

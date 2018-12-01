//前序遍历
public static void pre_Trav_1(BTN root){
	BTN p = root;
	BTN[] stack = new BTN[100];
	int i = -1;
	while (p != null || i != -1){
		while (p ! = null){
			System.out.println(p.val);
			stack[++i] = p;
			p = p.left;
		}
		if (i != -1) {
			p = stack[i--];
			p = p.right;
		}
	}
}

public static void pre_Trav_2(BTN root){
	BTN temp;
	int i = -1;
	BTN[] stack = new BTN[100];
	stack[++i] = root;
	while (i != -1){
		temp = stack[i--];
		System.out.println(temp.val);
		if (temp.right != null) stack[++i] = temp.right;
		if (temp.left != null) stack[++i] = temp.left;
	}

}


//中序遍历

public static void in_Trav_1(BTN root){
	    BTN p = root;
        BTN[] stack = new BTN[100];
        int i = -1;
        while (p != null || i != -1) {
            while(p != null){
            	stack[++i] = p;
            	p = p.left;
            }
            if (i != -1) {
            	p = stack[i--];
            	System.out.println(p.val);
            	p = p.right;
            }
        }
}


//后序遍历

  public static void postOrderTraNoRec1(BTN root){//双栈
        Stack<BTN> s1 = new Stack<>();
        Stack<BTN> s2 = new Stack<>();
        BTN p = root;
        s1.push(root);
        while (!s1.isEmpty()){
            p = s1.pop();
            s2.push(p);
            if (p.left!=null)s1.push(p.left);
            if (p.right!=null)s1.push(p.right);
        }
        while (!s2.isEmpty()){
            p = s2.pop();
            System.out.print(p.val+"  ");
        }
    }



//层序遍历

    // 利用队列，每出队一个节点，将其左右子节点依次入队；
    public static void lvOrderQ(BTN root){
    	if (root == null) return;
    	Queue<BTN> q = new LinkedList<>();
    	q.offer(root);
    	while (!q.isEmpty()){
    		BTN temp = q.poll();
    		System.out.print(temp.val+"  ");
    		if(temp.left != null) q.offer(temp.left);
    		if(temp.right != null) q.offer(temp.right);
    	}
    }

    //不用对用，用ArrayList每次输出一层时按顺序存储其下一层；
    public static void lvOrderArr(BTN root ){
    	if (root == null) {
    		return;
    	}
    	ArrayList<BTN> list = new ArrayList<>();
    	list.add(root);
    	while (!list.isEmpty()){
    		ArrayList<BTN> temp = new ArrayList<>();
    		foreach(BTN node : list){
    			System.out.print(node.val+"  ");
    			if(node.left != null)temp.add(node.left);
    			if(node.right != null)temp.add(node.right);
    		}
    		list = temp;
    	}
    }
    
 
#include<iostream>  
#include<queue>  
#include<stack>  
using namespace std;  
  
//二叉树结点的描述  
typedef struct BiTNode
{  
    char data;  
    struct BiTNode *lchild, *rchild;      //左右孩子  
}BiTNode,*BiTree;  
  
/* 
二叉树的非递归前序遍历，前序遍历思想：先让根进栈，只要栈不为空，就可以做弹出操作， 
每次弹出一个结点，记得把它的左右结点都进栈，记得右子树先进栈，这样可以保证右子树在栈中总处于左子树的下面。 
*/  
void PreOrder_Nonrecursive(BiTree T)     //先序遍历的非递归    
{  
    if(!T)    
        return ;    
    
    stack<BiTree> s;  
    s.push(T);  
  
    while(!s.empty())  
    {  
        BiTree temp = s.top();  
        cout<<temp->data<<" ";  
        s.pop();  
        if(temp->rchild)  
            s.push(temp->rchild);  
        if(temp->lchild)  
            s.push(temp->lchild);  
    }  
}  
 
void PreOrder_Nonrecursive1(BiTree T)     //先序遍历的非递归 
{
	if(!T)  
        return ;
	stack<BiTree> s;
	BiTree curr = T;
	while(curr != NULL || !s.empty())
	{
		while(curr != NULL)
		{
			cout<<curr->data<<"  ";
			s.push(curr);
			curr = curr->lchild;
		}
		if(!s.empty())
		{
			curr = s.top();
			s.pop();
			curr = curr->rchild;
		}
	}
}
 
void PreOrder_Nonrecursive2(BiTree T)     //先序遍历的非递归  
{  
    if(!T)
        return ;  
  
    stack<BiTree> s;  
    while(T)          // 左子树上的节点全部压入到栈中  
    {  
        s.push(T);  
        cout<<T->data<<"  ";  
        T = T->lchild;  
    }  
      
    while(!s.empty())  
    {          
        BiTree temp = s.top()->rchild;  // 栈顶元素的右子树  
        s.pop();                        // 弹出栈顶元素  
        while(temp)          // 栈顶元素存在右子树，则对右子树同样遍历到最下方  
        {  
            cout<<temp->data<<"  ";  
            s.push(temp);  
            temp = temp->lchild;  
        }  
    }  
}  
 
void InOrderTraverse1(BiTree T)   // 中序遍历的非递归  
{  
    if(!T)  
        return ;  
    BiTree curr = T;    // 指向当前要检查的节点  
    stack<BiTree> s;
	while(curr != NULL || !s.empty())
	{
		while(curr != NULL)
		{
			s.push(curr);
			curr = curr->lchild;
		}//while
		if(!s.empty())
		{
			curr = s.top();
			s.pop();
			cout<<curr->data<<"  ";
			curr = curr->rchild;
		}
	}
}
 
void InOrderTraverse(BiTree T)   // 中序遍历的非递归  
{  
    if(!T)  
        return ;  
    stack<BiTree> s;  
    BiTree curr = T->lchild;    // 指向当前要检查的节点  
    s.push(T);  
    while(curr != NULL || !s.empty())  
    {  
        while(curr != NULL)    // 一直向左走  
        {  
            s.push(curr);  
            curr = curr->lchild;  
        }  
        curr = s.top();  
        s.pop();  
        cout<<curr->data<<"  ";  
        curr = curr->rchild;  
    }  
}  
 
void PostOrder_Nonrecursive1(BiTree T)  // 后序遍历的非递归    
{    
    stack<BiTree> S;    
    BiTree curr = T ;           // 指向当前要检查的节点  
    BiTree previsited = NULL;    // 指向前一个被访问的节点  
    while(curr != NULL || !S.empty())  // 栈空时结束    
    {    
        while(curr != NULL)            // 一直向左走直到为空  
        {    
            S.push(curr);    
            curr = curr->lchild;    
        }    
        curr = S.top();  
        // 当前节点的右孩子如果为空或者已经被访问，则访问当前节点  
        if(curr->rchild == NULL || curr->rchild == previsited)    
        {    
            cout<<curr->data<<"  ";    
            previsited = curr;    
            S.pop();    
            curr = NULL;    
        }    
        else  
            curr = curr->rchild;      // 否则访问右孩子  
    }    
}   
  
void PostOrder_Nonrecursive(BiTree T)  // 后序遍历的非递归     双栈法  
{    
    stack<BiTree> s1 , s2;    
    BiTree curr ;           // 指向当前要检查的节点  
    s1.push(T);  
    while(!s1.empty())  // 栈空时结束    
    {  
        curr = s1.top();  
        s1.pop();  
        s2.push(curr);  
        if(curr->lchild)  
            s1.push(curr->lchild);  
        if(curr->rchild)  
            s1.push(curr->rchild);  
    }  
    while(!s2.empty())  
    {  
        printf("%c ", s2.top()->data);  
        s2.pop();  
    }  
}  
  
  
int visit(BiTree T)  
{  
    if(T)  
    {  
        printf("%c ",T->data);  
        return 1;  
    }  
    else  
        return 0;  
}  
  
void LeverTraverse(BiTree T)   //方法一、非递归层次遍历二叉树   
{  
    queue <BiTree> Q;  
    BiTree p;  
    p = T;  
    if(visit(p)==1)  
        Q.push(p);  
    while(!Q.empty())  
    {  
        p = Q.front();  
        Q.pop();  
        if(visit(p->lchild) == 1)   
            Q.push(p->lchild);  
        if(visit(p->rchild) == 1)  
            Q.push(p->rchild);  
    }  
}  
void LevelOrder(BiTree BT)     //方法二、非递归层次遍历二叉树   
{  
    BiTNode *queue[10];//定义队列有十个空间  
    if (BT==NULL)  
        return;  
    int front,rear;  
    front=rear=0;  
    queue[rear++]=BT;  
    while(front!=rear)//如果队尾指针不等于对头指针时  
    {  
        cout<<queue[front]->data<<"  ";  //输出遍历结果  
        if(queue[front]->lchild!=NULL)  //将队首结点的左孩子指针入队列  
        {  
            queue[rear]=queue[front]->lchild;  
            rear++;    //队尾指针后移一位  
        }  
        if(queue[front]->rchild!=NULL)  
        {  
            queue[rear]=queue[front]->rchild;    //将队首结点的右孩子指针入队列  
            rear++;   //队尾指针后移一位  
        }  
        front++;    //对头指针后移一位  
    }  
}  
  
int depth(BiTNode *T)   //树的深度  
{  
    if(!T)  
        return 0;  
    int d1,d2;  
    d1=depth(T->lchild);  
    d2=depth(T->rchild);  
    return (d1>d2?d1:d2)+1;  
    //return (depth(T->lchild)>depth(T->rchild)?depth(T->lchild):depth(T->rchild))+1;  
}  
int CountNode(BiTNode *T)  
{  
    if(T == NULL)  
        return 0;  
    return 1+CountNode(T->lchild)+CountNode(T->rchild);  
}  
  
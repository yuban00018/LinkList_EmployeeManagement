# LinkList got modified
## class Node
add:
```C++
friend ostream &operator<<(ostream &out,const Node<T> &node)
	{
		if(&node==NULL){out<<"!";return out;}
		out<<node.data;
		return out;
	}
```
## class LinkList
delete:
```C++
	for(; p!=NULL && TYPE(p->data)!=TYPE(data); p=p->next)	// for循环的表达式1为空：从链表的"当前"结点起继续查找
		;													// TYPE()为类型强制转换运算符
```
modified:
```C++
	for(; p!=NULL && p->data!=data; p=p->next)	// operator != got overloaded
		;	
```
you should be noticed that from now on, every class should overload operator **==** and operator **!=**
typedef struct list * Set;
typedef struct list {
	link  first;	   //指向第一个元素的指针
} List;

Set SetIntersection (Set A, Set B) { //交集运算实现
	link a, b, p, q, r;
	Set tmp = SetInit( );
	a= A->first;
	b= B->first;
	p= NewNode( );
	q= p;
	while (a && b) {
		if (a->data == b->data) {
			r = NewNode( );
			r->data = a->data;
			r->next=0;
			p->next=r;
			p=r;
			a=a->next;
			b=b->next;
		} else if (a->data < b->data) a=a->next;
		else b=b->next;
	}
	if (p!=q) tmp->first=q->next;
	free (q);
	return tmp;
}


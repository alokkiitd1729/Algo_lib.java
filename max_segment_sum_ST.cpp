// GSS1.  -    https://www.spoj.com/problems/GSS1/
// https://codeforces.com/blog/entry/18051

#include<bits/stdc++.h>

using namespace std;

#define MAX_N 50010

int arr[MAX_N];

int max3(int a,int b,int c)
{
	return max(max(a,b),c);
}

struct segNode {
	int left,right,segsum,bestsum;
};
segNode tree[4*MAX_N];
void merge(segNode &node,segNode &cl,segNode &cr)
{
	node.segsum = cl.segsum+cr.segsum;
	node.left = max(cl.segsum+cr.left,cl.left);
	node.right = max(cr.segsum+cl.right,cr.right);
	node.bestsum = max3(cl.bestsum,cr.bestsum,cl.right+cr.left);
}



void build(int node,int tl,int tr){  
	// node is the index or parent index in arr[] where segment[tl,tr] is stored. NOTE - id node is not the exacr=t index then 
	// some part of [tl,tr] may be in the left child(cl=2*node) of node with indexed cl in arr and remaining half in the right child(cr=2*node+1) with indexed cr
	
	//deb(node,tl,tr);
	if(tl==tr)
	{
		tree[node].left=tree[node].right=tree[node].segsum=tree[node].bestsum=arr[tl];
		return;
	}
	int cl = node<<1;   // 
	int cr = cl|1;
	int tm = (tl+tr)>>1;
	build(cl,tl,tm);
	build(cr,tm+1,tr);
	// above we did all the stuff in left child and right child
	merge(tree[node],tree[cl],tree[cr]);   // here it taking only the index of current, left, right node index in arr_segment tree to update the parent info.
}



void query(segNode &res,int node,int tl,int tr,int l,int r)
{
	if(tl==l and tr==r)
		res=tree[node];
	else
	{
		int cl=node<<1;
		int cr = cl|1;
		int tm= (tl+tr)>>1;
		if(r<=tm)
			query(res,cl,tl,tm,l,r);
		else if(l>tm)
			query(res,cr,tm+1,tr,l,r);
		else
		{
			segNode leftNode,rightNode;
			query(leftNode,cl,tl,tm,l,tm);
			query(rightNode,cr,tm+1,tr,tm+1,r);
			merge(res,leftNode,rightNode);
		}
	}
}
int main()
{
	int n,c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	build(1,1,n);
	scanf("%d",&c);
	int x,y;
	for(int i=0;i<c;i++)
	{
		scanf("%d %d",&x,&y);
		segNode res;
		query(res,1,1,n,x,y);
		printf("%d\n", res.bestsum);
	}	
	return 0;
}

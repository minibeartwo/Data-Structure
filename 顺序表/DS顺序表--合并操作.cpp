#include <bits/stdc++.h>
using namespace std;
 #include<iostream>
using namespace std;
#define ok 0
#define error -1

// 顺序表类定义
class SeqList
{
private:
    int *list;      // 元素数组
    int maxsize;    // 顺序表最大长度
    int size;       // 顺序表实际长度
public:
    SeqList();                          // 构造函数
    ~SeqList();                         // 析构函数
    int list_size();                    // 获取顺序表实际长度
    int list_insert(int i, int item);   // 插入一个元素，参数是插入的数值和位置
    int list_del(int i);                // 删除一个元素，参数是删除的位置
    int list_get(int i);                // 获取一个元素，参数是获取的位置
    void list_display();                // 输出整个顺序表
};

SeqList::SeqList()
{
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}
SeqList::~SeqList()
{
    delete []list;
}
int SeqList::list_size(){
	return size;
} 
int SeqList::list_insert(int i,int item){
	if(i<1||i>size+1){
		return 0;
	}
	int j=size;
	for(j=size;j>i-1;j--){
		list[j]=list[j-1];
	}
	list[j]=item;
	size++;
	return 1;
}
int SeqList::list_del(int i){
	if(i<1||i>size+1){
		return 0;
	}
	for(int j=i-1;j<size-1;j++){
		list[j]=list[j+1];
	}
	size--;
	return 1;
}
int SeqList::list_get(int i){
	if(i<1||i>size){
		return 0;
	}else{
		return list[i-1];
	}
}
void SeqList::list_display(){
	cout<<size<<" ";
	for(int i=0;i<size;i++)cout<<list[i]<<" ";
	cout<<endl;
}
int main(){
	SeqList m;
	int n1,n2;
	int a[1000],b[1000];
	cin>>n1;
	for(int i=0;i<n1;i++)cin>>a[i];
	cin>>n2;
	for(int i=0;i<n2;i++)cin>>b[i];
	int *aindex=a+n1-1,*bindex=b+n2-1;
	for(int i=0;i<n1+n2;i++){
		if(*aindex>*bindex){
			m.list_insert(1,*aindex);
			aindex--;
		}else{
			m.list_insert(1,*bindex);
			bindex--;
		}
	}
	m.list_display();
}

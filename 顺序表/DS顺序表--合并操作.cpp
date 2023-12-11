#include <bits/stdc++.h>
using namespace std;
 #include<iostream>
using namespace std;
#define ok 0
#define error -1

// ˳����ඨ��
class SeqList
{
private:
    int *list;      // Ԫ������
    int maxsize;    // ˳�����󳤶�
    int size;       // ˳���ʵ�ʳ���
public:
    SeqList();                          // ���캯��
    ~SeqList();                         // ��������
    int list_size();                    // ��ȡ˳���ʵ�ʳ���
    int list_insert(int i, int item);   // ����һ��Ԫ�أ������ǲ������ֵ��λ��
    int list_del(int i);                // ɾ��һ��Ԫ�أ�������ɾ����λ��
    int list_get(int i);                // ��ȡһ��Ԫ�أ������ǻ�ȡ��λ��
    void list_display();                // �������˳���
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

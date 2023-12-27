#include <iostream>
using namespace std;

#define LH 1 // ��� 
#define EH 0 // �ȸ� 
#define RH -1 // �Ҹ� 

class BiNode
{
    public:
        int key; // �ؼ�ֵ
        int bf; // ƽ������ 
        BiNode *lChild, *rChild;
        BiNode(int kValue, int bValue)
       {

           key = kValue;
           bf = bValue;
           lChild = NULL;
           rChild = NULL;
       }
       BiNode(){}
       ~BiNode()
      {
           key = 0;
           bf = 0;
           lChild = NULL;
           rChild = NULL;
       }
};

// ����������
class BST
{
     private:
         BiNode *root; // �����ָ�� 
         void rRotate(BiNode *&p);
         void lRotate(BiNode *&p);
         void leftBalance(BiNode *&t);
         void rightBalance(BiNode *&t);
         int insertAVL(BiNode *&t, int key, bool &taller); // ����Ԫ�ز���ƽ�⴦��
         void inOrder(BiNode *p);
     public:
         BST();
         void insertAVL(int key); // ��������������Ԫ�� 
         ~BST();
         void inOrder(); // ������� 
};

// ��pΪ���Ķ������������������� 
void BST::rRotate(BiNode *&p)
{
    BiNode *temp=p->lChild;
    p->lChild=temp->rChild; 
    temp->rChild=p;
    p=temp;
}

// ��pΪ���Ķ������������������� 
void BST::lRotate(BiNode *&p)
{
    BiNode *temp=p->rChild;
    p->rChild=temp->lChild;
    temp->lChild=p;
    p=temp;
}

// tΪ���Ķ�������������ƽ����ת����
void BST::leftBalance(BiNode *&t)
{
     BiNode *temp=t->lChild;
     switch(temp->bf){
     	case 1:
     		t->bf=0;
     		temp->bf=0;
     		rRotate(t);
     		break;
     	case -1:
     		BiNode *temp2=temp->rChild;
     		switch(temp2->bf){
     			case 1:
     				temp->bf=0;
     				t->bf=-1;
     				break;
     			case 0:
     				temp->bf=0;
     				t->bf=0;
     				break;
     			case -1:
     				temp->bf=1;
     				t->bf=0;
     				break;
			 }
			 temp2->bf=0;
			 lRotate(t->lChild);
			 rRotate(t);
	 }
}

// tΪ���Ķ�������������ƽ����ת����
void BST::rightBalance(BiNode *&t)
{
    BiNode *temp=t->rChild;
    switch(temp->bf){
    	case -1:
    		t->bf=0;
    		temp->bf=0;
    		lRotate(t);
    		break;
    	case 1:
    		BiNode *temp2=temp->lChild;
    		switch(temp2->bf){
    			case -1:
    				temp->bf=0;
    				t->bf=1;
    				break;
    			case 0:
    				temp->bf=0;
    				t->bf=0;
    				break;
    			case 1:
    				t->bf=0;
    				temp->bf=-1;
    				break;
			}
			temp2->bf=0;
			rRotate(t->rChild);
			lRotate(t);
	}
}


int BST::insertAVL(BiNode *&t, int key, bool &taller)
{

    if(!t){
    	t=new BiNode;
    	t->key=key;
    	t->lChild=NULL;
    	t->rChild=NULL;
    	t->bf=0;
    	taller=true;
	}else{
		if(t->key==key){
			taller=false;
			return 0;
		}
		if(t->key>key){
			if(!insertAVL(t->lChild,key,taller)){
				taller=false;
				return 0;
			}
			if(taller){
			    switch(t->bf){
				    case 1:
					    leftBalance(t);
					    taller=false;
					    break;
				    case 0:
					    taller=true;
					    t->bf=1;
					    break;
				    case -1:
					    taller=false;
					    t->bf=0;
					    break;
			    }
		    }
		}else{
			if(!insertAVL(t->rChild,key,taller)){
				taller=false;
				return 0;
			}
			if(taller){
				switch(t->bf){
					case 1:
						t->bf=0;
						taller=false;
						break;
					case 0:
						t->bf=-1;
						taller=true;
						break;
					case -1:
						rightBalance(t);
						taller=false;
						break;
				}
			}
		}
	}
	return 1;
}

void BST::inOrder(BiNode *p)
{
    if(p)
    {
        inOrder(p->lChild);
        cout << p->key << ':' << p->bf << ' ';
        inOrder(p->rChild);
    }

    return;
}

// ������������ʼ��
BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    root = NULL;
}

// ����Ԫ�ز���ƽ�⴦��
void BST::insertAVL(int key)
{
    bool taller = false;
    insertAVL(root, key, taller);
}


// �������
void BST::inOrder()
{
    inOrder(root);
}

int main(void)
{
    int t;
    cin >> t;
    while(t --)
    {
        // ��������ƽ���������ڲ���Ԫ��ʱ��ƽ�⴦�� 
        int n, elem;
        cin >> n;
        BST tree;
        while(n --)
        {
           cin >> elem;
           tree.insertAVL(elem);
        }
        tree.inOrder();
        cout << endl;
    }

    return 0;
} 

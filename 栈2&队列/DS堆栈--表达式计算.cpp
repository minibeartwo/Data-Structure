#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<stack> // ʹ��C++�Դ���STLջ
using namespace std;

#define OK 0
#define ERROR -1
#define OVERFLOW -1
#define OPSETSIZE 7 // ������ż��ϳ��ȣ�Ŀǰֻ��7������
typedef int Status;
char Prior[7][7] = {
    '>', '>', '<', '<', '<', '>', '>',
    '>', '>', '<', '<', '<', '>', '>',
    '>', '>', '>', '>', '<', '>', '>',
    '>', '>', '>', '>', '<', '>', '>',
    '<', '<', '<', '<', '<', '=', ' ',
    '>', '>', '>', '>', ' ', '>', '>',
    '<', '<', '<', '<', '<', ' ', '='
};
float Operate(float a, unsigned char theta, float b){
	if(theta=='*'){
		return a*b;
	}else if(theta=='/'){
		return a/b;
	}else if(theta=='+'){
		return a+b;
	}else if(theta=='-'){
		return a-b;
	}else{
		return -1;
	}
}
char OPSET[OPSETSIZE] = {'+', '-', '*', '/', '(', ')', '#'}; // ���������
int In(char Test, char* TestOp){
	for(int i=0;i<7;i++){
		if(Test==TestOp[i]){
			return 1;
		}
	}
	return 0;
}
char precede(char Aop, char Bop){
	int i,j;
	for(i=0;i<7;i++){
		if(OPSET[i]==Aop){
			for(j=0;j<7;j++){
				if(OPSET[j]==Bop){
					return Prior[i][j];
				}
			}
		}
	}
	return -1;
}
float EvaluateExpression(string MyExp)
{
    // �������ʽ��ֵ����������㷨��
    // ��OPTR��OPND�ֱ�Ϊ�����ջ��������ջ��OPΪ��������ϡ�
    stack<char> OPTR;   // �����ջ���ַ�Ԫ��
    stack<double> OPND; // ������ջ��ʵ��Ԫ��
    char TempData[20];
    double Data, a, b;
    char theta, Dr[2];
    char c;
    int i = 0; // ���ڿ����ַ�����λ���ƶ�
    // InitStack(OPTR); InitStack(OPND); ���д�������ȥ��
    // Push(OPTR, '#'); c = MyExpression; ԭ�е����д������Ϊ��������
    OPTR.push('#');
    c = MyExp[0];
    strcpy(TempData, "\0");
    while(c != '#' || OPTR.top() != '#')
    {
        if(!In(c, OPSET))
        {
            // ������ַ�������������� 1 ������
            Dr[0] = c;
            Dr[1] = '\0';
            strcat(TempData, Dr);
            c = MyExp[++i]; // ����һ���ַ�
            if(In(c, OPSET))
            {
                Data = (float)atof(TempData);
                OPND.push(Data);
                strcpy(TempData, "\0");
            }
        }
        else
        {
            // �����������ʼ���м���
            switch(precede(OPTR.top(), c))
            {
                case '<':   // ջ��Ԫ������Ȩ��
                    OPTR.push(c);
                    c=MyExp[++i];
                    break;
                case '=':   // �����Ų�������һ�ַ�
                    // Pop(OPTR, x);
                    OPTR.pop();
                    c=MyExp[++i];
                    // ........������һ�����Ϊ1-2��c++����
                    // ........����һ���ַ�
                    break;
                case '>':   // ��ջ������������ջ
                theta=OPTR.top();
                OPTR.pop();
                b=OPND.top();
                OPND.pop();
                a=OPND.top();
                OPND.pop();
                OPND.push(Operate(a,theta,b));
                    // Pop(OPTR, theta);
                    // Pop(OPND, b);
                    // Pop(OPND, a);
                    // Push(OPND, Operate(a, theta, b));
                    // ........�������ľ��������7-8��c++����
                    break;
            } // end switch
        }   // end else
    }   // end while
    return OPND.top();
    // ........������һ�����Ϊһ��c++����
}   // end function
int main()
{
    string Exp;
    int t;
    double result;
    cin >> t;
    while(t --)
    {
        cin >> Exp;
        result = EvaluateExpression(Exp);
        cout << fixed << setprecision(4) << result << endl;
    }
    return 0;
}

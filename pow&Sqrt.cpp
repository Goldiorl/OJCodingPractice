POW: һ����Ѫ�����

class Solution {
public:
    double pow(double x, int n) {
        //x^n = x*x*x...x;
        //Divide and conquer:
        if(n==0) return 1;
        if(n==1) return x;
        
        //Trick: INT_MAX ȡ������INT_MAX������
        //���������INT_MAX��������������һ��ֱ��2�֣��������ж������ĺ����У���leetcode����������)����
        //��ʱͨ��2�ֽ��⣬���ȷʵ��������pow(x,-n) ����Ȼ֮ǰ�Ǹ����� 
        //https://leetcode.com/discuss/15202/00000-2147483648-test-case-failed-code-passed-another-code
        if( n == INT_MIN ) return 1.0/(pow(x, -n+1)*x);
        if(n<0)  return 1.0/pow(x,-n);
        
        double result = pow(x, n/2);
        double ret = result*result;
        if( n&1 )  ret*=x;
        return ret;
    }
};


SQRT:
Important divide and conquer:

class Solution {
public:
    int sqrt(int x) {
        //Make sure you know what's been asked in the question.
        //That is to define the question using english
        if(x==0) return 0;
        int left=0, right=x;
        int mid = (left+right)/2;
        if(x<2) return x;
        int biggest_less_than_answer = mid;
        while( left != right ){
        	//IMPORTANT
        	//WHEN USING DICHOTOMY TEMPLATE
        	//PUT THE MID CALCULIATION HERE INSIDE THE LOOP!
            if( (1.0*x)/mid >mid){
                left = mid +1 ;
                biggest_less_than_answer = mid;
            }else{
                right = mid ;
            }
            //dichotomy can use the exact case to prune. Efficient!
            
            mid =(left+right)/2;
        }
        return (x==mid*mid)? mid: biggest_less_than_answer ;
        
    }
};

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string str1,str2;
        int min1 = min(a,b);
        int left = max(a-min1,b-min1);
        if(a>=b){
            int m1=a,m2=b;
            while(str1.size()!=a+b){
                if(left>0) {
                    if(m2>0) {str1+="aab";m2-=1;m1-=2;}
                    else if(m1>=2) {str1+="aa";m1-=2;}
                    else if(m1>=1) {str1+='a';m1-=1;}
                    left--;
                }
                else if(m2>0) {str1+="ab";m2--;m1--;}
                else {str1+='a';m1--;}
            }
            return str1;
        }
        else{
            int m1=a,m2=b;
            while(str2.size()!=a+b){
                if(left>0) {
                    if(m1>0) {str2+="bba";m1-=1;m2-=2;}
                    else if(m2>=2) {str2+="bb";m2-=2;}
                    else if(m2>=1) {str2+='b';m2-=1;}
                    left--;
                }
                else if(m1>0) {str2+="ba";m1--;m2--;}
                else {str2+='b';m2--;}
            }
            return str2;
        }
    }
};

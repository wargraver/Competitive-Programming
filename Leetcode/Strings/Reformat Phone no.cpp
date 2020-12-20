class Solution {
public:
    string reformatNumber(string number) {
         string str2;int i,j;
        for(i=0;i<number.size();i++){
             if(number[i]==' ' || number[i]=='-') continue;
             else str2+=number[i];
             }
        string str3;
       int m=str2.size()%3;
        if(str2.size()==2) return str2;
        else if(str2.size()==3) return str2;
        else if(str2.size()==4){
              string str4;
            str4+=str2[0];str4+=str2[1];str4+='-';str4+=str2[2];str4+=str2[3];
            return str4;
        }
        if(m==0){
            int ct=0;
            for(i=0;i<str2.size();i++){
                if(ct==3) {str3+='-';i--;ct=0;}
                else {str3+=str2[i];ct++;}
            }
        }
        else if(m==1){
            int ct=0;
            for(i=0;i<str2.size()-4;i++){
                if(ct==3) {str3+='-';i--;ct=0;}
                else {str3+=str2[i];ct++;}
            }
            int n=str2.size();
            str3+='-';
            str3+=str2[n-4];str3+=str2[n-3];str3+='-';str3+=str2[n-2];str3+=str2[n-1];
        }
        else if(m==2){
            int ct=0;
            for(i=0;i<str2.size()-2;i++){
                if(ct==3) {str3+='-';i--;ct=0;}
                else {str3+=str2[i];ct++;}
            }
            int n=str2.size();
            str3+='-';
            str3+=str2[n-2];str3+=str2[n-1];
          }
        return str3;
    }
};

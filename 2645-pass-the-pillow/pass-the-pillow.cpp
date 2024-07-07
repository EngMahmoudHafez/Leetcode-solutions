class Solution {
public:
    int passThePillow(int n, int time) {
        bool dir=true;
        int p=1,end=n;
        while(time--){
            if(dir)p++;
            else p--;
            if(p==end) dir=false;
            if(p==1) dir=true;
            cout<<p<<" ";
        }

        return p;


    }
};
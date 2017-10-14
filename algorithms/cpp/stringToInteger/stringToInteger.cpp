/*
 * stupid problem, see description on website
 */
class Solution {
public:
    int myAtoi(string str) {
        transform(str.begin(), str.end(),str.begin(), ::toupper);
        const char * p = str.c_str();
        bool is_negative = false;
        uint64_t r = 0;
        int res=0;
        int radix = 10;
        //limits:not start with 0; all characters are digit num; first character can be '-'
        while(*p!=NULL){
            if(*p==' '){
                p++;
                continue;
            }
            break;
        }
        if(*p == '-'){
            is_negative = true;
            p++;
        }else if(*p == '+')
            p++;
        cout<<"begin with :"<<*p<<endl;
        
        const char *p2 = p;
        while(*p2 != NULL){
            if(*p2 >'9' || *p2 < '0'){                
                cout<<"invalide string:"<<(int)*p2<<"p="<<(int)(*p)<<endl;
                break;
                //return 0;
            }
            p2++;
        }
        cout<<"p="<<*p<<",p2="<<*p2<<endl;
        while(p<p2){
            int ip=(int)(*p-48);
            r = r*radix + ip;
            if(r>INT_MAX)
                if(!is_negative)
                    return INT_MAX;
                else if(-r < INT_MIN)
                    return INT_MIN;
            cout<<bitset<36>(r)<<endl;
            res = r;
            cout<<"res="<<res<<endl;
            p++;
        }
        if(is_negative)
            return -res;
        return res;
    }
};

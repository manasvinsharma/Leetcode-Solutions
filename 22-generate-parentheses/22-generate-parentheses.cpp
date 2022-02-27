class Solution {
public:
    vector<string>ans;
    void fun(int &n, int open, int end, string str)
    {
        if(open==0 && end==0)
        {
            ans.push_back(str);
            return ;
        }
        
        if(open==0)
        {
            str+=')';
            end--;
            fun(n,open,end,str);
        }
        else if(open==end)
        {
            str+='(';
            open--;
            fun(n,open,end,str);
        }
        else if(open<end)
        {
            string str1=str,str2=str;
            str1+='(';
            str2+=')';
            fun(n,open-1,end,str1);
            fun(n,open,end-1,str2);
        }
        
        return ;
    }
    
    vector<string> generateParenthesis(int n) {
        string str="";
        fun(n,n,n,str);
        return ans;
    }
};
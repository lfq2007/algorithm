#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e,f;
    cin >> n;
    char c = '0';
    char s[100], b[100];
    for(int i = 0; i < n; i++){
        cin >> b;
        if(b[0] <= 'z' && b[0] >= 'a'){
            c = b[0];
            cin >> e >> f;
        }
        else{
            sscanf(b,"%d",&e);
            cin >> f;
        }
        memset(s,0,sizeof(s));
	    if(c == 'a')
		    sprintf(s,"%d+%d=%d",e,f,e+f);
	    else if(c == 'b')
	    	sprintf(s,"%d-%d=%d",e,f,e-f);
	    else if(c == 'c')
	    	sprintf(s,"%d*%d=%d",e,f,e*f);
        cout << s << endl << strlen(s) << endl;    
        
    }
    return 0;
}
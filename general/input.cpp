void readInt(int &n){
    int sign = 1;
    char c;
    bool found = false;
    n = 0;
    
    while(true){
    	c = getc(stdin);
    	
        switch(c){
            case '-' :
                sign = -1;
                found = true;
                break;
            case ' ':
                if(found) goto jump;
                break;
            case '\n':
                if(found) goto jump;
                break;
            default:
                if(c>='0' && c<='9'){
                    n = n*10+c-'0';
                    found = true;
                }else goto jump;
                break;
        }
    }
    
    jump:
        n *= sign;
}

struct Scanner{
    char* curPos;
    
    Scanner(){
        const int MAX_SIZE = 6000000;
        static char input[MAX_SIZE];
        
        fread(input, 1, sizeof(input), stdin);
        curPos = input;
    }
    
    int nextInt(){
        while(*curPos<'-') ++curPos;
        
        bool neg = false;
        if(*curPos == '-'){
            neg = true;
            ++curPos;
        }
        
        int ret = 0;
        while(*curPos>='0'){
            ret = ret*10 + (*curPos)-'0';
            ++curPos;
        }
        
        if(neg) ret = -ret;
        return ret;
	}
	
	char nextChar(){
        while(*curPos<'A') ++curPos;		
        return *curPos++;
    }
};

//Leer varios carácteres indicados : scanf("%*[\r\n ]");

#include <stdio.h>
#include <stdlib.h>


void analyse(char* tokens,int len,int loops[500][2],int lenLoops){
    char array[30000];
    int ptr = 0;
    char input;
    int findPos;
    for(int i = 0;i < 30000;i++){
        array[i] = 0;
    }
    
    for(int i = 0; i < len;i++){
        
        switch (tokens[i]){
         
        case '>':
            ptr++;
            break;
        case '<':
            ptr--;
            break;
        case '+':
            array[ptr] + 1 > 255? array[ptr] = 0 : array[ptr]++;
            break;    
        case '-':
            array[ptr] - 1 < 0? array[ptr] = 255 : array[ptr]--;
            break;
        case '.':
            printf("%c",array[ptr]);
            break;
        case ',':
            scanf(" %c",&input);
            array[ptr] = input;
            break;
        case '['://0     
            for(findPos = 0; findPos < lenLoops;findPos++){
                if(i == loops[findPos][0])
                   break;
            }    
                if(array[ptr] == 0)
                    i = loops[findPos][1];
            
            break;
        case ']'://1    
            for(findPos = 0; findPos < lenLoops;findPos++){
                if(i == loops[findPos][1])
                   break;
            }
            i = loops[findPos][0] - 1;
            break;
          
        default:
            break;
        }
        if (ptr > 29999 || ptr < 0 ){
            printf("error: invalid ptr");
            break;
        }
        
    }
    printf("\n");
}

int main(int argc, char** argv){
    if(argc != 2){
        printf("invalids arguments");
        return 1;
    }
    char tokens[500];
    FILE* ptr;
    
    ptr = fopen(argv[1],"r");
    if(NULL == ptr){
        printf("file can not be open");
        return 1;
    }
    char ch;
    int pos = 0;
    int loops[500][2];
    int open = 0;
    int close = 0;
    int len = 0;
    while(ch != EOF){
        ch = fgetc(ptr);
        if(ch == '>'|| ch == '<'||ch == '+'||ch == '-'||
           ch == '.'||ch == ','||ch == '['|| ch == ']'){
                tokens[pos] = ch;
                if(ch == '['){
                    open++;
                    loops[len++][0] = pos;
                }else if(ch == ']'){
                    close++;
                    loops[open - close][1] = pos;
                }
               pos++;
            }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    } 
    analyse(tokens,pos,loops,len);
    return 0;
}

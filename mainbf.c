#include <stdio.h>
#include <stdlib.h>


void analyse(char* tokens,int len){
    char array[30000];
    int ptr = 0;
    char input;
    int loopPos;
    int endloop;
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
            array[ptr]++;
            break;    
        case '-':
            array[ptr]--;
            break;
        case '.':
            printf("%c",array[ptr]);
            break;
        case ',':
            scanf(" %c",&input);
            array[ptr] = input;
            break;
        case '[':
            loopPos = i;
            if(array[ptr] == 0)
                i = endloop;
            
            break;
        case ']':    
            endloop = i;
            i = loopPos - 1;
            break;
          
        default:
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
    while(ch != EOF){
        ch = fgetc(ptr);
        if(ch == '>'|| ch == '<'||ch == '+'||ch == '-'||
           ch == '.'||ch == ','||ch == '['|| ch == ']'){
               tokens[pos++] = ch;
           }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    } 
    analyse(tokens,pos);
    return 0;
}
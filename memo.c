#include "mem.h"
//#include "libMemo.c"



void main(){
    //Declaring variables(not initialize in this same line)
    char ss[50],ss1[50];
    char h[5];

    so:
        printf("-h Show this help.\n");
        scanf("%s",h);
                    
            if(strcmp(h,"-h")==0){
                soo:
                //Giving various options help to choose from
                printf("\n\n-i\t\t\t\tInit a new empty database.\nmemo -i \"memo.csv\"\n\n"); 
                printf("-a\t\t\t\tAppend at the end of the database the following message.\nmemo -a \"This message will be included at the end of the database\"\n\n");
                printf("-s\t\t\t\tSearch and find specific entries in the database.\n memo -s will show all entries on the given date.\n\n");
                printf("-d\t\t\t\tDelete an entry in the database.\nmemo -d 123 will delete a entry number 123.\n\n"); 
                //getting input and removing whitespace
                    gets(ss);
                    //fgets(ss,50,stdin);
                        int i, len = 0,j; 
                        len = sizeof(ss)/sizeof(ss[0]);  
                        for(i = 0; i < len; i++){  
                            if(ss[i] == ' '){  
                                for(j=i;j<len;j++)
                            {  
                                ss[j]=ss[j+1];
                            }  
                            len--;
                            }//this part I wrote but its not belong to me  
                        }
                        //strcpy(command1,command);
                        printf("%s\n",ss);
                        //printf("%s\n",command1);
                        if(strcmp(ss,"memo-i\"memo.csv\"")==0){
                            new_file();                       
                        }
                        if(strcmp(ss,"memo-a")==0){
                            append();
                        }                       
                        if(strcmp(ss,"memo-s")==0){
                           find();
                        }
                        if(strcmp(ss,"memo-d")==0){
                            deletee();
                        }
                        else{
                        goto soo;
                        }
        }
        else{
            printf("Please try again!\n");
            goto so;
        }
}
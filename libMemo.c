#include "mem.h"

//This function makes a new file
void new_file(){
    FILE *ph = fopen("memo.csv", "w");
    fclose(ph);
}


int fun(){
    static int i;
    char message[100]="";
    char h[80],hh[80],bu[1000];
    bool keepreading=true;
    
    FILE *ph=fopen("memo.csv","r");
    while (keepreading){
        fscanf(ph,"%d,%s %s,%s",&i,hh,h,message);
        fgets(bu,1000,ph);
        if (feof(ph)){
        keepreading=false;
        }
    }
    i++;
    return i;
    fclose(ph);


}


int append(){
    char message[100]="";
    char h[80],hh[80],bu[1000];
    FILE *ph;

    while(message!=0){
        ph = fopen("memo.csv", "a");
        if(ph==NULL){
            printf("error\tcan't open file or the file doesn't exist\n");
            return 1;
        }
    
        printf("Please enter a message, enter | to save and quit\n");
        gets(&message);
        //fgets(message,100,stdin);
        if(strcmp(message,"|")==0){//this line can close the file!
        fclose(ph);
        exit(0);
        return 0;
        }
        //I gets the time part      
        time_t raw;
        struct tm *info;
        time(&raw);
        info = localtime(&raw);
        strftime(h,80,"%X", info);
        strftime(hh,80,"%x", info);
        //int p=fun();
        fprintf(ph,"%d,%s %s,%s\n",fun(),hh,h,message);
        fclose(ph);
        printf("\nNew entry is been done\n");
    }

}

void find(){
    char bu[1000],charr[50];
    int f;
    char hh[50],h[50],message[50];

    printf("\nEnter the keyword here>>");
    gets(&charr);
    FILE *pph = fopen("memo.csv", "r");
    bool keepreading = true;


    while(keepreading){

        fgets(bu,1000,pph);
        sscanf(bu,"%d,%s%s,%s",&f,hh,h,message);

        if(strstr(bu,charr)){
            //printf("%d,%s %s,%s",f,hh,h,message);
            // if(strcmp(bu,charr)!=0)
            printf("%s",bu);
                // if(strcmp(hh,charr)!=0)
                //     keepreading=false;
        }



        if(feof(pph))
            keepreading=false;
    }
    fclose(pph);
}


int deletee(){
    char str[200],date[50],message[200];
    FILE *pp,*ph;
    int id, i;
    printf("Which entry do you want to delete:\n");
    scanf("%d", &i);
    /*Fix bug:
        Debugged where the comma seperated values file got "double commas" in style: ,, after I deleted an entry 
        I used a normal file instead */
  
    pp=fopen("memo.csv","r");
    ph=fopen("tmp.txt","w");
        if(pp==NULL||ph==NULL){
            printf("Error opening file");
            return 1;
    }

    while(fgets(str,200,pp)){
        sscanf(str,"%d,%s,%s",&id,&date,&message);
        if(id != i)
            fprintf(ph,"%s",str);

    }
    fclose(pp);
    fclose(ph);

    remove("memo.csv");
    rename("tmp.txt","memo.csv");

    return 0;
    EXIT_SUCCESS;
}


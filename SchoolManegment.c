#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


bool addstudent(char first_name[],char last_name[], int roll_no,char Class[],char vill[],float per);
void studentrecord();
void searchstudent();
void delete();

  struct student {
    char first_name[20];
    char last_name[20];
    int roll_no;
    char Class[10];
     char vill[20];
    float per;
};

void main()
{
    
    int choice,roll;
    char ano,opt;
    while(choice!=5){

    system("cls");
    printf("\t\t\t=====STUDENT DATABASE MANAGEMENT SYSTEM=====");
    printf("\n\n\n\t\t\t\t     1. Add Student\n");
    printf("\t\t\t\t     2. Students Records\n");
    printf("\t\t\t\t     3. Search Student\n");
    printf("\t\t\t\t     4. Delete Student\n");
    printf("\t\t\t\t     5. Exit\n");
    printf("\t\t\t\t    _____________________\n");
    printf("\t\t\t\t     ");
    scanf("%d",&choice);
    
   switch(choice){
       case 1:
        do{
                system("cls");
                
                bool flag=false;
                
                char first_name[20],last_name[20],Class[10],vill[20];
                int roll_no;
                float per;
              printf("\t\t\t\t=======Add Students Info=======\n\n\n");
              printf("\n\t\t\tEnter First Name     : ");
              scanf("%s",first_name);
              printf("\n\t\t\tEnter Last Name     : ");
              scanf("%s",last_name);
              printf("\n\t\t\tEnter Roll-No       : ");
              scanf("%d",&roll_no);
              printf("\n\t\t\tEnter Class(course) : ");
              scanf("%s",Class);
              printf("\n\t\t\tEnter Address       : ");
              scanf("%s",vill);
              printf("\n\t\t\tEnter Percentage    : ");
              scanf("%f",&per);
              printf("\n\t\t\t______________________________\n");
              flag = addstudent(first_name,last_name,roll_no,Class,vill,per);
              if (flag == true)
              {
                printf("\t\t\tSuccesfully Done !!! \n\n");
              }

              printf("\t\t\tYou want to add another record?(y/n) : ");
              scanf("%c",&ano);
            }while((getchar())=='y');
         break;
     case 2: 
        system("cls");
              studentrecord();
              while(true)
              {
                  printf("\n\t\t\t\t  press y to exit.....");
                  //getchar();
                  scanf("%c",&opt);
                  if(opt == 'y')
                  {
                    break;
                  } 
                  else
                  {
                    printf("\n\t\t\t\t  Invalid Input.....\n\n");
                  }
              }
        break;
        
     case 3:
        system("cls");
        do{

              printf("\t\t\t\t=======Search Student=======\n\n\n");
               printf("\n\t\t\tEnter the Roll No     : ");
              scanf("%d",&roll);

              searchstudent(roll);

              while(opt != 'y')
              {
                  printf("\n\t\t\t\t  press y to exit.....");
                  printf("\n\t\t\t\t  press a to search again.....");
                  getchar();
                  scanf("%c",&opt);
                  if(opt == 'a')
                  {
                    system("cls");
                    break;
                  }
                  else
                  {
                    printf("\n\t\t\t\t  Invalid Input.....\n\n");
                  }   
              }
              
            }while(opt != 'y');
        break;
     case 4:
         system("cls");
         printf("\t\t\t\t=======DELETE STUDENTS RECORD=======\n\n\n");
         printf("\t\t\t\tEnter the roll no : ");
         scanf("%d",&roll);
         delete(roll);
         
         printf("\n\t\t\t\tPress any key to exit.......\n");
         getchar();
         scanf("%c",&opt);
         system("cls");
        break;
     case 5:
          system("cls");
          printf("\n\t\t\t\tThank you, for used this software.\n\n");
         // exit(0);
        break;
        
     default :
         system("cls");
         //getch();
         printf("\n\t\t\t\t\tEnter a valid number\n\n");
         printf("\t\t\t\tPress any key to continue.......");
       //  getch();
       // clrscr();
         break;
        }
  
        }
  
        //getch();
     }
    
 bool addstudent(char first_name[],char last_name[], int roll_no,char Class[],char vill[],float per){
   
     char another;
     FILE *fp;
     int n,i;
     struct student info;

       fp=fopen("information.txt","a"); //use can give any file name. Give the name with extention or without extention.
         
         strcpy(info.first_name,first_name);
         strcpy(info.last_name,last_name);
         info.roll_no = roll_no;
         strcpy(info.Class,Class);
         strcpy(info.vill,vill);
         info.per = per;
       
          if(fp==NULL){
            fprintf(stderr,"can't open file");
        }else{
            printf("\t\t\tRecord stored successfuly\n");
        }
        
        fwrite(&info, sizeof(struct student), 1, fp); 
        fclose(fp);
        
        return true;
}

 void studentrecord(){
   
     FILE *fp;

    struct student info;
    fp=fopen("information.txt","r");
    
     printf("\t\t\t\t=======STUDENTS RECORD=======\n\n\n");
      
    if(fp==NULL){
        
        fprintf(stderr,"can't open file\n");
        //exit(0);
    }else{
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t___________\n\n");
    }
        
        while(fread(&info,sizeof(struct student),1,fp)){
        printf("\n\t\t\t\t Student Name  : %s %s",info.first_name,info.last_name);
        printf("\n\t\t\t\t Roll NO       : %d",info.roll_no);
        printf("\n\t\t\t\t Class         : %s",info.Class);
        printf("\n\t\t\t\t Village/City  : %s",info.vill);
        printf("\n\t\t\t\t Percentage    : %f%",info.per);
        printf("\n\t\t\t\t ________________________________\n");
      
         }
        fclose(fp);
       // getch();
      
  }

void searchstudent(int roll_no){
       struct student info;
      FILE *fp;
      int found=0;
     
    fp=fopen("information.txt","r");
    
    
    
    while(fread(&info,sizeof(struct student),1,fp)>0){
         
        if(info.roll_no==roll_no){
           
        found=1;
        printf("\n\n\t\t\tStudent Name : %s %s",info.first_name,info.last_name);
        printf("\n\t\t\tRoll NO        : %d",info.roll_no);
        printf("\n\t\t\tClass          : %s",info.Class);
        printf("\n\t\t\tAddress        : %s",info.vill);
        printf("\n\t\t\tPercentage     : %f%",info.per);
        printf("\n\t\t\t______________________________________\n");
  
         }
       
    }
     
    if(!found){
       printf("\n\t\t\tRecord not found\n");
    }
  
    fclose(fp);
  // scanf("%c",getchar());
    
}


 void delete(int roll_no){
      struct student info;
      FILE *fp, *fp1;
     
       
    int found=0;
    
    fp=fopen("information.txt","r");
    fp1=fopen("temp.txt","w");
    
    if(fp==NULL){
         fprintf(stderr,"can't open file\n");
         //exit(0);
      }
    
    while(fread(&info,sizeof(struct student),1,fp)){
        if(info.roll_no == roll_no){
          
            found=1;
        
        }else{
           fwrite(&info,sizeof(struct student),1,fp1);
        }
  
    }
     fclose(fp);
     fclose(fp1);

    if(!found){
          printf("\n\t\t\t\tRecord not found\n");
        }
      if(found){ 
        printf("\n\t\t\t\tRecord deleted succesfully\n");
    remove("information.txt");
        rename("temp.txt","information.txt");
        
        
        }
 
  //getch();
  }

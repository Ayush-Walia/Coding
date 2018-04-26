/* ********************************************Warning***************************************** */
/* This is meant ONLY for unix based systems like linux, Mac OS etc,It WILL misbehave on Windows*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

struct subscriber{
char phonenumber[20],name[50],phonenumber2[20];
int time;
float amount;
}s;

void t(int time){
    if (time > 3600) {
			   double hour = time/3600;
			   int hours = (int) hour;
			   double min = (time/60)%60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   printf("%d hours %d mins %d secs",hours,mins,secs);
		   } else if (time > 60) {
			   double min = time/60;
			   int mins = (int) min;
			   double sec = time%60;
			   int secs = (int) sec;
			   printf("%d mins %d secs",mins,secs);
		   }
		   else {
			   int secs = (int) time;
               printf("%d secs",secs);}
}
void addrecords(struct subscriber *s){
  char key[1];
  while(1){
  FILE *f;
  f=fopen("bill.txt","a+");
  if(f==NULL){
    f=fopen("bill.txt","w+");
    }
    system("clear");
    printf("Enter name:");
    scanf("%s",s->name);
    fprintf(f,"%s ",s->name);
    printf("\nEnter phone number:");
    scanf("%s",s->phonenumber);
    fprintf(f,"%s ",s->phonenumber);
    printf("\nEnter number of Reciever:");
    scanf("%s",s->phonenumber2);
    fprintf(f,"%s ",s->phonenumber2);
    printf("\nEnter Time Duration of Call:");
    scanf("%d",&s->time);
    fprintf(f,"%d ",s->time);
    printf("\nEnter Call Charge:");
    scanf("%f",&s->amount);
    fprintf(f,"%.2f\n",s->amount);
    fclose(f);
    system("clear");
    printf("Record successfully added");
    printf("\nDo you want to add more records(y/n): ");
    scanf("%s",key);
    if(key[0]=='n'){
            system("clear");
            break;
        }
    }
}
void listrecords(struct subscriber *s){
  FILE *f;
  int i;
  char key[1];
  if((f=fopen("bill.txt","r"))==NULL){
    system("clear");
    printf("File Doesn't Exists\n");
    }
    else{
    system("clear");
    printf("Records:\n\n");
    printf("User Name\tPhone Number\tReciever Number\t     Call Duration\tCall Charge\n");
    for(i=0;i<88;i++){
    printf("-");}
    i=5;
    while((fscanf(f,"%s %s %s %d %f",s->name,s->phonenumber,s->phonenumber2,&s->time,&s->amount))!=-1){
    printf("\n%s",s->name);
    gotoxy(i,17);
    printf("%s",s->phonenumber);
    gotoxy(i,33);
    printf("%s",s->phonenumber2);
    gotoxy(i,54);
    t(s->time);
    gotoxy(i,73);
    printf("Rs %.2f /-",s->amount);
    i++;
    }
    printf("\n");
    for(i=0;i<88;i++){
    printf("-");}
    printf("\n\n");
    fclose(f);
    printf("Do you want to go back to Main Menu?(y/n):\n");
    scanf("%s",key);
    if(key[0]=='n')
    exit(0);
    else
    system("clear");
    }
}
void modifyrecords(struct subscriber *s){
  FILE *f,*t;
  int i=1,count=0,j=1;
  char key[1],name[20];
  if(((f=fopen("bill.txt","r"))==NULL) || (t=fopen("temp.txt","w+"))==NULL){
      printf("Error!! file can't be accessed.");
      exit(0);
    }
    else{
    system("clear");
    printf("Enter username to be modified:\n");
    scanf("%s",name);
    while((fscanf(f,"%s %s %s %d %f",s->name,s->phonenumber,s->phonenumber2,&s->time,&s->amount))!=-1){
        if(strcmp(s->name,name)==0){
          i=0;
          count++;
        }
        }
    rewind(f);
    system("clear");
    if(!i){
    printf("%d records found!!!",count);
    while((fscanf(f,"%s %s %s %d %f",s->name,s->phonenumber,s->phonenumber2,&s->time,&s->amount))!=-1){
        if(strcmp(s->name,name)==0){
        printf("\n\nFor %d Record:\n\n",j);
        printf("Enter name:");
        scanf("%s",s->name);
        fprintf(t,"%s ",s->name);
        printf("\nEnter phone number:");
        scanf("%s",s->phonenumber);
        fprintf(t,"%s ",s->phonenumber);
        printf("\nEnter number of Reciever:");
        scanf("%s",s->phonenumber2);
        fprintf(t,"%s ",s->phonenumber2);
        printf("\nEnter Time Duration of Call:");
        scanf("%d",&s->time);
        fprintf(t,"%d ",s->time);
        printf("\nEnter Call Charge:");
        scanf("%f",&s->amount);
        fprintf(t,"%.2f\n",s->amount);
        j++;
        }
        else{
          fprintf(t,"%s %s %s %d %.2f\n",s->name,s->phonenumber,s->phonenumber2,s->time,s->amount);
          }
      }
      remove("bill.txt");
      rename("temp.txt","bill.txt");
      system("clear");
      printf("Record successfully Updated!!!\n\n");
      fclose(f);
      fclose(t);
    }
    else{
        printf("User not found!!!\n\n");
        fclose(f);
    }
    printf("Do you want to go back to Main Menu?(y/n):\n");
    scanf("%s",key);
    if(key[0]=='n')
    exit(0);
    else
    system("clear");
    }
}
void deleterecords(struct subscriber *s){
      FILE *f,*t;
      int i=1;
      char name[20],key[1];
      if((t=fopen("temp.txt","w+"))==NULL){
      printf("Error!! temp.txt can't be accessed.");
      exit(0);}
      if((f=fopen("bill.txt","r"))==NULL){
      printf("Error!! bill.txt can't be accessed.");
      exit(0);}
      system("clear");
      printf("Enter the Name of the User to be deleted:\n");
      scanf("%s",name);
      while((fscanf(f,"%s %s %s %d %f",s->name,s->phonenumber,s->phonenumber2,&s->time,&s->amount))!=-1){
        if(strcmp(s->name,name)==0){
          i=0;
          continue;
        }
        else{
          fprintf(t,"%s %s %s %d %.2f\n",s->name,s->phonenumber,s->phonenumber2,s->time,s->amount);
          }
      }
      if(i==1){
        system("clear");
        printf("User \"%s\" not found\n\n",name);
        remove("temp.txt");
        fclose(f);
        fclose(t);
        printf("Do you want to go back to Main Menu?(y/n):\n");
        scanf("%s",key);
        if(key[0]=='n')
        exit(0);
        else
        system("clear");
      }
      else{
      remove("bill.txt");
      rename("temp.txt","bill.txt");
      system("clear");
      printf("User %s Successfully Deleted!!!!\n\n",name);
      fclose(f);
      fclose(t);
      printf("Do you want to go back to Main Menu?(y/n):\n");
      scanf("%s",key);
      if(key[0]=='n')
      exit(0);
      else
      system("clear");
      }
}
void payment(struct subscriber *s){
  FILE *f;
  int i=1,time=0;
  float sum;
  char key[1],name[20];
  if((f=fopen("bill.txt","r"))==NULL){
    system("clear");
    printf("File Doesn't Exists\n");
    }
    else{
    system("clear");
    printf("Enter username to generate bill:\n");
    scanf("%s",name);
    while((fscanf(f,"%s %s %s %d %f",s->name,s->phonenumber,s->phonenumber2,&s->time,&s->amount))!=-1){
        if(strcmp(s->name,name)==0){
          i=0;
          sum+=s->amount;
          time+=s->time;
        }
        }
    rewind(f);
    system("clear");
    if(!i){
    printf("Bill:\n\n");
    printf("User Name\tPhone Number\tTotal Call Duration     Total Charge\n");
    for(i=0;i<73;i++){
    printf("-");}
    i=5;
    while((fscanf(f,"%s %s %s %d %f",s->name,s->phonenumber,s->phonenumber2,&s->time,&s->amount))!=-1){
    if(strcmp(s->name,name)==0){
    printf("\n%s",s->name);
    gotoxy(i,17);
    printf("%s",s->phonenumber);
    gotoxy(i,33);
    t(time);
    gotoxy(i,58);
    printf("Rs %.2f /-",sum);
    i++;
    break;
      }
    }
    printf("\n");
    for(i=0;i<73;i++){
    printf("-");}
    printf("\n\n");
    fclose(f);
    }
    else{
        printf("User not found!!!\n\n");
        fclose(f);
    }
    printf("Do you want to go back to Main Menu?(y/n):\n");
    scanf("%s",key);
    if(key[0]=='n')
    exit(0);
    else
    system("clear");
    }
}
void searchrecords(struct subscriber *s){
  FILE *f;
  int i=1;
  char key[1],name[20];
  if((f=fopen("bill.txt","r"))==NULL){
    system("clear");
    printf("File Doesn't Exists\n");
    }
    else{
    system("clear");
    printf("Enter username to be searched:\n");
    scanf("%s",name);
    while((fscanf(f,"%s %s %s %d %f",s->name,s->phonenumber,s->phonenumber2,&s->time,&s->amount))!=-1){
        if(strcmp(s->name,name)==0){
          i=0;
          break;
        }
        }
    rewind(f);
    system("clear");
    if(!i){
    printf("Records:\n\n");
    printf("User Name\tPhone Number\tReciever Number\t     Call Duration\tCall Charge\n");
    for(i=0;i<88;i++){
    printf("-");}
    i=5;
    while((fscanf(f,"%s %s %s %d %f",s->name,s->phonenumber,s->phonenumber2,&s->time,&s->amount))!=-1){
    if(strcmp(s->name,name)==0){
    printf("\n%s",s->name);
    gotoxy(i,17);
    printf("%s",s->phonenumber);
    gotoxy(i,33);
    printf("%s",s->phonenumber2);
    gotoxy(i,54);
    t(s->time);
    gotoxy(i,73);
    printf("Rs %.2f /-",s->amount);
    i++;
      }
    }
    printf("\n");
    for(i=0;i<88;i++){
    printf("-");}
    printf("\n\n");
    fclose(f);
    }
    else{
        printf("User not found!!!\n\n");
        fclose(f);
    }
    printf("Do you want to go back to Main Menu?(y/n):\n");
    scanf("%s",key);
    if(key[0]=='n')
    exit(0);
    else
    system("clear");
    }
}

int main(){
    int choice;
    while (1){
    printf("\n\t################################################################");
    printf("\n\t#   ---WELCOME TO THE TELECOM BILLING MANAGEMENT SYSTEM---     #");
    printf("\n\t################################################################");
    printf("\n Choose any option:\n 1 : Add New Records.\n 2 : List of Records.");
    printf("\n 3 : Modify Records.\n 4 : Bill Generation.");
    printf("\n 5 : Search Records.");
    printf("\n 6 : Delete Records.\n 7 : Exit.\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        addrecords(&s);break;
      case 2:
        listrecords(&s);break;
      case 3:
        modifyrecords(&s);break;
      case 4:
        payment(&s);break;
      case 5:
        searchrecords(&s);break;
      case 6:
        deleterecords(&s);break;
      case 7:
        exit(0);
        break;
      default:
        system("clear");
        printf("Incorrect Input,Try again.\n");
    }
  }
}

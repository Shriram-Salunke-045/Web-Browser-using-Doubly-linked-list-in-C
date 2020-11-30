//Web-Browser-using-Doubly-linked-list-in-C

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
struct Node {
char url[63];
int sr_no ;
struct Node *prev;
struct Node *next;
};
typedef struct Node *node;
node accept(){
node temp;
int sr=1;
temp =(node)malloc(sizeof(struct Node));
printf("\n Enter the URL : ");
scanf("%s",temp->url);
temp->sr_no=sr;
temp->next=NULL;
temp->prev=NULL;
return(temp);
}
node insert_record(node head, int numOfUrls){
node new_node,temp;
new_node=accept();
new_node->sr_no = numOfUrls + 1;
if(head==NULL){
head =new_node;
return(head);
}
else{
temp = head;
while(temp->next!=NULL){
temp = temp->next;
}
temp->next=new_node;
new_node->prev=temp;
return (head);
}
}
void display(node head){
node temp= head;
int op;
if(head==NULL){
printf("\n X-X-X-X-X-XThere are no websites linked X-X-XX-X-X");
return ;
}
else{
while(temp!=NULL){
printf("\n--_------------------_");
printf("\n URL : %s",temp->url);
printf("\n SR.NO : %d",temp->sr_no);
char link[70] = "start ";
strcat(link, temp->url);
system(link);
printf("\n IF YOU WANT TO GO TO NEXT URL PRESS '1' OR TO PREVIOUS URL PRESS '2' OR PRESS '0' TO GO TO MENU ");
scanf("%d",&op);
if(op==1){
temp=temp->next;
}
if(op==2){
temp=temp->prev;
}
if(op==0){
return;
}
}
}
}
void modify_rec(node head){
node temp;
int num;
if(head==NULL){
printf("\n X-X-X-X-X-XThere are no websites linked X-X-XX-X-X");
return ;
}
printf("\n ENTER THE SERIAL NUMBER OF THE WEBSITE TO BE MODIFIED :");
scanf("%d",&num);
temp =head;
while(temp->next!=NULL && temp->sr_no!=num){ // to search the record
temp = temp->next;
 }
 if(temp==NULL){
 printf("\n WEBSITE NOT FOUND!!!!!!!\n");
 }
 else{
printf("\n--_------------------_");
 printf("\n THE SEARCHED WEBSITE IS FOUND : ");
 printf("\n Enter the url to be modified: ");
 scanf("%s",temp->url);
printf("\n <> YOUR URL IS MODIFIED <>");
printf("\n--_------------------_");
 }
}
node delete_rec(node head){
node temp,temp1,prev_temp;
int num;
printf("\n ENTER THE SERIAL NUMBER OF THE WEBSITE TO BE DELETED :");
scanf("%d",&num);
temp =head;
while(temp->next!=NULL && temp->sr_no!=num){
temp = temp->next;
 }
 if(temp==NULL){ //if it is a empty list
 printf("\n WEBSITE NOT FOUND!!!!!!!\n");
 return (head);
 }
 else{
 if(temp->prev==NULL){
 printf("\n THE SEARCHED WEBSITE IS FOUND IS : ");
 printf("\n--_------------------_");
 printf("\n URL : %s",head->url);
 printf("\n--_------------------_");
 printf("\n <> THIS WEBSITE IS DELETED <>");
 temp1=temp->next;
 temp->next=NULL;
 temp1->prev=NULL;
 free(temp);
 return(temp1); //returing new head
 }
 else if(temp->next==NULL){ //if it is the last node
 printf("\n THE SEARCHED WEBSITE IS FOUND IS : ");
 printf("\n--_------------------_");
 printf("\n URL : %s",temp->url);
 printf("\n--_------------------_");
 printf("\n <> THIS WEBSITE IS DELETED <>");
 temp1=temp->prev;
 temp1->next=NULL;
 temp->prev=NULL;
 free(temp); // releasing the memory
 return (head);
 }
 else{ //if it is the node in between
 printf("\n THE SEARCHED WEBSITE IS FOUND IS : ");
 printf("\n--_------------------_");
 printf("\n URL : %s",temp->url);
 printf("\n--_------------------_");
 printf("\n <> THIS WEBSITE IS DELETED <>");
 prev_temp=temp->prev;
 temp1=temp->next;
 prev_temp->next=temp1;
 temp->prev=NULL;
 temp1->prev=prev_temp;
 temp->next=NULL;
 free(temp);
 return (head);

 }
 }
}
void CloseTabs()
{
system("taskkill /F /IM MicrosoftEdge.exe");
system("TASKKILL /IM chrome.exe /F");
system("cls");
}
int main(){
int choice, numOfUrls = 0;
node head=NULL ;
do{
printf("\n ----_MENU---_-");
printf("\n 1.INSERT URL \n 2.DISPLAY URL \n 3.MODIFY RECORD \n 4.DELETE RECORD \n 5.CLOSE ALL TABS (Works only for Chrome and Edge) \n 0.EXIT");
printf("\n ENTER YOUR CHOICE : ");
scanf("%d",&choice);
switch(choice){
case 1:
 head=insert_record(head, numOfUrls);
numOfUrls++;
break;
case 2:
display(head);
break;
case 3:
modify_rec(head);
break;
case 4:
if(head==NULL)
printf("\n X-X-X-X-X-XThere are no websites linked XX-X-X-X-X");
else
{
head=delete_rec(head);
}
break;
case 5:
CloseTabs();
break;
default:
printf("Invalid Input!");
break;
}
}while(choice!=0);
return 0;
}

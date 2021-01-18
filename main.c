#include <stdio.h>
#include <stdlib.h>

typedef struct President President;
struct President {
    char fname[15];
    char lname[15];
    int votes;
    President *next;
};

typedef struct voter voter;
struct voter {
    char CIN[10];
    int isVoted ;
    voter *next;
};

typedef struct Listvoters Listvoters;
struct Listvoters {
    voter *start;
};



typedef struct ListPresidents ListPresidents;
struct ListPresidents {
    President *First;
};

//motioned functions :
int CurrNumberOfP(ListPresidents *);
void getAllPresidents(ListPresidents *);
int duplicateP(ListPresidents *,President *);
void AddPresident(ListPresidents *,int );
int duplicateV(Listvoters *,voter *);
int checkCin(char []);
void AddVoter(Listvoters *,int );
void getAllVoters(Listvoters *);
int CurrNumberOfv(Listvoters *);
int PreTour(ListPresidents *,Listvoters *);
voter *VoterInList(Listvoters *,char []);
void vote(ListPresidents *,voter * );
int getTheresultPre(ListPresidents *,Listvoters *);
int CurrNotVoted(Listvoters *);
int sign(float );
void restartVote(Listvoters *,ListPresidents *);
void DelExluP(ListPresidents *,Listvoters *);
int getTheresultSec(ListPresidents *,Listvoters *);
int SecTour(ListPresidents *,Listvoters *);
void restartVoters(Listvoters *);
void DelExluS(ListPresidents *,Listvoters *,int );
int Final(ListPresidents *,Listvoters *);
int getTheresultFinal(ListPresidents *,Listvoters *);
void DelExluFinal(ListPresidents *,Listvoters *,int );






int main()
{

    ListPresidents *PList = (ListPresidents*)malloc(sizeof(ListPresidents));
    PList->First=NULL;

    Listvoters *VList = (ListPresidents*)malloc(sizeof(ListPresidents));
    VList->start = NULL;
    int res=0;
    int re=0;
    while(re==0){
    int i,nb,ch;
    printf("\t\t\t\t=> welcome To the Elections Of 2021 <= \n\n");
    printf("\t\t 1 - Add new Nominated Presidents to the List : \n");
    printf("\t\t 2 - The current List of Presidents nominated : \n");
    printf("\t\t 3 - Add new voter to the List : \n");
    printf("\t\t 4 - The current List of Voters : \n");
    printf("\t\t 5 - Start the first Tour : \n");
    printf(" \n\t\t Select : ");
    scanf("%d",&ch);


            switch(ch){
            case 1:
                printf("\n\n\t\tWhat is the number of nominated President that you want to add : ");
                scanf("%d",&nb);
                if(PList->First == NULL  ){
                    while(nb<5){
                        printf("\n\n\t\tThe min number of the Presidents nominated is 5  : ");
                        scanf("%d",&nb);
                    }
                }else{
                    printf("\n\t\tAdd more Presidents  ======> \n");

                }
                AddPresident(PList,nb);
                printf("\n\n\t'0' to go back to list '1' to exit :");
                scanf("%d",&re);
                ch=0;
                system("cls");
                break;
            case 2:
                getAllPresidents(PList);
                printf("\t'0' to go back to list '1' to exit :");
                scanf("%d",&re);
                ch=0;
                system("cls");
                break;
            case 3:
                printf("\n\n\t\tWhat is the number of Voters that you want to add : ");
                scanf("%d",&nb);
                if(VList->start == NULL  ){
                    while(nb<10){
                        printf("\n\n\t\tThe min number of the Voters  is 10  : ");
                        scanf("%d",&nb);
                    }
                }else{
                    printf("\n\t\tAdd more Voters  ======> \n");
                }
                AddVoter(VList,nb);
                printf("\t'0' to go back to list '1' to exit :");
                scanf("%d",&re);
                ch=0;
                system("cls");
                break;
            case 4:
                getAllVoters(VList);
                printf("\t'0' to go back to list '1' to exit :");
                scanf("%d",&re);
                ch=0;
                system("cls");
                break;
            case 5:
                res=0;
                while(res == 0){
                    res = PreTour(PList,VList);
                }
                if(res == 2){
                    printf("\n\t ====>Round One Completed start the second round by clicking 1 : ");
                    scanf("%d",&re);
                    DelExluP(PList,VList);
                    restartVoters(VList);
                }
                ch=0;
                system("cls");
                break;
            default:
                re=0;
                system("cls");
            }





        while( re==1){
            int ch;
        printf("\t\t\t\t=> welcome To the Elections Of 2021 <= \n\n");
        printf("\n\t\t 1 -Presidents That rest in Elections : ");
        printf("\t\t 2 - The current List of Voters :");
        printf("\n\t\t 3- starting The second round :");
        printf(" \n\t\t Select : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                getAllPresidents(PList);
                printf("\t\t'1' to the second round list:\n\t\t'0' to go back to main list :\n\t\t'3' to exit :");
                scanf("%d",&re);
                ch=0;
                system("cls");
                break;
            case 2:
                getAllVoters(VList);
                printf("\t'1' to the second round list '3' to exit :");
                scanf("%d",&re);
                ch=0;
                system("cls");
                break;
            case 3:
                res=0;
                while(res == 0){
                    res = SecTour(PList,VList);
                }
                if(res == 1){
                    printf("\n\t ====>Round Two Completed start the third round by clicking 2 : ");
                    scanf("%d",&re);
                    restartVoters(VList);
                }
                ch=0;
                system("cls");
                break;


        }


    }

    while( re==2){
            int ch;
        printf("\t\t\t\t=> welcome To the Elections Of 2021 <= \n\n");
        printf("\n\t\t 1 -Presidents That Rest in The Elections : ");
        printf("\t\t 2 - The current List of Voters :");
        printf("\n\t\t 3- starting The Final round :");
        printf(" \n\t\t Select : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                getAllPresidents(PList);
                printf("\t\t'2' to the Third round list:\n\t\t'0' to go back to main list :\n\t\t'3' to exit :");
                scanf("%d",&re);
                ch=0;
                system("cls");
                break;
            case 2:
                getAllVoters(VList);
                printf("\t'1' to the second round list '3' to exit :");
                scanf("%d",&re);
                ch=0;
                system("cls");
                break;
            case 3:
                res=0;
                while(res == 0){
                    res = Final(PList,VList);
                }
                if(res == 2){
                    printf("\n\t ====>Elections End Exit the by clicking on '3' : ");
                    scanf("%d",&re);
                }
                ch=0;
                system("cls");
                break;


        }


    }


    }





}



//functions :

int CurrNumberOfP(ListPresidents *list){
    int count=0;
    President *tmp=list->First;
    while(tmp!=NULL){
        count++;
        tmp=tmp->next;
    }
    return count;
}
int CurrNumberOfv(Listvoters *list){
    int count=0;
    voter *tmp=list->start;
    while(tmp!=NULL){
        count++;
        tmp=tmp->next;
    }
    return count;
}

int CurrNotVoted(Listvoters *list){
    int count=0;
    voter *tmp=list->start;
    while(tmp!=NULL){
        if( tmp->isVoted==0){
            count++;
        }
        tmp=tmp->next;
    }
    return count;
}

void getAllPresidents(ListPresidents *list){
    President *tmp=list->First;
    while(tmp!=NULL){
        printf("%s %s\n",tmp->fname,tmp->lname);
        tmp = tmp->next;
    }

}

int duplicateP(ListPresidents *list,President *nv){
    President *tmp=list->First;
    while(tmp!=NULL){

        if(strcmp(nv->fname,tmp->fname) == 0 && strcmp(nv->lname,tmp->lname) == 0){
            return 0;
        }
        tmp=tmp->next;
    }
    return 1;
}

int duplicateV(Listvoters *list,voter *nv){
    voter *tmp=list->start;
    while(tmp!=NULL){

        if(strcmp(nv->CIN,tmp->CIN) == 0){
            return 0;
        }
        tmp=tmp->next;
    }
    return 1;
}



void AddPresident(ListPresidents *list,int nb){
    char fname[15],lname[15];
    int i=0;
    for(i=0;i<nb;i++){
        printf("\n\n\t\t============> Adding the Nominated President number %d:",CurrNumberOfP(list)+1);
        printf("\n\t\tTHE First name :",i+1);
        scanf("%s",fname);
        printf("\t\tTHE Last Name :",i+1);
        scanf("%s",lname);
        //creating the new President :
        President *nv = (President*)malloc(sizeof(President));
        strcpy(nv->fname,fname);
        strcpy(nv->lname,lname);
        nv->votes = 0;
        nv->next = NULL;

        //checking the new President :
        if(duplicateP(list,nv) == 0){
            printf("\n\t\t===>Sorry the President '%s %s' Already in the List",nv->fname,nv->lname);
            i--;
        }else{
                if(list->First == NULL){
                list->First = nv; // the list already empty
            }else{
                //List not empty
                President *currentPresident = list->First;
                //going to the end of list
                while(currentPresident->next!=NULL){
                    currentPresident = currentPresident->next;
                }
                //adding the new nominated to the list
                currentPresident->next = nv;
                }

        } ;
    }
}

//CIN checker :
int checkCin(char cin[10]){
    int i,checker=0;
    if(isalpha(cin[1])){
    for(i=2;i<strlen(cin);i++){
            int a=cin[i];
           if(!isalpha(cin[0])  ||  (a<48 || a>57)){
                return 0;
            }
        }
    }else{
            for(i=1;i<strlen(cin);i++){
            int a=cin[i];
            if(!isalpha(cin[0])  || (a<48 || a>57)){
                return 0;
                }
            }
        }
    return 1;
}


//adding new voter :
void AddVoter(Listvoters *vlist,int nb){
    char CIN[10];
    int i=0,ch=0;

    for(i=0;i<nb;i++){
        printf("\n\n\t\t============> Adding the Voter number %d:",CurrNumberOfv(vlist)+1);
        printf("\n\t\tEnter The CIN :");
        scanf("%s",CIN);

        //checking CIN :
        int ch = checkCin(CIN);
        while(ch==0){
            printf("\n\t\t The form of the Right CIN is like 'ZT233083' or 'R215698' :");
            scanf("%s",CIN);
            ch = checkCin(CIN);
        }
        if( isalpha(CIN[0])){
            CIN[0]=toupper(CIN[0]) ;
        }
        if(isalpha(CIN[1])){
            CIN[1]=toupper(CIN[1]) ;
        }
        voter *nv=malloc(sizeof(voter));
        nv->next=NULL;
        nv->isVoted = 0;
        strcpy(nv->CIN,CIN);

         //checking the new Voter :
        if(duplicateV(vlist,nv) == 0){
            printf("\n\t\t===>Sorry the Voter %s Already in the List",nv->CIN);
            i--;
        }else{
            if(vlist->start == NULL){
                vlist->start = nv; // the list already empty
            }else{
                //List not empty
                voter *currentPresident = vlist->start;
                //going to the end of list
                while(currentPresident->next!=NULL){
                    currentPresident = currentPresident->next;
                }
                //adding the new nominated to the list
                currentPresident->next = nv;
                }

        } ;

    }

}


void getAllVoters(Listvoters *l){
    voter *tmp=l->start;
    while(tmp!=NULL){
        printf("%s\n",tmp->CIN);
        tmp=tmp->next;
    }

}

voter *VoterInList(Listvoters *list,char cin[10]){
    voter *tmp=list->start;
    while(tmp!=NULL){
        if(strcmp(cin,tmp->CIN) == 0){
            return tmp;
        }
        tmp=tmp->next;
    }

    return NULL;
}

void vote(ListPresidents *Plist,voter *currVoter){
    if(currVoter->isVoted == 0){
    int j=1,voted=0,i=1;
    President *tmp=Plist->First;
    while(tmp!=NULL){
        printf("\n\t\t =>[%d] - President %s %s",j,tmp->lname,tmp->fname);
        tmp=tmp->next;
        j++;
    }

    printf("\n\t\t\tYOU VOTE FOR ? : ");
    scanf("%d",&voted);
    tmp=Plist->First;
    while(i<voted){
        tmp=tmp->next;
        i++;
    }
    tmp->votes++;
    currVoter->isVoted = 1;
    }else{
        printf("\n\t\t ===>You Can Vote just one time !!!");
    }
}

int PreTour(ListPresidents *Plist,Listvoters *Vlist){
    voter *currentVoter = Vlist->start;
    President *currentPresident = Plist->First;
    char cin[10],i;
    int notVoted = CurrNotVoted(Vlist);
    printf("\n%d\n",notVoted);
    system("cls");
    printf("\n\t\t==> The First Round Of Elections <==");
    for(i=0;i<notVoted;i++){
        printf("\n\t\tPlease verify Your Identity (Enter your CIN) :");
        scanf("%s",cin);

        if( isalpha(cin[0])){
                cin[0]=toupper(cin[0]) ;
            }
        if(isalpha(cin[1])){
                cin[1]=toupper(cin[1]) ;
            }
        voter *inList = VoterInList(Vlist,cin);
        if(inList==NULL){
            printf("\n\t\t====>You are not In the List Please Verify you CIN or sign up First ");
            i=i-1;
        }else{
            printf("\n\t\tWelcome Again %s Please Vote for your President : ",inList->CIN);
            if(inList->isVoted==1){
                i--;
            }


            vote(Plist,inList);

        }
    }
    int res= getTheresultPre(Plist,Vlist);
    if(res == 0){
        restartVote(Vlist,Plist);
        return 0;

    }else if(res == 1){
        return 1;
    }else{
    return 2;
    }
}



int SecTour(ListPresidents *Plist,Listvoters *Vlist){
    voter *currentVoter = Vlist->start;
    President *currentPresident = Plist->First;
    char cin[10];
    int i;
    int notVoted = CurrNotVoted(Vlist);
    printf("\n%d\n",notVoted);
    system("cls");
    printf("\n\t\t==> The Second Round Of Elections <==");
    for(i=0;i<notVoted;i++){
        printf("\n\t\tPlease verify Your Identity (Enter your CIN) :");
        scanf("%s",cin);

        if( isalpha(cin[0])){
                cin[0]=toupper(cin[0]) ;
            }
        if(isalpha(cin[1])){
                cin[1]=toupper(cin[1]) ;
            }
        voter *inList = VoterInList(Vlist,cin);
        if(inList==NULL){
            printf("\n\t\t====>You are not In the List Please Verify you CIN or sign up First ");
            i=i-1;
        }else{
            printf("\n\t\tWelcome Again %s Please Vote for your President : ",inList->CIN);
            if(inList->isVoted==1){
                i--;
            }


            vote(Plist,inList);

        }
    }

    int res= getTheresultSec(Plist,Vlist);
    if(res == 0){
        restartVote(Vlist,Plist);
        return 0;

    }else if(res == 1){
        return 1;
    }else{
        return 2;
    }
}


void restartVote(Listvoters *list,ListPresidents *plist){
    voter *tmp= list->start;
    President *tmp2 = plist->First;
    while(tmp!=NULL){
        tmp->isVoted = 0;
        tmp=tmp->next;
    }
    while(tmp2!=NULL){
        tmp2->votes = 0;
        tmp2=tmp2->next;
    }

}

int getTheresultPre(ListPresidents *list,Listvoters *vlist){
    system("cls");
    printf("\t\t\t ==> The Result for the First round Of Elections 2021 <==\n\n");
    int numofv = CurrNumberOfv(vlist);
    float moy = 0;
    President *tmp=list->First;
    while(tmp!=NULL){
        moy = ((float)tmp->votes/numofv)*100;
        printf("\n\t\tPresident *%s %s* \t\t %.2f %% =========> %s",tmp->fname,tmp->lname,moy,sign(moy)?"PASSED":"EXLU");
        tmp=tmp->next;
    }
    tmp=list->First;
    int what= tmp->votes;
    int count = 0,ok;
    while(tmp!=NULL){
        if(what == tmp->votes){
            count++;
        }else{
            count--;
        }
        tmp=tmp->next;
    }

    if(CurrNumberOfP(list) == count){
          printf("\n\n\t\t Votes is equal for all Presidents restarting the round 1 =>");
          printf("\n\t\tEnter 0 to restart the Vote :");
          scanf("%d",&ok);
          return ok;
    }
    return 2;

}

int sign(float moy){
    if(moy<15){
        return 0;
    }else {
        return 1;
    }
}

void restartVoters(Listvoters *voters){
    voter *tmp=voters->start;

    while(tmp!=NULL){
        tmp->isVoted = 0;
        tmp=tmp->next;
    }
}
void DelExluP(ListPresidents *Plist,Listvoters *Vlist){
    int curr = CurrNumberOfv(Vlist);
    President *tmp=Plist->First;
    President *current ;
    President *previece=Plist->First;
    while(tmp!=NULL){
        float moy = ((float)tmp->votes/curr)*100;
        if(sign(moy) == 0){
            if(tmp!=previece){
                while(previece->next!=tmp){
                    previece = previece->next;
                }
                previece->next=tmp->next;
                free(tmp);
            }else{
                previece=previece->next;
                free(tmp);
            }
        }else{
            tmp->votes = 0;
        }
        tmp=tmp->next;
    }


}


void DelExluS(ListPresidents *Plist,Listvoters *Vlist,int min){

    President *tmp=Plist->First;
    President *current ;
    President *previece=Plist->First;
    while(tmp!=NULL){
        if(tmp->votes == min){
            if(tmp!=previece){
                while(previece->next!=tmp){
                    previece = previece->next;
                }
                previece->next=tmp->next;
                free(tmp);
            }else{
                previece=previece->next;
                free(tmp);
            }
        }else{
            tmp->votes = 0;
        }
        tmp=tmp->next;
    }
    tmp=Plist->First;


}


int getTheresultSec(ListPresidents *Plist,Listvoters *Vlist){
    system("cls");
    printf("\t\t\t ==> The Result for the Second round Of Elections 2021 <==\n\n");
    int min = 0;
    President *tmp=Plist->First;
    min = tmp->votes;

    while(tmp!=NULL){

        if(tmp->votes <min){
            min = tmp->votes;
        }
        tmp=tmp->next;
    }
    tmp=Plist->First;
    system("cls");
    while(tmp!=NULL){
        printf("\n\t\tPresident *%s %s* \t\t %d =========> %s",tmp->fname,tmp->lname,tmp->votes,tmp->votes != min?"PASSED":"EXLU");
        tmp=tmp->next;
    }

    tmp=Plist->First;
    int count = 0,ok;
    while(tmp!=NULL){
        if(min == tmp->votes){
            count++;
        }else{
            count--;
        }
        tmp=tmp->next;
    }

    if(CurrNumberOfP(Plist) == count){
          printf("\n\n\t\t Votes is equal for all Presidents restarting the round 1 =>");
          printf("\n\t\tEnter 0 to restart the Vote 1 to make changes in lists");
          scanf("%d",&ok);
          return ok;
    }else{
        DelExluS(Plist,Vlist,min);
        return 1;

    }


}





int Final(ListPresidents *Plist,Listvoters *Vlist){

    voter *currentVoter = Vlist->start;
    President *currentPresident = Plist->First;
    char cin[10];
    int i;
    int notVoted = CurrNotVoted(Vlist);
    system("cls");
    printf("\n\t\t==> The Final Round Of Elections <==");
    for(i=0;i<notVoted;i++){
        printf("\n\t\tPlease verify Your Identity (Enter your CIN) :");
        scanf("%s",cin);

        if( isalpha(cin[0])){
                cin[0]=toupper(cin[0]) ;
            }
        if(isalpha(cin[1])){
                cin[1]=toupper(cin[1]) ;
            }
        voter *inList = VoterInList(Vlist,cin);
        if(inList==NULL){
            printf("\n\t\t====>You are not In the List Please Verify you CIN or sign up First ");
            i=i-1;
        }else{
            printf("\n\t\tWelcome Again %s Please Vote for your President : ",inList->CIN);
            if(inList->isVoted==1){
                i--;
            }


            vote(Plist,inList);
        }
    }

    int res= getTheresultFinal(Plist,Vlist);
    if(res == 0){
        restartVote(Vlist,Plist);
        return 0;

    }else if(res == 1){
        return 1;
    }else{
        return 2;
    }


}


int getTheresultFinal(ListPresidents *Plist,Listvoters *Vlist){
    system("cls");
    printf("\t\t\t ==> The Result for the Final round Of Elections 2021 <==\n\n");
    int max = 0;
    President *tmp=Plist->First;
    max = tmp->votes;

    while(tmp!=NULL){

        if(tmp->votes >max){
            max = tmp->votes;
        }
        tmp=tmp->next;
    }
    printf("%d",max);

    tmp=Plist->First;
    while(tmp!=NULL){
            if(tmp->votes==max){
                printf("\n\t\tPresident '%s %s' \t\t %d =========> %s",tmp->fname,tmp->lname,tmp->votes,"WINNER");
            }
            tmp=tmp->next;
    }

    tmp=Plist->First;
    int count = 0,ok;
    while(tmp!=NULL){
        if(max == tmp->votes){
            count++;
        }else{
            count--;
        }
        tmp=tmp->next;
    }

    if(CurrNumberOfP(Plist) == count){
          printf("\n\n\t\t Votes is equal for all Presidents restarting the Final round =>");
          printf("\n\t\tEnter 0 to restart the Vote :");
          scanf("%d",&ok);
          return ok;
    }else{
        DelExluFinal(Plist,Vlist,max);
        return 2;

    }
}


void DelExluFinal(ListPresidents *Plist,Listvoters *Vlist,int max){

    President *tmp=Plist->First;
    President *current ;
    President *previece=Plist->First;
    while(tmp!=NULL){
        if(tmp->votes == max){
            if(tmp!=previece){
                while(previece->next!=tmp){
                    previece = previece->next;
                }
                previece->next=tmp->next;
                free(tmp);
            }else{
                previece=previece->next;
                free(tmp);
            }
        }
        tmp=tmp->next;
    }


}

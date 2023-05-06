#include<stdio.h>
#include<string.h>
struct book_detail{
	int book_num;
	char book_name[50];
    char book_author[50];
}book_detail2;

struct issue_book{
    int book_id;
    int token;
    char issuer_name[50];
    char book_name[50], book_author[50];
    char issue_date[50], return_date[50];
    
};

int add_books();
int search_books();
int issue_book();
int show_issued_book();
int return_book();
int book_list();
char anonymous(int parameter);
char anonymous2(int parameter2);


int main(){

    printf("\n----------------------------------------------");
    printf("\n********** Library Management **********\n");
    printf("----------------------------------------------");
    printf("\nSelect Option\n1--> |Add Books to DataBase| \n2--> |Issue Books| \n3--> |Search Book in DataBase| \n4--> |Show Issued Books| \n5--> |Return Book| \n6--> |Book List| \n");

    int choice;
    printf("\n\nEnter Option : ");
    scanf("%d",&choice);

    switch(choice){
        case 1 :
            printf("\nYou Have to Enter Details to Add Books in Database\n");
            add_books();
            break;
        case 2 :
            printf("\nIssue Books\n");
            issue_book();
            break;
        case 3 :
            printf("\nSearch Book\n");
            search_books();
            break;
        case 4:
            printf("\nIssued Books Details\n");
            show_issued_book();
            break;
        case 5:
            printf("\nReturn Book\n");
            return_book();
            break;
        case 6:
            printf("\nBook List : Following Books are Present in Repository\n");
            book_list();
            break;
        default:
            printf("\nWrong Option Selected!!\n");
    }


    
}
//Add book function
int add_books(){
    int check=0,press=1;
    do{
    FILE *file_pointer;
    
	printf("\nEnter Book ID Number : ");
	scanf("%d",&book_detail2.book_num);

    FILE *file_pointer_read;
    struct book_detail b_detail_read;
    file_pointer_read=fopen("books.txt","r");
	while(fread(&b_detail_read,sizeof(struct book_detail),1,file_pointer_read)){
		if(book_detail2.book_num==b_detail_read.book_num){
            check=1;
            fclose(file_pointer_read);
            break;
        }
    };

    if(check==1){
        printf("\n>< >< >< >< >< A Book already Exist With entered Book ID Number. >< >< >< >< ><\n");
    }
    else{

        printf("Enter Book Name.(Use Hypen '-' instead of Space)  : ");
        scanf("%s",&book_detail2.book_name);
	
	    printf("Enter Book author. (Use Hypen '-' instead of Space) : ");
	    scanf("%s",&book_detail2.book_author);

	    file_pointer=fopen("books.txt","a");
	    fwrite(&book_detail2,sizeof(struct book_detail),1,file_pointer);
        fclose(file_pointer);
        printf("\n!!!!!!!! Book Details Added to the DataBase !!!!!!!!\n");
        }
    
    printf("\nEnter 1 To Add more books and 0 to go to Main Menu : ");
    scanf("%d",&press);
    }
    while(press==1);
    main();
    
	
}
// issue book function
int issue_book(){
    char iss_name[50];

    int book_number , found=0;

    //Taking Book ID input
    printf("\nEnter Book Number: ");
    scanf("%d",&book_number);

    // Initalizing file pointer to search book
    FILE *ftr;
    struct book_detail book_detail_read;
    ftr=fopen("books.txt","r");
    char id_num_exist= anonymous(book_number);
    while(fread(&book_detail_read,sizeof(struct book_detail),1,ftr)){
        if (book_number == book_detail_read.book_num && id_num_exist=='N'){
            found=1;
            int choice=0;
            printf("\n------------------------------------------\n");
            printf("Do You Want TO Issue This | Book ID = %d | Book name= %s | Book Author= %s | ? Then Press 1 : "
            ,book_detail_read.book_num,book_detail_read.book_name,book_detail_read.book_author);
            printf("\n------------------------------------------");
            scanf("%d", &choice);

            if (choice==1){

                printf("\nEnter Issuer Name. (Use Hypen '-' instead of Space) : ");
                scanf("%s",&iss_name);
                struct issue_book issue_book_detail;
                issue_book_detail.book_id=book_detail_read.book_num;
                strcpy(issue_book_detail.issuer_name,iss_name);
                strcpy(issue_book_detail.book_name,book_detail_read.book_name);
                strcpy(issue_book_detail.book_author,book_detail_read.book_author);
                
                printf("\nEnter Issuer Date [DD/MM/YYYY] : ");
                scanf("%s",&issue_book_detail.issue_date);

                printf("\nEnter Return Date [DD/MM/YYYY] : ");
                scanf("%s",&issue_book_detail.return_date);

                char token_num_exist='Y';
                do{
                    printf("\nEnter TOKEN Number for Issuing (Must Be 6 Digit XXXXXX) : ");
                    scanf("%d",&issue_book_detail.token);
                    char token_num_exist= anonymous2(issue_book_detail.token);
                    printf("%c",token_num_exist);
                    if (token_num_exist=='N'){
                        FILE *file_pointer;
                        file_pointer=fopen("issue-book.txt","a");
                        fwrite(&issue_book_detail,sizeof(struct issue_book),1,file_pointer);
                        fclose(file_pointer);

                        printf("\n!!!!!BOOK ISSUED !!!!!\n");
                        break;}
                    else{
                        printf("\n >< >< >< >< A Book is already Issued With entered Token Number. Kindly Enter Unique. >< >< >< >< \n");}
                }while(token_num_exist=='N');
            }
        }
    }

    if(found==0){
        printf("\n!!!   NO BOOK Found   !!! | May Be Book is Issued.\n");
    }
    main();

}
// Search book Function
int search_books(){
    int book_num, found=0;
    printf("Enter Book Number to Search  :  ");
    scanf("%d",&book_num);
    FILE *ftr;
    struct book_detail book_detail_read;
    ftr=fopen("books.txt","r");
    printf("\nBook Details are Below \n----------------------------------------------------------------\n");
    while(fread(&book_detail_read,sizeof(struct book_detail),1,ftr)){
        if (book_num == book_detail_read.book_num){
            found++;
            printf(" | Book ID = %d | Book name= %s | Book Author= %s |\n",
            book_detail_read.book_num,book_detail_read.book_name,book_detail_read.book_author);}       
	}
    if(found==0){
        printf("!!!!!!! NO Book Found !!!!!!!\n");
        
    }
    printf("----------------------------------------------------------------\n\n");
    main();
	fclose(ftr);

    
}
// show issued Books
int show_issued_book(){

    FILE *ftr;
    struct issue_book issue_book_detail;
    ftr=fopen("issue-book.txt","r");
    

    while(fread(&issue_book_detail,sizeof(struct issue_book),1,ftr)){
        printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("| Book ID : %d | Issuer Name : %s | Book Name : %s | Book Author : %s | Issued Date : %s | Return Date : %s | Token : %d | \n",
        issue_book_detail.book_id,issue_book_detail.issuer_name,issue_book_detail.book_name,issue_book_detail.book_author,issue_book_detail.issue_date,
        issue_book_detail.return_date, issue_book_detail.token);
    }
    
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    main();
}

// Return Book
int return_book(){
    int token_num , check=0;
    printf("\nEnter TOKEN Number: (Must Be Six Digit XXXXX)");
    scanf("%d",&token_num);
    
    FILE *ftr;
    ftr=fopen("issue-book.txt","r");

    FILE *file_pointer;
    file_pointer=fopen("temp.txt","w");

    struct issue_book issue_book_detail2;

    while(fread(&issue_book_detail2,sizeof(struct issue_book),1,ftr)){
        if(token_num==issue_book_detail2.token){
            check=1;
            continue;
        }
        else{
            fwrite(&issue_book_detail2,sizeof(struct issue_book),1,file_pointer);

        }
    }
    fclose(file_pointer);
    fclose(ftr);

    if (check==1){
        FILE *ftr2;
        struct issue_book issue_book_detail;
        ftr2=fopen("temp.txt","r");

        FILE *ftr_point;
        ftr_point=fopen("issue-book.txt","w");

        while(fread(&issue_book_detail,sizeof(struct issue_book),1,ftr2)){
            fwrite(&issue_book_detail,sizeof(struct issue_book),1,ftr_point);
        }


        fclose(ftr2);
        fclose(ftr_point);

        printf(" \n~~~~~~~~~~~~~~~~~~ BooK Returend | Details Updated in Data Base ~~~~~~~~~~~~~~~~~~~\n ");
        
    }
    else{
        printf(" \n>< >< >< >< ><Invalid Token Number >< >< >< >< ><\n ");
    }
    main();
}
//

int book_list(){
    FILE *file_pointer_read;
    struct book_detail b_detail_read;
    file_pointer_read=fopen("books.txt","r");
    printf("\n-------------------------------------------------------------");
	while(fread(&b_detail_read,sizeof(struct book_detail),1,file_pointer_read)){
        
		printf("\n |Book ID = %d | Book name= %s | Book Author= %s | ",b_detail_read.book_num,b_detail_read.book_name,b_detail_read.book_author);
        //printf("\n-------------------------------------------------------------");
    }
    printf("\n-------------------------------------------------------------");
	fclose(file_pointer_read);
    main();
}

char anonymous(int parameter){
    FILE *ftr_point;
    char check1='N';
    ftr_point=fopen("issue-book.txt","r");
    struct issue_book issue_book_detail;
    while(fread(&issue_book_detail,sizeof(struct issue_book),1,ftr_point)){
        if(parameter==issue_book_detail.book_id){
            check1='Y';
            break;
        }
    }
    return check1;
}


char anonymous2(int parameter2){
    char check2='N';
    FILE *ftr_point10;
    ftr_point10=fopen("issue-book.txt","r");
    struct issue_book issue_book_detail_new;
    while(fread(&issue_book_detail_new,sizeof(struct issue_book),1,ftr_point10)){
        if(parameter2==issue_book_detail_new.token){
            check2='Y';
            break;
        }
    }
    return check2;
}
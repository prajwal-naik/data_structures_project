#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
}tnode;
char morse[100]="*EISH00V00UF000ARL000WP00J00TNDB00X00KC00Y00MGZ00Q00O00";
struct tnode* create();
//void preorder(struct tnode *t);
void decode(char* , struct tnode** );
void encode(char* , char*);


int main()
{
    char input[100];
    char english_input[100];
    int choice;
    tnode *root=NULL;
    while(1)
    {
        printf("\nWhat do you want to do ?\n");
        printf("1. Encode\n2. Decode\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter string to be converted to Morse : ");
                fflush(stdin);
                scanf("%[^\n]s", english_input);
                encode(english_input, input);
                break;
            case 2:
                
                root=create();
                                                                                              //preorder(root);
                printf("\nEnter the morse code \n");
                fflush(stdin);
                scanf("%s", input);
                decode(input, &root);
                break;
            case 3:
                exit(0);
        }
    }
    
    



    return 0;
}

struct tnode *create() 
{
  static int i=0;
  char x;
  struct tnode* p;
  x=morse[i];
  i++;
  if(x!='\0')
  {
    
    if(x=='0')
        return NULL;
    p=malloc(sizeof(struct tnode));
    p->data=x;
    p->left=create();  
    p->right=create();
  }
  return p;
}

                                                                                  // void preorder(struct tnode *t)
                                                                                  // {
                                                                                  //    if(t!=NULL)
                                                                                  //    {
                                                                                  //       printf("%c ",t->data);
                                                                                  //       preorder(t->left);
                                                                                  //       preorder(t->right);
                                                                                  //    }
                                                                                  // }

void decode(char* input, struct tnode** root)
{
    int i=0;
    struct tnode* cur;
    while(input[i]!='\0')
    {
        cur=*root;
        int j=i;
        while(input[j]!='\0' && input[j]!='/')
        {
            if(input[j]=='-')
                cur=cur->right;
            else
            if(input[j]=='.')
                cur=cur->left;
            j++;
        }
        if(input[j]=='\0')
            break;
        else
        if ((input[j]=='/') && (input[j+1]=='/'))
        {
            printf("%c ", cur->data);
            i=j+2;
        }
        else
        {
            printf("%c", cur->data);
            i=j+1;
        }
    }
    printf("%c", cur->data);  
}


char english[100]="*ETIANMSURWDKGOHVF0L0PJBXCYZQ";
void encode(char* input, char* array)
{
    char morse_string[1000];
    int i=0;
    while(input[i]!='\0')
    {
        
        if(input[i] != ' ')
        {
            char letter[100];
            char x=input[i];
            int count=0;
            for(int j=0; j<29; j++)
            {
                if(x==english[j])
                {
                    break;
                }
                count++;
            }
            int pos=count;
            char source=english[pos];
            int m=0;
            while(source!='*')
            {
                
                if(pos%2==1)
                {
                    letter[m]='.';
                    m++;
                    pos/=2;
                }
                else
                {
                    letter[m]='-';
                    m++;
                    pos=(pos/2)-1;
                }
                source=english[pos];
            }
            letter[m]='\0';
            printf("%s", strrev(letter));
            if((input[i+1]!=' ') && (input[i+1]!='\0'))
                printf("/");
            i++;
        }
        else
        {
            printf("//");
            i++;
        }
    }
}













































// int i=0;
//     //struct tnode *cur = *root;
    
//     while(input[i]!='\0')
//     {
//         // int j=i;
//         // struct tnode *cur = *root;
//         // while((input[j]!='/') || (input[j]!='\0'))
//         // {
//         //     if(input[j]=='-')
//         //         cur=cur->right;
//         //     else if(input[j]=='.')
//         //         cur=cur->left;
//         //     j++;
//         // }
//         // printf("%c", cur->data);
//         // i=j+1;
        
//         if(input[i]=='/')
//             cur = *root;
//         else
//         {
//             struct tnode* cur = *root;
//             int j=i;
//             while(input[j]!='/')
//             {
//                 if(input[i]=='-')
//                     cur=cur->right;
//                 else if(input[i]=='.')
//                     cur=cur->left;
//                 j++;
//             }
//             printf("%c", cur->data);
//             i=j+1;
//         }
//     }
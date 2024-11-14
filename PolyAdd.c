#include <stdio.h>

struct poly{
    float coeff;
    int exp;
} p1[10] ,p2[10],p3[20];

int ReadPoly(struct poly p[]) {
    int t1,i;
    printf("Enter number of terms in the polynomial");
    scanf("%d",&t1);
    printf("Enter Coeff and exp");
    for(int i=0;i<t1;i++){
        scanf("%f%d",&p[i].coeff,&p[i].exp);
    }
    printf("\n");
    return t1;
};

int AddPoly(struct poly p1[],struct poly p2[],int t1,int t2, struct poly p3[])
{
    int i=0,j=0,k=0;
    while(i<t1 && j<t2){
        if(p1[i].exp==p2[j].exp){
            p3[k].exp = p1[i].exp;
            p3[k].coeff= p1[i].coeff + p2[j].coeff;
            i++;
            j++;
            k++;
        }

        else if(p1[i].exp>p2[j].exp){
            p3[k].exp = p1[i].exp;
            p3[k].coeff = p1[i].coeff;
            i++;
            k++;
        }

        else{
            p3[k].exp = p2[j].exp;
            p3[k].coeff = p2[j].coeff;
            k++;
            j++;
        }
    }

    while(i<t1){
        p3[k].exp = p1[i].exp;
        p3[k].coeff = p1[i].coeff;
        i++;
        k++;
    }

    while(j<t2){
        p3[k].exp = p2[j].exp;
        p3[k].coeff = p2[j].coeff;
        j++;
        k++;

    }

    return k;

    /* data */
};

void DisplayPoly(int t, struct poly p[]){
    for(int i=0;i<t-1;i++){
        printf("%.2f x^%d + ",p[i].coeff,p[i].exp);
    }
    printf("%.2f x^%d + ",p[t-1].coeff,p[t-1].exp);

}

int main(){
    int t1,t2,t3;
    printf("Polynomial 1\n");
    t1 = ReadPoly(p1);
    printf("Polynomial 2\n");
    t2 = ReadPoly(p2);
    printf("Add Polynomial\n");
    t3=AddPoly(p1,p2,t1,t2,p3);
    DisplayPoly(t3,p3);

    return 0;
    
}

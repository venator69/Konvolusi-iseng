#include <stdio.h>
int i = 0, j = 0;
void flip(double response[],int len){
    int head,tail,temp = 0;
    head = i;
    tail = len;
    while (head < tail){
        temp = response[tail-1] ;
        response[tail-1] = response [head];
        response[head] = temp;
        head ++;
        tail --;
    }
    }

void printarr(double arr[],int len){
    for (i = 0; i < len; i++) {
        printf("%2.lf \n", arr[i]);
    }
}

void konvolusi(double signal[], double response[], int lnsig, int lnres, double *tempsig, double *consig){
    double out[lnsig + (lnres-1)*2];
    for (i=0;i<lnres-1;i++){
        tempsig[i] = 0;
    }
    for (i=0;i<lnsig;i++){
        tempsig[i+lnres-1] = signal[i];
    }
    for (i=0;i<lnres-1;i++){
        tempsig[lnsig+lnres+i-1] = 0;
    }
    for (i=0;i<lnres+lnsig-1;i++){
        consig[i] = 0;
    }
    for (i=0; i<lnsig+lnres-1;i++){
        for (j=0; j<lnres;j++){
        consig[i] += tempsig[i+j] * response[j];
        }
    }
}

int main() {
    int lnres,lnsig, i;
    
    printf("masukkan jumlah input response :");
    scanf("%d", &lnres);
    
    double response[lnres];
    
    for (i = 0; i < lnres; i++) {
        scanf("%lf", &response[i]);
    }
    flip(response,lnres);

    
    printf("masukkan jumlah input signal :");
    scanf("%d", &lnsig);
    double signal[lnsig];
    for (i = 0; i < lnsig; i++) {
        scanf("%lf", &signal[i]);
    }
    double tempsig[lnsig + (lnres-1)*2];
    double consig[lnsig + lnres - 1];
    konvolusi(signal,response,lnsig,lnres,tempsig,consig);
    printf("hasil konvolusi :\n");
    printarr(consig,lnsig + lnres - 1);
    return 0;
}
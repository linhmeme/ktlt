#include<stdio.h>
#include <stdlib.h>
double* maximum(double *htl, int size) {
    double *max;
    max = htl; 
    if(htl == NULL) return NULL;
    for(int i = 1; i < size; i++){
        if(*max < htl[i]) max = &htl[i];
    }
    return max;
}

int main() {
    printf("Hoang Thuy Linh  20235135\n");
    int n;
    double *htl;
    scanf("%d", &n);
    htl = (double*) malloc (n * sizeof(double));
    if (htl == NULL) {
        printf("memory allocation failed");
        return 1;
    }
    for(int i = 0; i < n; i++){
        scanf("%lf", &htl[i]);
    }
    double *max = maximum(htl, n);
    printf("%lf\n", *max);
    free(htl);
    return 0;
}
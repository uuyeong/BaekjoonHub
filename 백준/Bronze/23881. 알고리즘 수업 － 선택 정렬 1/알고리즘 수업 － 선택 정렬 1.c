#include <stdio.h>
#include <string.h>

void Selection_Sort(int *A, int n, int k, int* result_1, int* result_2){
    int last = n-1; //배열의 마지막 인덱스
    
    int intercount = 0;
    
    //3 1 2 5 4 last = 4 / big = 5, big_index = 3, temp = 4
    // last = 3, 3 1 2 4 5
    while(last > 0){
        int big = A[0];
        int big_index = 0;
        for(int i=0;i<=last;i++){
            if(big<A[i]){
                big = A[i];
                big_index = i;
            }
        }
        if(big_index != last){
            int temp = A[last];
            A[last] = big;
            A[big_index] = temp;
            intercount++;
            if(intercount == k){
                *result_1 = A[big_index];
                *result_2 = A[last];
                return;
            }
            
        }
        last --;
    }
    
    if(intercount < k){
        *result_1 = -1;
        *result_2 = -1;
    }
}


int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int A[n];
    
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    
    int result_1;
    int result_2;
    
    /*for(int i=0;i<n;i++){
        printf("A[%d] = %d \n", i, A[i]);
    }
    printf("n = %d\n", n);
    printf("k = %d\n", k);
     */ //입력 확인용
    
    Selection_Sort(A, n, k, &result_1, &result_2);
    
    
    if(result_1 == -1 && result_2 == -1){
        printf("-1 \n");
    }
    else printf("%d %d\n",result_1, result_2);
    
    
    return 0;
}

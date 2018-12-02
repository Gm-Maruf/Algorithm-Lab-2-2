#include<stdio.h>
int main()
{
    int T,N,a[10000];
    int i,j,m,k,p=1;

    while(scanf("%d",&T) != EOF){
        if(T<=50){
            for(k=0; k<T; k++){
            scanf("%d",&N);
            if(N>=1 && N<=100){
                for(i=0; i<N; i++){
                scanf("%d",&a[i]);
                }
            for(i=0; i<N; i++){
                for(j=i+1; j<N; j++){
                    if(a[i]<a[j]){
                        m=a[j];
                        a[j]=a[i];
                        a[i]=m;
                        }
                    }
                }
            printf("Case %d: %d\n",p,a[0]);
            p=p+1;
            }
        }
      }
    }
    return 0;
}

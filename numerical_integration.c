#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>


#define dt     0.05
#define time     5
 

int main()
{
   
   int l,t,N;
      
   double y,T,f;
   
   FILE *fpm;
   
   N=time/dt;
   l=1;
   double Y[N];
  
   fpm=fopen("integracao_numerica_dt005.txt","w");
   if(!fpm) exit(0);   
   
   fprintf(fpm,"#tempo\t\t\t\t\t\t\t\t#Yt_1\t\t\t\t#yt_1-y\n"); 
   
   Y[0]=1.0;
   T=0.0;
   y=exp(T)+exp(T/2)*sin(5*T);
   fprintf(fpm,"%lf\t\t\t\t\t%.12f\t\t\t\t%.12f\n",T,Y[0],fabs(fabs(Y[0])-fabs(y)));
   
   for(t=0;t<N;t++){   
      T=t*dt; //valores de cada loop para o eixo x     
      Y[t+1] = Y[t] + Y[t]*dt - (1.00/2.00)*exp(T/2.0)*sin(5.0*T)*dt + 5.0*exp(T/2.0)*cos(5.0*T)*dt; //função de integraçao       

   }             
   for(t=0;t<N;t++){
      T=(t+1)*dt;      
      if(T==0.1*l){
        y=exp(T)+exp(T/2)*sin(5*T);
        fprintf(fpm,"%lf\t\t\t\t\t%.12f\t\t%.12f\n",T,Y[t+1],fabs(fabs(Y[t+1])-fabs(y))); 
        l++;
      }
      
   }
   fclose(fpm);
   
}   

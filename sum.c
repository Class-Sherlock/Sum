#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INTS 1000000

int sum = 0;
int Tsum = 0;
int Tcount = 0;
int intcount = 0;
int num[MAX_INTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *sumThread(void *i)
{
  pthread_mutex_lock(&mutex);
  
  int count = intcount/Tcount + 1;
  int Tnum = *((int *) i);
  int i =  Tnum * count;
  int j = i + count;
  free(i);
  Tsum = 0;
  
  for(i; i < j; i++)
  {
    if(i < intcount)
	{
      Tsum += num[i];
    }
  }
  printf("Thread %d: %d\n", Tnum + 1, Tsum);
  sum += Tsum;
  pthread_mutex_unlock(&mutex);
}

int main(int argc, char ** argv)
{
  if( argc != 3) 
  {
    fprintf(stderr,"incorrect input\n");
    exit(-1);
  }
  FILE * fp = fopen(argv[1], "r");
  int i = 0;
  while(fscanf(fp, "%d", &num[i]) > 0)
  {
    i++;
  }
  fclose(fp);
  intcount = i;
  Tcount = strtol(argv[2], NULL, 10);
  pthread_t threads[Tcount];
  
  for (i = 0; i < Tcount; i++)
  {
    int *arg = malloc(sizeof(*arg));
    *arg = i;
    pthread_create(&threads[i], NULL, sumThread, arg);
  }

  for (i = 0; i < Tcount; i++)
  {
    pthread_join(threads[i], NULL);
  }
  printf("Sum = %d\n",sum);
  return 0;
}


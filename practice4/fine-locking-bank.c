//#include <time.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <sys/types.h>
//#include <pthread.h>
//
//#define INIT_BALANCE 50
//#define NUM_TRANS 10000
//
//int balance = INIT_BALANCE;
//int credits = 0;
//int debits = 0;
//
//pthread_mutex_t b_lock,c_lock,d_lock;
//
//void * transactions(void * args)
//{
//    int i,v;
//
////    struct timespec start, end;
////    double elapsed;
////
////    clock_gettime(CLOCK_MONOTONIC, &start); // start time
//
//    for(i=0; i<NUM_TRANS; i++)
//    {
//
//        //choose a random value
//        srand(time(NULL));
//        v = rand() % NUM_TRANS;
//
//        //randomnly choose to credit or debit
//        if( rand()% 2)
//        {
//            //credit
//            pthread_mutex_lock(&b_lock);
//            balance = balance + v;
//            pthread_mutex_unlock(&b_lock);
//
//            pthread_mutex_lock(&c_lock);
//            credits = credits + v;
//            pthread_mutex_unlock(&c_lock);
//        }
//        else
//        {
//            //debit
//
//            pthread_mutex_lock(&b_lock);
//            balance = balance - v;
//            pthread_mutex_unlock(&b_lock);
//
//            pthread_mutex_lock(&d_lock);
//            debits = debits + v;
//            pthread_mutex_unlock(&d_lock);
//        }
//
//    }
//
////    clock_gettime(CLOCK_MONOTONIC, &end); // end time
////
////    // calculate elapsed time in milliseconds
////    elapsed = (end.tv_sec - start.tv_sec) * 1000.0;
////    elapsed += (end.tv_nsec - start.tv_nsec) / 1000000.0;
////
////    printf("Thread %ld finished transactions in %.3f ms\n",
////           (long)pthread_self(), elapsed);
//
//    return 0;
//}
//
//int main(int argc, char * argv[])
//{
//
//    int n_threads,i;
//    pthread_t * threads;
//    struct timespec start, end;
//    double elapsed;
//
//    pthread_mutex_init(&b_lock, NULL);
//    pthread_mutex_init(&c_lock, NULL);
//    pthread_mutex_init(&d_lock, NULL);
//
//    //error check
//    if(argc < 2)
//    {
//        fprintf(stderr, "ERROR: Require number of threads\n");
//        exit(1);
//    }
//
//    //convert string to int
//    n_threads = atol(argv[1]);
//
//    //error check
//    if(n_threads <= 0)
//    {
//        fprintf(stderr, "ERROR: Invalivd value for number of threads\n");
//        exit(1);
//    }
//
//    //allocate array of thread identifiers
//    threads = calloc(n_threads, sizeof(pthread_t));
//
//    // start timing whole program (only the threaded workload)
//    clock_gettime(CLOCK_MONOTONIC, &start);
//    //start all threads
//    for(i=0; i<n_threads; i++)
//    {
//        pthread_create(&threads[i], NULL, transactions, NULL);
//    }
//
//    //wait for all threads finish its jobs
//    for(i=0; i<n_threads; i++)
//    {
//        pthread_join(threads[i], NULL);
//    }
//
//    // end timing
//    clock_gettime(CLOCK_MONOTONIC, &end);
//
//    // calculate elapsed time in milliseconds
//    elapsed = (end.tv_sec - start.tv_sec) * 1000.0;
//    elapsed += (end.tv_nsec - start.tv_nsec) / 1000000.0;
//
//    pthread_mutex_destroy(&b_lock);
//    pthread_mutex_destroy(&c_lock);
//    pthread_mutex_destroy(&d_lock);
//
//    printf("\t Debits:\t%d\n\n", debits);
//    printf("%d+%d-%d=\t%d\n", INIT_BALANCE,credits,debits,INIT_BALANCE+credits-debits);
//    printf("\t Balance:\t%d\n", balance);
//    printf("Total runtime: %.3f ms\n", elapsed);
//
//    //free array
//    free(threads);
//    return 0;
//}
//

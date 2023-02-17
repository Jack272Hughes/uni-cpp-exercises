#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <math.h>

#include "classes/GameObject.h"

using namespace std;

enum Priority {
    THREAD_PRIORITY_IDLE,
    THREAD_PRIORITY_LOWEST,
    THREAD_PRIORITY_BELOW_NORMAL,
    THREAD_PRIORITY_NORMAL,
    THREAD_PRIORITY_ABOVE_NORMAL,
    THREAD_PRIORITY_HIGHEST,
    THREAD_PRIORITY_TIME_CRITICAL
};

void* BasicThread(void* param) {
    cout << "Thread start" << endl;
    sleep(2);
    cout << "Thread end" << endl;
    return 0;
};

void* MessageThread(void* param) {
    int* tab = (int*) param;
    for (int n = 0; n < 10; n++) {
        usleep(200000);
        if (*tab == 1)
            cout <<"\t\t 1:Thread\n";
        else if (*tab == 2)
            cout <<"\t\t\t\t 2:Thread\n";
        else
            cout <<"\t\t\t\t\t\t 3:Thread\n";
    }

    delete tab;
    return 0;
}

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
void* SyncThread(void* param) {
    pthread_mutex_lock(&mutex1);
    GameObject *syncObj = (GameObject*) param;
    cout << "Game Object Health: " << syncObj->getHealth() << endl;
    pthread_mutex_unlock(&mutex1);
    return 0;
}

int setThreadPriority(pthread_t thread, Priority priority) {
    int minimumPriority = sched_get_priority_min(SCHED_FIFO);
    int maximumPriority = sched_get_priority_max(SCHED_FIFO);
    int actualPriority = min(minimumPriority + priority, maximumPriority);

    struct sched_param priotityParam;
    priotityParam.sched_priority = actualPriority;

    return pthread_setschedparam(thread, SCHED_FIFO, &priotityParam);
}

int main() {
    cout << "-=== Introduction ===-" << endl;
    pthread_t thread;
    int successCode = pthread_create(&thread, NULL, BasicThread, NULL);

    cout << "Press enter to continue..." << endl;
    system("read"); // Alternative to Window's 'pause' command
    pthread_join(thread, NULL); // This also allows the program to wait for passed thread to complete before moving on

    cout << "-=== Exercise 1 ===-" << endl;
    pthread_t threads[3];
    Priority threadPrios[] = { THREAD_PRIORITY_IDLE, THREAD_PRIORITY_TIME_CRITICAL, THREAD_PRIORITY_LOWEST };
    for (int i = 0; i < 3; i++) {
        int* label = new int(i + 1);
        pthread_create(&threads[i], NULL, MessageThread, label);
        setThreadPriority(threads[i], threadPrios[i]);
    }
    
    cout << "Press enter to continue..." << endl;
    system("read");

    cout << "-=== Exercise 2 ===-" << endl;
    void* param = NULL;
    pthread_t handlers[2];
    GameObject *obj = new GameObject();
    pthread_create(&handlers[0], NULL, SyncThread, obj);
    pthread_create(&handlers[1], NULL, SyncThread, obj);
    // The cause of the output '100100' is due to how both threads need to
    // access the same object simultaneously and are getting in each others way

    cout << "Press enter to continue..." << endl;
    system("read");
    delete obj;
}

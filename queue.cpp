#include <iostream>
using namespace std;

#define BUFF_SIZE   2048
#define MIN_SIZE    4
struct queue1
{
    unsigned char buff[BUFF_SIZE];
    unsigned short front;
    unsigned short rear;

} q1;

struct queue2
{
    unsigned short buff[BUFF_SIZE];
    short front;
    short rear;

} q2;


bool insertq2(unsigned short msg)
{
    // Check if q is full
    if(((q2.front == 0) && q2.rear == BUFF_SIZE-1) ||
        (q2.front == q2.rear + 1))
    {
        return 0;
    }
    else
    {
        // Enable front for read
        if(q2.front == -1)
            q2.front = 0;
        
        q2.rear = (q2.rear + 1) & (BUFF_SIZE - 1);
        //Alternately: q2.rear = (q2.rear + 1) % BUFF_SIZE;
        q2.buff[q2.rear] = msg;
    
        return 1;
    }

}


unsigned short *readq2(void)
{
    unsigned short *ptr;
    // Check if q is empty
    if(q2.front == -1)
        return NULL;
    else
    {
        ptr = &q2.buff[q2.front];

        if(q2.front == q2.rear)
        {
            q2.front = -1;
            q2.rear = -1;
        }
        else
            q2.front = (q2.front + 1) & (BUFF_SIZE - 1);
            //Alternately: q2.front = (q2.front + 1) % BUFF_SIZE;

        return ptr;
    }
}



//########################################################################################


unsigned char rdbuff[BUFF_SIZE];


void queueinit(void)
{
    q1.front = BUFF_SIZE - 1;
    q1.rear = 0;

    q2.front = -1;
    q2.rear = -1;

    memset(rdbuff, 0, BUFF_SIZE);
}

bool insertq(unsigned char *msg, int length)
{
    if(length < (BUFF_SIZE + q1.front - q1.rear) % BUFF_SIZE)
    {
        for (int i = 0; i < length; ++i)
        {
            q1.buff[q1.rear] = msg[i];

            q1.rear = (q1.rear + 1) & (BUFF_SIZE - 1);
        }

        return 1;
    }
    else
        return 0;
}

unsigned char *readq(int length)
{
    if(length < 4 || length > BUFF_SIZE)
        return NULL;
    else
    {
        for (int i = 0; i < length; ++i)
        {
            q1.front = (q1.front + 1) & (BUFF_SIZE - 1);

            rdbuff[i] = q1.buff[q1.front];
        }

        unsigned char * ptr = rdbuff;
        
        return ptr;
    }

}

int main() {

    unsigned char arr[10] = {1,2,3,44,5,6,7,3,5,7};
    unsigned char arr2[10] = {77,77,77,77,77,77,77,77,77,77};

    queueinit();

    insertq(arr, 10);
    insertq(arr2, 10);

    readq(10);
    readq(10);

    for (int i = 0; i < 10; ++i)
    {
        // printf("%d\n", rdbuff[i]);
    }

    insertq2(10);
    insertq2(20);

    unsigned short *ptr = readq2();
    ptr = readq2();

    cout << *ptr << endl;

  
   return 0;
}
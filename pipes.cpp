#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;



int main() {

    int fd1[2];
    int fd2[2];
    char arr1[] = "NIKHIL";
    char arr2[16] = {'\0'};
    int ret;

    if(!pipe(fd1) && !pipe(fd2))
    {
        if(fork() > 0)
        {
            //Parent
            close(fd1[0]); // close reading end before writting

            //Write parent to child
            write(fd1[1], arr1, (strlen(arr1)+1));
            wait(NULL);

            //Read from child
            close(fd2[1]);
            read(fd2[0], arr2, 5);
            cout << arr2<< endl;
            close(fd2[0]);
        }
        else
        {
            //child
            close(fd1[1]); // close writting end before reading
            int numofbytes = read(fd1[0], arr2, (strlen(arr1)+1));
            cout << arr2 << endl;
            close(fd1[0]);

            //write from child to parent
            close(fd2[0]);
            write(fd2[1], "MORAY", 5);
            close(fd2[1]);

            exit(0);

        }
    }
    


   return 0;
}

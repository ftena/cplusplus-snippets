#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <string>

//#define FUNCTION_TIME(x) gmtime(x)
#define FUNCTION_TIME(x) localtime(x)

using namespace std;

int main (int argc, char *argv[])
{

     time_t ltime;  
     //int timestamp = 1246962445;
     const time_t timestamp = 10;
     struct tm *Tm;  
   
/* time: Get the current time (number of seconds from the epoch) from the system clock. Stores that value in timer. If timer is null, the value is not stored, but it is still returned by the function. */

     ltime=time(NULL);  
     cout << "ltime --> " << ltime << endl;

/* localtime: Convert a time_t time value to a tm structure as local time. This structure is statically allocated and shared by gmtime, localtime and ctime functions. Each time one of these functions is called the content of the structure is overwritten. */

     Tm=localtime(&ltime);
     //Tm=localtime((const time_t*) &timestamp);   
     cout << endl << Tm->tm_wday << " " << Tm->tm_mday << "/" << Tm->tm_mon+1 << "/" << Tm->tm_year+1900 << " ";
     cout << Tm->tm_hour << ":" << Tm->tm_min << ":" << Tm->tm_sec << endl;
 
     Tm=gmtime(&timestamp); 
     cout << endl << Tm->tm_wday << " " << Tm->tm_mday << "/" << Tm->tm_mon+1 << "/" << Tm->tm_year+1900 << " ";
     cout << Tm->tm_hour << ":" << Tm->tm_min << ":" << Tm->tm_sec << endl;
   
/*     printf("[%d] %d %d %d, %d:%d:%d",  
         Tm->tm_wday, // Mon - Sun 
         Tm->tm_mday,  
         Tm->tm_mon+1,  
         Tm->tm_year+1900,  
         Tm->tm_hour,  
         Tm->tm_min,  
         Tm->tm_sec);  */

    struct timeval detail_time;  
    gettimeofday(&detail_time,NULL);  
    printf("%li %li \n",   
    detail_time.tv_usec /1000,  /* milliseconds */  
    detail_time.tv_usec); /* microseconds */  

    return 0;
}

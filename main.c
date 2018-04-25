#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
//
void filestat1(void)
{
  stat("./text1", &stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
  stat("./text2", &stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
	printf("filetime 1\n");
  time1 = localtime(&stat1.st_mtime);
	printf("text1 파일이 %d년 %d월 %d일 %d시 %d분 %d초 마지막으로 수정됨\n\n",time1->tm_year+1900,time1->tm_mon+1,time1->tm_mday,time1->tm_hour,time1->tm_min,time1->tm_sec);
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
	printf("filetime 2\n");
  time2 = localtime(&stat2.st_mtime);
	printf("text2 파일이 %d년 %d월 %d일 %d시 %d분 %d초 마지막으로 수정됨\n\n",time2->tm_year+1900,time2->tm_mon+1,time2->tm_mday,time2->tm_hour,time2->tm_min,time2->tm_sec);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
	printf("size compare\n");
  if(stat1.st_size > stat2.st_size){
		printf("text1 is bigger\n\n");
  }else if(stat1.st_size < stat2.st_size){
		printf("text2 is bigger\n\n");
  }else{
		printf("text1, text2 size same\n\n");
  }
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)	// 하늘
{
	// struct stat stat1, stat2;
	// blksize_t st_blksize;	// Block size for filesystem I/O.

	if(stat1.st_blksize > stat2.st_blksize)
		printf("test1 is bigger. ");

	else if(stat1.st_blksize < stat2.st_blksize)
		printf("test2 is bigger. ");

	else
		printf("Sizes are equal. ");

}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)	// 하늘
{
	// struct timespec st_mtim;	// Time of last modification
	/* struct tm{
	 * 	int tm_mday;
	 * 	int tm_mon;
	 * 	}
	 */
	// struct timespec st_mtim;	// Time of last modification

	stat1.tm_mday, stat1.tm_mon > stat1.tm;
	stat2.tm_mday, stat2.tm_mon > stat2.tm;

	if(stat1.tm > stat2.tm)
		printf("test1 is early. ");

	else if(stat1.tm < stat2.tm)
		printf("test2 is early. ");

	else
		printf("Same time. ");
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(void)
{
	// struct timespec st_mtim;	// Time of last modification
	/* struct tm
	 * {
	 * 	int tm_min;
	 * 	int tm_hour;
	 * 	}
	 */

	stat1.tm_min, stat1.tm_hour > stat1.tm;
	stat2.tm_min, stat2.tm_hour > stat2.tm;

	if(stat1.tm > stat2.tm)
		printf("test1 is early. ");

	else if(stat1.tm < stat2.tm)
		printf("test2 is early. ");

	else
		printf("Same time. ");
}

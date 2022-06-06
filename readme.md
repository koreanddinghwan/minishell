## readline

< 메뉴얼 해석 >

많은 프로그램들이 CLI(command line interface)를 제공한다.

대표적으로 shell, mail, ftp등이 있다.

몇몇 프로그램들에겐 readline의 기본동작만으로 충분하다.

### 역할

- 사용자로부터 한 줄을 입력받는다.

### 헤더

```c++
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
```

readline 헤더의 정의들이 stdio 라이브러리를 사용하기때문에

readline 헤더 이전에 반드시 stdio.h 헤더가 와야한다.

### 컴파일

위 헤더들과 더불어서

```c++
gcc -lreadline 파일명.c
```

로 컴파일 해야 사용할 수 있다.

### 사용법

- char *prompt에는 사용자에게 입력받을때 띄우고 싶은 문자열을 입력한다.
- prompt가 NULL이면 아무런 문자열을 표시하지 않는다.
- 사용자가 입력한 문자열을 char *로 리턴해주는데, malloc되어 있으므로, 할당해제는 필수!!!
- 개행이 삭제된 상태로 리턴해준다(enter키로 입력받기때문에 newline이 입력될 것 같지만, 리턴받는 문자열은 개행 전까지의 문자열만을 포함한다.)

```c++
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
```

## rl_on_new_line


```c++
int rl_one_new_line(void);
```

업데이트 함수들에게 새로운 라인으로 이동했다고 알린다.

## rl_redisplay

```c++
void rl_redisplay(void);
```

rl_line_buffer 에 현재 들어있는 내용을 반영하기위해 스크린에 있는 내용을 바꾼다.

## rl_line_buffer

```c++
char *rl_line_buffer
```

readline 관련 함수 작성자들이 사용할 수 있는 변수 중 하나이다.

## rl_replace_line

```c++
void rl_replace_line(const char *text, int clear_undo);
```

rl_line_buffer에 있는 내용을 인자로 받은 text 문자열로 대체한다.

위 3개 함수는 아마 bash 화면 조정에만 사용되고 큰 역할은 없을 것 같음.

### ref

1. stackoverflow [https://stackoverflow.com/questions/6727171/using-readline-for-completion](https://stackoverflow.com/questions/6727171/using-readline-for-completion)
2. readline 라이브러리 메뉴얼 [https://tiswww.case.edu/php/chet/readline/readline.html](https://tiswww.case.edu/php/chet/readline/readline.html)

<br>

## add_history

많은 프로그램들은 한 번에 유저로부터 입력을 받는다.

이 함수또한 GNU history 라이브러리의 함수인데, 각 줄의 임의의 데이터와 관련해 유저가 입력한 데이터들을 추적할 수 있다.

이에따라, 새로운 것을 구성할 때, 이전의 줄 들의 정보를 활용할 수 있다.

history 라이브러리를 사용하는 프로그래머들은 history list의 줄들을 기억하는 함수들, 삭제하는 함수, list에서 원하는 정보를 찾는 함수를 사용할 수 있다.

이 라이브러리가 가진 함수를 사용하기 위해선

```c
#include <readline/history.h>
```

를 include해야한다.

## history storage

### 개요

history list는 history 객체의 배열이다.

history 객체는 아래와 같다.

```c++
typedef void *hisdata_t;

typedef struct _hist_entry {
    char *line;
    char *timestamp;
    histdata_t  data;
} HIST_ENTRY;
```

그리고 history list는 아래와 같이 정의되어 있다.

```c++
HIST_ENTRY **the_history_list;
```

history library의 상태를 가진 구조체도 있는데, 이는 

```c++
typedef struct _hist_state {
    HIST_ENTRY **entries;
    int offset;
    int length;
    int size;
    int flags;
} HISTORY_STATE;
```

요로코롬 저장되어있습니다

### 함수 정의

그래서 add_history함수는 

```c++
void add_history(cont char *string)
```

이런 형태를 가지고 있는데, string으로 들어온 이 문자를 history list의 마지막 history 객체로 추가해준다.

단, history객체의 data부분은 NULL이다.

<br>

## fork

```c++
#include <unistd.h>

pid_t fork(void);
```

새로운 프로세스(자식 프로세스)를 생성.

### 개요

이 자식프로세스는 함수를 호출한 프로세스의 완벽한 복사본이다.

단, 완벽한 복사본일지라도, 구분할 수 있어야하는데, 이에는 4가지가 있다.

1. 자식프로세스는 자신만의 유일한 PID를 가진다.
2. 자식프로세스의 PPID는 부모의 PPID와 다르다.
3. 자식 프로세스는 자신만의 부모의 descriptor들의 복사본을 가진다.
    - 이 디스크립터들은 같은 객체를 참조한다. 따라서 자식프로세스와 부모프로세스 간
        
        파일 객체에 대한 파일포인터는 공유된다.
        
    - 따라서 자식 프로세스에서 lseek함수를 디스크립터에 사용하는 것은 부모에게도 영향을 줄 수 있다.
    - 이 디스크립터 복사본은 쉘이 새로 생성되는 프로세스들의 표준 입출력 생성하는데에 사용되며
    - 파이프를 만드는데에도 사용된다.
    - 자식프로세스의 자원 사용은 0으로 설정된다.

### 리턴값

만약 프로세스 생성이 완료되면 포크함수는 자식프로세스에게는 0을, 부모프로세스에게는 자식의 PID를 준다.

만약 실패하면 부모프로세스에게는 -1을 리턴해주고, 자식프로세스는 생성되지 않는다.

그리고 errno가 해당 에러를 나타내기위해 설정된다.

### 주의사항

완전히 안전하려면 자식 프로세스에선 exec함수 중 하나가 사용되기 전까지 

 async-signal-safe 함수만을 사용하도록 제한해야한다.

signal-safe함수들 목록 [https://man7.org/linux/man-pages/man7/signal-safety.7.html](https://man7.org/linux/man-pages/man7/signal-safety.7.html)

<br>

## wait

```c++
#include <sys/wait.h>

pid_t wait(int *stat_loc);
pid_t wait3(int *stat_loc, int options, struct rusage *rusage);
pid_t wait4(pid_t pid, int *stat_loc, int options, struct rusage *rusage);
pid_t waitpid(pid_t pid, int *stat_loc, int options);
```

### 개요

wait함수는 호출한 프로세스의 실행을 정지한다.

주로 fork를 통해 자식프로세스를 생성했을 때 사용한다.

wait을 부모프로세스에서 사용하면, 자식프로세스가 종료될때까지 부모프로세스는 휴면상태가 된다.

자식프로세스가 종료되기 전에 부모프로세스가 종료되어 orphan(고아)가 되는 것을 방지하기위한 목적이다.

자식프로세스가 종료되면 함수가 즉시 리턴되어 자식이 사용한 모든 시스템 자원을 해제한다.

근데, 어쩌다보면 부모가 wait을 호출하기전에 자식프로세스가 종료되는 경우도 있다(SEGV 등)

그 경우, 자식프로세스가 좀비프로세스가되는데, wait함수는 즉시 리턴되게 되어있다.

종료된 자식 프로세스의 ID는 0이며, 에러일 경우 -1이다.

### man

man page에선 wait함수가 자식프로세스가 종료되면서 함수 인자의 `stat_loc` 정보가 사용가능하거나 signal을 받을때까지 부모프로세스를 정지한다고 나타낸다.

wait함수가 성공적으로 리턴되면 stat_loc 은 자식프로세스의 exit상태를 나타내게된다.

## wait4

wait4함수는 자식프로세스가 종료될때까지 기다려야하는 프로그램에 좀 더 많은 인터페이스를 제공한다.

자식프로세스에 의해 사용된 자원통계나, option을 필요로한다.

다른 wait함수들은 wait4함수를 이용해 만들어졌다.

wait에서 사용되는 pid인자의 경우 어떤 자식 프로세스가 기다려야하는지 특정한다.

만약 pid가 -1이라면, 자식프로세스 중 아무거나를 지정한다.

만약 pid가 0이면 wait을 호출한 프로세스의 그룹에 속한 자식프로세스를 대상으로 기다린다.

만약 pid가 0보다 크면 해당 pid를 가진 프로세스의 종료만을 기다린다.

만약 pid가 -1보다 작으면 그 pid의 절대값과 같은 프로세스 그룹의 종료를 기다린다.

stat_loc 인자는 자식프로세스의 상태를 나타내는데에 쓰이는데, 이 인자를 아래의 매크로에 던져서 테스트를 하게된다. 

```c++
#endif /* _POSIX_SOURCE */

#define	_WSTATUS(x)	(_W_INT(x) & 0177)
#define	_WSTOPPED	0177		/* _WSTATUS if process is stopped */
#define WIFSTOPPED(x)	(_WSTATUS(x) == _WSTOPPED)
#define WSTOPSIG(x)	(_W_INT(x) >> 8)
#define WIFSIGNALED(x)	(_WSTATUS(x) != _WSTOPPED && _WSTATUS(x) != 0)
#define WTERMSIG(x)	(_WSTATUS(x))
#define WIFEXITED(x)	(_WSTATUS(x) == 0)
#define WEXITSTATUS(x)	(_W_INT(x) >> 8)
#if !defined(_POSIX_SOURCE)
#define WCOREDUMP(x)	(_W_INT(x) & WCOREFLAG)

#define	W_EXITCODE(ret, sig)	((ret) << 8 | (sig))
#define	W_STOPCODE(sig)		((sig) << 8 | _WSTOPPED)
#endif /* !defined(_POSIX_SOURCE) */
```

option인자는 bit연산을 통해 2개 중 하나를 가진다.

- WHOHANG 옵션은 상태를 보고하고 싶어하는 프로세스가 전혀 없다면 wait호출 시, block하지 않도록 하는데에 사용된다.
- WUNTRACED옵션은 SIGTTIN SIGTTOU SIGTSTP SIGSTOP 에 의해 종료된 자식 프로세스가 자신의 상태를 보고하고자 할때 사용된다.

rusage가 0이 아니라면, 종료된 프로세스에 의해 사용된 자원의 요약과 프로세스의 모든 자식이 반환된다.

이 정보의 경우에는 중지된 프로세스에 대해선 사용될 수 없다.

WHOHANG옵션이 지정되었는데, 아무런 자식프로세스가 상태보고를 원하지 않는다면 wait4함수는 pid 0을 반환한다.

waitpid 함수는 wait4함수의 rusage를 0으로 사용한 것과 같다.

wait3함수는 wait4함수의 pid값을 -1로 한 것과 같다.

### 주의

만약에 부모프로세스가 자식프로세스가 끝나기 전에 종료되면 남은 자식프로세스들은 1 프로세스(init)에게 입양된다.

wait으로 기다리는 중에 signal이 발생하면 signal action 루틴이 리턴되면 wait이 Interrupted되거나 재시작된다. 

<br>

## getcwd

```c++
#include <unistd.h>

char *getcwd(char *buf, size_t size);
```

현재 작업중인 디렉터리의 절대경로를 buf 메모리에 넣는다.

그리고 buf의 포인터를 리턴한다.

size 인자는 buf에 참조된 배열의 바이트단위 크기를 의미한다.

만약에 buf가 널포인터면 path문자열을 담을 수 있는만큼 메모리가 할당되고, size인자는 무시된다.

→ free해줘야함 나중에

<br>

## chdir

```c++
#include <unistd.h>

int chdir(const char *path);;
```

path인자는 디렉터리의 경로에 대한 포인터이다.

chdir함수는 현재 작업 디렉터리(current working directory)를 path로 바꿔준다.

경로 이름의 경로 검색 시작점이 /로 시작하지 않는다.

→ 해석 너무 씹이라서 함수 써보면서 공부해야할 듯

<br>

## stat

file의 상태를 얻는다.

```c++
#include <sys/stat.h>

int fstat(int fildes, struct stat *buf);
int lstat(const char *restrict path, struct stat *restrict buf);
int stat(const char *restrict path, struct stat *restrict buf);
```

stat구조체

```c++
/*stat.h*/
struct stat {
	dev_t	  st_dev;		/* inode's device */
	ino_t	  st_ino;		/* inode's number */
	mode_t	  st_mode;		/* inode protection mode */
	nlink_t	  st_nlink;		/* number of hard links */
	uid_t	  st_uid;		/* user ID of the file's owner */
	gid_t	  st_gid;		/* group ID of the file's group */
	dev_t	  st_rdev;		/* device type */
#ifndef _POSIX_SOURCE
	struct	timespec st_atimespec;	/* time of last access */
	struct	timespec st_mtimespec;	/* time of last data modification */
	struct	timespec st_ctimespec;	/* time of last file status change */
#else
	time_t	  st_atime;		/* time of last access */
	long	  st_atimensec;		/* nsec of last access */
	time_t	  st_mtime;		/* time of last data modification */
	long	  st_mtimensec;		/* nsec of last data modification */
	time_t	  st_ctime;		/* time of last file status change */
	long	  st_ctimensec;		/* nsec of last file status change */
#endif
	off_t	  st_size;		/* file size, in bytes */
	int64_t	  st_blocks;		/* blocks allocated for file */
	u_int32_t st_blksize;		/* optimal blocksize for I/O */
	u_int32_t st_flags;		/* user defined flags for file */
	u_int32_t st_gen;		/* file generation number */
	int32_t	  st_lspare;
	int64_t	  st_qspare[2];
};
```

```c++
/*sys/types.h*/
typedef	u_int32_t	gid_t;		/* group id */
typedef	u_int32_t	ino_t;		/* inode number */
typedef	long		key_t;		/* IPC key (for Sys V IPC) */
typedef	u_int16_t	mode_t;		/* permissions */
typedef	u_int16_t	nlink_t;	/* link count */
typedef	quad_t		off_t;		/* file offset */
typedef	int32_t		pid_t;		/* process id */
typedef quad_t		rlim_t;		/* resource limit */
```

stat함수는 path로 지정된 파일에 대한 정보를 획득한다.

파일에 대한 rwx 권한은 요구되지 않으나, 파일의 경로에 명시된 directory들은 반드시 검색가능해야한다.

lstat함수는 stat함수와 다른점이 파일이 심볼릭 링크일때이다.

lstat함수는 심볼릭 링크에 대한 정보를 리턴하는데, stat함수는 심볼릭 링크가 참조중인 파일에 대한 정보를 리턴한다.

심볼릭 링크에서 st_mode 멤버변수는 파일타입 매크로들과 사용될때 유용한 정보를 포함한다.

그리고 st_size멤버변수는 심볼릭 링크에 포함된 경로의 길이를 가진다.

<br>

## unlink

파일 경로에 대해 해당 파일을 삭제하거나, 해당 파일이 참조하는 대상(ex, 심볼릭 링크)을 삭제한다.

### 헤더, 정의

```c++
#include <unistd.h>

int unlink(const char* pathname);
```

### 설명

파일시스템에서 name을 삭제한다.
- 만약 그 name이 파일에 대한 마지막 링크였고, 아무런 프로세스도 해당 그 파일을 연 상태가 아닌 경우, 
그 파일은 삭제되고, 해당 공간은 재사용할 수 있도록 비워진다.

- 하지만, 프로세스가 만약 연 상태였다면, 그 프로세스가 파일을 참조하기 위해 사용하는 파일디스크립터가 닫힐때까지 존재한다.

- 심볼릭 링크의 이름이라면, 해당 연결이 제거된다.

- 만약 이름이 소켓에 대한 이름이었담녀, fifo(first in first out?)또는 장치는 제거되나, 사용하고있던 프로세스는 여전히 사용할 수 있다.

### error

성공함녀 0이 리턴되나, 에러발생하면 -1이 이런되고 errno가 설정된다.

<br>

## execve

### 헤더, 정의

```c++
#include <unistd.h>

int execve(const char *path, char *const argv[], char *const envp[]);
```

### 설명

`execve` 함수는 호출한 프로세스를 새로운 프로세스로 변환한다.  
새로운 프로세스라 함은, path인자로 들어온 경로에 있는 파일에 의해 만들어진 프로세스이다.  
이 파일은 (1)실행가능하거나, (2)인터프리터를 위한 데이터 파일이다.   

실행가능한 오브젝트 파일은 데이터 페이지를 초기화하고 초기 프로그램을 표현하는 데이터 페이지를 가진  식별헤더로 이루어져있다.  
zero데이터로 초기화할 헤더로 추가 데이터를 지정할 수 있다.  

인터프리터 파일은 아래와 같은 포맷으로 시작한다.

`#! interpreter [arg ...]`
sh 파일을 작성할 때, 가장 상단에 이런 문구를 본 적이 있을텐데, 위와같은 문구를 만나게되면 뒤의 인자를 인터프리터로 실행하게된다.  

인터프리터 파일이 실행되면, 시스템이 해당 인터프리터를 실행한다.(#! /bin/bash 하면 bash로 쉘 스크립트 실행하듯)  

만약 옵션으로 args가 추어진다면 인터프리터에 대한 인자로 주어지게된다.  
원래 실행될 파일의 이름은 그 이후의 인자가 되거나, 첫 번째 인자가 된다.
인터프리터를 발동하는 원래 인자는 마지막 인자가 되고, 0번째 인자는 보통 실행파일이 된다.  

<br>

`argv`는 우리가 보통 main문에서 사용하는 인자이다.  
새로운 프로세스가 사용할 수 있게끔, 마지막 포인터(`char **argv`의 마지막 포인터)는 널포인터이고,  
1번째 원소(인덱스 0번쨰)는 실행된 프로그램의 이름이다.(path의 마지막 요소)  


<br>

envp또한 argv와 같은 형태의 문자열 포인터이다.  
이 배열에 대한 포인터는 보통 전역변수 `environ`에 저장되어있다.  
명령어에 대한 직접적인 인자가 아닌 형태로 프로세스에 문자열로 전달된다.  

<br>

호출한 프로세스 이미지에 열린 파일 디스크립터들은 close 플래그가 설정된 파일디스크립터들을  
제외하고는 새로운 프로세스 이미지에서 열린 상태로 유지된다.  
열린 상태의 파일디스크립터들은 `execve`함수의 영향을 받지 않는다.  

<br>

호출한 프로세스에서 무시되도록 설정된 시그널들은 새로운 프로세스에서 무시되도록 설정된다.  
호출한 프로세스 이미지에서 잡히도록 설정된 시그널들은 새로운 프로세스 이미지에서 기본동작을 하게된다.  
블럭된 시그널들은 signal action이 바뀌더라도 블럭된 상태로 유지된다.  
시그널 스택은 undefined 상태로 리셋된다.  

<br>

만약 새로운 프로세스 이미지 파일의 `set-user-ID mode bit`이 설정되면,  
새로운 프로세스 이미지의 유효 사용자 ID가 새로운 프로세스 이미지 파일의 소유자 ID가된다.  

만약 새로운 프로세스 이미지의 `set-user-group-ID mode bit`가 설정된다면,  
새로운 프로세스 이미지의 유효 그룹 ID 또한 새로운 프로세스 이미지 파일의 group ID가 된다.  

유효 사용자 ID의 경우, 일반적으로 실제 사용자 ID이다.

유효 그룹 ID는 그룹 리스트 중 첫 번째 요소이다.  

새로운 프로세스 이미지의 실제 사용자 ID, 실제 그룹 ID, 타 그룹 ID는 호출 프로세스와 같다.  

사용자 ID, 그룹 ID 처리가 끝나고나면, 유효 사용자 ID는 set-user-ID로 기록된다.  
그리고 유효 그룹 ID의 경우, set-group-ID로 저장되어 기록된다.  

`새로운 프로세스는 호출한 프로세스의 아래 속성을 상속받는다.`  

```sh
process ID           see getpid(2)
parent process ID    see getppid(2)
process group ID     see getpgrp(2)
access groups        see getgroups(2)
working directory    see chdir(2)
root directory       see chroot(2)
control terminal     see termios(4)
resource usages      see getrusage(2)
interval timers      see getitimer(2)
resource limits      see getrlimit(2)
file mode mask       see umask(2)
signal mask          see sigaction(2), sigsetmask(2)
```

execve함수는 현재 프로세스 이미지를 새로운 프로세스 이미지로 덮기때문에  
호출에 성공하면 반환할 프로세스가 없다.  

execve함수는 호출한 프로세스에 반환되면 에러가 발생한 것이고, 반환값은 -1이고,  
errno가 설정된다.


<br>

## dup, dup2

### 프로토타입

```c++
#include <unistd.h>

int dup(int fd);
int dup2(int fd, int fd2);
```

### 설명

`dup()`함수는 현재 존재하는 객체 디스크립터를 복사하고 호출한 프로세스에 그 값을 반환한다.  
`fildes2 = dup(fildes)`  
여기서 `fildes`인자는 프로세스마다 존재하는 디스크립터 테이블의 0보다 크거나 같은 작은 정수 인덱스이다.  
그 값은 반드시 table의 크기보다 작아야하고, 이 table의 크기는 `getdtablesize()`로 얻을 수 있다.  
함수를 호출되어 얻는 새로운 디스크립터는 프로세스가 사용중이지 않은 가장 낮은 숫자의 디스크립터이다.  

<br>

디스크립터에 의해 참조되는 객체는 `fildes2`와 `fildes`를 구분하지 않는다.  
그러므로, 만약 fildes2와 fildes가 파일을 여는 참조를 복사하면 `read, write, lseek`과 같은 시스템콜은 모두 하나의 호인터를 파일로 이동하게되고, append mode에선 `non-blocking I/O`와 `asynchronous I/O`는 참조간 공유된다.  
[참조](https://ju3un.github.io/network-basic-1/)  

만약 파일에서 분리된 포인터가 필요하다면 추가적인 open system call을 통해 파일에 대한 다른 참조를 얻어야한다.  
새 파일 디스크립터에 대한 `close-on-exec`플래그는 설정되지 않는다.  


<br>

`dup2()`함수는 `fildes2`라는 새로운 디스크립터의 값이 지정된다.  
만약 `fildes`와 `fildes2`의 값이 같다면, `dup2()`는 `fildes2`를 리턴하게된다.  
이 때는 아무런 변화가 디스크립터에게 생기지 않는다.  
다르다면, 만약 `fildes2`라는 디스크립터가 이미 사용중일때, `close`로 파일 디스크립터를 닫은 것처럼 `fildes2`를 할당해제해버린다.  

<br>

### 에러

성공 시, 새로운 파일디스크립터가 반환되나, 실패하면 -1이 리턴되고 errno가 설정된다.  


<br

# Minishell

## pipe : 파이프 생성

**의존성**: **`#include <unistd.h>`**

**원형**: **`int pipe(int** *pipefd***[2])**`

**설명**: 단방향 데이터 채널인 파이프를 생성한다. 프로세스간 통신에 사용됌.
배열 인자를 2로 받는 이유: pipefd[0]→파이프의 읽기전용, pipefd[1]→파이프의 쓰기전용이다.
파이프의 쓰기 끝에 기록된 데이터는 파이프의 읽기 끝에서 읽을 때까지 커널에 의해 버퍼링된다.
주로 부모프로세스와 자식프로세스간의 통신을 목적으로 사용된다.

**반환값**: 성공→0, 실패→-1 (에러를 나타내도록 errno가 설정)

**에러**:

**EMFILE**

너무 많은 파일 디스크립터가 프로세스에 의해 사용되고 있다.

**ENFILE**

시스템 파일 테이블이 꽉찼을경우

**EFAULT**

filedes 가 유효하지 못하다.

main:

```c
#include <sys/types.h>
       #include <sys/wait.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>
       #include <string.h>

       int
       main(int argc, char *argv[])
       {
           int pipefd[2];
           pid_t cpid;
           char buf;

           if (argc != 2) {
               fprintf(stderr, "Usage: %s <string>\n", argv[0]);
               exit(EXIT_FAILURE);
           }

           if (pipe(pipefd) == -1) {
               perror("pipe");
               exit(EXIT_FAILURE);
           }

           cpid = fork();
           if (cpid == -1) {
               perror("fork");
               exit(EXIT_FAILURE);
           }

           if (cpid == 0) {    /* Child reads from pipe */
               close(pipefd[1]);          /* Close unused write end */

               while (read(pipefd[0], &buf, 1) > 0)
                   write(STDOUT_FILENO, &buf, 1);

               write(STDOUT_FILENO, "\n", 1);
               close(pipefd[0]);
               _exit(EXIT_SUCCESS);

           } else {            /* Parent writes argv[1] to pipe */
               close(pipefd[0]);          /* Close unused read end */
               write(pipefd[1], argv[1], strlen(argv[1]));
               close(pipefd[1]);          /* Reader will see EOF */
               wait(NULL);                /* Wait for child */
               exit(EXIT_SUCCESS);
           }
       }
```

자식 프로세스는 파이프로부터 쓰지 않으므로 pipefd[1]을 close한다.

부모 프로세스는 파이프로부터 읽지 않으므로 pipefd[0]을 close한다.

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/51396c0f-a40e-458c-9ee2-04ec1b8dd587/Untitled.png)

# DIR

## opendir: 디렉토리 열기

**의존성:** **`#include <sys/types.h>`,** **`#include <dirent.h>`**

**원형:**  `**DIR *opendir(const char **name*)**`

**설명:** name디렉토리를 열고 스트림포인터를 리턴한다. 스트림은 디렉토리의 첫번째 요소의 위치를 가리킨다.

**반환값:** 디렉토리 스트림에대한 포인터를 반환. 에러→NULL

**에러**: 

EACCES

Permission 거부

EMFILE

프로세스에 의해서 너무 많은 파일이 열렸음

ENFILE

최근 시스템에 의해서 너무 많은 파일이 열렸음

ENOENT

**name**이 빈문자열 이거나 혹은 같은 이름의 디렉토리가 없음

ENOMEM

작업을 수행하기 위한 충분한 메모리가 없음

ENOTDIR

**name**이 디렉토리가 아님

main:

```c
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

int main()
{
    struct dirent *item;
    DIR *dp;

    dp = opendir("/Users/baggyumin/Desktop/42cursus");
    if (dp != NULL)
    {
        for(;;)
        {
            item = readdir(dp);
            if (item == NULL)
                break;
            printf("DIR : %s\n", item->d_name);
        }
        closedir(dp);
    }
}
```

## readdir: 디렉토리 읽기

**의존성**: **`#include <dirent.h>`**

**원형**: **`struct dirent *readdir(DIR ****dirp***)**`

**설명**: dirp가 가리키는 디렉토리 스트림의 다음 디렉토리 항목을 나타내는 dirent구조체에 대한 포인터를 반환한다.
—dirent 구조—

```c
struct dirent {
               ino_t          d_ino;       /* Inode number */ 아이오드 번호
               off_t          d_off;       /* Not an offset; see below */ 오프셋
               unsigned short d_reclen;    /* Length of this record */ 레코드(엔트리) 길이
               unsigned char  d_type;      /* Type of file; not supported
                                              by all filesystem types */ 파일유형
               char           d_name[256]; /* Null-terminated filename */ 파일이름
           };
```

**반환값**: 성공→dirent구조체에 대한 포인터 반환 끝에 도달시 NULL (errno 설정안됌), 실패→NULL (errno가 설정)

**에러**: 
**EBADF
유효하지않은 dirp**

[https://man7.org/linux/man-pages/man3/readdir.3.html](https://man7.org/linux/man-pages/man3/readdir.3.html)

## closedir: 디렉토리 닫기

**의존성**:**`#include <sys/types.h>`,** **`#include <dirent.h>`**

**원형**: **`int closedir(DIR *** *dirp* **)**`

**설명**: dirp와 연결된 디렉토리 스트림을 닫는다. dirp와 연결된 fd도 닫는다. 이 함수 호출 이후에 dirp를 사용할 수 없다.

**반환값**: 성공→0, 오류→-1 (errno 설정됌)

**에러**:

**EBADF**

유효하지않은 dirp

# ERROR

## strerror: 오류번호를 설명하는 문자열 반환

**의존성**: **`#include <string.h>`**

**원형**: **`char *strerror(int** *errnum***)**`

**설명**: errnum인수에 전달된 오류코드를 설명하는 문자열에 대한 포인터를 반환한다.

**반환값**: 오류번호에 따른 오류설명 문자열 반환, 오류번호를 알 수 없을경우는 `"Unknown error nnn"` 반환

**에러**:
**EINVAL**
errno의 값이 유효한 오류 번호가 아님

main:

```c
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main() {
  FILE* pFile;
  pFile = fopen("unexist.ent", "r");
  if (pFile == NULL)
    printf("Error opening file unexist.ent: %s\n", strerror(errno));
  return 0;
}
```

## errno: 에러의 번호

**의존성**: **`#include <errno.h>`**

**원형**: 

**설명**: 호출의 반환값이 오류를 나타날때만(-1, NULL) errno를 사용한다. 성공하는 함수에서 errno를 바꾸는것이 허용한다. 절대 errno의 값을 0으로 설정하지 않는다.

**반환값**:

**에러**:
[https://man7.org/linux/man-pages/man3/errno.3.html](https://man7.org/linux/man-pages/man3/errno.3.html)

## isatty: 파일 디스크립터가 터미널을 참조하는지 테스트

**의존성**: **`#include <unistd.h>`**

**원형**: **`int isatty(int** *fd* **)**`

**설명**: fd가 터미널을 참조하는 열린 파일 디스크립터인지 여부를 테스트한다.

**반환값**: fd가 ‘’ → 1, 아니면 0 (errno 설정)

**에러**:
**EBADF**
fd는 유효한 파일 디스크립터가 아님

main:

```c
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    int fd;
    // 표준입력은 터미널에 연결되어 있으므로 1을 출력한다.
    printf("%d\n", isatty(0));

    // 파일은 터미널에 연결되어 있지 않으므로 0을 출력한다.
    fd = open("test100", O_RDWR);
    printf("%d\n", isatty(fd));
    close(fd);

    fd = open("/dv/ttyS0", O_RDONLY);
    if (fd < -1)
    {
        printf("open error\n");
		exit(0);
    }
    printf("%d\n", isatty(fd));
    close(fd);
    exit(0);
}
```

## ttyname: 터미널의 이름 반환

**의존성**: **`#include <unistd.h>`**

**원형**: **`char *ttyname(int** *fd* **)**`

**설명**: fd를 열은 터미널 장치의 경로이름에 대한 포인터를 반환한다.=

**반환값**: 성공→경로 이름에대한 포인터 반환, 실패→NULL (errno설정)

**에러**:
**EBADF**

잘못된 fd

**ENODEV**

해당 경로 이름을 못찾음

**ENOTTY**

fd가 터미널 장치를 참조하지않음

main:

```c
#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("%s\n", ttyname(0));
}
```

## ttyslot: 현재 사용자 터미널의 슬롯을 찾음

**의존성**: **`#include <unistd.h>`**

**원형**: **`int ttyslot(void)`**

**설명**: ttyslot을 호출한 프로그램이 참조하는 터미널의 index를 반환한다. (터미널의 tty경로)

**반환값**: 성공→슬롯번호(터미널의 index) 반환, 실패→시스템에따라 0또는 -1

**에러**: X

main:

```c
#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("%d\n", ttyslot());
}
```

## ioctl: 제어장치(control device)

**의존성**: **`#include <sys/ioctl.h>`**

**원형**: **`int ioctl(int** *fd* **, unsigned long** *request* **, ...)**`

**설명**: 시스템콜로 device에게 요청을 보낼때 사용한다. Unix의 모든 장치는 파일로 추상화가 되어서 조작되는데 ioctl함수를 사용할때도 파일 조작을 통해 이뤄지므로 fd는 장치를 참조하는 파일 디스크립터가 된다. 두번째 인자는 fd가 참조하는 장치에게 보낼 코드다. 마지막 가변인자는 메모리 공간을 참조하는 포인터다. 일반적으로 마지막 인자의 가변인자는 `char*` 로 이용된다.

**반환값**: 성공→0 일부 ioctl은 반환값을 출력 매개변수로 사용한다(음수가 아닌값), 실패→-1 (errno 설정)

**에러**: 

**EBADF**
유효하지않은 fd

[https://richong.tistory.com/254](https://richong.tistory.com/254)

[https://mintnlatte.tistory.com/22](https://mintnlatte.tistory.com/22)

## getenv: 환경변수 가져오기

**의존성**: **`#include <stdlib.h>`**

**원형**: **`char *getenv(const char ****name***)**`

**설명**: name변수에 저장된 환경변수를 읽어온다. 환경변수는 “key=value”형식으로 저장되있으며 name은 key이름이 된다.

**반환값**: 성공→환경변수 값에 대한 포인터 반환, 실패→NULL

**에러**:

main:

```c
#include <stdlib.h>

#include <stdio.h>

int main(int argc, char **argv)
{
    char *value;
    value = getenv(argv[1]);

    if (value != NULL)
    {
        printf("%s=%s\n", argv[1], value);
    }

    return 0;
}
```

## tcsetattr: 터미널파일 fd에 대한 속성 설정

**의존성**: **`#include <termios.h>`,** **`#include <unistd.h>`**

**원형**: **`int tcsetattr(int** *fd***, int** *optional_actions***,**`**`const struct termios ****termios_p***)**`

**설명**: *termios_p 에 의해 참조되는 termios* 구조 에서 터미널과 관련된 매개변수를 설정한다.

fd: 터미널 파일 디스크립터

optional_actions: 동작 선택 (정해진 4가지의 action이 있음)

termios_p: 터미널 속성의 저장 주소

**반환값**: 성공→0, 실패→-1 (errno 설정)

**에러**:

## tcgetattr: 터미널파일 fd에 대한 속성 저장

**의존성**: **`#include <termios.h>`,** **`#include <unistd.h>`**

**원형**: **`int tcgetattr(int** *fd***, struct termios ****termios_p***)**`

**설명**: *fd* 가 참조하는 객체와 관련된 매개변수를 가져와 *termios_p 가 참조하는 termios* 구조 에 저장한다.

fd: 터미널 파일 디스크립터

termios_p: 터미널 속성의 저장 주소

**반환값**: 성공→0, 실패→-1 (errno 설정)

**에러**: 

# **terminfo 기능 데이터베이스에 대한 직접 curses 인터페이스**

**의존성**: **`#include <curses.h>`, `#include <term.h>`**

**반환값**: 

명시적으로 언급된 경우를 제외하고 정수를 반환하는 루틴은 실패 시 **ERR** 을 반환 하고 성공적인 완료 시 **OK**를 반환합니다.

포인터를 반환하는 루틴은 오류가 발생 **하면 NULL 을 반환합니다.**

## tgetent:

**원형**: **`int tgetent(char *bp, const char *name)`**

**설명**: **tgetent**루틴은 name 항목을 로드 *합니다* . 에*뮬레이션은 버퍼 포인터 bp* 를 무시한다.

**반환값**: 성공→1, 항목이 없으면→0, terminfo 데이터베이스를 찾을 수 없으면 -1

**에러**:

## tgetflag:

**원형**: `int tgetflag(char *id)`

**설명**: tgetflag 루틴 은 *id* 에 대한 boolean 항목을 가져오거나 사용할 수 없는 경우 0을 가져옵니다.

**반환값**: 

**에러**:

## tgetnum:

**원형**: `int tgetnum(char *id);`

**설명**: tgetnum 루틴 은 *id* 에 대한 숫자 항목을 가져오거나 사용할 수 없는 경우 -1을 가져옵니다.

**반환값**:

**에러**:

## tgetstr:

**원형**: `char *tgetstr(char *id, char **area)`

**설명**: tgetstr 루틴 은 *id* 에 대한 문자열 항목을 반환 하거나 사용할 수 없는 경우 0을 반환합니다. **tputs** 를 사용 하여 반환된 문자열을 출력합니다. *반환 값은 area* 가 가리키는 버퍼에도 복사되고 area *값* 은 이 값을 끝내는 null을 넘어서 가리키도록 업데이트됩니다.

**반환값**:

**에러**:

## tgoto:

**원형**: `char *tgoto(const char *cap, int col, int row)`

**설명**: tgoto루틴 은 매개변수를 지정된 기능으로 인스턴스화합니다. 이 루틴의 출력은 **tputs** 로 전달됩니다 .

**반환값**:

**에러**:

## tputs:

**원형**: `int tputs(const char *str, int affcnt, int (*putc)(int))`

**설명**: tputs루틴은 터미널 출력결과를 나타낸다. 마지막 putc 함수포인터는 ASCII문자값을 인자로 받아서 표준출력의 쓰기 작업으로 터미널에 ASCII문자를 출력한다.

**반환값**:

**에러**:







#pipeline, redirection, Here Documents

## pipeline

pipeline은 `|`로 구분된 한 개 이상의 일련의 명령어이다.  
파이프라인의 포맷은  

```c++
command [| command2]
```

command의 표준출력은 `pipe`로 연결되어 command2의 표준입력이 된다.  
`이 연결은 명령어로 식별된 rediections 전에 먼저 수행된다.!!!`

pipeline의 return state는, pipefail옵션이 켜져있지 않으면 `마지막 커맨드의 exit status`가 된다.  
만약 pipefail옵션이 켜져있다면, pipeline의 return status는 실패한 가장 오른쪽의 명령어의 반환값이 되고,  
모두 성공적으로 종료되면 0이 된다.  

!옵션이랑 pipefail 옵션, time 옵션, -p 옵션은 서브젝트 요구사항 아니므로 패스.  

pipeline의 각각의 커맨드는 모두 분리된 프로세스로 실행된다.  

<br>

## redirection

command가 실행되기 전에, 쉘에 의해 특수하게 지정된 기능을 통해 input과 output이 `redirect`될 수 있다.  
이 redirection의 경우, 현재 쉘 실행 환경을 위해 파일을 열거나 닫는데에 사용될 수 있다.  
`<`, `>`과 같은 redirection 연산자는 간단한 명령어 내에 나타나거나, 명령을 따를 수 있다.  
`연산 순서는 왼쪽에서 오른쪽으로 가면서 연산자가 나타난 순서대로`이다...  

<br>

파일 디스크립터 숫자가 없는 상태에서 redirection 연산자가 `<`라면, 그 redirection은 stdin(fd 0)을 참조한다.  
만약 `>`라면, 해당 redirection은 stdout(fd 1)을 참조한다.  

<br>

`redirection의 순서는 상당히 중요하다.`  

예를들어,  

```sh
ls > dirlist 2>&1
```

위 명령어는 stdout, stderr 모두를 dirlist로 지시한다.  

반면,  

```sh
ls 2>&1 > dirlist
```

이 명령어의 경우에는, stdout만을 dirlist에 direct한다.  
왜냐하면 stderr는, stdout이 dirlist에 redirect되기전에 stdout으로 복제되기 때문이다.  

<br>

bash는 redirection에 사용되는 몇몇 특별한 파일이름들을 컨트롤한다.  
이에는  

```sh
/dev/fd/fd -> fd가 유효한 숫자라면, fd는 복제된다.
/dev/stdin -> fd 0이 복제된다.
/dev/stdout -> fd 1이 복제된다.
/dev/stderr -> fd 2가 복제된다.
/dev/tcp/host/port -> 만약 host가 유효한 호스트이름이거나, 인터넷 주소이고, port가 정수로된 port이름이거나 서비스이름이라면 bash는 해당 소켓에 상응하는 TCP연결을 시도한다.
/dev/udp/host/port -> 위와 동일한 조건하에 UDP 연결을 시도한다.  
```

9 이상의 숫자로된 파일디스크립터를 사용한 redirection은 주의되어야하는데, 그 이유가 쉘이 내부적으로 사용하는 파일디스크립터와 충돌할 수 있기 때문이다.  


<br>

### Redirecting Input

```sh
[n]<word
```

input의 redirection은 word라는 이름을 가진 파일을 fd `n`로 읽어들일 수 있게 하거나,  
n이 지정되지 않으면 0으로 읽어들일 수 있게 한다.  

<br>

### Redirecting Output

```sh
[n]>word
```

output의 redirection은 word라는 이름을 가진 파일을 fd `n`으로 쓸 수 있게 하거나,  
n이 이정되지 않으면 1로 쓸 수 있게한다.  
만약 파일이 없다면, 생성되는데, 있다면 크기가 0이된다.(존재하던 데이터 무시한다는 의미)  

<br>

### Appending Redirected Output

```sh
[n]>>word
```

이 방식의 redirecction은 fd n을 가진 파일의 끝에 붙인다.  
이 역시, n이 생략되면 stdout울 redirection하게된다.  

<br>


## Here Documents

```sh
<<[-]word
		here-document
	delimiter
```

이 타입의 redirection은word로 끝나는 문자를 만날때까지 문자열을 입력받을 수 있다.  
이걸 테스트해보려면  

```sh
cat << EOF
The current working directory is: $PWD
You are logged in as: $(whoami)
EOF
```
이걸 해보면 EOF로 감싸진 내부의 문자를 cat 커맨드의 stdin으로 바꿔서 날려주는 것을 볼 수 있다.  

EOF말고도, 다른 문자열로도 할 수 있는데, 반드시 `word`와 완전히 동일해야한다.  
단, word가 `t t`처럼 공백이 포함된 문자열인 경우, 뒤의 t는 씹히고, 앞의 t만 `word`로 인식되어  
delimiter로는 `t`하나만 입력해야한다.  















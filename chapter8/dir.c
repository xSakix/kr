#include <linux/limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
// #include <limits.h>
#include <malloc.h>
#include <sys/dir.h>


#define DIRSIZE 256

// typedef struct{
//     int fd;
//     struct dirent d;
// } _DIR;


// struct direct{
//     ino_t d_ino;
//     char d_name[DIRSIZE];
// };

void fsize(char *);


int main(int argc, char *argv[]){

    if(argc == 1){
        fsize(".");
    }else{
        while(--argc > 0){
            fsize(*++argv);
        }
    }
    
    return 0;
}

void dirwalk(char *, void (*fcn)(char*));

void fsize(char *name){

    struct stat stbuf;

    if(stat(name, &stbuf) == -1){
        fprintf(stderr, "fsize: can't access %s\n",name);
        return;
    }

    if((stbuf.st_mode & S_IFMT) == S_IFDIR){
        dirwalk(name, fsize);
    }

    printf("%8ld %s\n", stbuf.st_size, name);
}

// DIR *_opendir(char *dirname){

//     int fd;
//     struct stat stbuf;
//     DIR *dp;

//     if((fd = open(dirname,O_RDONLY,0)) == -1 || fstat(fd, &stbuf) == -1 || (stbuf.st_mode & S_IFMT) != S_IFDIR || (dp = (DIR*)malloc(sizeof(DIR*))) == NULL){
//         return NULL;
//     }
    
//     dp->fd = fd;
//     //strcpy(dp->d.d_name, dirname);

//     //printf("%s:%d\n", dirname, dp->fd);

//     return dp;
// }

// void _closedir(DIR *dp){
//     if(dp){
//         close(dp->fd);
//         free(dp);
//     }
// }

// struct dirent *_readdir(DIR *dp){
//     struct direct dirbuf;
//     static struct dirent d;
//     int n;


//     //printf("%s:%d\n", dp->d.d_name, dp->fd);
    
//     while((n = read((dp->fd, (char*)&dirbuf, sizeof(dirbuf))) == sizeof(dirbuf)){
//         printf("bytes read:%d\n", n);
//         printf("DIR ino:%ld\n", dirbuf.d_ino);
//         printf("DIR:%s\n",dirbuf.d_name);

//         if(dirbuf.d_ino == 0){
//             continue;
//         }
//         d.d_ino = dirbuf.d_ino;
//         strncpy(d.d_name, dirbuf.d_name, DIRSIZE-2);
//         d.d_name[DIRSIZE-1] = '\0';
//         return &d;
//     } 
//     printf("bytes read:%d\n", n);
//     printf("DIR ino:%ld\n", dirbuf.d_ino);
//     printf("DIR:%s\n",dirbuf.d_name);
    

//     return NULL;
// }

void dirwalk(char *dir, void (*fcn)(char*)){
    char name[PATH_MAX];

    struct dirent *dp;
    DIR *dfd;

    if((dfd = opendir(dir)) == NULL){
        fprintf(stderr, "dirwalk: can't open %s\n",dir);
        return;
    }

    while((dp = readdir(dfd)) != NULL){
        if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0){
            continue;
        }

        if(strlen(dir) + strlen(dp->d_name) + 2 > PATH_MAX){
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->d_name);
        }else{
            sprintf(name, "%s/%s",dir,dp->d_name);
            (*fcn)(name);
        }
    }

    closedir(dfd);
}
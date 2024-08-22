// 9. Write a program to print the following information about a given file.
// a. inode
// b. number of hard links
// c. uid
// d. gid
// e. size
// f. block size
// g. number of blocks
// h. time of last access
// i. time of last modification
// j. time of last change

#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat fileStat;
    const char *filename = "p8file.txt";  

    if (stat(filename, &fileStat) < 0) {
        perror("Error");
        return 1;
    }

    printf("Inode: %lu\n", fileStat.st_ino);
    printf("Hard Links: %lu\n", fileStat.st_nlink);
    printf("UID: %u\n", fileStat.st_uid);
    printf("GID: %u\n", fileStat.st_gid);
    printf("Size: %ld bytes\n", fileStat.st_size);
    printf("Block Size: %ld bytes\n", fileStat.st_blksize);
    printf("Blocks: %ld\n", fileStat.st_blocks);
    printf("Last Access: %ld\n", fileStat.st_atime);
    printf("Last Modification: %ld\n", fileStat.st_mtime);
    printf("Last Change: %ld\n", fileStat.st_ctime);

    return 0;
}

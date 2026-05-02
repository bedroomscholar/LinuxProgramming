#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat sb;

    if (stat(argv[1], &sb) == -1) {
        perror("stat");
        return 1;
    }

    printf("File: %s\n", argv[1]);
    printf("I-node number:   %lu\n", (unsigned long)sb.st_ino);
    printf("File type:       ");

    switch (sb.st_mode & S_IFMT) {
        case S_IFREG:  printf("regular file\n");    break;
        case S_IFDIR:  printf("directory\n");        break;
        case S_IFLNK:  printf("symbolic link\n");   break;
        case S_IFCHR:  printf("character device\n"); break;
        case S_IFBLK:  printf("block device\n");     break;
        case S_IFIFO:  printf("FIFO/pipe\n");        break;
        case S_IFSOCK: printf("socket\n");           break;
        default:       printf("unknown\n");          break;
    }

    printf("Permissions:     %o (octal)\n", sb.st_mode & 0777);
    printf("Hard links:      %lu\n", (unsigned long)sb.st_nlink);
    printf("Owner UID:       %u\n", sb.st_uid);
    printf("Group GID:       %u\n", sb.st_gid);
    printf("Size:            %ld bytes\n", (long)sb.st_size);
    printf("Block size:      %ld bytes\n", (long)sb.st_blksize);
    printf("Blocks:          %ld (512-byte units)\n", (long)sb.st_blocks);
    printf("Last access:     %s", ctime(&sb.st_atime));
    printf("Last modify:     %s", ctime(&sb.st_mtime));
    printf("Last change:     %s", ctime(&sb.st_ctime));

    return 0;
}

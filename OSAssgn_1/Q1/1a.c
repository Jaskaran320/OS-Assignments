#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
int errno;
char *section[26];
int marks[26][6];
float assgn[6];
void data(){
    int fd = open("student_record.csv", O_RDONLY);
    if(fd == -1){
        printf("Error number: %d\n", errno);
        perror("File open");
        return;
    }
    int i = 0;
    char *lines[27];
    char *ch = (char *)calloc(850, sizeof(char));
    int sz = read(fd, ch, 850);
    if (sz == -1){
        printf("Error number: %d\n", errno);
        perror("File read");
        return;
    }
    char *token = strtok(ch,"\n");
    while (token!=NULL){
        lines[i++] = token;
        token = strtok(NULL,"\n");
    }
    for (int i = 0; i < 26; i++){
        token = strtok(lines[i+1], ",");
        token = strtok(NULL, ",");
        section[i] = token;
        token = strtok(NULL, ",");
        marks[i][0] = atoi(token);
        token = strtok(NULL, ",");
        marks[i][1] = atoi(token);
        token = strtok(NULL, ",");
        marks[i][2] = atoi(token);
        token = strtok(NULL, ",");
        marks[i][3] = atoi(token);
        token = strtok(NULL, ",");
        marks[i][4] = atoi(token);
        token = strtok(NULL, ",");
        marks[i][5] = atoi(token);
    }
    close(fd);
}
int main(){
    float sum = 0;
    int status;
    float avg = 0;
    char str[1000];
    int fd = open("written_records1.txt", O_WRONLY);
    if(fd == -1){
        printf("Error number: %d\n", errno);
        perror("File open");
        exit(0);
    }
    data();
    pid_t pid = fork();
    if (pid < 0){
        perror("Fork");
    }
    else if (pid == 0){
        write(fd, "The average for section A is\n", 29);
        for (int j = 0; j < 6; j++){
            sum = 0;
            for (int i = 0; i < 26; i++)
                if (!strcmp(section[i], "A"))
                    sum += marks[i][j];
            avg = sum/9;
            snprintf(str, 1000, "The average marks for assignment %d is %f\n", (j+1), avg);
            write(fd, str, strlen(str));
        }
        exit(0);
    }
    else{
        waitpid(pid, &status, 0);
        write(fd, "\nThe average for section B is\n", 30);
        for (int j = 0; j < 6; j++){
            sum = 0;
            for (int i = 0; i < 26; i++)
                if (!strcmp(section[i], "B"))
                    sum += marks[i][j];
            avg = sum/17;
            snprintf(str, 1000, "The average marks for assignment %d is %f\n", (j+1), avg);
            write(fd, str, strlen(str));
        }
        exit(0);
    }
}
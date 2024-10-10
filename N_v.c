#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int areStringsEqual(const char *str1, const char *str2) {
    return strcmp(str1, str2) == 0; // 如果相等，返回 1；否則返回 0
}

void initRepo() {
    system("git init");
    printf("The N_version warehouse has been created.\n");
}

void clone_github(const char *url) {
    char command[256];
    snprintf(command, sizeof(command), "git clone \"%s\"", url);
    system(command);
    printf("N_v is cloning the repository: %s\n", url);
}

void git_log_oneline() {
    system("git log --oneline");
}

void push_existing(const char *branch_name) {
    char command[256];
    snprintf(command, sizeof(command), "git push --set-upstream %s", branch_name);
    system(command); // 推送到指定的分支
    printf("N_v is pushing to the existing repository on branch: %s\n", branch_name);
}

void saveChanges(const char *status_name) {
    system("git add .");
    char command[256];
    snprintf(command, sizeof(command), "git commit -m \"%s\"", status_name);
    system(command);
    printf("Changes have been saved with status: %s\n", status_name);
}

void check_out(const char *id) {
    char command[256];
    snprintf(command, sizeof(command), "git checkout %s", id);
    system(command);
    printf("Code has been checked out to: %s\n", id);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command> [options]\n", argv[0]);
        return 1;
    }

    if (areStringsEqual(argv[1], "init")) {
        initRepo();
    } else if (areStringsEqual(argv[1], "save")) {
        if (argc < 3) {
            printf("Usage: %s save <status_name>\n", argv[0]);
            return 1;
        }
        const char *status_name = argv[2];
        saveChanges(status_name);
    } else if (areStringsEqual(argv[1], "get")) {
        if (argc < 3) {
            printf("Usage: %s get <repository_url>\n", argv[0]);
            return 1;
        }
        const char *url = argv[2];
        clone_github(url);
    } else if (areStringsEqual(argv[1], "log")) {
        git_log_oneline();
    } else if (areStringsEqual(argv[1], "check")) {
        if (argc < 3) {
            printf("Usage: %s check <branch_or_commit_id>\n", argv[0]);
            return 1;
        }
        const char *id = argv[2];
        check_out(id);
    } else if (areStringsEqual(argv[1], "push_existing")) {
        if (argc < 3) {
            printf("Usage: %s push_existing <branch_name>\n", argv[0]);
            return 1;
        }
        const char *branch_name = argv[2];
        push_existing(branch_name);
    } else {
        printf("Unknown command: %s\n", argv[1]);
    }

    return 0;
}

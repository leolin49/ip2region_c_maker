#include <stdio.h>
#include <string.h>

void print_help(char *argv[]) {
    printf("ip2region xdb c maker\n");
    printf("%s [command] [command options]\n", argv[0]);
    printf("Command: \n");
    printf("  gen      generate the binary db file\n");
}

void gen_db(int argc, char *argv[]) {
    int i, n, err;
    // for args parse
    char *r, key[33] = {'\0'}, val[256] = {'\0'};
    char src_file[256] = {'\0'}, dst_file[256] = {'\0'};
    int index_policy = 1;
    // Check input parameters
    for (i = 2; i < argc; i++) {
        r = argv[i];
        if (strlen(r) < 5) {
            continue;
        }

        if (r[0] != '-' || r[1] != '-') {
            continue;
        }
        
        if (strchr(r, '=') == NULL) {
            printf("missing = for args pair '%s'\n", r);
            return;
        }

        n = sscanf(r+2, "%32[^=]=%255[^\n]", key, val);
        if (n != 2) {
            printf("invalid option flag `%s`\n", r);
            return;
        }
        if (strcmp(key, "src") == 0) {
            snprintf(src_file, sizeof(src_file), "%s", val);
        } else if (strcmp(key, "dst") == 0) {
            snprintf(dst_file, sizeof(dst_file), "%s", val);
        } else if (strcmp(key, "index") == 0) {
            // todo
        } else {
            printf("undefined option `%s`\n", r);
            return;
        }
    }

    if (strlen(src_file) < 1 || strlen(dst_file) < 1) {
        printf("%s gen [command options]", argv[0]);
        printf("options:");
        printf(" --src string   source ip text file path");
        printf(" --dst string   destination binary xdb file path");
        return;
    }

    // err = 
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help(argv);
        return 0;
    }

    char *opt = argv[1];
    if (strcmp(opt, "gen") == 0) {
        gen_db(argc, argv);
    } else {
        print_help(argv);
    }

    return 0;
}
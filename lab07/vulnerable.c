// vuln_complex.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line_stdin(void) {
    char buf[256];
    if (!fgets(buf, sizeof(buf), stdin)) return NULL;
    size_t len = strlen(buf);
    if (len && buf[len-1] == '\n') buf[len-1] = '\0';
    return strdup(buf); // caller must free
}

/* 1) Format-string: printf with user-controlled format */
void format_vuln() {
    char *s = read_line_stdin();
    if (!s) return;
    printf(s);                 // <-- vulnerable
    free(s);
}

/* 2) Use-after-free: free then use */
void use_after_free_vuln() {
    char *p = malloc(64);
    if (!p) return;
    strcpy(p, "temporary");
    free(p);
    printf("still: %s\n", p);  // <-- use-after-free
}

/* 3) Integer overflow / allocation bug: attacker-supplied counts */
void alloc_vuln() {
    char *len_s = read_line_stdin();     // e.g. attacker supplies a large number
    if (!len_s) return;
    long count = atol(len_s);            // unvalidated
    if (count <= 0) { free(len_s); return; }
    // multiply count by element size (e.g. 8) -> risk overflow
    size_t total = (size_t)count * 8;    // possible overflow
    char *buf = malloc(total);           // allocation too small
    if (!buf) {
        free(len_s);
        return;
    }
    memset(buf, 'A', total);            // buffer overrun if overflow happened
    free(buf);
    free(len_s);
}

/* 4) Unsafe system call: concatenating user input into command */
void system_vuln() {
    char *arg = read_line_stdin();
    if (!arg) return;
    char cmd[512];
    snprintf(cmd, sizeof(cmd), "cp %s /tmp/backup", arg); // injection if arg contains shell metacharacters
    system(cmd); // <-- dangerous if arg untrusted
}

int main(void) {
    puts("Enter something for format_vuln:");
    format_vuln();

    puts("Enter something for use_after_free_vuln:");
    use_after_free_vuln();

    puts("Enter a number for alloc_vuln (big number to trigger overflow):");
    alloc_vuln();

    puts("Enter a filename for system_vuln:");
    system_vuln();

    return 0;
}

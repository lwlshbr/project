#include <stdio.h>
#include <string.h>

struct s {
    char xh[20], zh[20], pw[20];
    int m, e, c, j, a;
};

int main() {
    struct s s[20];
    int n = 10;
    char tu[10], tp[10];
    const char tuc[] = "lll", tpc[] = "llll";

    for (int i = 0; i < 10; i++) {
        sprintf(s[i].xh, "%d", i+1);
        sprintf(s[i].zh, "%d", i+1);
        sprintf(s[i].pw, "%d", i+1);
        s[i].m = 70 + i*2; s[i].e = 75 + i; s[i].c = 72 + i*2;
        s[i].j = 68 + i*2; s[i].a = 73 + i*2;
    }

    int ok = 0, att = 3;
    printf("=== Teacher Sys ===\n");
    while (att--) {
        printf("ID: "); scanf("%s", tu);
        printf("PW: "); scanf("%s", tp);
        if (!strcmp(tu, tuc) && !strcmp(tp, tpc)) { ok = 1; break; }
        att ? printf("Wrong! Remain: %d\n", att) : printf("3 wrong, exit!\n");
    }
    if (!ok) return 0;
    printf("Login ok!\n");

    int op;
    do {
        printf("\n1.Add 2.Mod 3.View 4.Exit\nOpt: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                if (n >= 20) { printf("Full!\n"); break; }
                struct s ns;
                printf("XH Acc PW M E C J A: ");
                scanf("%s%s%s%d%d%d%d%d", ns.xh, ns.zh, ns.pw, &ns.m, &ns.e, &ns.c, &ns.j, &ns.a);
                s[n++] = ns;
                printf("Add ok! Total: %d\n", n);
                break;

            case 2:
                char acc[20]; int idx = -1;
                printf("Acc to mod: "); scanf("%s", acc);
                for (int i = 0; i < n; i++) if (!strcmp(s[i].zh, acc)) idx = i;
                if (idx == -1) { printf("Not found!\n"); break; }
                printf("New M E C J A: ");
                scanf("%d%d%d%d%d", &s[idx].m, &s[idx].e, &s[idx].c, &s[idx].j, &s[idx].a);
                printf("Mod ok!\n");
                break;

            case 3:
                if (!n) { printf("No data!\n"); break; }
                for (int i = 0; i < n; i++) {
                    int tot = s[i].m + s[i].e + s[i].c + s[i].j + s[i].a;
                    int r = 1;
                    for (int j = 0; j < n; j++) if (i != j && (s[j].m+s[j].e+s[j].c+s[j].j+s[j].a) > tot) r++;
                    printf("\nStd%d: XH=%s Acc=%s PW=%s M=%d E=%d C=%d J=%d A=%d Tot=%d Avg=%.1f Rank=%d\n",
                           i+1, s[i].xh, s[i].zh, s[i].pw, s[i].m, s[i].e, s[i].c, s[i].j, s[i].a, tot, tot/5.0f, r);
                }
                break;

            case 4: printf("Exit!\n"); break;
            default: printf("Invalid!\n");
        }
    } while (op != 4);

    return 0;
}

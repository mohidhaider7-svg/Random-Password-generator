#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Password
{
    int length;
    int choice;
    char pass[21];
};
void generate(struct Password *p, int i)
{
    char num[] = "0123456789";
    char alp[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char mix[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char strong[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    if (i == p->length)
    {
        p->pass[i] = '\0';
        return;
    }
    switch (p->choice)
    {
        case 1:
            p->pass[i] = num[rand() % 10];
            break;
        case 2:
            p->pass[i] = alp[rand() % 52];
            break;
        case 3:
            p->pass[i] = mix[rand() % 62];
            break;
        case 4:
            p->pass[i] = strong[rand() % 70];
            break;
    }
    generate(p, i + 1);
}
int main()
{
    struct Password p;
    FILE *fp;
    srand(time(NULL));
    printf("Enter password length (max 20): ");
    scanf("%d", &p.length);
    if (p.length <= 0 || p.length > 20)
    {
        printf("Invalid length");
        return 0;
    }
    printf("1. Numbers\n");
    printf("2. Alphabets\n");
    printf("3. Alphabets + Numbers\n");
    printf("4. Strong (Alphabets + Numbers + Symbols)\n");
    printf("Choice: ");
    scanf("%d", &p.choice);
    if (p.choice < 1 || p.choice > 4)
    {
        printf("Invalid choice");
        return 0;
    }
    generate(&p, 0);
    printf("\nGenerated Password: %s\n", p.pass);
    fp = fopen("password.txt", "w");
    if (fp != NULL)
    {
        fprintf(fp, "Password: %s", p.pass);
        fclose(fp);
        printf("Password saved successfully in password.txt\n");
    }
    else
    {
        printf("File saving error\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    int j;
    int x;
};
struct sparse
{
    int m;
    int n;
    int non_zero;
    struct element *ele;
};
void create(struct sparse *s)
{
    s->ele = (struct element *)malloc(s->non_zero * sizeof(struct sparse));
}
int non_zeros_count(int n, int m, int A[n][m])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}
void display_sparse(struct sparse s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (i == s.ele[k].i && j == s.ele[k].j)
            {
                printf("%d ", s.ele[k++].x);
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main(void)
{
    int n1, m1 = 0;
    scanf("%d %d", &n1, &m1);
    int x[n1][m1];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            scanf("%d", &x[i][j]);
        }
    }

    struct sparse matrix_1;
    struct sparse *s1;
    s1 = &matrix_1;
    s1->m = n1;
    s1->n = m1;
    s1->non_zero = non_zeros_count(n1, m1, x);
    s1->ele = (struct element *)malloc(s1->non_zero * sizeof(struct sparse));

    int cnt = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            if (x[i][j] != 0)
            {
                s1->ele[cnt].i = i;
                s1->ele[cnt].j = j;
                s1->ele[cnt].x = x[i][j];
                cnt++;
            }
        }
    }

    int n2 = 0;
    int m2 = 0;

    scanf("%d%d", &n2, &m2);
    int y[n2][m2];
    int trans[m2][n2];
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            scanf("%d", &y[i][j]);
        }
    }

    struct sparse matrix_2;
    struct sparse *s2;
    s2 = &matrix_2;
    s2->m = n2;
    s2->n = m2;
    s2->non_zero = non_zeros_count(n2, m2, y);
    s2->ele = (struct element *)malloc(s2->non_zero * sizeof(struct sparse));
    cnt = 0;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            if (y[i][j] != 0)
            {
                s2->ele[cnt].i = i;
                s2->ele[cnt].j = j;
                s2->ele[cnt].x = y[i][j];
                cnt++;
            }
        }
    }
    // computing the transpose
    for (int i = 0; i < n2; ++i)
    {
        for (int j = 0; j < m2; ++j)
        {
            trans[j][i] = y[i][j];
        }
    }

    struct sparse matrix_3;
    struct sparse *s3;
    s3 = &matrix_3;
    s3->m = n2;
    s3->n = m2;
    s3->non_zero = non_zeros_count(n2, m2, y);
    s3->ele = (struct element *)malloc(s2->non_zero * sizeof(struct sparse));
    cnt = 0;
    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (trans[i][j] != 0)
            {
                s3->ele[cnt].i = i;
                s3->ele[cnt].j = j;
                s3->ele[cnt].x = trans[i][j];
                cnt++;
            }
        }
    }
    struct sparse matrix_4;
    struct sparse *s4;
    s4 = &matrix_4;
    s4->m = n1;
    s4->n = m2;
    cnt = 0;
    for (int i = 0; i < s1->non_zero; i++)
    {
        for (int j = 0; j < s2->non_zero; j++)
        {
            if (s1->ele[i].j == s3->ele[j].j)
            {
                cnt++;
            }
        }
    }
    s4->ele = (struct element *)malloc(cnt * sizeof(struct sparse));
    cnt = 0;
    for (int i = 0; i < s1->non_zero; i++)
    {
        for (int j = 0; j < s3->non_zero; j++)
        {
            if (s1->ele[i].j == s3->ele[j].j)
            {
                s4->ele[cnt].i = s1->ele[i].i;
                s4->ele[cnt].j = s3->ele[j].i;
                s4->ele[cnt].x = s1->ele[i].x * s3->ele[j].x;
                cnt++;
            }
        }
    }
    int new_cnt = 0;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            if (s4->ele[i].i == s4->ele[j].i && s4->ele[i].j == s4->ele[j].j)
            {
                new_cnt += 1;
            }
        }
    }
    struct sparse matrix_5;
    struct sparse *s5;
    s5 = &matrix_5;
    s5->m = n1;
    s5->n = m2;
    s5->ele = (struct element *)malloc(500 * sizeof(struct sparse));
    int new_cnt2 = 0;
    int flag = 0;
    int flag2 = 0;
    int arr[500] = {};
    for (int i = 0; i < cnt; i++)
    {
        s5->ele[i].x = 0;
    }

    for (int i = 0; i < cnt; i++)
    {
        flag = 0;
        if (arr[i] != 1)
        {
            for (int j = i + 1; j < cnt; j++)
            {
                if (arr[j] != 1)
                {
                    if (s4->ele[i].i == s4->ele[j].i && s4->ele[i].j == s4->ele[j].j)
                    {
                        s5->ele[new_cnt2].i = s4->ele[i].i;
                        s5->ele[new_cnt2].j = s4->ele[j].j;
                        if (flag2 == 0)
                        {
                            s5->ele[new_cnt2].x += s4->ele[i].x;
                        }
                        flag2 = 1;
                        s5->ele[new_cnt2].x += s4->ele[j].x;
                        arr[i] = 1;
                        arr[j] = 1;
                        flag = 1;
                    }
                }
            }
            if (flag == 0)
            {
                s5->ele[new_cnt2].i = s4->ele[i].i;
                s5->ele[new_cnt2].j = s4->ele[i].j;
                s5->ele[new_cnt2].x = s4->ele[i].x;
                new_cnt2++;
            }
            else
                new_cnt2++;
            flag2 = 0;
        }
    }
    if (m1 != n2)
    {
        printf("Not Valid");
        return 0;
    }
    display_sparse(matrix_5);

    return 0;
}

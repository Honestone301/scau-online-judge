#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>//C++
using namespace std;
struct LNode
{
    int data;
    LNode* next;
};
void createList(LNode*& L, int n)
{/**< 尾插法创建单链表 */
    LNode* r, * p;
    r = L = new LNode;/**< 创建头结点 */
    L->next = NULL;
    for (int i = 1; i <= n; i++)
    {
        p = new LNode;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}
void trv(LNode* L)
{ /**< 一个简单的链表遍历函数，供编程过程中测试使用 */
    L = L->next;
    while (L)
    {
        cout << L->data << ' ';
        L = L->next;             
    }
}
int getK(LNode* L, int k)
{
    LNode* p = L->next;
    int n = 0;
    while (p!=NULL) {
        n++;
        p = p->next;
    }

    if (k > n) {
        return -1;
    }
    int x = n - k;
    p = L;
    for (int i = 0; i < x;i++) {

    }

}
int main()
{
    int n, k;
    LNode* L;
    cin >> n >> k;
    createList(L, n);
    //trv(L);
    cout << getK(L, k);
    return 0;
}
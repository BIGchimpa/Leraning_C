int potenciaDez(int i){
    int num = 1;
    while (i > 0){
        num *= 10;
        i--;
    }
    return num;
}

struct ListNode* novoNo(int valor, int digits, int i){
    if (digits == 0){
        return NULL;
    }
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = (valor % (potenciaDez(i)))/(potenciaDez(i-1));
    i++;
    digits--;
    newNode->next = novoNo(valor,digits,i);
    return newNode;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int num1 = 0;
    int num2 = 0;
    int finalNum = 0;
    int i = 0;
    struct ListNode* laux;
    laux = l1;

    do{
        num1 += laux->val*(potenciaDez(i));
        i++;
        laux = laux->next;
    } while (laux != NULL);

    laux = l2;
    i = 0;

    do{
        num2 += laux->val*(potenciaDez(i));
        i++;
        laux = laux->next;
    } while (laux != NULL);

    finalNum = num1 + num2;
    int d = 0;

    while (finalNum >= potenciaDez(d)){
        d++;
    }
    if (d == 0){
        d = 1;
    }
    i = 1;
    struct ListNode* FirstNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    FirstNode->val = (finalNum % (potenciaDez(i)))/(potenciaDez(i-1));
    i++;
    d--;
    FirstNode->next = novoNo(finalNum,d,i);
    return FirstNode;

}

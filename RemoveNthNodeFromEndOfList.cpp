#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// we get a linked list of nodes. Remove the nth from the end
// just iterate to the position and remove the bastard
ListNode* removeNthFromEnd(ListNode* head, int n) {
        
    // maintain two pointers with a delay of n steps. When we get to the end we already have the 
    // pointer to the size - nth one
    ListNode* lag = head;
    ListNode* current = head;
    int lagAmount = 0;
    int size = 0;
    while(lagAmount < n+1 && current != NULL){


        
        current = current->next; // creating the space between them
        lagAmount++;
        size++;
    }

    while(current != NULL){
        current = current->next;
        lag = lag->next;
        size++;

    }


    // we've reached the end here
    if(size == n){
        head = head->next;
    }
    else{
        lag->next = lag->next->next;
    }

    return head;
}



int main(){
    cout << "hello world" << endl;
}
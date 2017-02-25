#include "gsatck.h"
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

#define LOGE(error) cout << error;

struct less_g {
    // implementetion expects that

    bool operator()(int oldElement,
                    int newElement) { // newElement is the element we are just inserting

        cout << newElement << endl;
        if (newElement < oldElement)
            return true; // when the function returns true, we swap.
        return false;
    }
};

char *toReverse = "I am a string";

template <typename B> int gSizeOf(B var) {
    int count = 0;
    while (var) {
        var = var >> 1;

        count++;
    }

    return count;
}

string reverseString(char *toBeReversed) {
    char *toBeReversed_char = toBeReversed;

    char reversed[strlen(toBeReversed)];

    for (int i = strlen(toBeReversed) - 1, j = 0; i >= 0; i--, j++) {
        reversed[j] = toBeReversed_char[i];
    }

    return string(reversed);
}

string reverseString2(char *toBeReversed) {
    int strLen = strlen(toBeReversed);

    char *tempChar = new char[strLen];

    memcpy(tempChar, toBeReversed, strLen);

    strLen--;
    cout << toBeReversed[11] << endl;

    for (int i = 0; i <= strLen / 2; i++) {
        swap(tempChar[i], tempChar[strLen - i]);
    }

    return string(tempChar);
}

int nthFib(int n) {
    int prev[] = {0, 1};

    int nFib = 0;

    if (n == 1)
        return 1;
    for (int i = 1; i < n; i++) {
        nFib = prev[0] + prev[1];

        prev[0] = prev[1];
        prev[1] = nFib;
    }

    return nFib;
}

int nthFibRecurs(int first, int second, int n, int i) {
    int t = first + second;

    i++;
    if (1 == n)
        return 1;
    if (i == n)
        return t;
    else {
        first = second;
        second = t;
        nthFibRecurs(first, second, n, i);
    }
}

int nthFibRecurs2(int n) {
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;
    return (nthFibRecurs2(n - 2) + nthFibRecurs2(n - 1));
}

int nthFactorial(int n) {
    if (n == 1)
        return 1;
    return n * nthFactorial(n - 1);
}

void printTimesTable(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%*d ", 3, i * j);
        }
        printf("\n");
    }
}

void printOddss(int n) {
    if (n % 2 == 1)
        printf("%d, ", n);
    if (n == 1)
        return;
    printOddss(n - 1);
}

bool isBalanced(string to_check) {
    // const char* to_check = to_check_str.c_str();

    gStack<char> balancer;

    for (int i = 0; i < to_check.length(); i++) {
        if (to_check[i] == '[' || to_check[i] == '(' || to_check[i] == '{') {
            balancer.push(to_check[i]);
        } else {
            if ((to_check[i] == ']' || to_check[i] == '}' || to_check[i] == ')') &&
                balancer.empty())
                return false;
            else {
                if (to_check[i] == ']') {
                    if (balancer.top() == '[') {
                        balancer.pop();
                        continue;
                    } else
                        return false;
                }

                if (to_check[i] == ')') {
                    if (balancer.top() == '(') {
                        balancer.pop();
                        continue;
                    } else
                        return false;
                }

                if (to_check[i] == '}') {
                    if (balancer.top() == '{') {
                        balancer.pop();
                        continue;
                    } else
                        return false;
                }
            }
        }
    }

    if (!balancer.empty())
        return false;
    return true;
}

void formatToHex(int r, int g, int b) { printf("%02X %02X  %02X\n", r, g, b); }

int reverse2(int x) {
    int result = 0;

    while (x != 0) {
        int tail = x % 10;
        int newResult = result * 10 + tail;
        if ((newResult - tail) / 10 != result) {
            return 0;
        }
        result = newResult;
        x = x / 10;
    }

    return result;
}
int reverse(int x) {
    int result = 0;

    while (x != 0) {
        int tail = x % 10;
        int newResult = result * 10 + tail;

        if (newResult - tail != result * 10)
            return 0;

        result = newResult;

        x = x / 10;
    }

    return result;
}

void swapp(int &a, int &b) {
    a = a ^ b; // get xor
    b = a ^ b; // b is now former a
    a = a ^ b; // a is now former b
}


void evenOdd(int *array, int len) {
    unsigned int oddPointer = 0;
    unsigned int evenPointer = 0;

    while (oddPointer < len) {

        if(evenPointer == len) break;

        if (array[oddPointer] % 2 != 0) {


            while (evenPointer < len) {

                if(evenPointer< oddPointer)evenPointer= oddPointer+1;

                if(array[evenPointer]%2 ==0){

                     //cout << array[oddPointer] << " mod: " << array[oddPointer] % 2 << " swap: " << array[evenPointer]<< endl;
                    swap(array[oddPointer] , array[evenPointer]);

                    evenPointer++;

                    break;
                }

                evenPointer++;
            }
        }

        oddPointer++;
    }


}

void evenOdd2(int *array, int len){

    unsigned int oddPointer = len-1;
    unsigned int evenPointer = 0;


    while(evenPointer < oddPointer){

        if(array[evenPointer]%2 ==0){

            evenPointer++;

        }else{

         swapp(array[evenPointer], array[oddPointer--]);

        }



    }


}

void dutch(int *array, int len, int pivot){

    unsigned int putIndex =0;

    //less than
    for(int i=putIndex+1; i< len; i++){

        if(array[putIndex] < pivot){
            putIndex++;
            continue;
        }
        if(array[i] < pivot){
            swapp(array[i], array[putIndex]);
             putIndex++;
        }
    }

    //equal
    for(int i=putIndex+1; i< len; i++){

        if(array[putIndex] == pivot){
            putIndex++;
            continue;
        }
        if(array[i] == pivot){
            swapp(array[i], array[putIndex]);
             putIndex++;
        }
    }

}


int main(int argc, char *argv[]) {
    //    priority_queue<int, vector<int>, less_g> minQ;

    //    minQ.push(4);
    //    minQ.push(1);
    //    minQ.push(3);
    //    minQ.push(6);

    // LOGE("test");

    // int testThis[] = {1,2,3,4,5,6};

    // int(* cool)[2] = (int(*)[2])&testThis[0];

    // cout << "Top element " <<  minQ.top() << endl;
    // testing heap

    // BSTNode root;

//    int a = 4;
//    int b = 5;

//    int arr[] ={1,0,2,3,1,4,6,0,1,5};

//    dutch(arr, 10 ,1);

//    for(int i=0; i< 10; i++){

//        cout << arr[i] << " " ;
//    }

    // swapp(a,b);
    // cout << "a: "<< a << "b: " << b;
    // cout << reverse(1534236469);

    node* head = new node(0, NULL);
    sll myLinkedList(head);

    for(int i=1; i<10; i++){

        myLinkedList.insert(new node(i,NULL));
    }

    cout << "before " << myLinkedList;
    cout << endl;

    node* nn = head->next;
    head->next = NULL;
    myLinkedList.updateTail(head);
    node* nk;

    while(nn != NULL){

        nk= nn->next;
        nn->next = head;
        head = nn;
        nn = nk;
    }

    myLinkedList.updateHead(head);
    cout << "after " << myLinkedList;

    return 0;
}

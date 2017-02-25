#include "gsatck.h"


aStack::aStack(){

    //initialize stack
    subStack = new int*[maxSubStacks];
    subStack[0] = new int[maxNoElementes];
    size = new int[maxSubStacks];
    size[0] =0;

}

void aStack::clear(){
    size =0;
}

void aStack::pop(){
    //get the current sub stack and get its last element

    if(currSubstack ==0 && size[currSubstack] ==0){

        //stack is empty
        return;
    }

    int back = subStack[currSubstack][size[currSubstack]];
    size[currSubstack]--;

    if(size[currSubstack] < 0)currSubstack--;

}

void aStack::push(int val){

    if(size[currSubstack] == maxNoElementes){

        if(currSubstack++ != maxSubStacks){
        subStack[currSubstack] = new int[maxNoElementes];
        size[currSubstack] = 0;
        }else{

            return; // stack is full
        }

    }

     subStack[currSubstack][size[currSubstack]] = val;
     size[currSubstack]++;

}

//
// Created by Muhammad Moiz on 04/07/2023.
//

#include "Queue.cpp"
#define print(x) std::cout<<x<<std::endl

int main()
{
    auto queue_obj = new Queue::queue<int>(10);

    for (int i = 21; i <=30; i++)
    {
       queue_obj->enqueue(i);
        print("Adding :: "<< i << " || Size of stack :: " << queue_obj->size());
    }

    queue_obj->dequeue();
    std::cout << "After popping (size) : ";
    std::cout <<queue_obj->size() <<std::endl;

    print("----------------------------------");
    queue_obj->printQueue();
    print("\n----------------------------------");

    print("Current size " << queue_obj->size());
    size_t stack_size = queue_obj->size();
    for(auto i=0; i<stack_size; i++){
        queue_obj->dequeue();
    }
    queue_obj->front();
    // delete stack object
    delete queue_obj;

    return 0;
}
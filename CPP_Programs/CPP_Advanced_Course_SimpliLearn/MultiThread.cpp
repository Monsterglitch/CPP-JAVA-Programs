// #include<iostream>
// #include<pthread.h>

// void *InsideThread() {
//     std::cout<<"Inside Thread!"<<std::endl;
// }
// int main() {
//     pthread_t tid;
//     pthread_create(&tid, NULL, &InsideThread, NULL)
//     pthread_join(tid, NULL)

//     std::cout<<"Main Thread!"<<std::endl;
//     return 0;
// }
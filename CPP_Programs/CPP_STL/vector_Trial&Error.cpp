#include <iostream>
#include <vector>

int main() {
    // std::vector<int>* vect1 = new std::vector<int>(5);
    // std::vector<std::vector<int> > vect2(5, std::vector<int>(2, -1));
    // for(std::vector i : vect2) {
    //     for(int j : i) {
    //         std::cout<<j<<"\t";
    //     }
    //     std::cout<<std::endl;
    // }
    std::vector<int> vect3;
    vect3.push_back(1);
    vect3.push_back(2);
    vect3.push_back(3);
    vect3.push_back(4);
    vect3.push_back(5);

    // Iterating using advanced for loop
    for(int i : vect3) {
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;

    // Iterating using auto keyword
    for(auto & j : vect3) {
        std::cout<<j<<"\t";
    }
    
    std::cout<<std::endl;
    

    /* 
        Iterator                  vs                Auto Iterator
        Specific Container Types       Deduces the iterator type automatically      
        (EXplicit Declaration)         (Implicit Action)
    */

    // Iterating using auto iterator 
    for(auto k = vect3.begin(); k < vect3.end(); k++) {
        std::cout<<*k<<"\t";
    }

    std::cout<<std::endl;


    // Iterating using traditional for loop
    // for(int k = 1; k < 5; k++) {
    //     std::cout<<vect3[k]<<"\t";
    // } 
    // Vector array-like iteration using a for loop, starting at index 0.
    
    std::cout<<std::endl<<-vect3[4]; // Last value becomes negative
    return 0;
}
#include <fstream>
#include <iostream>

int main(){

    //  unsigned char data[] = 
    // {
    //     0xbb,
    //     0x09,
    //     0xbb,
    //     0x05,
    //     0xab,
    //     0x00
    // };
     unsigned char data[] = 
    {
        0x11,
        0x80,
        0x00,
        0x00,
        0x01
    };

    std::ofstream file("C:\\Users\\Kirin\\Desktop\\VM\\src\\example.dat", std::ios::out|std::ios::binary|std::ios::trunc);
    if(file.is_open()){
        file.write((char *)data, sizeof(data));  
    }
    file.close();
    // std::cin.get();
}



#include <fstream>

#include "../ARCVM/MNEMONICS.h"

int main(){

        //                     // start program
        // _UBCONST_PUSH_,
        // 0xff,
        // _NEW_ARR_,
        // 0x02,
        // _DUP_,
        // _UBCONST_PUSH_,
        // 0x08,
        // _UBCONST_PUSH_,
        // 0x03,
        // _UBA_STORE_,
        // _REF_STORE_,
        // 0x00,
        // _REF_LOAD_,
        // 0x00,
        //                 // end program

     unsigned char data[] = 
    {
        0x42,           // start file signature
        0x72,
        0x61,
        0x6e,
        0x64,
        0x6f,
        0x6e,
        0x4b,
        0x69,
        0x72,
        0x69,
        0x6e,
        0x63,
        0x69,
        0x63,
        0x68,           // end file signature

                        // start of function table
        0x02,           // number of functions
                        
        'm',
        'a',
        'i',
        'n',
        0x00,

        'a',
        'd',
        'd',
        0x00,
        
        _UBCONST_PUSH_,     // bootstrap code
        0x05,
        _CALL_LOCAL_,   
        'm',
        'a',
        'i',
        'n',
        0x00,

        _EXIT_,         // exit
        0x00, 


                        // start main
        0xff,
        0xff,
        'f',
        'n',
        'm',
        'a',
        'i',
        'n',
        0x00,
        
        0x01,           // local variable count
        0x01,           // arg count

        0x02,           // arg types
                    
        _UB_LOAD_,
        0x00,
        _UBCONST_PUSH_,
        0x04,
        _CALL_LOCAL_,
        'a',
        'd',
        'd',
        0x00,
        _RET_,
                        // end main
        

                        // start add
        0xff,
        0xff,
        'f',
        'n',
        'a',
        'd',
        'd',
        0x00,

        0x02,           // local variable count
        0x02,           // arg count

        0x02,           // arg types
        0x02,

        _UB_LOAD_,
        0x00,
        _UB_LOAD_,
        0x01,
        _UB_ADD_,
        _RET_,

    };

    std::ofstream file("C:\\Users\\Kirin\\Desktop\\ARCANE\\ARCVM\\src\\example.arcb", std::ios::out|std::ios::binary|std::ios::trunc);
    if(file.is_open())
        file.write((char *)data, sizeof(data));  
    file.close();
}



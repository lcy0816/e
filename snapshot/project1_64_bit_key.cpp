//Chenyang Li
//HOMEWORK
//This is the main function of the program
//which will have the input of an external file
//and use it as an key
//After that, we have an user input choice as well
//DO THIS IN CHAR ARRAY NEXT TIME

#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>
#include <bitset>  
#include <stdio.h>

using namespace std;

const int SIZE = 16;
const int ROUND = 16;
const int SUB_KEY_LENGTH = 12;
unsigned long long int ftable[256] =
{0xa3,0xd7,0x09,0x83,0xf8,0x48,0xf6,0xf4,0xb3,0x21,0x15,0x78,0x99,0xb1,0xaf,0xf9,  
    0xe7,0x2d,0x4d,0x8a,0xce,0x4c,0xca,0x2e,0x52,0x95,0xd9,0x1e,0x4e,0x38,0x44,0x28,  
    0x0a,0xdf,0x02,0xa0,0x17,0xf1,0x60,0x68,0x12,0xb7,0x7a,0xc3,0xe9,0xfa,0x3d,0x53,  
    0x96,0x84,0x6b,0xba,0xf2,0x63,0x9a,0x19,0x7c,0xae,0xe5,0xf5,0xf7,0x16,0x6a,0xa2,  
    0x39,0xb6,0x7b,0x0f,0xc1,0x93,0x81,0x1b,0xee,0xb4,0x1a,0xea,0xd0,0x91,0x2f,0xb8,  
    0x55,0xb9,0xda,0x85,0x3f,0x41,0xbf,0xe0,0x5a,0x58,0x80,0x5f,0x66,0x0b,0xd8,0x90,  
    0x35,0xd5,0xc0,0xa7,0x33,0x06,0x65,0x69,0x45,0x00,0x94,0x56,0x6d,0x98,0x9b,0x76,  
    0x97,0xfc,0xb2,0xc2,0xb0,0xfe,0xdb,0x20,0xe1,0xeb,0xd6,0xe4,0xdd,0x47,0x4a,0x1d,  
    0x42,0xed,0x9e,0x6e,0x49,0x3c,0xcd,0x43,0x27,0xd2,0x07,0xd4,0xde,0xc7,0x67,0x18,  
    0x89,0xcb,0x30,0x1f,0x8d,0xc6,0x8f,0xaa,0xc8,0x74,0xdc,0xc9,0x5d,0x5c,0x31,0xa4,  
    0x70,0x88,0x61,0x2c,0x9f,0x0d,0x2b,0x87,0x50,0x82,0x54,0x64,0x26,0x7d,0x03,0x40,  
    0x34,0x4b,0x1c,0x73,0xd1,0xc4,0xfd,0x3b,0xcc,0xfb,0x7f,0xab,0xe6,0x3e,0x5b,0xa5,  
    0xad,0x04,0x23,0x9c,0x14,0x51,0x22,0xf0,0x29,0x79,0x71,0x7e,0xff,0x8c,0x0e,0xe2,  
    0x0c,0xef,0xbc,0x72,0x75,0x6f,0x37,0xa1,0xec,0xd3,0x8e,0x62,0x8b,0x86,0x10,0xe8,  
    0x08,0x77,0x11,0xbe,0x92,0x4f,0x24,0xc5,0x32,0x36,0x9d,0xcf,0xf3,0xa6,0xbb,0xac,  
    0x5e,0x6c,0xa9,0x13,0x57,0x25,0xb5,0xe3,0xbd,0xa8,0x3a,0x01,0x05,0x59,0x2a,0x46};

int main()
{
    ifstream file_key;
    char * filename1 = new char[ strlen("key.txt") + 1];
    strcpy(filename1, "key.txt");
    file_key.open(filename1);
    delete [] filename1;

    ifstream file_plaintext;
    char * filename2 = new char[ strlen("plaintext.txt") + 1];
    strcpy(filename2, "plaintext.txt");
    file_plaintext.open(filename2);
    delete [] filename2;

    char * key = new char[SIZE];// save the key from the file
    // unsigned char * key_temp = new unsigned char[SIZE];// save the key from the file

    unsigned long long int k = 0;// the converted key format
    unsigned long long int w = 0;// the converted key format
    // unsigned long long int musk[8] = 0;// the converted key format
    char * plaintext = new char[SIZE];
    char * plaintext_temp = new char[SIZE];
    bool repeat = false;
    int choice = 0;

    cout << "Welcome to cs585" << endl;
    cout << "This is the plaintext we have: " << endl;
    if(file_plaintext.is_open())//file exits or not
    {
        file_plaintext.get(plaintext, 100, '|');file_plaintext.ignore(100, '|');
        while (file_plaintext && !file_plaintext.eof())
        {
            file_plaintext.get(plaintext, 100, '|');file_plaintext.ignore(100, '|');
        }
        cout << plaintext << endl;
        file_plaintext.close();//Close the file
    }
    cout << endl;
    // for(int i = 0; i < sizeof(plaintext); ++i) { 
    //     cout << hex << (int)plaintext[i] << " " <<endl;

    //     sprintf(plaintext, "%x%x%x%x%x%x%x%x", plaintext[0], plaintext[1], plaintext[2], plaintext[3], plaintext[4], plaintext[5], plaintext[6], plaintext[7]);
    //     // plaintext_temp[i] = (int)plaintext[i];
    // }
        sprintf(plaintext, "0x%x%x%x%x%x%x%x%x", plaintext[0], plaintext[1], plaintext[2], plaintext[3], plaintext[4], plaintext[5], plaintext[6], plaintext[7]);

    cout << hex << plaintext << " test " <<endl;


    // w =(unsigned long long int) atoi(plaintext);
    // w = atoi(plaintext);
    // cout << hex << plaintext_temp << endl;

    w = stoull(plaintext, nullptr, 0);
    // cout << hex << w << endl;
    // cout << w << endl;
    cout << "This is the key we have: " << endl;
    // if(file_key.is_open())//file exits or not
    // {
    //     file_key.get(key, 100, '|');file_key.ignore(100, '|');
    //     while (file_key && !file_key.eof())
    //     {
    //         file_key.get(key, 100, '|');file_key.ignore(100, '|');
    //     }
    //     // cout << "0x" << key << endl;
    //     cout << key << endl;
    //     file_key.close();//Close the file
    // }
    if(file_key.is_open())//file exits or not
    {
        file_key.get(key, 100, '|');file_key.ignore(100, '|');
        while (file_key && !file_key.eof())
        {
            file_key.get(key, 100, '|');file_key.ignore(100, '|');
        }
        // cout << "0x" << key << endl;
        cout << key << endl;
        file_key.close();//Close the file
    }
    // key_temp = (unsigned char) key;
    k = stoull(key, nullptr, 0);

    cout << "round keys generated: " <<endl;
    unsigned long long int **ary = new unsigned long long int*[ROUND];//save all the sub keys 
    for(int i = 0; i < ROUND; ++i) {
        ary[i] = new unsigned long long int[SUB_KEY_LENGTH];
    }

    // cout << "This is the 15th element in the key, just for test" << endl;
    // cout << key[14] <<endl;
    // cout << key[15] <<endl;
    //cout << hex << key << endl;
    // printf("%llu", k);//k is fine 


    cout << hex << k << endl;
    // k >>= 4;
    // cout << hex << k << endl;
    
    // bool test;
    // for (int i = 63; i >= 0; --i) {
    //     if (i % 4 == 3) {
    //         cout << endl << dec << i << "~" << dec << i - 3 << endl;   
    //     }
    //     test = k & (1 << i);
    //     cout <<  test << " ";
    // }//this thing is wrong
    
    //test sub key generation for the first round
    bool to_be_msb, msb;
    unsigned long long one = 1;
    for (int j = 0; j < ROUND; ++j){
        cout << endl;
        for (int i = 0; i < SUB_KEY_LENGTH; ++i) {
            msb = k & (one << 63);
            to_be_msb = k & (one << 62);
            // k |= 0x4000000000000000;//set to_be_msb to 1

            // cout << "msb is " << msb << " to_be_msb is " << to_be_msb << endl;
            k <<= 1;
            // if (i == 0 ? msb : to_be_msb) {
            if (msb == 1){
                k |= 1;
            }//otherwise, do nothing, we have the 0 we want
            // cout << hex << k << " " << endl;

            int add_on = i % 4;
            if ((j * 4 + add_on) % 8 == 0 ){
                ary[j][i] = k & 0xff;
            }
            if ((j * 4 + add_on) % 8 == 1 ){
                ary[j][i] = k & 0xff00;
                ary[j][i] >>= 8;
            }
            if ((j * 4 + add_on) % 8 == 2 ){
                ary[j][i] = k & 0xff0000;
                ary[j][i] >>= 16;
            }
            if ((j * 4 + add_on) % 8 == 3 ){
                ary[j][i] = k & 0xff000000;
                ary[j][i] >>= 24;
            }
            if ((j * 4 + add_on) % 8 == 4 ){
                ary[j][i] = k & 0xff00000000;
                ary[j][i] >>= 32;
            }
            if ((j * 4 + add_on) % 8 == 5 ){
                ary[j][i] = k & 0xff0000000000;
                ary[j][i] >>= 40;
            }
            if ((j * 4 + add_on) % 8 == 6 ){
                ary[j][i] = k & 0xff000000000000;
                ary[j][i] >>= 48;
            }
            if ((j * 4 + add_on) % 8 == 7 ){
                // if (to_be_msb == 0)
                    ary[j][i] = k & 0xff00000000000000;

                ary[j][i] >>= 56;
            }

            // cout << hex << ary[0][i] <<' ';
            cout << ary[j][i] <<' ';
            // cout << endl;
        }
    }
    cout << endl;
    // cout << hex << w << endl;
    // cout << hex << k << endl;
    // unsigned long long int *g;
    // g[1] = w & 
    // for(int i = 3; i < 7; ++i) {
    //     g[i] = 
    // }
    unsigned long long int *r = new unsigned long long int[6];//save all the sub keys 
    unsigned long long int *g = new unsigned long long int[13];//save all the sub keys 
    unsigned long long int *t = new unsigned long long int[2];//save all the sub keys 
    unsigned long long int *f = new unsigned long long int[2];//save all the sub keys 
    unsigned long long int *c = new unsigned long long int[4];//save all the sub keys 
    // for(int i = 0; i < 6; ++i) {
    //     g[i] = new unsigned long long int[6];
    // }
    cout << "This is w^k: "<< hex << (w^k) << endl;

    r[0] = (w^k) & 0xffff000000000000;
    r[0] >>= 48;

    cout << "This is r0: " << r[0] << endl;
    r[1] = (w^k) & 0xffff00000000;
    r[1] >>= 32;

    r[2] = (w^k) & 0xffff0000;
    r[2] >>= 16;//R0 second half

    r[3] = (w^k) & 0xffff;

    // g[3] = (unsigned long long int) ftable(g[2] ^ ary[0][0]) ^ g[1];
    // cout << hex << (unsigned long long int)(g[2] ^ ary[0][0]) <<endl;
    for (int j = 0; j < 16; ++j){
        cout << "Beginning of Round: " << j << endl;
        g[1] = r[0] & 0xff00;//R0 first half 
        g[1] >>= 8;
        g[2] = r[0] & 0xff;//R0 second half

        // unsigned int temp = g[2] ^ (int) ary[0][0];
        // cout << (ftable[g[2] ^ (int) ary[0][0]] ^ g[1]) << endl;
        g[3] = ftable[g[2] ^ (int) ary[j][0]] ^ g[1];
        g[4] = ftable[g[3] ^ (int) ary[j][1]] ^ g[2];
        g[5] = ftable[g[4] ^ (int) ary[j][2]] ^ g[3];
        g[6] = ftable[g[5] ^ (int) ary[j][3]] ^ g[4];

        // cout << "test of g6: " << (g[5] ^ (int) ary[j][3]) << endl;
        for (int i = 1; i < 7; ++i)
        {
            // cout <<"g" << i << " is " << g[i] << " ";
            cout <<"g" << i << ": " << g[i] << " ";
        }
        t[0] = (g[5] << 8) + g[6];

        cout << endl;

        g[7] = r[1] & 0xff00;//R0 first half 
        g[7] >>= 8;
        g[8] = r[1] & 0xff;//R0 second half
        // g[7] = (w^k) & 0xff0000000000;
        // g[7] >>= 40;//R1 first half 

        // g[8] = (w^k) & 0xff00000000;
        // g[8] >>= 32;//R0 second half

        // g[3] = (unsigned long long int) ftable(g[2] ^ ary[0][0]) ^ g[1];
        // cout << hex << (unsigned long long int)(g[2] ^ ary[0][0]) <<endl;

        // unsigned int temp = g[2] ^ (int) ary[0][0];
        // cout << (ftable[g[2] ^ (int) ary[0][0]] ^ g[1]) << endl;
        g[9] = ftable[g[8] ^ (int) ary[j][4]] ^ g[7];
        g[10] = ftable[g[9] ^ (int) ary[j][5]] ^ g[8];
        g[11] = ftable[g[10] ^ (int) ary[j][6]] ^ g[9];
        g[12] = ftable[g[11] ^ (int) ary[j][7]] ^ g[10];

        for (int i = 7; i < 13; ++i)
        {
            // cout <<"g" << i << " is " << g[i] << " ";
            cout <<"g" << i - 6 << ": " << g[i] << " ";
        }
        t[1] = (g[11] << 8) + g[12];

        cout << endl;

        // cout << dec << "t0: " << t[0]<< " t1: " << t[1] << endl;
        cout << "t0: " << t[0]<< " t1: " << t[1] << endl;

        // cout << "This is the test key " << hex << (ary[0][8] << 8) + ary[0][9] << endl;
        f[0] = (t[0] + 0x2 * t[1] + (ary[j][8] << 8) + ary[j][9]) % 0x10000;
        cout << "f0: " << f[0] << " ";

        // cout << "This is the test key " << hex << (ary[0][10] << 8) + ary[0][11] << endl;
        f[1] = (0x2 * t[0] + t[1] + (ary[j][10] << 8) + ary[j][11]) % 0x10000;

        cout << "f1: " << f[1] << " ";


        r[5] = r[0];
        r[6] = r[1];

        r[0] = f[0] ^ r[2];
        r[1] = f[1] ^ r[3];

        r[2] = r[5];
        r[3] = r[6];
        cout << endl;
        cout << "Block: ";
        for (int i = 0; i < 4; ++i)
        {
            cout << r[i];
        }

        cout << endl;
    }
    // cout << "The key is " << k << endl;
    // cout << r[2] << endl;
    c[0] = r[2] ^ (k >> 48);
    c[1] = r[3] ^ (k & 0xffff00000000) >> 32;
    c[2] = r[0] ^ (k & 0xffff0000) >> 16;
    c[3] = r[1] ^ (k & 0xffff);
    cout << "Ciphertext: ";
    for (int i = 0; i < 4; ++i){
        cout << c[i];
        r[i] = c[i];
    }


    cout << endl;

    cout << "This is the dcryptioin part: ***************" << endl;
    
    r[0] ^= (k >> 48);
    r[1] ^= (k & 0xffff00000000) >> 32;
    r[2] ^= (k & 0xffff0000) >> 16;
    r[3] ^= (k & 0xffff);

    cout << r[0] << endl;

    for (int j = 15; j >= 0; --j){
        // for (int i = 0; i < 4; ++i){
        //         cout << r[i];
        // }
        cout << endl;
        cout << "Beginning of Round: " << j << endl;
        g[1] = r[0] & 0xff00;//R0 first half 
        g[1] >>= 8;
        g[2] = r[0] & 0xff;//R0 second half

        // unsigned int temp = g[2] ^ (int) ary[0][0];
        // cout << (ftable[g[2] ^ (int) ary[0][0]] ^ g[1]) << endl;
        g[3] = ftable[g[2] ^ (int) ary[j][0]] ^ g[1];
        g[4] = ftable[g[3] ^ (int) ary[j][1]] ^ g[2];
        g[5] = ftable[g[4] ^ (int) ary[j][2]] ^ g[3];
        g[6] = ftable[g[5] ^ (int) ary[j][3]] ^ g[4];

        // cout << "test of g6: " << (g[5] ^ (int) ary[j][3]) << endl;
        for (int i = 1; i < 7; ++i)
        {
            // cout <<"g" << i << " is " << g[i] << " ";
            cout <<"g" << i << ": " << g[i] << " ";
        }
        t[0] = (g[5] << 8) + g[6];

        cout << endl;

        g[7] = r[1] & 0xff00;//R0 first half 
        g[7] >>= 8;
        g[8] = r[1] & 0xff;//R0 second half
        // g[7] = (w^k) & 0xff0000000000;
        // g[7] >>= 40;//R1 first half 

        // g[8] = (w^k) & 0xff00000000;
        // g[8] >>= 32;//R0 second half

        // g[3] = (unsigned long long int) ftable(g[2] ^ ary[0][0]) ^ g[1];
        // cout << hex << (unsigned long long int)(g[2] ^ ary[0][0]) <<endl;

        // unsigned int temp = g[2] ^ (int) ary[0][0];
        // cout << (ftable[g[2] ^ (int) ary[0][0]] ^ g[1]) << endl;
        g[9] = ftable[g[8] ^ (int) ary[j][4]] ^ g[7];
        g[10] = ftable[g[9] ^ (int) ary[j][5]] ^ g[8];
        g[11] = ftable[g[10] ^ (int) ary[j][6]] ^ g[9];
        g[12] = ftable[g[11] ^ (int) ary[j][7]] ^ g[10];

        for (int i = 7; i < 13; ++i)
        {
            // cout <<"g" << i << " is " << g[i] << " ";
            cout <<"g" << i - 6 << ": " << g[i] << " ";
        }
        t[1] = (g[11] << 8) + g[12];

        cout << endl;

        // cout << dec << "t0: " << t[0]<< " t1: " << t[1] << endl;
        cout << "t0: " << t[0]<< " t1: " << t[1] << endl;

        // cout << "This is the test key " << hex << (ary[0][8] << 8) + ary[0][9] << endl;
        f[0] = (t[0] + 0x2 * t[1] + (ary[j][8] << 8) + ary[j][9]) % 0x10000;
        cout << "f0: " << f[0] << " ";

        // cout << "This is the test key " << hex << (ary[0][10] << 8) + ary[0][11] << endl;
        f[1] = (0x2 * t[0] + t[1] + (ary[j][10] << 8) + ary[j][11]) % 0x10000;

        cout << "f1: " << f[1] << " ";
        for (int i = 0; i < 4; ++i){
                cout << r[i];
        }

        r[5] = r[0];
        r[6] = r[1];

        r[0] = f[0] ^ r[2];
        r[1] = f[1] ^ r[3];

        r[2] = r[5];
        r[3] = r[6];
        cout << endl;
        cout << "Block: ";
        for (int i = 0; i < 4; ++i)
        {
            cout << r[i];
        }

        cout << endl;
    }

    c[0] = r[2] ^ (k >> 48);
    c[1] = r[3] ^ (k & 0xffff00000000) >> 32;
    c[2] = r[0] ^ (k & 0xffff0000) >> 16;
    c[3] = r[1] ^ (k & 0xffff);
    cout << "Plaintext in hex: ";
    for (int i = 0; i < 4; ++i){
        cout << hex << c[i];

        // c[i] >>= 2;
    }


    cout << endl << "Let's see the real plaintext:" <<endl;

    // sprintf(plaintext, "%c%c%c%c",c[0], c[1], c[2], c[3]);

    // c[1] = (c[0] & 0xff00) >> 8;
    // cout << c[0] << endl;
    // printf("%c\n", c[0]);
    // printf("%c\n", c[1]);
    // printf("%c\n", c[2]);
    // printf("%c\n", c[3]);
    plaintext_temp[0] = (c[0] & 0xff00) >> 8;
    plaintext_temp[1] = (c[0] & 0xff);
    plaintext_temp[2] = (c[1] & 0xff00) >> 8;
    plaintext_temp[3] = c[1] & 0xff;
    plaintext_temp[4] = (c[2] & 0xff00) >> 8;
    plaintext_temp[5] = c[2] & 0xff;
    plaintext_temp[6] = (c[3] & 0xff00) >> 8;
    plaintext_temp[7] = c[3] & 0xff;
    // sprintf(plaintext, "%c%c", c[0], (c[0] >> 8));

    // sprintf(plaintext, "%c%c%c%c%c%c%c%c", plaintext[0], plaintext[1], plaintext[2], plaintext[3], plaintext[4], plaintext[5], plaintext[6], plaintext[7]);

    cout << plaintext_temp << endl;
    cout << endl << endl;
    while(repeat)
    {
        cout << endl << 
            "Please enter an choice of what you want to do: " << endl;
        cout<<"1.List the keys for each round."<<endl;
        cout<<"2.Retrieve information about an item."<<endl;
        cout<<"3.Remove an item."<<endl;
        cout<<"4.Display height"<<endl;
        cout<<"5.Display all"<<endl;
        cout<<"6.Remove everything listed for a particular website!"<<endl;
        cout<<"7.Exit"<<endl;
        cin >> choice;
        cin.ignore(100, '\n');
        switch(choice)
        {
            case 1: 
                    cout << endl << "name?";
            //         cin.get(name, SIZE, '\n');cin.ignore(100, '\n');
            //         cout << endl << "description?";
            //         cin.get(description, SIZE, '\n');cin.ignore(100, '\n');
            //         cout << endl << "color?";
            //         cin.get(color, SIZE, '\n');cin.ignore(100, '\n');
            //         cout << endl << "dimension?";
            //         cin.get(dimension, SIZE, '\n');cin.ignore(100, '\n');
            //         cout << endl << "website?";
            //         cin.get(website, SIZE, '\n');cin.ignore(100, '\n');
            //         to_add.create_entry(name, description, color, dimension, website);
            //         my_table.insert(name, to_add);//insert
            //         cout << endl << "Insert finished:"; 
            //         break;
            // case 2:
            //         cout << endl << "Enter item name Please:" << endl;
            //         cin.get(name, SIZE, '\n');cin.ignore(100, '\n');
            //         if (my_table.retrieve(name, an_entry) == 1)//retrieve
            //         {
            //             an_entry.display();
            //         }
            //         else
            //             cout << "Can't find this item" << endl;
            //         break;
            // case 3:
            //         cout << endl << "Enter item name Please" << endl;
            //         cin.get(name, SIZE, '\n');cin.ignore(100, '\n');
            //         my_table.remove_item(name);//remove
            //         break;
            // case 4:
            //         cout << "The height is " << 
            //         my_table.display_height();//display
            //         break;
            // case 5:
            //         my_table.display_all();
            //         break;
            // case 6:
            //         cout << endl << "Enter item website Please" << endl;
            //         cin.get(website, SIZE, '\n');cin.ignore(100, '\n');
            //         my_table.remove_website(website);
            //         break;
            case 7:
                    repeat = 0;
                    cout << "Thanks bye!!" << endl;
                    break;

            default: 
                    repeat = 0; 
                    cout << "Invalid input" << endl;
                    break;
        }
    }

    delete [] key;
    // delete [] ftable;
    // delete [] key_temp;
    delete [] plaintext;
    delete [] plaintext_temp;

    for(int i = 0; i < ROUND; ++i) {
        delete [] ary[i];
    }
    delete [] ary;
    delete [] g;
    delete [] t;
    delete [] r;

    return 0;
}

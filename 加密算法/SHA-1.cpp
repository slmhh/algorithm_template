#include<bits/stdc++.h>
using namespace std;

namespace SHA1{
    string padding(string str){
        int len = (str.size() << 3) & ((2 << 10) - 1),add = 0;
        bitset<64> a(str.size() << 3);
        if(len + 1 > 448) add = 959 + len;
        else add = 447 - len;
        str.push_back(128);
        for(int i = 0;i < add >> 3;i++) str.push_back(0);
        for(int i = 63;i >= 0;){
            int temp = 0;
            for(int j = 0;j < 8;j++,i--) temp = (temp << 1) + a[i];
            str.push_back(temp);
        }
        return str; 
    }

    unsigned F(int t,unsigned B,unsigned C,unsigned D){
        if(t <= 19) return (B & C) | (~B & D);
        else if(t <= 39) return B ^ C ^ D;
        else if(t <= 59) return (B & C) | (B & D) | (C & D);
        return B ^ C ^ D;
    }

    unsigned ROTL(int t,unsigned x){
        return (x << t) | (x >> (32 - t));
    }

    string enctypt(string str){
        str = padding(str);
        unsigned H[5] = {0x67452301,0xEFCDAB89,0x98BADCFE,0x10325476,0xC3D2E1F0};
        unsigned K[4] = {0x5A827999,0x6ED9EBA1,0x8F1BBCDC,0xCA62C1D6};
        for(int i = 0;i < str.size();i += 64){
            vector<unsigned> w;
            for(int j = 0;j < 64;j += 4)
                w.push_back(((uint8_t)str[j] << 24) | ((uint8_t)str[j + 1] << 16) | ((uint8_t)str[j + 2] << 8) | ((uint8_t)str[j + 3]));
            for(int j = 0;j < 16;j++){
                cout << bitset<32>(w[j]) << "\n";
            }
            for(int j = 16;j < 80;j++)
                w.push_back(ROTL(1, (w[j - 3] ^ w[j - 8] ^ w[j - 14] ^ w[j - 16])));
            unsigned A = H[0],B = H[1],C = H[2],D = H[3],E = H[4];
            for(int j = 0;j < 80;j++){
                unsigned t = ROTL(5, A) + F(j, B, C, D) + E + w[j] + K[j / 20];
                E = D;
                D = C;
                C = ROTL(30, B);
                B = A;
                A = t;
            }
            H[0] += A;
            H[1] += B;
            H[2] += C;
            H[3] += D;
            H[4] += E;
        }
        string sha = "";
        for(int i = 0;i <= 4;i++){
            // cout << H[i] << "\n";
            bitset<32> temp(H[i]);
            unsigned t;
            for(int j = 31;j >= 0;j -= 4){
                t = temp[j - 3] + (temp[j - 2] << 1) + (temp[j - 1] << 2) + (temp[j] << 3);
                if(t < 10) sha += (char)(t + '0');
                else sha += (char)(t - 10 + 'a');
            }
        }
        return sha;
    }
};

int main(){
    string str;
    // cout << "��ѡ����ܶ���1���ļ�  2�����ļ�\t";
    int choose;
    cin >> choose;
    if(choose == 2){
        // cout << "��������������ݣ�\t";
        getline(cin,str);
        getline(cin,str);
    }
    else{
        string path,temp;
        // cout << "�����������ļ�·����\t";
        cin >> path;
        ifstream file;
        file.open(path,ios::in|ios::binary);
        file.read(&str[0],file.tellg());
        file.close();
    }    
    // cout << "SHA-1���ܽ���� ";
    cout << SHA1::enctypt(str) << "\n";
    return 0;
}

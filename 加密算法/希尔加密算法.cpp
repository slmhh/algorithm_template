#include<bits/stdc++.h>
using namespace std;

int key[3][3] = {{1,1,0},{1,1,1},{0,1,1}};
int dekey[3][3] = {{0,1,-1},{1,-1,1},{-1,1,0}};

string encryption(string str){
    int i = 0,temp[1000][3] = {0},plain_m[1000][3] = {0};
    for(int j = 0;j < ceil(str.size() / 3 + 1);j++)
        for(int k = 0;k < 3;k++,i++)
            if(i < str.size()) plain_m[j][k] = str[i] - 'a';

    for(i = 0;i < 3;i++){
        for(int j = 0;j < ceil(str.size() / 3 + 1);j++){
            for(int k = 0;k < 3;k++)
                temp[i][j] += key[k][j] * plain_m[i][k]; 
            temp[i][j] = (temp[i][j] % 26 + 26) % 26;
        }
    }

    string code = "";
    for(int j = 0,i = 0;j < ceil(str.size() / 3 + 1);j++)
        for(int k = 0;k < 3;k++,i++)
            code = code + (char)(temp[j][k] + 'a');

    return code.substr(0,str.size() + 1);
}

string decryption(string str){
    int i = 0,temp[1000][3] = {0},code_m[1000][3] = {0};
    for(int j = 0;j < ceil(str.size() / 3 + 1);j++)
        for(int k = 0;k < 3;k++,i++)
            if(i < str.size()) code_m[j][k] = str[i] - 'a';

    for(i = 0;i < 3;i++){
        for(int j = 0;j < ceil(str.size() / 3 + 1);j++){
            for(int k = 0;k < 3;k++)
                temp[i][j] += dekey[k][j] * code_m[i][k]; 
            temp[i][j] = (temp[i][j] + 26) % 26;
        }
    }

    string decode = "";
    for(int j = 0;j < ceil(str.size() / 3 + 1);j++){
        for(int k = 0;k < 3;k++){
            decode = decode + (char)(temp[j][k] + 'a');
        }
    }
    return decode.substr(0,str.size() - 1);
}

int main(){
    string plain,code,decode;
    cout << "ÇëÊäÈëÃ÷ÎÄ:";
    cin >> plain;
    code = encryption(plain);
    cout << "The code is : " << code << "\n";
    decode = decryption(code);
    cout << "The decode is : " << decode << "\n";
    return 0;
}

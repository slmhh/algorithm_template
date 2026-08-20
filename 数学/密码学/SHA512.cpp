#include<bits/stdc++.h> 
using namespace std;

namespace SHA512{    
    #define ROTR(x,t)  ((x >> t) | (x << (64 - t)))
    #define Cho(x,y,z) ((x & y) ^ (~x & z))
    #define Maj(x,y,z) ((x & y) ^ (x & z) ^ (y & z))
    #define S0(x) (ROTR(x,28) ^ ROTR(x,34) ^ ROTR(x,39))
    #define S1(x) (ROTR(x,14) ^ ROTR(x,18) ^ ROTR(x,41))
    #define s0(x) (ROTR(x,1 ) ^ ROTR(x,8 ) ^ (x >> 7))
    #define s1(x) (ROTR(x,19) ^ ROTR(x,61) ^ (x >> 6))
    #define SHL8(x,t) (((uint64_t)x << t) & (255ull << t))
    #define Rou 80
	typedef array<uint64_t,8> Hash;
	
    string padding(string str){
        int len = (str.size() << 3) & ((2 << 11) - 1),add = 0;
        bitset<128> a((uint64_t)str.size() << 3);
        if(len + 1 > 896)
            add = 1024 - (len + 1 - 896);
        else
            add = 896 - (len + 1);
        
        str.push_back(128);
        str.append(add >> 3,0);

        for(int i = 127;i >= 0;){
            int temp = 0;
            for(int j = 0;j < 8;j++,i--)
                temp = (temp << 1) + a[i];
            str.push_back(temp);
        }
        return str; 
    }

    Hash encrypt(string str){
        Hash H =  {0x6A09E667F3BCC908, 0xBB67AE8584CAA73B, 0x3C6EF372FE94F82B, 0xA54FF53A5F1D36F1,
                   0x510E527FADE682D1, 0x9B05688C2B3E6C1F, 0x1F83D9ABFB41BD6B, 0x5BE0CD19137E2179};
        array<uint64_t,80> K = {0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
                                0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
                                0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
                                0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
                                0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
                                0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
                                0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
                                0xc6e00bf33da88fc2, 0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70,
                                0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
                                0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
                                0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
                                0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
                                0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
                                0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
                                0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
                                0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b,
                                0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
                                0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
                                0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
                                0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817};
        str = padding(str);
        for(int i = 0;i < str.size();i += 128){
            array<uint64_t,80> W;
            for(int j = 0;j < 128;j += 8)
                W[j >> 3] = SHL8(str[j],56) | SHL8(str[j + 1],48) | SHL8(str[j + 2],40) | SHL8(str[j + 3],32)
                          | SHL8(str[j + 4],24) | SHL8(str[j + 5],16) | SHL8(str[j + 6],8) | SHL8(str[j + 7],0);
            
            for(int j = 16;j < Rou;j++)
                W[j] = s1(W[j - 2]) + W[j - 7] + s0(W[j - 15]) + W[j - 16];

            Hash T = H;
            for(int j = 0;j < Rou;j++){
                uint64_t T1 = T[7] + S1(T[4]) + Cho(T[4],T[5],T[6]) + K[j] + W[j];
                uint64_t T2 = S0(T[0]) + Maj(T[0],T[1],T[2]);
                for(int k = 7;k >= 1;k--)
                    T[k] = T[k - 1];
                T[0] = T1 + T2;
                T[4] = T[4] + T1;
            }

            for(int j = 0;j < 8;j++)
                H[j] += T[j];
        }
        return Hash(H);
    }

    string join(Hash hash){
        stringstream res;
        for(int i = 0;i < 8;i++)
            res << hex << setfill('0') << setw(16) << hash[i];
        return res.str();
    }
};

ostream& operator << (ostream& os, const SHA512::Hash& hash){
    for(int i = 0;i < 8;i++)
	   	os << hex << setfill('0') << setw(16) << hash[i];
	return os;
}
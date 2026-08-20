#include<iostream>
#include<string>
using namespace std;

const int N = 4;

string multiplication(char* str,int a[N][N]){
	string s = "";
	char c = 0;
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			c = (char)((c + a[i][j] * str[j] -'a') % 26 + 'a');
		}
		s += c;
		c = 0;
	}
	return s;
}

class cryption{
	string plain;
	string encode;
	string decode;
	public:
		cryption(string a) : plain(a){};
		string out_en(){return encode;}
		string out_de(){return decode;};
		void input_en(string a){encode = a;}
		void encryption(int a[N][N],int b[N]);
		void decryption(int a[N][N],int b[N]);
	friend string multiplication(char* str,int a[N][N]);
};

void cryption::encryption(int a[N][N],int b[N]){
	string temp,str = plain;
	int len = str.size();
	
	for(int i = 0;i < len / N;i++)
		temp += multiplication(&(str[N * i]),a);
	for(int i = 0;i < len;i++)
		temp[i] = (char)((temp[i] + b[i % N] - 'a') % 26 + 'a');
	encode = temp;
}

void cryption::decryption(int a[N][N],int b[N]){
	string temp,str = encode;
	int len = str.size();
	
	for(int i = 0;i < len;i++)
		str[i] = (char)((str[i] + b[i % N] - 'a') % 26 + 'a');
	for(int i = 0;i < len / N;i++)
		temp += multiplication(&(str[N * i]),a);
	decode = temp;
}

void is_right(int a[N][N],int b[N][N]){
	int t[N][N] = {0};
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			for(int k = 0;k < N;k++)
				t[i][j] += a[i][k] * b[k][j];
		}
	}
	int flag = 1;
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			cout << (char)((t[i][j] - 'a') % 26 + 'a') << " ";
			if(t[i][j] != 1 && i == j) flag = 0;
			if(t[i][j] != 0 && i != j) flag = 0;
		}
		cout << "\n";
	}
	
	if(flag) cout << "ÃÜÔ¿ÕýÈ·\n";
	else{
		cout << "ÃÜÔ¿´íÎó\n";
		exit(1);
	}	
}

int main(){
	cout << "ÇëÊäÈë¼ÓÃÜÃÜÔ¿ a:\n";
	int a[N][N],b[N],c[N][N];
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			cin >> a[i][j];
		}
	}
	cout << "ÇëÊäÈë¼ÓÃÜÃÜÔ¿ b:\n";
	for(int i = 0;i < N;i++) cin >> b[i];
	cout << "ÇëÊäÈë½âÃÜÃÜÔ¿ t:\n";
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			cin >> c[i][j];
		}
	}
	
	string str;
	is_right(a,c);
	getchar();
	getline(cin,str);
	int len = str.size();
	if(len % N){
		for(int k = 0;k < N - len % N;k++) str += " ";
	}
	
	cryption test(str);
	test.encryption(a,b);
	test.decryption(c,b);
	cout << test.out_en() << "\n";
	cout << test.out_de() << "\n";
	return 0;
}



#pragma once
#include<iostream>
#include<cstring>
#include<map>
using namespace std;

//将输入的字符串转化为二进制明文字符串
string Cto2(string m)
{
	map<char, string> cto2;
	cto2['!'] = "00100001"; cto2['\"'] = "00100010"; cto2['#'] = "00100011"; cto2['$'] = "00100100"; cto2['%'] = "00100101"; cto2['&'] = "00100110"; cto2['\''] = "00100111"; cto2['('] = "00101000";
	cto2[')'] = "00101001"; cto2['*'] = "00101010"; cto2['+'] = "00101011"; cto2[','] = "00101100"; cto2['-'] = "00101101"; cto2['.'] = "00101110"; cto2['/'] = "00101111"; cto2['0'] = "00110000";
	cto2['1'] = "00110001"; cto2['2'] = "00110010"; cto2['3'] = "00110011"; cto2['4'] = "00110100"; cto2['5'] = "00110101"; cto2['6'] = "00110110"; cto2['7'] = "00110111"; cto2['8'] = "00111000"; cto2['9'] = "00111001";
	cto2[':'] = "00111010"; cto2[';'] = "00111011"; cto2['<'] = "00111100"; cto2['='] = "00111101"; cto2['>'] = "00111110"; cto2['?'] = "00111111"; cto2['@'] = "01000000"; cto2['A'] = "01000001"; cto2['B'] = "01000010"; cto2['C'] = "01000011";
	cto2['D'] = "01000100"; cto2['E'] = "01000101"; cto2['F'] = "01000110"; cto2['G'] = "01000111"; cto2['H'] = "01001000"; cto2['I'] = "01001001"; cto2['J'] = "01001010"; cto2['K'] = "01001011"; cto2['L'] = "01001100"; cto2['M'] = "01001101"; cto2['N'] = "01001110"; cto2['O'] = "01001111"; cto2['P'] = "01010000"; cto2['Q'] = "01010001";
	cto2['R'] = "01010010"; cto2['S'] = "01010011"; cto2['T'] = "01010100"; cto2['U'] = "01010101"; cto2['V'] = "01010110"; cto2['W'] = "01010111"; cto2['X'] = "01011000"; cto2['Y'] = "01011001"; cto2['Z'] = "01011010"; cto2['['] = "01011011"; cto2['\\'] = "01011100";
	cto2[']'] = "01011101"; cto2['^'] = "01011110"; cto2['_'] = "01011111"; cto2['`'] = "01100000"; cto2['a'] = "01100001"; cto2['b'] = "01100010"; cto2['c'] = "01100011"; cto2['d'] = "01100100"; cto2['e'] = "01100101"; cto2['f'] = "01100110"; cto2['g'] = "01100111"; cto2['h'] = "01101000"; cto2['i'] = "01101001"; cto2['j'] = "01101010";
	cto2['k'] = "01101011"; cto2['l'] = "01101100"; cto2['m'] = "01101101"; cto2['n'] = "01101110"; cto2['o'] = "01101111"; cto2['p'] = "01110000"; cto2['q'] = "01110001"; cto2['r'] = "01110010"; cto2['s'] = "01110011"; cto2['t'] = "01110100"; cto2['u'] = "01110101"; cto2['v'] = "01110110"; cto2['w'] = "01110111"; cto2['x'] = "01111000"; cto2['y'] = "01111001"; cto2['z'] = "01111010";
	cto2['{'] = "01111011"; cto2['|'] = "01111100"; cto2['}'] = "01111101"; cto2['~'] = "01111110"; cto2[' '] = "00100000";
	string M = "";
	for (int i = 0; i < m.length(); i++)
		M += cto2[m[i]];
	return M;
}

//将二进制明文字符串转化为明文字符串
string btoc(string m)
{
	map<string, string> cto2;
	cto2["00100001"] = "!"; cto2["00100010"] = "\""; cto2["00100011"] = "#"; cto2["00100100"] = "$"; cto2["00100101"] = "%"; cto2["00100110"] = "&"; cto2["00100111"] = "\'"; cto2["00101000"] = "(";
	cto2["00101001"] = ")"; cto2["00101010"] = "*"; cto2["00101011"] = "+"; cto2["00101100"] = ","; cto2["00101101"] = "-"; cto2["00101110"] = "."; cto2["00101111"] = "/"; cto2["00110000"] = "0";
	cto2["00110001"] = "1"; cto2["00110010"] = "2"; cto2["00110011"] = "3"; cto2["00110100"] = "4"; cto2["00110101"] = "5"; cto2["00110110"] = "6"; cto2["00110111"] = "7"; cto2["00111000"] = "8"; cto2["00111001"] = "9";
	cto2["00111010"] = ":"; cto2["00111011"] = ";"; cto2["00111100"] = "<"; cto2["00111101"] = "="; cto2["00111110"] = ">"; cto2["00111111"] = "?"; cto2["01000000"] = "@"; cto2["01000001"] = "A"; cto2["01000010"] = "B"; cto2["01000011"] = "C";
	cto2["01000100"] = "D"; cto2["01000101"] = "E"; cto2["01000110"] = "F"; cto2["01000111"] = "G"; cto2["01001000"] = "H"; cto2["01001001"] = "I"; cto2["01001010"] = "J"; cto2["01001011"] = "K"; cto2["01001100"] = "L"; cto2["01001101"] = "M"; cto2["01001110"] = "N"; cto2["01001111"] = "O"; cto2["01010000"] = "P"; cto2["01010001"] = "Q";
	cto2["01010010"] = "R"; cto2["01010011"] = "S"; cto2["01010100"] = "T"; cto2["01010101"] = "U"; cto2["01010110"] = "V"; cto2["01010111"] = "W"; cto2["01011000"] = "X"; cto2["01011001"] = "Y"; cto2["01011010"] = "Z"; cto2["01011011"] = "["; cto2["01011100"] = "\\";
	cto2["01011101"] = "]"; cto2["01011110"] = "^"; cto2["01011111"] = "_"; cto2["01100000"] = "`"; cto2["01100001"] = "a"; cto2["01100010"] = "b"; cto2["01100011"] = "c"; cto2["01100100"] = "d"; cto2["01100101"] = "e"; cto2["01100110"] = "f"; cto2["01100111"] = "g"; cto2["01101000"] = "h"; cto2["01101001"] = "i"; cto2["01101010"] = "j";
	cto2["01101011"] = "k"; cto2["01101100"] = "l"; cto2["01101101"] = "m"; cto2["01101110"] = "n"; cto2["01101111"] = "o"; cto2["01110000"] = "p"; cto2["01110001"] = "q"; cto2["01110010"] = "r"; cto2["01110011"] = "s"; cto2["01110100"] = "t"; cto2["01110101"] = "u"; cto2["01110110"] = "v"; cto2["01110111"] = "w"; cto2["01111000"] = "x"; cto2["01111001"] = "y"; cto2["01111010"] = "z";
	cto2["01111011"] = "{"; cto2["01111100"] = "|"; cto2["01111101"] = "}"; cto2["01111110"] = "~"; cto2["00100000"] = " ";
	string M = "";
	for (int i = 0; i < m.length() / 8; i++)
	{
		if (m.substr(i * 8, 8) == "00000000")
			break;
		M += cto2[m.substr(i * 8, 8)];
	}
	return M;
}

//初始置换IP
string IP(string c)
{
	string temp = c;

	//置换IP表
	int ipTable[64] =
	{
		58,50,42,34,26,18,10,2,
		60,52,44,36,28,20,12,4,
		62,54,46,38,30,22,14,6,
		64,56,48,40,32,24,16,8,
		57,49,41,33,25,17,9,1,
		59,51,43,35,27,19,11,3,
		61,53,45,37,29,21,13,5,
		63,55,47,39,31,23,15,7
	};

	for (int i = 0; i < c.length(); i++)
		temp[i] = c[ipTable[i] - 1];
	return temp;
}

//逆初始置换IP_rev
string IP_rev(string c)
{
	string temp = c;

	//逆初始置换表
	int ipRevTable[64] =
	{
		40,8,48,16,56,24,64,32,
		39,7,47,15,55,23,63,31,
		38,6,46,14,54,22,62,30,
		37,5,45,13,53,21,61,29,
		36,4,44,12,52,20,60,28,
		35,3,43,11,51,19,59,27,
		34,2,42,10,50,18,58,26,
		33,1,41,9,49,17,57,25
	};

	for (int i = 0; i < c.length(); i++)
		temp[i] = c[ipRevTable[i] - 1];
	return temp;
}

//选择扩展运算E（32->48）
string E(string c)
{
	//长度48的字符串
	string temp(48, '0');
	//E表
	int eTable[48] =
	{
		32,1,2,3,4,5,
		4,5,6,7,8,9,
		8,9,10,11,12,13,
		12,13,14,15,16,17,
		16,17,18,19,20,21,
		20,21,22,23,24,25,
		24,25,26,27,28,29,
		28,29,30,31,32,1
	};
	for (int i = 0; i < 48; i++)
		temp[i] = c[eTable[i] - 1];
	return temp;
}

//密钥置换选择PC_1
string PC_1(string c)
{
	string temp(56, '0');
	//PC_1表
	int pc1Table[56] =
	{
		57,49,41,33,25,17,9,1,
		58,50,42,34,26,18,10,2,
		59,51,43,35,27,19,11,3,
		60,52,44,36,63,55,47,39,
		31,23,15,7,62,54,46,38,
		30,22,14,6,61,53,45,37,
		29,21,13,5,28,20,12,4
	};
	for (int i = 0; i < 56; i++)
		temp[i] = c[pc1Table[i] - 1];
	return temp;
}

//密钥左右部分循环移位
void loop(string& l, string& r, int n)
{
	//各轮的左循环移位位数
	int loopTable[16] = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };
	//第n轮位数
	int move = loopTable[n];
	string l_temp = l; string r_temp = r;
	for (int i = 0; i < l.length(); i++)
	{
		l_temp[i] = l[(i + move) % 28];
		r_temp[i] = r[(i + move) % 28];
	}
	l = l_temp;
	r = r_temp;
	return;
}

//密钥置换选择PC_2
string PC_2(string l, string r)
{
	string k = l + r;
	string temp(48, '0');
	//PC_2表
	int pc2Table[48] =
	{
		14,17,11,24,1,5,
		3,28,15,6,21,10,
		23,19,12,4,26,8,
		16,7,27,20,13,2,
		41,52,31,37,47,55,
		30,40,51,45,33,48,
		44,49,39,56,34,53,
		46,42,50,36,29,32
	};
	for (int i = 0; i < 48; i++)
		temp[i] = k[pc2Table[i] - 1];
	return temp;
}

//异或运算
string XOR(string r, string k)
{
	string res(r.length(), '0');
	for (int i = 0; i < r.length(); i++)
	{
		if (r[i] == k[i])
			res[i] = '0';
		else
			res[i] = '1';
	}
	return res;
}

//S盒代换
string S(string c)
{
	//S盒
	int sBox[8][4][16] =
	{
		//S1
		14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
		0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
		4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
		15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13,
		//S2
		15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
		3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
		0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
		13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9,
		//S3
		10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
		13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
		13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
		1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12,
		//S4
		7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
		13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
		10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
		3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14,
		//S5
		2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
		14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
		4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
		11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3,
		//S6
		12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
		10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
		9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
		4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13,
		//S7
		4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
		13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
		1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
		6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12,
		//S8
		13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
		1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
		7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
		2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
	};

	//字符串转行号&列号
	map<string, int> stringtoint;
	stringtoint["00"] = 0; stringtoint["01"] = 1; stringtoint["10"] = 2; stringtoint["11"] = 3;
	stringtoint["0000"] = 0; stringtoint["0001"] = 1; stringtoint["0010"] = 2; stringtoint["0011"] = 3; stringtoint["0100"] = 4; stringtoint["0101"] = 5; stringtoint["0110"] = 6;
	stringtoint["0111"] = 7; stringtoint["1000"] = 8; stringtoint["1001"] = 9; stringtoint["1010"] = 10; stringtoint["1011"] = 11; stringtoint["1100"] = 12; stringtoint["1101"] = 13;
	stringtoint["1110"] = 14; stringtoint["1111"] = 15;

	//数字转四位二进制字符串
	map<int, string> inttostring;
	inttostring[0] = "0000"; inttostring[1] = "0001"; inttostring[2] = "0010"; inttostring[3] = "0011"; inttostring[4] = "0100"; inttostring[5] = "0101"; inttostring[6] = "0110";
	inttostring[7] = "0111"; inttostring[8] = "1000"; inttostring[9] = "1001"; inttostring[10] = "1010"; inttostring[11] = "1011"; inttostring[12] = "1100"; inttostring[13] = "1101";
	inttostring[14] = "1110"; inttostring[15] = "1111";

	//等分成6bit的8份
	string g[8];
	for (int i = 0; i < 8; i++)
		g[i] = c.substr(i * 6, 6);
	for (int i = 0; i < 8; i++)
	{//第i个S盒
		string row(2, '0'); row[0] = g[i][0]; row[1] = g[i][5];
		string column(4, '0');
		for (int j = 0; j < 4; j++)
			column[j] = g[i][j + 1];
		int temp = sBox[i][stringtoint[row]][stringtoint[column]];
		string s_temp = inttostring[temp];
		g[i] = s_temp;
	}
	string res = "";
	for (int i = 0; i < 8; i++)
		res += g[i];
	return res;
}

//置换运算P
string P(string c)
{
	string temp = c;
	//P表
	int pTable[32] =
	{
		16,7,20,21,
		29,12,28,17,
		1,15,23,26,
		5,18,31,10,
		2,8,24,14,
		32,27,3,9,
		19,13,30,6,
		22,11,4,25
	};
	for (int i = 0; i < 32; i++)
		temp[i] = c[pTable[i] - 1];
	return temp;
}

//加密
string Encode(string m16)
{
	//****************密钥生成*****************//
	//置换选择PC_1，生成56位初始密钥
	//密钥
	string key = Cto2("87654321");
	key = PC_1(key);
	//密钥分成左右两部分
	string k_L = key.substr(0, 28);
	string k_R = key.substr(28, 28);
	//产生16个子密钥
	string keys[16];
	for (int i = 0; i < 16; i++)
	{
		//密钥左循环移位
		loop(k_L, k_R, i);
		//密钥置换选择PC_2，得到48位轮密钥
		keys[i] = PC_2(k_L, k_R);
	}
	//****************************************//
	//将输入的明文字符串转化为二进制明文字符串
	string M = Cto2(m16);

	//明文分组
	int n = (M.length() / 64) * 64 == M.length() ? M.length() / 64 : M.length() / 64 + 1;
	if ((M.length() / 64) * 64 != M.length())
	{
		int dert = M.length() - ((M.length() / 64) * 64);
		for (int i = 0; i < 64 - dert; i++)
			M += "0";
	}
	string* m = new string[n];
	for (int i = 0; i < n; i++)
	{
		m[i] = M.substr(i * 64, 64);
	}

	//密文空间
	string* C = new string[n];

	//启用CBC模式
	string IV = Cto2("12345678");

	//循环对每个分组加密
	for (int i = 0; i < n; i++)
	{
		string c = m[i];

		c = XOR(c, IV);

		//初始置换IP
		c = IP(c);

		//明文分成左右两部分
		string L = c.substr(0, 32);
		string R = c.substr(32, 32);

		//轮结构（16轮）
		for (int j = 0; j < 16; j++)
		{
			string temp = R;

			//选择扩展运算E
			R = E(R);

			//异或运算
			//加解密的密钥顺序不同
			R = XOR(R, keys[j]);

			//S盒（代换/选择）
			R = S(R);

			//置换P
			R = P(R);

			//异或运算
			R = XOR(L, R);

			L = temp;
		}

		//逆初始置换IP_rev
		c = R + L;
		c = IP_rev(c);
		C[i] = c;

		IV = c;
	}
	string out = "";
	for (int i = 0; i < n; i++)
		out += C[i];
	return out;
}

//解密
string Decode(string M)
{
	//****************密钥生成*****************//
	//置换选择PC_1，生成56位初始密钥
	//密钥
	string key = Cto2("87654321");
	key = PC_1(key);
	//密钥分成左右两部分
	string k_L = key.substr(0, 28);
	string k_R = key.substr(28, 28);
	//产生16个子密钥
	string keys[16];
	for (int i = 0; i < 16; i++)
	{
		//密钥左循环移位
		loop(k_L, k_R, i);
		//密钥置换选择PC_2，得到48位轮密钥
		keys[i] = PC_2(k_L, k_R);
	}
	//****************************************//

	//密文分组
	int n = (M.length() / 64) * 64 == M.length() ? M.length() / 64 : M.length() / 64 + 1;
	if ((M.length() / 64) * 64 != M.length())
	{
		int dert = M.length() - ((M.length() / 64) * 64);
		for (int i = 0; i < 64 - dert; i++)
			M += "0";
	}
	string* m = new string[n];
	for (int i = 0; i < n; i++)
	{
		m[i] = M.substr(i * 64, 64);
	}

	//明文空间
	string* C = new string[n];

	//启用CBC模式
	string IV = Cto2("12345678");

	//循环对每个分组解密
	for (int i = 0; i < n; i++)
	{
		string c = m[i];

		//初始置换IP
		c = IP(c);

		//密文分成左右两部分
		string L = c.substr(0, 32);
		string R = c.substr(32, 32);

		//轮结构（16轮）
		for (int j = 0; j < 16; j++)
		{
			string temp = R;

			//选择扩展运算E
			R = E(R);

			//异或运算
			//加解密的密钥顺序不同
			R = XOR(R, keys[15 - j]);

			//S盒（代换/选择）
			R = S(R);

			//置换P
			R = P(R);

			//异或运算
			R = XOR(L, R);

			L = temp;
		}

		//逆初始置换IP_rev
		c = R + L;
		c = IP_rev(c);

		c = XOR(c, IV);
		C[i] = c;

		IV = m[i];
	}
	string out = "";
	for (int i = 0; i < n; i++)
		out += C[i];
	out = btoc(out);
	return out;
}
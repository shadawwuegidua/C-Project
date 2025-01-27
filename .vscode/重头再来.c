#include<string.h>
#include<stdio.h>
#define MAX_LEN 1000
void replace_number(char *s){
	char result[MAX_LEN]="";
	int j=0;
	
	for(int i=0;s[i]!='\0';i++){  // 使用s[i]!='\0'代替strlen(s)避免重复计算
		if(s[i]>='0'&&s[i]<='9'){
			result[j]='n';
			result[j+1]='u'; 
			result[j+2]='m';
			result[j+3]='b';
			result[j+4]='e';
			result[j+5]='r';
			j+=6;
		}else {
			result[j]=s[i];
			j++;
		}
	}
	printf("%s\n",result);
}
int main(){
	char s[MAX_LEN];
	scanf("%s",s);
	replace_number(s);
	return 0;
}
/*
Description:
给定一个字符串s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。

例如，对于输入字符串"a1b2c3"，函数应该将其转换为"anumberbnumbercnumber"。
对于输入字符串"a5b"，函数应该将其转换为"anumberb"。

Input:
一个字符串s,s仅包含小写字母和数字字符。

Output:
打印一个新的字符串，其中每个数字字符都被替换为了number
*/

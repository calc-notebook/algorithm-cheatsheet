## 2017-Mock–D: Palindrome

**总时间限制**: 3000ms **内存限制**: 65536kB



**描述**

A palindrome is a symmetrical string, that is, a string read identically from left to right as well as from right to left. You are to write a program which, given a string, determines the minimal number of characters to be inserted into the string in order to obtain a palindrome.  As an example, by inserting 2 characters, the string "Ab3bd" can be transformed into a palindrome ("dAb3bAd" or "Adb3bdA"). However, inserting fewer than 2 characters does not produce a palindrome. 



**输入**

Your program is to read from standard input. The first line contains one integer: the length of the input string N, 3 <= N <= 5000. The second line contains one string with length N. The string is formed from uppercase letters from 'A' to 'Z', lowercase letters from 'a' to 'z' and digits from '0' to '9'. Uppercase and lowercase letters are to be considered distinct.



**输出**

Your program is to write to standard output. The first line contains one integer, which is the desired minimal number.



**样例输入**

```c++
5
Ab3bd
```



**样例输出**

```c++
2
```



**来源**

IOI 2000



**题解**

此问题可以转换为最长公共字符串问题求解.

```c++
int calculate(char* data1, char* data2, int length){
	short dp[N_MAX + 1][N_MAX + 1];
	for (int idx = 0; idx <= length; idx++) dp[0][idx] = dp[idx][0] = 0;
	for (int idx1 = 1; idx1 <= length;idx1++)
	for (int idx2 = 1; idx2 <= length; idx2++){
		if (data1[idx1 - 1] == data2[idx2 - 1]) dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1] + 1;
		else dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
	}
	return length-dp[length][length];
}
```



**总结**

1. 尝试本题的过程中一度出现`wrong answer`，最终发现是将数组`dp`定义为`int`会超出最大内存限制，将内存定义为`short`时问题解决。


2. 本题中未采用字符串输入，而是用`scanf`读入单个字符，此时一定要注意输入`N`后的那个`\r\n`要先用`getchar`加以处理。

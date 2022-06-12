# AST

ast -> abstract syntax tree  


![스크린샷 2022-06-09 오후 3 00 11](https://user-images.githubusercontent.com/76278794/172775253-50404a80-4e3d-4e5e-8a82-390871dd54a9.png)  

readline 라이브러리를 통해 사용자의 input을 입력받는다.  

프로그래밍 로직 상에서,  

Text -> Lexer(token화) -> Parser -> AST -> Evaluator -> Behavior  

이 방식대로 작동하게된다.  

Lexer는 텍스트를 각 토큰으로 분해한다.  
우리의 미니쉘 코드에서는 이 작업을 `Tokenizer`와 `Lexer`가 분담한다.  


Tokenizer 모듈이 텍스트의 각 1바이트를 잘라서 토큰화를 하게된다.  

```sh
echo "test | test" > result

token_buf
{
	{
		value : 'e'
		type : NORM
	},
	{
		value : 'c'
		type : NORM
	},
	{
		...
	}
	{
		value : '\"'
		type : DQOU
	},
	{
		value : 't'
		type : NORM
	}
	...
}
```

이렇게 1바이트별로 토큰화를 수행할때, 토큰화를 진행중인 문자가  
쌍 따옴표 내부에 있는지, 홑 따옴표 내부에 있는지, 아니면 이 둘 바깥에 있는지에 따라 type을 달리하게된다.  


<br>

이렇게 토큰화가 완료되면, `lexer`가 각 토큰을 이어붙이게된다.  
각 토큰을 이어붙이고 난 다음에는, 각 단어가 어느 위치에 있는지에 따라  
`word_type`을 정하게 된다.  




토큰화된 리스트를 parser 함수에서 구문분석하고 각 유효성을 검사하게된다.  
parser는 또한, 토큰화된 문자열을 AST로 변환하는 역할을 한다.  

이후, AST에서 구문 분석된 문장을 각 노드에 지니고있게된다.  


![스크린샷 2022-06-09 오후 3 05 12](https://user-images.githubusercontent.com/76278794/172776006-41f46e7c-d551-493e-bbc7-343d07cfbd72.png)  

# case test

## 다중 파이프

### case 1

```sh
echo t > test | grep t | echo t
>>t
```

1. `echo t` 명령어의 결과 출력된다.  
2. `echo t > test`의 결과로 생성된 test에 t가 저장된다.  
3. grep t 는 씹힘.

<br>

### case 2

```sh
echo tt | echo t | echo ttt
>>ttt
```

1. `echo ttt`만 가능함.
2. 앞의 두 명령어는 씹힘

<br>

### case 3

```sh
cat | cat | cat
>>asdf
asdf
>>
```

1. cat에 아무런 입력 파일을 주지 않은 것처럼 작동한다.
2. 단, 여기서 3개의 cat이 모두 살아있다.

```sh
501 87090 87089   0  3:51PM ttys019    0:00.33 bash
501 88867 87090   0  4:15PM ttys019    0:00.00 cat
501 88868 87090   0  4:15PM ttys019    0:00.00 cat
501 88869 87090   0  4:15PM ttys019    0:00.01 cat
```


### case 4

```sh
echo a >| grep a

>>cat grep
a a
```

파이프가 아무런 역할을 하지 않는다.  
[defence](https://unix.stackexchange.com/questions/45201/bash-what-does-do)


```sh
echo testsetsetsetse |> grep a
bash: a: command not found
>>ls
grep
>>cat grep

```
